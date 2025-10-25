//
// Created by roger on 10/25/25.
//

#include "rocket_design_serializable.h"

/*

// RocketDesignSerializable
RocketDesignSerializable::RocketDesignSerializable(const std::string& _id,
                                                   const std::string& _name,
                                                   const std::string& _desc)
    : id(_id), design_name(_name), description(_desc) {}

const std::string& RocketDesignSerializable::get_id() const { return id; }
const std::string& RocketDesignSerializable::get_name() const { return design_name; }
const std::string& RocketDesignSerializable::get_description() const { return description; }
const std::vector<Image>& RocketDesignSerializable::get_images() const { return images; }

void RocketDesignSerializable::addImage(const RocketImage& img) {
    images.push_back(img);
}

Json RocketDesignSerializable::serialize(SerializationMode mode, int depth) {
    Json j;
    j["id"] = id;
    j["design_name"] = design_name;
    j["description"] = description;

    if (!images.empty() && mode != SerializationMode::NoLevel) {
        j["images"] = Json::array();
        for (const auto& img : images) {
            j["images"].push_back({
                {"url", img.url},
                {"filename", img.filename}
            });
        }
    }
    return j;
}

void RocketDesignSerializable::deserialize(const Json& j) {
    if (j.contains("id")) j["id"].get_to(id);
    if (j.contains("design_name")) j["design_name"].get_to(design_name);
    if (j.contains("description")) j["description"].get_to(description);

    images.clear();
    if (j.contains("images") && j["images"].is_array()) {
        for (const auto& img_json : j["images"]) {
            RocketImage img;
            if (img_json.contains("url")) img_json["url"].get_to(img.url);
            if (img_json.contains("filename")) img_json["filename"].get_to(img.filename);
            images.push_back(img);
        }
    }
}
*/