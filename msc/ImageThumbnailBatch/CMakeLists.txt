cmake_minimum_required(VERSION 2.8)
project(ImageThumbnailBatch)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5GUI REQUIRED)
add_definitions( ${QT_DEFINITIONS} )
include_directories( ${CMAKE_BINARY_DIR} )

file(GLOB ImageThumbnailBatch_SRC
    "*.h"
    "*.cpp"
)

add_executable(${PROJECT_NAME} "main.cpp" ${ImageThumbnailBatch_SRC})
qt5_use_modules(${PROJECT_NAME} Core Gui)
target_link_libraries( PROJECT_NAME ${QT_LIBRARIES} )
