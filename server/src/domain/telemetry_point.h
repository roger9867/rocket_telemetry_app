//
// Created by roger on 10/25/25.
//

#ifndef TELEMETRY_POINT_H
#define TELEMETRY_POINT_H
#include <chrono>

using Timestamp = std::chrono::system_clock::time_point;


struct TelemetryPoint {
    Timestamp timestamp;   // common timestamp for this snapshot

    // Regular sensors
    double sensor1;
    double sensor2;
    double sensor3;
    double sensor4;
    double sensor5;
    double sensor6;
    double sensor7;
    double sensor8;
    double sensor9;
    double sensor10;

    // GPS data
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
    double accuracy;

    TelemetryPoint(Timestamp ts,
                   const std::array<double, 10>& sensors,
                   double lat, double lon, double alt,
                   double spd = 0.0, double hdg = 0.0, double acc = 0.0)
        : timestamp(ts),
          sensor1(sensors[0]), sensor2(sensors[1]), sensor3(sensors[2]),
          sensor4(sensors[3]), sensor5(sensors[4]), sensor6(sensors[5]),
          sensor7(sensors[6]), sensor8(sensors[7]), sensor9(sensors[8]),
          sensor10(sensors[9]),
          latitude(lat), longitude(lon), altitude(alt),
          speed(spd), heading(hdg), accuracy(acc) {}
};

#endif //TELEMETRY_POINT_H
