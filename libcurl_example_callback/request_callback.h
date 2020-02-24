#ifndef GLIB_REQUEST_CALLBACK_H
#define GLIB_REQUEST_CALLBACK_H

struct Request {
    const char *readptr;
    size_t sizeleft;
};

size_t request_sent_callback(void *dest, size_t size, size_t nmemb, void *userp);

#endif //GLIB_REQUEST_CALLBACK_H
