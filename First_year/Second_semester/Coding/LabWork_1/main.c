#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *key;
    char *value;
} keyvalue;

typedef struct roll {
    keyvalue element;
    struct roll *next;
} dictionary;

typedef struct return_string {
    int size;
    char *string;
} return_string;


dictionary *make(dictionary *);
void copy(dictionary *);
void compare(dictionary *);

dictionary *start_delete(dictionary *);
void delete(dictionary *, char *);

char *start_search(dictionary *);
dictionary *search(dictionary *, char *);

void dictionary_print(dictionary *);
dictionary *dictionary_delete(dictionary *);

return_string input_string(void);


int main() {
    printf("Hi! It's the program for working with a dictionary.\n \
Here are all the commands you can work with:\n\n \
\tmake              : Makes new dictionary with 1 element;\n \
\tdelete            : Deletes chosen element from dictionary;\n \
\tcopy              : Copies one element's value to another value;\n \
\tsearch            : Searches element's value in dictionary.\n \
\tcompare           : Compares one element's value with another value;\n\n \
\tprint dictionary  : Displays the created dictionary;\n \
\tdelete dictionary : Deletes new dictionary;\n\n \
\texit              : Exit from the program.\n\n");

    dictionary *dict;
    dict = NULL;
    char *choice_status = (char *) malloc(20 * sizeof(char));
    while (1) {
        printf("Enter the command: ");
        fgets(choice_status, 19, stdin);
        *(choice_status + strlen(choice_status) - 1) = '\0';

        if (!strcmp(choice_status, "exit")) {
            free(dict);
            free(choice_status);

            return 0;
        } else {
            if (!strcmp(choice_status, "make")) {
                dict = make(dict);
            } else if (!strcmp(choice_status, "delete")) {
                dict = start_delete(dict);
            } else if (!strcmp(choice_status, "copy")) {
                copy(dict);
            } else if (!strcmp(choice_status, "search")) {
                start_search(dict);
            } else if (!strcmp(choice_status, "compare")) {
                compare(dict);
            } else if (!strcmp(choice_status, "print dictionary")) {
                dictionary_print(dict);
            } else if (!strcmp(choice_status, "delete dictionary")) {
                dictionary_delete(dict);
            }
        }
    }
}


return_string input_string(void) {
    int n = 8;
    char *string = (char *) malloc(n * sizeof(char));
    char symbol = (char) getchar();

    int i = 0;
    while (symbol != '\n') {
        if (n - i == 0) {
            n *= 2;
            string = (char *) realloc(string, n * sizeof(char));
        }

        *(string + i) = symbol;
        i++;
        symbol = (char) getchar();
    }

    if (n - i == 0) {
        n += 1;
        string = (char *) realloc(string, n * sizeof(char));
    }

    *(string + i) = '\0';
    i++;

    return_string modif_str;
    modif_str.size = i;
    modif_str.string = (char *) malloc(modif_str.size * sizeof(char));
    memcpy(modif_str.string, string, i * sizeof(char));
    free(string);

    return modif_str;
}


char *start_search(dictionary *head) {
    printf("Enter the key of searchable element: ");
    return_string str_key = input_string();

    char *key = str_key.string;
    dictionary *res = search(head, key);

    if (!res) {
        puts("404: Not found!");
        return NULL;
    } else {
        printf("The value of this element is: %s\n", res -> element.value);
        return res -> element.value;
    }
}

dictionary *search(dictionary *cur_elem, char *key) {
    if (!cur_elem) {
        return NULL;
    }

    if (!strcmp(key, cur_elem -> element.key)) {
        return cur_elem;
    }

    return search(cur_elem -> next, key);
}

