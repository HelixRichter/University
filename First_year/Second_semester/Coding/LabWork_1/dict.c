#include "dict.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Keyvalue *keyvalue_new(char *key, void *value) {
    Keyvalue *keyvalue = (Keyvalue*)malloc(sizeof(Keyvalue));

    keyvalue->key = key;
    keyvalue->value = value;

    return keyvalue;
}

void keyvalue_del(Keyvalue *kv) {
    if (!kv) {
        return;
    }

    free(kv->key);
    free(kv->value);
    free(kv);
}

int keyvalue_cpy(Keyvalue *kv_cpy_to, Keyvalue *kv_cpy_from) {
    if (!kv_cpy_from || !kv_cpy_to) {
        return 1;
    }

    if (kv_cpy_from == kv_cpy_to) {
        return 0;
    }

    kv_cpy_to->value = kv_cpy_from->value;

    return 0;
}

int keyvalue_cmp_by_value(Keyvalue *kv1, Keyvalue *kv2) {
    if (!kv1 || !kv2) {
        fputs("Can't compare non-existent elements!", stderr);
        exit(1);
    }
    if (kv1 == kv2) {
        return 0;
    }

    unsigned long long skv1 = sizeof(kv1->value), skv2 = sizeof(kv2->value);
    printf("%llu %llu", skv1, skv2);

    if (skv1 != skv2) {
        printf("heh\n");
        return skv1 - skv2;
    }

    printf("WARNING\n");

    return memcmp(kv1->value, kv2->value, skv1);
}

int keyvalue_cmp_by_key(Keyvalue *kv1, Keyvalue *kv2) {
    if (!kv1 || !kv2) {
        fputs("Can't compare non-existent elements!", stderr);
        exit(1);
    }
    if (kv1 == kv2) {
        return 0;
    }

    return strcmp(kv1->key, kv2->key);
}

int keyvalue_cmp_with_key(Keyvalue *kv1, char *key) {
    if (!kv1 || !key) {
        fputs("Can't compare non-existent elements!", stderr);
        exit(1);
    }

    return strcmp(kv1->key, key);
}

Dictelem *dict_new_dict(char *key, void *value) {
    return dict_add_elem(NULL, key, value);
}

void dict_del_dict(Dictelem *head) {
    if (!head) {
        return;
    }

    Dictelem *newhead = head->next;

    keyvalue_del(head->keyvalue);
    free(head);

    dict_del_dict(newhead);
}

Dictelem *dict_add_elem(Dictelem *head, char *key, void *value) {
    Dictelem *duplikey = dict_srch_elem(head, key);
    if (duplikey) {
        fputs("Can't add element: key exists in dict!", stderr);
        exit(1);
    }

    Keyvalue *keyvalue = keyvalue_new(key, value);
    Dictelem *newhead = (Dictelem*)malloc(sizeof(Dictelem));

    newhead->keyvalue = keyvalue;
    newhead->next = head;

    return newhead;
}

Dictelem *dict_del_with_key(Dictelem *head, char *key) {
    if (!head) {
        return NULL;
    }

    if (!keyvalue_cmp_with_key(head->keyvalue, key)) {
        Dictelem *next = head->next;
        keyvalue_del(head->keyvalue);
        free(head);

        return next;
    }

    Dictelem *next = head->next;
    Dictelem *cur = head;
    char key_found = 0;

    while (next) {
        if (!keyvalue_cmp_with_key(next->keyvalue, key)) {
            key_found = 1;
            break;
        }

        cur = next;
        next = next->next;
    }

    if (key_found) {
        cur->next = next->next;
        keyvalue_del(next->keyvalue);
        free(next);
    }

    return head;
}

Dictelem *dict_srch_elem(Dictelem *head, char *key) {
    if (!head) {
        return NULL;
    }

    if (!keyvalue_cmp_with_key(head->keyvalue, key)) {
        return head;
    }

    return dict_srch_elem(head->next, key);
}

void dict_print(Dictelem *head) {
    if (!head) {
        return;
    }

    printf("key: %s\n", head->keyvalue->key);
    printf("value is a void pointer\n");
    printf("it is unsafe to print it's address\n");
    printf("and we can't be sure the value is printable\n");

    dict_print(head->next);
}
