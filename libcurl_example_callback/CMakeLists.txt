cmake_minimum_required(VERSION 3.15)
project(libcurl_example_callback)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(libcurl_example
        elastic_search_client_play.c
        example_get.c
        example_get.h
        example_put.c
        example_put.h
        request_callback.c
        request_callback.h
        response_callback.c
        response_callback.h)