dictionary *make(dictionary *head) {
    if (!head) {
        head = (dictionary *) malloc(sizeof(dictionary));

        printf("Enter the key: ");
        return_string key = input_string();
        head -> element.key = key.string;

        printf("Enter the value: ");
        return_string value = input_string();
        head -> element.value = value.string;

        head -> next = NULL;
        return head;
    }

    dictionary *cur_elem = head;
    while (cur_elem -> next) {
        cur_elem = cur_elem -> next;
    }

    return_string key;
    do {
        printf("Enter the key: ");
        key = input_string();

    } while((search(head, key.string)) ?
            (printf("The keys of all elements must be unique!\n"), 1) : (0));

    cur_elem -> next = (dictionary *) malloc(sizeof(dictionary));
    cur_elem = cur_elem -> next;
    cur_elem -> element.key = key.string;

    printf("Enter the value: ");
    return_string value = input_string();
    cur_elem -> element.value = value.string;

    cur_elem -> next = NULL;
    return head;
}

dictionary *start_delete(dictionary *head) {
    printf("Enter the key of deletable element: ");
    return_string str_key = input_string();
    char *key = str_key.string;

    if (!head) {
        printf("404: Dictionary not found!\n");

        return NULL;
    }

    dictionary *new_head = head -> next;
    if (!strcmp(key, head -> element.key)) {
        free(head);
        printf("Element deleted successfully!\n");

        return new_head;
    }

    if (!strcmp(key, new_head -> element.key)) {
        head -> next = new_head -> next;
        free(new_head);
        printf("Element deleted successfully!\n");

        return head;
    } else {
        if (!(new_head -> next)) {
            printf("404: Element not found!\n");

            return head;
        } else {
            delete(new_head, key);

            return head;
        }
    }
}

void delete(dictionary *head, char *key) {
    if (!(head -> next)) {
        printf("404: Element not found!\n");

        return;
    }

    dictionary *new_head = head -> next;
    if (!strcmp(key, new_head -> element.key)) {
        head -> next = new_head -> next;
        free(new_head);
        printf("Element deleted successfully!\n");

        return;
    } else {
        if (!(new_head -> next)) {
            printf("404: Element not found!\n");

            return;
        } else {
            delete(new_head, key);

            return;
        }
    }
}

void copy(dictionary *head) {
    printf("Which element do you want to copy? (Need a key) ");
    return_string str_key = input_string();
    char *key_copied = str_key.string;

    printf("Which element do you want to copy to? (Need a key) ");
    str_key = input_string();
    char *key_to_copy = str_key.string;

    if (!(head -> next)) {
        printf("404: Didn't find at least 2 elements!\n");

        return;
    }

    dictionary *copy_status = search(head, key_copied);
    if (!copy_status) {
        puts("404: I didn't find an element you want to copy!\n");

        return;
    } else {
        dictionary *copied_element = copy_status;
        copy_status = search(head, key_to_copy);
        if (!copy_status) {
            puts ("404: I didn't find the element to copy to!\n");

            return;
        } else {
            dictionary *to_copy_element = copy_status;
            to_copy_element -> element.value = copied_element -> element.value;
            puts("Operation done successfully!\n");

            return;
        }
    }
}

void compare(dictionary *head) {
    printf("Enter the first element you want to compare: (Need a key) ");
    return_string str_key = input_string();
    char *key_first = str_key.string;

    printf("Enter the second element you want to compare: (Need a key) ");
    str_key = input_string();
    char *key_second = str_key.string;

    if (!(head -> next)) {
        printf("404: Didn't find at least 2 elements!\n");

        return;
    }

    dictionary *copy_status = search(head, key_first);
    if (!copy_status) {
        puts("404: I didn't find the first element!\n");

        return;
    } else {
        dictionary *first_element = copy_status;
        copy_status = search(head, key_second);
        if (!copy_status) {
            puts ("404: I didn't find the second element!\n");

            return;
        } else {
            dictionary *second_element = copy_status;
            if (!strcmp(first_element -> element.value, second_element -> element.value)) {
                puts("The elements are the same!\n");

                return;
            } else if (strcmp(first_element -> element.value, second_element -> element.value) != 0) {
                puts("The elements are not the same!\n");

                return;
            }
        }
    }
}

void dictionary_print(dictionary *head) {
    if (!head) {
        return;
    }

    printf("%s : %s\n", head -> element.key, head -> element.value);
    return dictionary_print(head -> next);
}

dictionary *dictionary_delete(dictionary *head) {
    if (!head) {
        return NULL;
    }

    dictionary *next_elem = head -> next;
    free(head);

    return dictionary_delete(next_elem);
}