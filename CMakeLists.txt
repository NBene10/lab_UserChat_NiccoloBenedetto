cmake_minimum_required(VERSION 3.14)
project(lab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(gtest)
set(SOURCE_FILES ChatRoom.cpp NotificationCenter.cpp User.cpp UnreadMessage.cpp UnreadMessage.h Message.cpp)
add_executable(lab main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(lab core)


