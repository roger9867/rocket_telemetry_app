//
// Created by roger on 10/24/25.
//

#ifndef FLIGHTLOG_SERVICE_H
#define FLIGHTLOG_SERVICE_H
#include <chrono>
#include <string>

using Timestamp = std::chrono::system_clock::time_point;

class FlightLogService {
public:
    static FlightLogService& get_single_instance();
    static std::string timestamp_to_string(const Timestamp& timestamp);
    static Timestamp string_to_timestamp(const std::string& str);

    FlightLogService(const FlightLogService&) = delete;
    FlightLogService& operator=(const FlightLogService&) = delete;

private:

    FlightLogService() = default;
};





#endif //FLIGHTLOG_SERVICE_H
