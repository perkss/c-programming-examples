#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include "example_get.h"
#include "example_put.h"

int main(void) {

    CURL *curl_handle;
    CURLcode res;

    res = curl_global_init(CURL_GLOBAL_DEFAULT);
    /* Check for errors */
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_global_init() failed: %s\n",
                curl_easy_strerror(res));
        return 1;
    }

    char url[40] = "http://localhost:9200/chocolate/_doc/";
    strcat(url, "1");

    /* Index the document */
    put_request_with_callback(curl_handle, res, url, "{ \"id\": 1, \"name\": \"dark\" }");

    /* Required to be init each call*/

    /* Get the indexed document what is the best way to assign the memory here for the cat*/

    get_request(curl_handle, res, url);

    curl_global_cleanup();

    return 0;

}

