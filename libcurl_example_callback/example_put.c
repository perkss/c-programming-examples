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

    // this holds the response
    struct Record chunk;

    chunk.payload = malloc(1);  /* will be grown as needed by the realloc above */
    chunk.size = 0;    /* no data at this point */

    // TODO this holds the payload for writing data
    struct Record wt;

    // Assing the data to be posted
    wt.payload = data;
    wt.size = strlen(data);

    printf("\nPUT WT is filled with request data %s\n", wt.payload);

    /* First set the URL that is about to receive our POST. */
    curl_easy_setopt(curl, CURLOPT_URL, url);

    /* Now specify we want to POST data */
    curl_easy_setopt(curl, CURLOPT_PUT, 1L);

    /* we want to use our own read function */
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, request_sent_callback);


    /* pointer to pass to our read function */
    curl_easy_setopt(curl, CURLOPT_READDATA, &wt);

    /* get verbose debug output please */
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charsets: utf-8");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, response_callback);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    /*
      If you use POST to a HTTP 1.1 server, you can send data without knowing
      the size before starting the POST if you use chunked encoding. You
      enable this by adding a header like "Transfer-Encoding: chunked" with
      CURLOPT_HTTPHEADER. With HTTP 1.0 or without chunked transfer, you must
      specify the size in the request.
    */
#ifdef USE_CHUNKED
    {
      struct curl_slist *chunk = NULL;

      chunk = curl_slist_append(chunk, "Transfer-Encoding: chunked");
      res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
      /* use curl_slist_free_all() after the *perform() call to free this
         list again */
    }
#else
    /* Set the expected POST size. If you want to POST large amounts of data,
       consider CURLOPT_POSTFIELDSIZE_LARGE */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) wt.size);
#endif

#ifdef DISABLE_EXPECT
    /*
      Using POST with HTTP 1.1 implies the use of a "Expect: 100-continue"
      header.  You can disable this header with CURLOPT_HTTPHEADER as usual.
      NOTE: if you want chunked transfer too, you need to combine these two
      since you can only set one list of headers with CURLOPT_HTTPHEADER. */

    /* A less good option would be to enforce HTTP 1.0, but that might also
       have other implications. */
    {
      struct curl_slist *chunk = NULL;

      chunk = curl_slist_append(chunk, "Expect:");

        printf("Headers back put");
      res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
      /* use curl_slist_free_all() after the *perform() call to free this
         list again */
    }
#endif

    /* Perform the request, res will get the return code */

    res = curl_easy_perform(curl);
    /* Check for errors */
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    } else {
        /*
         * Now, our chunk.memory points to a memory block that is chunk.size
         * bytes big and contains the remote file.
         *
         * Do something nice with it!
         */

        printf("%lu bytes retrieved\n", (unsigned long) chunk.size);
        printf("Post data retrieved is %s\n", chunk.payload);

    }

    printf("\nPUT WT is empty as sent data and emptied buffer %s\n", wt.payload);
    /* always cleanup */
    curl_easy_cleanup(curl);
}

/**
 * Calls elastic search with a PUT request to install our JSON.
 */
void put_request(CURL *curl, CURLcode res) {

    curl = curl_easy_init();
    if (curl) {

        /* Set the headers */
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "charsets: utf-8");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        /* Say its a PUT */
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
        /* Set the URL */
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:9200/chocolate/_doc/1");
        /* Specify the data */
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{ \"id\": 1, \"name\": \"dark\" }");

        /* Perform the request PUTT the JSON, res will get the return code */
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
}
