//
// Created by roger on 10/24/25.
//

#ifndef JSON_SERIALIZABLE_H
#define JSON_SERIALIZABLE_H

#include "json.hpp"

typedef nlohmann::json Json;

/* All classes that can be transferred via network should implement this interface */
class JsonSerializable {
public:
    enum class SerializationMode {
        NoLevel,
        OneLevel,
        AllLevels
    };

    virtual Json serialize(SerializationMode = SerializationMode::OneLevel, int depth = 0) = 0;
    virtual void  deserialize(const Json& json) = 0;

    Json serialize_loadable_pointer(JsonSerializable* ptr, std::optional<std::string> id, SerializationMode mode = SerializationMode::OneLevel, int depth = 0);

    template<class T>
    T* deserialize_loadable_pointer(const Json& json, std::optional<std::string>& id) {
        if (json.is_null()) {
            id = std::nullopt;
            return nullptr;
        }
        if (json.is_number_unsigned()) {
            std::string _id;
            json.get_to(_id);
            id = _id;
            return nullptr;
        }
        if (json.is_object()) {
            T* object = new T("0");
            object->serialize(json);
            id = object->get_id();
            return object;
        }
        throw std::runtime_error("illegal json object");
    }
};

#endif //JSON_SERIALIZABLE_H
