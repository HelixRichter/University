#ifndef LABWORK_1_DICT_H
#define LABWORK_1_DICT_H

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

Keyvalue *keyvalue_new(char*, void*);
void keyvalue_del(Keyvalue *kv);
int keyvalue_cpy(Keyvalue*, Keyvalue*);
int keyvalue_cmp_by_value(Keyvalue*, Keyvalue*);
int keyvalue_cmp_by_key(Keyvalue*, Keyvalue*);
int keyvalue_cmp_with_key(Keyvalue*, char*);

Dictelem *dict_new_dict(char*, void*);
void dict_del_dict(Dictelem*);
Dictelem *dict_add_elem(Dictelem*, char*, void*);
Dictelem *dict_del_with_key(Dictelem*, char*);
Dictelem *dict_srch_elem(Dictelem*, char*);
void dict_print(Dictelem*);


#endif
