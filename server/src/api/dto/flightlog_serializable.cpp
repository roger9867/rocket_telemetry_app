//
// Created by roger on 10/24/25.
//

#include "flightlog_serializable.h"

#include "../../service/flightlog_service.h"

FlightLogSerializable::FlightLogSerializable(std::string id)
    : FlightLog(id) {}

FlightLogSerializable::FlightLogSerializable(std::string id, Timestamp timestamp, std::shared_ptr<RocketDesign> design)
    : FlightLog(id, timestamp, design) {}

FlightLogSerializable::FlightLogSerializable() {}

FlightLogSerializable::~FlightLogSerializable() {}

Json FlightLogSerializable::serialize(SerializationMode mode, int depth) {
    if (mode == SerializationMode::NoLevel) {
        return Json::object({ {"id", log_id} });
    }

    Json json = {
        { "id", log_id },
        { "timestamp", FlightLogService::timestamp_to_string(timestamp) },
        { "design_id", design->id }
    };
    return json;
}


void FlightLogSerializable::deserialize(const Json& json) {
    if (json.contains("id") && !json.at("id").is_null())
        json.at("id").get_to(log_id);


    if (json.contains("timestamp") && !json.at("timestamp").is_null()) {
        std::string timestamp_str;
        json.at("timestamp").get_to(timestamp_str);
        timestamp = FlightLogService::string_to_timestamp(timestamp_str);
    }

    design = nullptr;
    std::optional<std::string> design_id;
    if (json.contains("design_id") && !json.at("design_id").is_null()) {
        const auto& design_json = json.at("design_id");
        if (design_json.is_object() && design_json.contains("id") && !design_json.at("id").is_null())
            design_id = design_json.at("id").get<std::string>();
        //design = deserialize_loadable_pointer<DesignSerializable>(parent_json, parent_id);
    }
}