//
// Created by roger on 10/25/25.
//

#ifndef ROCKET_DESIGN_REPOSITORY_H
#define ROCKET_DESIGN_REPOSITORY_H
#include <pqxx/pqxx>
#include <vector>
#include <string>
#include "i_repository.h"
#include "../../../domain/rocket_design.h"
#include "../db/postgres_database.h"

class RocketDesignRepository : public IRepository<RocketDesign> {
public:
    RocketDesignRepository(PostgresDatabase& db);
    ~RocketDesignRepository() override = default;

    void create(const RocketDesign& design) override;
    RocketDesign read(const std::string& id) override;
    void update(const RocketDesign& design) override;
    void remove(const std::string& id) override;
    std::vector<RocketDesign> readAll() override;

private:
    PostgresDatabase& database;
};





#endif //ROCKET_DESIGN_REPOSITORY_H
