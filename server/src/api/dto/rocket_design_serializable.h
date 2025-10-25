//
// Created by roger on 10/25/25.
//

#ifndef ROCKET_DESIGN_SERIALIZABLE_H
#define ROCKET_DESIGN_SERIALIZABLE_H
#include <string>
#include <vector>
#include "../../domain/rocket_image.h"
/*

class RocketDesignSerializable : public JsonSerializable {
private:
    std::string id;
    std::string design_name;
    std::string description;
    std::vector<RocketImage> images;

public:
    RocketDesignSerializable() = default;
    RocketDesignSerializable(const std::string& _id,
                              const std::string& _name = "",
                              const std::string& _desc = "");

    // Getter
    const std::string& get_id() const;
    const std::string& get_name() const;
    const std::string& get_description() const;
    const std::vector<RocketImage>& get_images() const;

    void addImage(const RocketImage& img);

    // JsonSerializable Overrides
    Json serialize(SerializationMode mode = SerializationMode::OneLevel, int depth = 0) override;
    void deserialize(const Json& j) override;
};

*/

#endif //ROCKET_DESIGN_SERIALIZABLE_H
