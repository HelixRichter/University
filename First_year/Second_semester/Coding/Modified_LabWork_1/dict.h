#ifndef MODIFIED_LABWORK_1_DICT_H
#define MODIFIED_LABWORK_1_DICT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct keyvalue {
    char *key;
    void *value;
};
typedef struct keyvalue Keyvalue;

struct dictelem {
    Keyvalue *keyvalue;
    struct dictelem *next;
}; 
typedef struct dictelem Dictelem;

Keyvalue *keyvalue_new (char *, void *);
void keyvalue_del (Keyvalue *kv);
int keyvalue_cpy (Keyvalue *, Keyvalue *, void *(*val_cpy)(const void*));
int keyvalue_cmp_by_value (Keyvalue *, Keyvalue *, int cmp_fun (const void *, const void *));
int keyvalue_cmp_by_key (Keyvalue *, Keyvalue *);
int keyvalue_cmp_with_key (Keyvalue *, char *);

Dictelem *dict_new_dict (char *, void *);
Dictelem *dict_add_elem (Dictelem *, char *, void *);
Dictelem *dict_del_with_key (Dictelem *, char *);
Dictelem *dict_srch_elem (Dictelem *, char *);
void dict_del_dict (Dictelem *);
void dict_print (Dictelem *, void print (const void *));

#endif //MODIFIED_LABWORK_1_DICT_H
