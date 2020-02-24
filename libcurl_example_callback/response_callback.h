#ifndef GLIB_RESPONSE_CALLBACK_H
#define GLIB_RESPONSE_CALLBACK_H

struct Response {
    char *memory;
    size_t size;
};

// Can this be included?
static size_t;

size_t response_callback(void *contents, size_t size, size_t nmemb, void *userp);

#endif //GLIB_RESPONSE_CALLBACK_H
