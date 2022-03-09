#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"

char *str_cpy(char *str);

int main(void) {
    char *val0 = (char *) malloc(4 * sizeof(char));
    strcpy(val0, "222");

    Dictelem *dict = dict_new_dict("111", val0);

    Keyvalue *structure = (Keyvalue *) malloc(sizeof(Keyvalue));
    dict = dict_add_elem(dict, "super_struct", structure);


    char *val1 = (char *) malloc(4 * sizeof(char));
    strcpy(val1, "223");
    char *val2 = (char *) malloc(4 * sizeof(char));
    strcpy(val2, "224");
    char *val3 = (char *) malloc(4 * sizeof(char));
    strcpy(val3, "225");

    dict = dict_add_elem (dict, "112", val1);
    dict = dict_add_elem (dict, "113", val2);
    dict = dict_add_elem (dict, "114", val3);

    printf ("Here is your dict:\n");
    dict_print (dict, puts);
    printf("===\n");

    printf ("\n");

    printf("I will copy [114] element to [113] element.");
    keyvalue_cpy(dict -> next -> keyvalue, dict -> keyvalue, str_cpy);

    printf ("\n");

    printf ("Here is your dict:\n");
    dict_print (dict, puts);
    printf("===\n");

    printf ("\n");

    printf("[112]'s key = [111]'s key?\t");
    int status = keyvalue_cmp_by_key (dict -> next -> next -> keyvalue, dict -> next -> next -> next -> keyvalue);
    if (!status) {
        printf("Yep!");
    } else {
        printf("Nope!");
    }

    printf ("\n");

    printf("[112]'s value = [111]'s value?\t");
    status = keyvalue_cmp_by_value (dict -> next -> next -> keyvalue, dict -> next -> next -> next -> keyvalue, strcmp);
    if (!status) {
        printf("Yep!");
    } else {
        printf("Nope!");
    }

    printf ("\n");

    printf("Does [111] element have 111 key?\t");
    status = keyvalue_cmp_with_key(dict -> next -> next -> next -> next -> keyvalue, "111");
    if (!status) {
        printf("Yep!");
    } else {
        printf("Nope!");
    }

    printf ("\n");
    printf ("\n");

    printf("I will remove [112] element from the dictionary.\n");
    dict = dict_del_with_key (dict, "112");

    printf ("Here is your dict:\n");
    dict_print (dict, puts);
    printf("===\n");

    printf ("\n");

    printf("Is [112] element in the dictionary?\t");
    Dictelem *srch_status = dict_srch_elem (dict, "112");
    if (srch_status == NULL) {
        printf("Nope.");
    } else {
        printf("Yep!");
    }

    printf ("\n");

    dict_del_dict(dict);

    return 0;
}

char *str_cpy(char *str) {
	char *new_str = (char *) malloc(sizeof(char) * (1 + strlen(str)));
	strcpy(new_str, str);

	return new_str;
}
