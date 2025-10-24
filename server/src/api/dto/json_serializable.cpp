//
// Created by roger on 10/24/25.
//

#include "json_serializable.h"

// falls der pointer keinen wert hat, null json zurückgeben
Json JsonSerializable::serialize_loadable_pointer(JsonSerializable* serializable, std::optional<std::string> id, SerializationMode mode, int depth) {
    if (!id.has_value())
        return nullptr; // JSON null

    if (serializable == nullptr)
        return nullptr; // JSON null

    if (mode == SerializationMode::OneLevel) {
        return Json::object({{"id", id.value()}});
    }

    if (mode == SerializationMode::AllLevels)
        return serializable->serialize(SerializationMode::AllLevels);
}

