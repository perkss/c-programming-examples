#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "response_callback.h"
#include "record.h"

// https://curl.haxx.se/libcurl/c/getinmemory.html
// example of the write call back
/**
 * Gets the Indexed Document
 */
void get_request(CURL *curl_handle, CURLcode res, char *url) {

    struct Record chunk;

    chunk.payload = malloc(1);  /* will be grown as needed by the realloc above */
    chunk.size = 0;    /* no data at this point */

    if (curl_handle) {

        curl_easy_setopt(curl_handle, CURLOPT_URL, url);

        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, response_callback);

        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *) &chunk);

        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        res = curl_easy_perform(curl_handle);

        if (res != CURLE_OK) {
            fprintf(stderr, "CURL EASY PERFORM RETURNED %s\n", curl_easy_strerror(res));
        } else {
            /*
             * Now, our chunk.memory points to a memory block that is chunk.size
             * bytes big and contains the remote file.
             *
             * Do something nice with it!
             */
            printf("%lu bytes retrieved\n", (unsigned long) chunk.size);
            printf("GET Request data retrieved is %s\n", chunk.payload);

        }

        free(chunk.payload);

        curl_easy_cleanup(curl_handle);
    }
}
