//
// Created by roger on 10/25/25.
//

#include "postgres_database.h"



PostgresDatabase::PostgresDatabase(const std::string& connection_string)
    : connection_string(connection_string), connection(nullptr) {}

void PostgresDatabase::connect() {
    if (!connection || !connection->is_open()) {
        connection = std::make_unique<pqxx::connection>(connection_string);
        if (!connection->is_open()) {
            throw std::runtime_error("Failed to connect to PostgreSQL database");
        }
    }
}

void PostgresDatabase::execute(const std::string& query) {
    if (!connection || !connection->is_open())
        throw std::runtime_error("Database not connected");

    pqxx::work transaction(*connection);
    transaction.exec(query);
    transaction.commit();
}

pqxx::result PostgresDatabase::query(const std::string& query) {
    if (!connection || !connection->is_open())
        throw std::runtime_error("Database not connected");

    pqxx::work transaction(*connection);
    pqxx::result result = transaction.exec(query);
    transaction.commit();
    return result;
}

void PostgresDatabase::initSchemaFromFile(const std::string& filepath) {
    if (!connection || !connection->is_open())
        throw std::runtime_error("Database not connected");

    std::ifstream file(filepath);
    if (!file.is_open())
        throw std::runtime_error("Failed to open schema file: " + filepath);

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sql = buffer.str();

    pqxx::work transaction(*connection);
    std::stringstream ss(sql);
    std::string statement;

    while (std::getline(ss, statement, ';')) {
        statement.erase(0, statement.find_first_not_of(" \n\r\t"));
        statement.erase(statement.find_last_not_of(" \n\r\t") + 1);
        if (!statement.empty()) transaction.exec(statement);
    }

    transaction.commit();
    std::cout << "Schema initialized successfully from " << filepath << std::endl;
}
