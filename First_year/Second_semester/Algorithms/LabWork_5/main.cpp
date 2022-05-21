#include <iostream>

using namespace std;

class TreeDF {
private:
    struct Tree;
    typedef Tree* pTree;
    pTree root;

    struct Tree {
        pTree left;
        pTree right;
        int Inf;
    };

    pTree add(int i, pTree x) {
        if (x == nullptr) {
            x = new Tree;
            x -> Inf = i;
            x -> left = x -> right = nullptr;
        } else if (i < x -> Inf) {
            x -> left = add(i, x -> left);
        } else if (i > x -> Inf) {
            x -> right = add(i, x -> right);
        }

        return x;
    }

    void inorder(pTree x) {
        if (x == nullptr) {
            return;
        }

        inorder(x -> left);
        cout << x -> Inf << " ";
        inorder(x -> right);
    }

    pTree find(pTree x, int i) {
        if (x == nullptr) {
            return nullptr;
        } else if (i < x -> Inf) {
            return find(x -> left, i);
        } else if (i > x -> Inf) {
            return find(x -> right, i);
        } else {
            return x;
        }
    }

public:
    void add(int i) {
        root = add(i, root);
    }

    void show() {
        inorder(root);
        cout << endl;
    }

    bool find(int i) {
        return (find(root,i) != nullptr);
    }
};

int main() {
    TreeDF example;

    example.add(35);
    example.add(8);
    example.add(6);
    example.add(3);

    example.show();
    cout << example.find(3) << endl;
    example.show();

    cout << example.find(8) << endl;
    example.show();

    return 0;
}
