//
// Created by roger on 10/24/25.
//

#include "flightlog_service.h"

#include <iomanip>
#include <stdexcept>


FlightLogService& FlightLogService::get_single_instance() {
    static FlightLogService instance;
    return instance;
}


std::string FlightLogService::timestamp_to_string(const Timestamp& timestamp) {
    std::time_t t = std::chrono::system_clock::to_time_t(timestamp);
    std::tm tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}


Timestamp FlightLogService::string_to_timestamp(const std::string& str) {
    std::tm tm = {};
    std::istringstream ss(str);

    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (ss.fail()) {
        throw std::runtime_error("Failed to parse timestamp: " + str);
    }

    std::time_t time = std::mktime(&tm);
    return std::chrono::system_clock::from_time_t(time);
}