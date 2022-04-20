#include <stdio.h>
#include <string.h>
#include "dict.h"

int main(void) {
    Dictelem *test = dict_new("kag", NULL, 0);

    Dictelem *dict = dict_new("123", test, sizeof(*test));
    dict = dict_add_elem(dict, "124", "123", strlen("123") + 1);
    // dict_print(dict);

    keyvalue_cpy(dict -> keyvalue, dict -> next -> keyvalue);

    dict_print(dict);
    printf("%s == %s? %d\n", dict -> keyvalue -> key, dict -> next -> keyvalue -> key,
                                    keyvalue_cmp_by_value(dict -> keyvalue, dict -> next -> keyvalue));

    dict = dict_del_with_key(dict, "124");
    dict_print(dict);

    return 0;
}
