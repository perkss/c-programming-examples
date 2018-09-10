#include <stdio.h>
#include <glib.h>

void display_list (GSList *list);

int main(int argc, char** argv) {
  GSList* list = NULL;
  printf("The list is now %d items long\n", g_slist_length(list));

  list = g_slist_append(list, "first");
  list = g_slist_append(list, "second");
  list = g_slist_prepend(list, "zero");

  printf("The list is now %d items long\n", g_slist_length(list));

  display_list(list);

  list = g_slist_remove(list, "first");

  printf("The list is now %d items long\n", g_slist_length(list));

  display_list(list);

  printf("The item at index '1': '%s'\n", g_slist_nth_data(list, 1));

  g_slist_free(list);

  return 0;
}

void display_list (GSList *list) {
  int    nIndex;
  GSList *node;

  for (nIndex = 0; (node = g_slist_nth (list, nIndex)); nIndex++) {

    printf("%s\n", (char *) node->data);
  }
}
