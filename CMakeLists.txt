cmake_minimum_required (VERSION 2.6)
project (IPReserved)
include_directories("${PROJECT_SOURCE_DIR}")
add_executable(ip_reserved ip_reserved.c test.c)