#include "dict.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Keyvalue *keyvalue_new(char *key, void *value, size_t size) {
    if (!key || !strcmp(key, "\0")) {
        fprintf(stderr, "Invalid or empty key!");
        return NULL;
    }

    Keyvalue *keyvalue = (Keyvalue *) malloc(sizeof(Keyvalue));

    keyvalue -> key = malloc((strlen(key) + 1) * sizeof(char));
    strncpy(keyvalue -> key, key, strlen(key) + 1);
    keyvalue -> value = malloc(size);
    memcpy(keyvalue -> value, value, size);
    keyvalue -> value_size = size;

    return keyvalue;
}

void keyvalue_del(Keyvalue *kv) {
    if (!kv) {
        return;
    }

    free(kv -> key);
    free(kv -> value);
    free(kv);
}

int keyvalue_cpy(Keyvalue *kv_cpy_to, Keyvalue *kv_cpy_from) {
    if (!kv_cpy_to) {
        kv_cpy_to = keyvalue_new(kv_cpy_from->key, kv_cpy_from->value, kv_cpy_from->value_size);

        return 0;
    }

    kv_cpy_to -> value = realloc(kv_cpy_to->value, kv_cpy_from->value_size);

    if (!kv_cpy_to -> value && kv_cpy_from -> value_size) {
        fprintf(stderr, "Can't reallocate value!");
        exit(1);
    }

    memcpy(kv_cpy_to -> value, kv_cpy_from -> value, kv_cpy_from -> value_size);
    kv_cpy_to->value_size = kv_cpy_from->value_size;

    return 0;
}

int keyvalue_cmp_by_value(Keyvalue *kv1, Keyvalue *kv2) {
    if (!kv1 || !kv2) {
        exit(1);
    }

    if (kv1->value_size != kv2->value_size) {
        return 1;
    }

    if (memcmp(kv1->value, kv2->value, kv1->value_size)) {
        return 1;
    }

    return 0;
}

int keyvalue_cmp_by_key(Keyvalue *kv1, Keyvalue *kv2) {
    if (!kv1 || !kv2) {
        fprintf(stderr, "Can't compare non-existent elements!");
        exit(1);
    }

    if (kv1 == kv2) {
        return 0;
    }

    return strcmp(kv1 -> key, kv2 -> key);
}

int keyvalue_cmp_with_key(Keyvalue *kv1, char *key) {
    if (!kv1 || !key) {
        fprintf(stderr, "Can't compare non-existent elements!");
        exit(1);
    }

    return strcmp(kv1 -> key, key);
}

Dictelem *dict_new(char *key, void *value, size_t size) {
    return dict_add_elem(NULL, key, value, size);
}

void dict_del_dict(Dictelem *head) {
    if (!head) {
        return;
    }

    Dictelem *newhead = head -> next;

    keyvalue_del(head -> keyvalue);
    free(head);

    dict_del_dict(newhead);
}

Dictelem *dict_add_elem(Dictelem *head, char *key, void *value, size_t size) {
    if (head) {
        Dictelem *duplikey = dict_srch_elem(head, key);
        if (duplikey) {
            fprintf(stderr, "Can't add element: key exists in dict!");
            exit(1);
        }
    }

    Keyvalue *keyvalue = keyvalue_new(key, value, size);
    Dictelem *newhead = (Dictelem*)malloc(sizeof(Dictelem));

    newhead->keyvalue = keyvalue;
    newhead->next = head;

    return newhead;
}

Dictelem *dict_del_with_key(Dictelem *head, char *key) {
    if (!head) {
        return NULL;
    }

    if (!keyvalue_cmp_with_key(head -> keyvalue, key)) {
        Dictelem *next = head -> next;
        keyvalue_del(head -> keyvalue);
        free(head);

        return next;
    }

    Dictelem *next = head -> next;
    Dictelem *cur = head;
    char key_found = 0;

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
        fprintf(stdout, "----------------------------------------\n");
        return;
    }

    fprintf(stdout, "----------------------------------------\n");

    printf("key: %s\n", head -> keyvalue -> key);
    printf("value size: %lu\n", head->keyvalue->value_size);

    dict_print(head -> next);
}
