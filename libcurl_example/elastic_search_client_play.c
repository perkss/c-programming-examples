#include <stdio.h>
#include <curl/curl.h>

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

/**
 * Gets the Indexed Document
 */
void get_request(CURL *curl_handle, CURLcode res) {

    curl_handle = curl_easy_init();

    if (curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, "http://localhost:9200/chocolate/_doc/1");

        res = curl_easy_perform(curl_handle);

        if (res != CURLE_OK) {
            fprintf(stderr, "CURL EASY PERFORM RETURNED %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl_handle);
    }
}

int main(void) {

    CURL *curl_handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    /* Index the document */
    put_request(curl_handle, res);

    /* Get the indexed document */
    get_request(curl_handle, res);

    curl_global_cleanup();

    return 0;

}

