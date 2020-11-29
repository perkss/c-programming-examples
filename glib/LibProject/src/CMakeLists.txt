# Notice name prefix of this variable, set by CMake according
# to value given with "project()" in the root CMakeLists.txt.
include_directories(${MyProject_SOURCE_DIR}/LibProject/include)
add_library(LibProject ex-compile.c single-linked-list.c)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GLIB REQUIRED IMPORTED_TARGET glib-2.0)

target_link_libraries(LibProject PRIVATE PkgConfig::GLIB)