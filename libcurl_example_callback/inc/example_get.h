#ifndef GLIB_EXAMPLE_GET_H
#define GLIB_EXAMPLE_GET_H

// https://curl.haxx.se/libcurl/c/getinmemory.html
// example of the write call back
/**
 * Gets the Indexed Document
 */
void get_request(CURL *curl_handle, CURLcode res, char *id);

#endif //GLIB_EXAMPLE_GET_H
