cmake_minimum_required(VERSION 3.15)
project(libcurl-example-callback VERSION 0.0.1)

set(CMAKE_C_STANDARD 11)

include_directories(inc src)

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)

#add_library(example_get SHARED  example_get.c
#        example_get.h)

add_executable(libcurl-example-callback src/elastic_search_client_play.c
        src/example_get.c
        inc/example_get.h
        src/example_put.c
        inc/example_put.h
        src/request_callback.c
        inc/request_callback.h
        src/response_callback.c
        inc/response_callback.h)

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(libcurl-example-callback ${CURL_LIBRARIES})
