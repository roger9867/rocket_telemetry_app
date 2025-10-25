//
// Created by roger on 10/25/25.
//

#ifndef POSTGRES_DATABASE_H
#define POSTGRES_DATABASE_H
#include <pqxx/pqxx>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

class PostgresDatabase {
public:
    explicit PostgresDatabase(const std::string& connection_string);
    ~PostgresDatabase() = default;

    void connect();
    void execute(const std::string& query);
    pqxx::result query(const std::string& query);
    void initSchemaFromFile(const std::string& filepath);

    pqxx::connection& getConnection() { return *connection; }

private:
    std::string connection_string;
    std::unique_ptr<pqxx::connection> connection;
};




#endif //POSTGRES_DATABASE_H
