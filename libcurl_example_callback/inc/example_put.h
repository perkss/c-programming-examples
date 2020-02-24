#ifndef GLIB_EXAMPLE_PUT_H
#define GLIB_EXAMPLE_PUT_H

void put_request_with_callback(CURL *curl, CURLcode res, char *url, char *data);

void put_request(CURL *curl, CURLcode res);

#endif //GLIB_EXAMPLE_PUT_H
