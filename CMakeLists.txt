cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled src/main.cpp src/class_parser.h src/class_builder.h src/class_property.h src/parsed_result.h src/java_parser.cpp src/java_parser.h src/dart_class_builder.cpp src/dart_class_builder.h src/string_manip.cpp src/string_manip.h src/java_property.cpp src/java_property.h src/dart_property.cpp src/dart_property.h)