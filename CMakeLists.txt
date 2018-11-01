cmake_minimum_required(VERSION 3.8)
project(ally)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -v")

# Add Mstch
find_package(mstch)

# Add MySQL
add_library(libmysqlcppconn SHARED IMPORTED)
set_property(TARGET libmysqlcppconn PROPERTY IMPORTED_LOCATION /usr/local/Cellar/mysql-connector-c++/1.1.9_2/lib/libmysqlcppconn.dylib)

#Add Boost
include_directories(/usr/local/include)

add_library(libboost_system SHARED IMPORTED)
set_property(TARGET libboost_system PROPERTY IMPORTED_LOCATION /usr/local/opt/boost/lib/libboost_system.dylib)

add_library(libboost_filesystem SHARED IMPORTED)
set_property(TARGET libboost_filesystem PROPERTY IMPORTED_LOCATION /usr/local/opt/boost/lib/libboost_filesystem.dylib)

# Create executable
set(SOURCE_FILES source/main.cpp)
add_executable(ally ${SOURCE_FILES})
target_link_libraries(ally libboost_system libboost_filesystem mstch::mstch libmysqlcppconn)
