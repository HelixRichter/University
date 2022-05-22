#include <iostream>
using namespace std;

char* str = new char[100];

struct List;
typedef List* pList;
struct List {
    pList next;
    int R;
    union {
        pList level;
        char atom;
    };
};

typedef char Inf;
struct Tree;
typedef Tree* pTree;
struct Tree {
    Inf root;
    pTree left;
    pTree right;
};


void Input_to_List(pList& p) {

    char c;
    c = str[0];
    str += 1;
    if (c != 0) {

        if (c == '(') {
            p = new List;
            p->R = 0;

            Input_to_List(p->level);
            Input_to_List(p->next);
        } else if ((('a' <= c) && (c <= 'z')) || (c == '+') || (c == '-') || (c == '*') || (c == '/')) {
            p = new List;

            p->R = 1;
            p->atom = c;

            Input_to_List(p->next);
        } else if (c == ')') {
            p = nullptr;
        }

    } else {
        p = nullptr;
    }

}


Tree* construct(Tree* p1, Inf i, Tree* p2) {
    Tree* p = new Tree;

    p->root = i;
    p->left = p2;
    p->right = p1;

    return p;
}


pList Head(pList p) {
    pList head = p->level;
    p->level = head->next;
    head->next = nullptr;

    return head;
}


pTree input_ltt(pList p) {
    pTree q;

    if (p->R == 1) {
        q = construct(nullptr, p->atom, nullptr);
    } else {
        q = construct(input_ltt(Head(p)), Head(p)->atom, input_ltt(Head(p)));
    }

    return q;
}


pTree input_ctt() {
    pList a;

    Input_to_List(a);
    pTree b = input_ltt(a);

    return b;
}


void lkp(pTree p) {
    if (p != nullptr) {
        if (p->left != nullptr) {
            cout << '(';
        }

        lkp(p->left);
        cout << (p->root);

        lkp(p->right);
        if (p->right != nullptr) {
            cout << ')';
        }
    }
}


void lpk(pTree p) {
    if (p != nullptr) {
        lpk(p->left);
        lpk(p->right);

        cout << (p->root);
    }
}


int main() {
    pList f;
    scanf("%s", str);
    pTree a = input_ctt();

    cout << "LPK, keyboard to tree: ";
    lpk(a);
    cout << endl;

    cout << "LKP, keyboard to tree: ";
    lkp(a);
    cout << endl;

    return 0;

}