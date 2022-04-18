#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dict.h"

int main(void) {
    Dictelem *dict = dict_new_dict("123", "123");
    dict = dict_add_elem(dict, "124", "123");

    dict_print(dict);
    printf("%s == %s\n", dict->keyvalue->value, dict->next->keyvalue->value);

    printf("%d\n", keyvalue_cmp_by_value(dict->keyvalue, dict->next->keyvalue));

    return 0;
}
