#include <iostream>
#include <chrono>
#include <thread>
#include <uuid/uuid.h>
#include "json.hpp"
#include "../infrastructure/persistence/db/postgres_database.h"
#include "../infrastructure/persistence/repository/rocket_design_repository.h"
#include "../domain/rocket_design.h"


std::string generate_uuid() {
    uuid_t uuid;
    uuid_generate_random(uuid);
    char str[37];
    uuid_unparse_lower(uuid, str);
    return std::string(str);
}


int main() {
    try {
        PostgresDatabase db("host=localhost port=5432 dbname=rocket_db user=rocket_user password=rocket_pass");
        db.connect();

        RocketDesignRepository repo(db);

        // --- RocketDesign erstellen ---
        RocketDesign design(generate_uuid(), "Falcon", "High-speed rocket");
        design.addImage({"https://example.com/falcon1.png", "falcon1.png"});
        design.addImage({"https://example.com/falcon2.png", "falcon2.png"});

        repo.create(design);
        std::cout << "RocketDesign erfolgreich gespeichert!" << std::endl;

        // --- Design laden und ausgeben ---
        RocketDesign loadedDesign = repo.read(design.id);
        std::cout << "\n--- Geladenes RocketDesign ---" << std::endl;
        std::cout << "ID: " << loadedDesign.id << "\nName: " << loadedDesign.design_name
                  << "\nDescription: " << loadedDesign.description << "\nImages ("
                  << loadedDesign.images.size() << "):" << std::endl;
        for (size_t i = 0; i < loadedDesign.images.size(); ++i) {
            std::cout << "  Image " << i << ": "
                      << loadedDesign.images[i].url << ", "
                      << loadedDesign.images[i].filename << std::endl;
        }

        // --- Update durchführen ---
        loadedDesign.description = "Updated high-speed rocket design!";
        loadedDesign.addImage({"https://example.com/falcon3.png", "falcon3.png"});
        repo.update(loadedDesign);
        std::cout << "\nRocketDesign erfolgreich aktualisiert!" << std::endl;

        // --- Nach Update erneut laden und ausgeben ---
        RocketDesign updatedDesign = repo.read(design.id);
        std::cout << "\n--- Nach Update ---" << std::endl;
        std::cout << "ID: " << updatedDesign.id << "\nName: " << updatedDesign.design_name
                  << "\nDescription: " << updatedDesign.description << "\nImages ("
                  << updatedDesign.images.size() << "):" << std::endl;
        for (size_t i = 0; i < updatedDesign.images.size(); ++i) {
            std::cout << "  Image " << i << ": "
                      << updatedDesign.images[i].url << ", "
                      << updatedDesign.images[i].filename << std::endl;
        }

        // --- Löschen ---
        repo.remove(design.id);
        std::cout << "\nRocketDesign erfolgreich gelöscht!" << std::endl;

        // --- Überprüfen, ob es noch existiert ---
        try {
            RocketDesign deletedDesign = repo.read(design.id);
            std::cout << "Fehler: RocketDesign sollte gelöscht sein, ist aber noch vorhanden!" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Bestätigung: RocketDesign existiert nicht mehr in der DB." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
    }

    return 0;
}

