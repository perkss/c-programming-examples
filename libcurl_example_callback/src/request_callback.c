#include <stdio.h>
#include <string.h>
#include "inc/request_callback.h"
#include "inc/record.h"


/**For writing the data for the requests **/
size_t request_sent_callback(void *dest, size_t size, size_t nmemb, void *userp) {
    Record *wt = (Record *) userp;
    size_t buffer_size = size * nmemb;

    if (wt->size) {
        /* copy as much as possible from the source to the destination */
        printf("Copying data\n");
        size_t copy_this_much = wt->size;
        if (copy_this_much > buffer_size)
            copy_this_much = buffer_size;
        memcpy(dest, wt->payload, copy_this_much);

        wt->payload += copy_this_much;
        wt->size -= copy_this_much;
        return copy_this_much; /* we copied this many bytes */
    }

    return 0; /* no more data left to deliver */
}