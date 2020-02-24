#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "example_put.h"
#include "request_callback.h"
#include "response_callback.h"
#include "record.h"

// https://curl.haxx.se/libcurl/c/post-callback.html for getting the data written entered
void put_request_with_callback(CURL *curl, CURLcode res, char *url, char *data) {

    curl = curl_easy_init();

    // this holds the response simply stack allocated here no malloc required
    Record response;

    response.payload = malloc(1);  /* will be grown as needed by the realloc above */
    response.size = 0;    /* no data at this point */

    // this holds the payload for writing data simply stack allocated here
    Record request;

    // Accessing the data to be posted
    request.payload = data;
    request.size = strlen(data);

    printf("\nPUT WT is filled with request data %s\n", request.payload);

    /* First set the URL that is about to receive our POST. */
    curl_easy_setopt(curl, CURLOPT_URL, url);

    /* Now specify we want to POST data */
    curl_easy_setopt(curl, CURLOPT_PUT, 1L);

    /* we want to use our own read function */
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, request_sent_callback);


    /* pointer to pass to our read function */
    curl_easy_setopt(curl, CURLOPT_READDATA, &request);

    /* get verbose debug output please */
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charsets: utf-8");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, response_callback);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &response);

    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    /* Set the expected POST data message size. Which we will know in advance */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, (long) request.size);

    /* Perform the request, res will get the return code */

    res = curl_easy_perform(curl);
    /* Check for errors */
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    } else {
        printf("%lu bytes retrieved\n", (unsigned long) response.size);
        printf("Post data retrieved is %s\n", response.payload);
    }

    printf("\nPUT WT is empty as sent data and emptied buffer %s\n", request.payload);
    /* always cleanup */
    curl_easy_cleanup(curl);
}