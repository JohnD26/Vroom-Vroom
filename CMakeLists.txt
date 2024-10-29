cmake_minimum_required(VERSION 3.10)
project(VroomVroom)

set(CMAKE_CXX_STANDARD 17)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES}
        src/ml/DecisionModel.cpp
        src/ml/DecisionModel.h
        src/sensors/LiDAR.cpp
        src/sensors/LiDAR.h
        src/sensors/Radar.cpp
        src/sensors/Radar.h
        src/sensors/Camera.cpp
        src/sensors/Camera.h
        src/fusion/SensorFusion.cpp
        src/fusion/SensorFusion.h
        src/visualization/Renderer.cpp
        src/visualization/Renderer.h)

# Find OpenGL and GLFW
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# Include directories (usually handled automatically, but you can specify if needed)
include_directories(
        ${OPENGL_INCLUDE_DIR}
        src
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
        OpenGL::GL
        glfw
)


find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
