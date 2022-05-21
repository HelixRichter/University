#include <iostream>
using namespace std;


const int N = 10;
struct mem
{
    int key;
    int inf;
};

typedef mem array[N];
array a;


void bubble() {
    int comparisons = 0, swaps = 0;
    int i, j;

    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            comparisons++;
            if (a[i].inf > a[j].inf) {
                swap(a[i], a[j]);
                swaps++;
            }
        }
    }

    cout << "Bobble sort: ";
    for (auto & o : a) {
        cout << o.inf << " ";
    }

    cout << "\nAmount of comparisons:  " << comparisons << "\nAmount of swaps:  " << swaps;
}


void Shell() {
    int d = N / 2;
    int j;

    while (d > 0) {
        for (int i = 0; i < N - d; i++) {
            j = i;

            while (j >= 0 && a[j].inf > a[j + d].inf) {
                swap(a[j].inf, a[j + d].inf);
                j--;
            }
        }

        d /= 2;
    }

    cout << endl << "Shell sort: ";
    for (auto & i : a) {
        cout << i.inf << " ";
    }
}


int main() {
    for (int i = N; i > 0; i--) {
        a[i].inf = i;
    }

    cout << "Source array: ";
    for (int i = 0; i <= N; i++) {
        cout << a[i].inf << " ";
    }

    cout << endl << endl;
    bubble();
    cout << endl;
    Shell();
}