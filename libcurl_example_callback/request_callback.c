#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "request_callback.h"


/**For writing the data for the requests **/
size_t request_sent_callback(void *dest, size_t size, size_t nmemb, void *userp) {
    struct Request *wt = (struct Request *) userp;
    size_t buffer_size = size * nmemb;

    if (wt->sizeleft) {
        /* copy as much as possible from the source to the destination */
        printf("Copying data");
        size_t copy_this_much = wt->sizeleft;
        if (copy_this_much > buffer_size)
            copy_this_much = buffer_size;
        memcpy(dest, wt->readptr, copy_this_much);

        wt->readptr += copy_this_much;
        wt->sizeleft -= copy_this_much;
        return copy_this_much; /* we copied this many bytes */
    }

    return 0; /* no more data left to deliver */
}