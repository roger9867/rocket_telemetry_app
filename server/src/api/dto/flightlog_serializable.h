//
// Created by roger on 10/24/25.
//

#ifndef FLIGHT_SERIALIZABLE_H
#define FLIGHT_SERIALIZABLE_H
#include "json_serializable.h"
#include "../../domain/flight_log.h"

class FlightLog;
typedef std::chrono::system_clock::time_point Timestamp;

class FlightLogSerializable : virtual public FlightLog, public JsonSerializable {
public:

    FlightLogSerializable();
    FlightLogSerializable(std::string id);
    FlightLogSerializable(std::string id, Timestamp timestamp, std::shared_ptr<RocketDesign> design);
    FlightLogSerializable(FlightLog flightlog);
    virtual ~FlightLogSerializable();

    virtual Json serialize(SerializationMode mode = SerializationMode::NoLevel, int depth = 0) override;
    virtual void deserialize(const Json& json) override;
};

#endif // FLIGHT_SERIALIZABLE_H
