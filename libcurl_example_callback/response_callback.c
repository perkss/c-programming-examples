#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "response_callback.h"
#include "record.h"

/**
 * For reading the data that is returned into structure
 * @param contents
 * @param size
 * @param nmemb
 * @param userp
 * @return
 */
size_t response_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct Record *mem = (struct Record *) userp;

    char *ptr = realloc(mem->payload, mem->size + realsize + 1);
    if (ptr == NULL) {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->payload = ptr;
    memcpy(&(mem->payload[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->payload[mem->size] = 0;

    return realsize;
}