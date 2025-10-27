//
// Created by roger on 10/25/25.
//

#ifndef FLIGHT_LOG_REPOSITORY_H
#define FLIGHT_LOG_REPOSITORY_H
#include "IRepository.h"
#include "FlightLog.h"
#include <pqxx/pqxx>   // PostgreSQL C++ library
#include <memory>
#include <vector>
#include <string>

class FlightLogRepository : public IRepository<FlightLog> {
private:
    pqxx::connection& conn;

public:
    explicit FlightLogRepository(pqxx::connection& connection);
    ~FlightLogRepository() override = default;

    void create(const FlightLog& entity) override;
    FlightLog read(const std::string& id) override;
    std::vector<FlightLog> readAll() override;
    void update(const FlightLog& entity) override;
    void remove(const std::string& id) override;

private:
    void saveTelemetry(const std::string& log_id, const std::vector<TelemetryPoint>& telemetry);
    std::vector<TelemetryPoint> loadTelemetry(const std::string& log_id);
};


class flight_log_repository {

};



#endif //FLIGHT_LOG_REPOSITORY_H
