//
// Created by roger on 10/25/25.
//

#include "flight_log_repository.h"

FlightLogRepository::FlightLogRepository(pqxx::connection& connection) : connection(connection) {}

void FlightLogRepository::create(const FlightLog& entity) {
    pqxx::work transaction(connection);

    // Insert FlightLog
    transaction.exec_params(
        "INSERT INTO flight_logs (log_id, timestamp, rocket_design_id, video_url) "
        "VALUES ($1, $2, $3, $4)",
        entity.log_id,
        entity.timestamp.to_string(),   // adjust to your Timestamp type
        entity.design ? entity.design->id : "",
        entity.video_path
    );

    // Insert telemetry points
    saveTelemetry(entity.log_id, entity.telemetry);

    transaction.commit();
}

FlightLog FlightLogRepository::read(const std::string& id) {
    pqxx::work transaction(connection);

    auto result = transaction.exec_params(
        "SELECT log_id, timestamp, rocket_design_id, video_url FROM flight_logs WHERE log_id=$1",
        id
    );

    if (result.empty()) {
        throw std::runtime_error("FlightLog not found");
    }

    const auto& row = result[0];
    FlightLog flight:log;
    flight_log.log_id = row["log_id"].c_str();
    flight_log.timestamp = Timestamp(row["timestamp"].c_str());
    // load rocket design separately or set nullptr
    flight_log.video_path = row["video_url"].c_str();

    flight_log.telemetry = loadTelemetry(flight_log.log_id);

    return flight_log;
}

std::vector<FlightLog> FlightLogRepository::readAll() {
    pqxx::work transaction(connection);
    std::vector<FlightLog> flight_logs;

    auto result = transaction.exec("SELECT log_id FROM flight_logs");

    for (const auto& row : res) {
        flight_logs.push_back(read(row["log_id"].c_str())); // reuse read() to load telemetry
    }

    return flight_logs;
}

void FlightLogRepository::update(const FlightLog& entity) {
    pqxx::work transaction(connection);

    transaction.exec_params(
        "UPDATE flight_logs SET timestamp=$1, rocket_design_id=$2, video_url=$3 WHERE log_id=$4",
        entity.timestamp.to_string(),
        entity.design ? entity.design->id : "",
        entity.video_path,
        entity.log_id
    );

    // Replace telemetry: delete old, insert new
    transaction.exec_params("DELETE FROM telemetry WHERE log_id=$1", entity.log_id);
    saveTelemetry(entity.log_id, entity.telemetry);

    transaction.commit();
}

void FlightLogRepository::remove(const std::string& id) {
    pqxx::work transaction(connection);

    transaction.exec_params("DELETE FROM telemetry WHERE log_id=$1", id);
    transaction.exec_params("DELETE FROM flight_logs WHERE log_id=$1", id);

    transaction.commit();
}

// --- Private helpers ---

void FlightLogRepository::saveTelemetry(const std::string& log_id, const std::vector<TelemetryPoint>& telemetry) {
    if (telemetry.empty()) return;

    pqxx::work transaction(conn);

    for (const auto& point : telemetry) {
        transaction.exec_params(
            "INSERT INTO telemetry (log_id, timestamp, sensor1,sensor2,sensor3,sensor4,sensor5,"
            "sensor6,sensor7,sensor8,sensor9,sensor10,latitude,longitude,altitude,speed,heading,accuracy) "
            "VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18)",
            log_id, point.timestamp.to_string(),
            point.sensor1, point.sensor2, point.sensor3, point.sensor4, point.sensor5,
            point.sensor6, point.sensor7, point.sensor8, point.sensor9, point.sensor10,
            point.latitude, point.longitude, point.altitude, point.speed, point.heading, point.accuracy
        );
    }

    transaction.commit();
}

std::vector<TelemetryPoint> FlightLogRepository::loadTelemetry(const std::string& log_id) {
    pqxx::work transaction(conn);
    std::vector<TelemetryPoint> telemetry;

    auto result = transaction.exec_params(
        "SELECT timestamp, sensor1,sensor2,sensor3,sensor4,sensor5,sensor6,sensor7,sensor8,sensor9,sensor10,"
        "latitude,longitude,altitude,speed,heading,accuracy "
        "FROM telemetry WHERE log_id=$1 ORDER BY timestamp ASC",
        log_id
    );

    for (const auto& row : result) {
        TelemetryPoint point(
            Timestamp(row["timestamp"].c_str()),
            { row["sensor1"].as<double>(), row["sensor2"].as<double>(), row["sensor3"].as<double>(), row["sensor4"].as<double>(),
              row["sensor5"].as<double>(), row["sensor6"].as<double>(), row["sensor7"].as<double>(), row["sensor8"].as<double>(),
              row["sensor9"].as<double>(), row["sensor10"].as<double>() },
            row["latitude"].as<double>(),
            row["longitude"].as<double>(),
            row["altitude"].as<double>(),
            row["speed"].as<double>(),
            row["heading"].as<double>(),
            row["accuracy"].as<double>()
        );
        telemetry.push_back(point);
    }

    return telemetry;
}