//
// Created by domin on 10/29/2024.
//
// Vehicle.cpp
#include "Vehicle.h"

Vehicle::Vehicle()
        : position(0.0f, 0.0f, 0.0f),
          velocity(0.0f, 0.0f, 0.0f),
          acceleration(0.0f, 0.0f, 0.0f) {
    // Initialize vehicle properties
}

void Vehicle::update(float deltaTime) {
    // Update velocity
    velocity += acceleration * deltaTime;
    // Update position
    position += velocity * deltaTime;
}

void Vehicle::render() {
    // Rendering code (to be implemented)
}

glm::vec3 Vehicle::getPosition() const {
    return position;
}
