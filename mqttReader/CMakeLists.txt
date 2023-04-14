cmake_minimum_required(VERSION 3.14)

project(mqttReader LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(mqttReader
  main.cpp
)
target_link_libraries(mqttReader Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(mqttReader paho-mqttpp3 paho-mqtt3as)


install(TARGETS mqttReader
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
