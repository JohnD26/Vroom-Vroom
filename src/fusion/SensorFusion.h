//
// Created by domin on 10/29/2024.
//

// src/fusion/SensorFusion.h
#ifndef SENSORFUSION_H
#define SENSORFUSION_H

#include "../sensors/LiDAR.h"
// Include other sensor headers as needed

struct EnvironmentState {
    // Define the state of the environment as perceived by the sensors
};

class SensorFusion {
public:
    SensorFusion();
    EnvironmentState fuseData(const std::vector<Point>& lidarData);
    // Overload fuseData to include other sensor data as needed
};

#endif // SENSORFUSION_H
