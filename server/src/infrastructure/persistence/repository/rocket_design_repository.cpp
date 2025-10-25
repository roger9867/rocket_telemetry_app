//
// Created by roger on 10/25/25.
//
#include <stdexcept>
#include "rocket_design_repository.h"

// Konstruktor
RocketDesignRepository::RocketDesignRepository(PostgresDatabase& db) : database(db) {}

// CREATE
void RocketDesignRepository::create(const RocketDesign& design) {
    pqxx::work txn(database.getConnection());

    txn.exec(
        "INSERT INTO rocket_designs (id, design_name, description) VALUES (" +
        txn.quote(design.id) + ", " +
        txn.quote(design.design_name) + ", " +
        txn.quote(design.description) + ")"
    );

    for (const auto& image : design.images) {
        txn.exec(
            "INSERT INTO rocket_design_images (rocket_id, url, filename) VALUES (" +
            txn.quote(design.id) + ", " +
            txn.quote(image.url) + ", " +
            txn.quote(image.filename) + ")"
        );
    }

    txn.commit();
}

// READ
RocketDesign RocketDesignRepository::read(const std::string& id) {
    pqxx::work txn(database.getConnection());

    pqxx::result r = txn.exec(
        "SELECT id, design_name, description FROM rocket_designs WHERE id = " + txn.quote(id)
    );

    if (r.empty()) {
        throw std::runtime_error("RocketDesign not found");
    }

    const auto& row = r[0];
    RocketDesign design(row["id"].c_str(), row["design_name"].c_str(), row["description"].c_str());

    pqxx::result img_r = txn.exec(
        "SELECT url, filename FROM rocket_design_images WHERE rocket_id = " + txn.quote(id)
    );

    for (const auto& img_row : img_r) {
        design.addImage({ img_row["url"].c_str(), img_row["filename"].c_str() });
    }

    return design;
}

// UPDATE
void RocketDesignRepository::update(const RocketDesign& design) {
    pqxx::work txn(database.getConnection());

    txn.exec(
        "UPDATE rocket_designs SET design_name = " + txn.quote(design.design_name) +
        ", description = " + txn.quote(design.description) +
        " WHERE id = " + txn.quote(design.id)
    );

    // Alte Bilder löschen
    txn.exec("DELETE FROM rocket_design_images WHERE rocket_id = " + txn.quote(design.id));

    for (const auto& image : design.images) {
        txn.exec(
            "INSERT INTO rocket_design_images (rocket_id, url, filename) VALUES (" +
            txn.quote(design.id) + ", " +
            txn.quote(image.url) + ", " +
            txn.quote(image.filename) + ")"
        );
    }

    txn.commit();
}

// DELETE / REMOVE
void RocketDesignRepository::remove(const std::string& id) {
    pqxx::work txn(database.getConnection());

    txn.exec("DELETE FROM rocket_design_images WHERE rocket_id = " + txn.quote(id));
    txn.exec("DELETE FROM rocket_designs WHERE id = " + txn.quote(id));

    txn.commit();
}

// READ ALL
std::vector<RocketDesign> RocketDesignRepository::readAll() {
    pqxx::work txn(database.getConnection());

    pqxx::result r = txn.exec("SELECT id, design_name, description FROM rocket_designs");

    std::vector<RocketDesign> designs;
    for (const auto& row : r) {
        RocketDesign design(row["id"].c_str(), row["design_name"].c_str(), row["description"].c_str());

        pqxx::result img_r = txn.exec(
            "SELECT url, filename FROM rocket_design_images WHERE rocket_id = " + txn.quote(design.id)
        );

        for (const auto& img_row : img_r) {
            design.addImage({ img_row["url"].c_str(), img_row["filename"].c_str() });
        }

        designs.push_back(design);
    }

    return designs;
}