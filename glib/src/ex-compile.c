#include <stdio.h>
#include <glib.h>

#include "ex-compile.h"

int appendSingleItem() {
    GList *list = NULL;
    list = g_list_append(list, "Hello world!");
    printf("The first item is '%s'\n", g_list_first(list)->data);
    return 0;
}
