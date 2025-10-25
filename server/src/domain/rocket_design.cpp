//
// Created by roger on 10/24/25.
//

#include "rocket_design.h"

RocketDesign::RocketDesign(std::string id, std::string design_name, std::string description)
    : id(id), design_name(design_name), description(description) {}

void RocketDesign::addImage(const RocketImage& image) {
    images.push_back(image);
}