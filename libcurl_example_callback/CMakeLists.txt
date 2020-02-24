cmake_minimum_required(VERSION 3.15)
project(libcurl-example-callback)

set(CMAKE_C_STANDARD 11)

include_directories(.)

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)

#add_library(example_get SHARED  example_get.c
#        example_get.h)

add_executable(libcurl-example-callback elastic_search_client_play.c
        example_get.c
        example_get.h
        example_put.c
        example_put.h
        request_callback.c
        request_callback.h
        response_callback.c
        response_callback.h)

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(libcurl-example-callback ${CURL_LIBRARIES})
