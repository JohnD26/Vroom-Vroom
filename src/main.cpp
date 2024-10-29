// src/main.cpp
#include "vehicle/Vehicle.h"
#include "sensors/LiDAR.h"
#include "fusion/SensorFusion.h"
#include "visualization/Renderer.h"

#include <GLFW/glfw3.h>
#include <iostream>

void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Autonomous Vehicle Simulator", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Set up your simulation objects
    Vehicle vehicle;
    LiDAR lidar;
    SensorFusion sensorFusion;
    Renderer renderer;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);

        // Update simulation
        vehicle.update(0.016f); // Assuming a fixed time step of 16ms
        auto lidarData = lidar.scan(vehicle);
        auto environmentState = sensorFusion.fuseData(lidarData);

        // Rendering commands here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        renderer.render(vehicle, environmentState);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    // Close window on pressing 'Esc'
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // Adjust the viewport when the window size changes
    glViewport(0, 0, width, height);
}
