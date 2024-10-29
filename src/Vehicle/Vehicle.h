// src/vehicle/Vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <glm/glm.hpp>

class Vehicle {
public:
    Vehicle();
    void update(float deltaTime);
    void render();

    glm::vec3 getPosition() const;

private:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
};

#endif // VEHICLE_H
