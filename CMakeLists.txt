cmake_minimum_required(VERSION 3.14)
project(winapi_demo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

include_directories("/")

add_executable(
        KontrolnayaRabota_oy_to_est_Laba1
        Main.cpp
        View/view.cpp
        Controller/controller.cpp
        Model/model.cpp
        Model/Client/clients.cpp
        Model/Client/honorable_clients.cpp
        Model/Client/cheating_clients.cpp
        Visitor/remove_visitor.cpp
        Model/Client/human.cpp)

target_link_libraries(KontrolnayaRabota_oy_to_est_Laba1 "Comctl32.lib")
