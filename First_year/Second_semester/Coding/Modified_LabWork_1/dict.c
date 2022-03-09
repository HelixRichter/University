#include "dict.h"
#include <stdlib.h>

Keyvalue *keyvalue_new (char *key, void *value) {
    Keyvalue *keyvalue = (Keyvalue*)malloc(sizeof(Keyvalue));

    keyvalue -> key = (char*)malloc(sizeof(char)*(1 + strlen(key)));
    strcpy(keyvalue->key, key);

    keyvalue -> value = value;

    return keyvalue;
}

void keyvalue_del (Keyvalue *kv) {
    if (!kv) {
        return;
    }

    free(kv -> key);
    free(kv -> value);
    free(kv);
}

int keyvalue_cpy (Keyvalue *kv_cpy_to, Keyvalue *kv_cpy_from, void *(*val_cpy)(const void*)) {
    if (!kv_cpy_from || !kv_cpy_to) {
        return 1;
    }

    if (kv_cpy_from == kv_cpy_to) {
        return 0;
    }

    if (kv_cpy_to -> value) {
	    free(kv_cpy_to -> value);
    }

    kv_cpy_to -> value = (*val_cpy)(kv_cpy_from -> value);

    return 0;
}

int keyvalue_cmp_by_value (Keyvalue *kv1, Keyvalue *kv2, int cmp_fun (const void *, const void *)) {
    void *val1 = kv1 -> value, *val2 = kv2 -> value;
    return (*cmp_fun)(val1, val2);
}

int keyvalue_cmp_by_key(Keyvalue *kv1, Keyvalue *kv2) {
    if (!kv1 || !kv2) {
        return 1;
    }

    if (kv1 == kv2) {
        return 0;
    }

    return strcmp (kv1 -> key, kv2 -> key);
}

int keyvalue_cmp_with_key (Keyvalue *kv1, char *key) {
    if (!kv1 || !key) {
        return 1;
    }

    return strcmp (kv1 -> key, key);
}

Dictelem *dict_new_dict (char *key, void *value) {
    return dict_add_elem(NULL, key, value);
}

void dict_del_dict (Dictelem *head) {
    if (!head) {
        return;
    }

    Dictelem *newhead = head -> next;

    keyvalue_del(head -> keyvalue);
    free(head);

    dict_del_dict(newhead);
}

Dictelem *dict_add_elem (Dictelem *head, char *key, void *value) {
    Dictelem *duplikey = dict_srch_elem (head, key);
    if (duplikey) {
        fputs("Can't add element: key exists in dictionary!", stderr);
        exit(1);
    }

    Keyvalue *keyvalue = keyvalue_new (key, value);
    Dictelem *newhead = (Dictelem *) malloc(sizeof(Dictelem));

    newhead -> keyvalue = keyvalue;
    newhead -> next = head;

    return newhead;
}

Dictelem *dict_del_with_key (Dictelem *head, char *key) {
    if (!head) {
        fputs("Can't delete element in non-existent dictionary!", stderr);
        return head;
    }

    if (!keyvalue_cmp_with_key(head -> keyvalue, key)) {
        Dictelem *next = head -> next;
        keyvalue_del(head -> keyvalue);
        free(head);

        return next;
    }

    Dictelem *next = head -> next;
    Dictelem *cur = head;
    short key_found = 0;

    while (next) {
        if (!keyvalue_cmp_with_key(next -> keyvalue, key)) {
            key_found = 1;
            break;
        }

        cur = next;
        next = next -> next;
    }

    if (key_found) {
        cur -> next = next -> next;
        keyvalue_del(next -> keyvalue);
        free(next);
    }

    return head;
}

Dictelem *dict_srch_elem (Dictelem *head, char *key) {
    if (!head) {
        return NULL;
    }

    if (!keyvalue_cmp_with_key(head -> keyvalue, key)) {
        return head;
    }

    return dict_srch_elem(head -> next, key);
}

void dict_print (Dictelem *head, void print(const void *val)) {
    if (!head) {
        return;
    }

    printf("key:\t%s\n", head -> keyvalue -> key);
    printf("value:\t");
    (*print)(head -> keyvalue -> value);

    printf("\n");

    dict_print(head -> next, print);
}
