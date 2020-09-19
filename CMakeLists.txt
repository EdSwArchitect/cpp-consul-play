cmake_minimum_required(VERSION 3.17)
project(cpp_consul_play)

set(CMAKE_CXX_STANDARD 14)

find_package(oatpp 1.1.0 REQUIRED)
find_package(oatpp-consul 1.1.0 REQUIRED)

add_executable(cpp_consul_play main.cpp)

target_link_libraries(cpp_consul_play oatpp::oatpp oatpp::oatpp-consul)