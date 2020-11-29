cmake_minimum_required(VERSION 3.17)
project(glib-examples)
enable_language(C)

set(CMAKE_C_STANDARD 11)

# the `pkg_check_modules` function is created with this call
find_package(PkgConfig REQUIRED)

# these calls create special `PkgConfig::<MODULE>` variables
pkg_check_modules(GLIB REQUIRED IMPORTED_TARGET glib-2.0)

# Adds the two directories
include_directories(include src)

# Adds any library source code and headers into the project
add_library(LibsModule
        include/single-linked-list.h
        include/ex-compile.h
        src/ex-compile.c
        src/single-linked-list.c)

add_executable(glib-examples src/main.c)

# Add the dependent libraries to the modules
target_link_libraries(LibsModule PRIVATE PkgConfig::GLIB)
# Add the dependent libraries to the executable including local libs module
target_link_libraries(glib-examples PUBLIC PkgConfig::GLIB LibsModule)