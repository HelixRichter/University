#include <iostream>
using namespace std;

const int maxim = 10000;
const int n = 6;
const int M[n][n] =
        {
                {0,7,9,0,0,14 },
                {7,0,10,15,0,0},
                {9,10,0,11,0,2},
                {0,15,11,0,6,0},
                {0,0,0,6,0,9  },
                {14,0,2,0,9,0 }
        };

int *krot_puti(int in_start) {
    int *d = new int[n]; //минимальное расстояние
    bool visited[n];
    int max = maxim;

    for (int i = 0; i < n; i++) {
        d[i] = max;
        visited[i] = false;
//        cout << d[i] << " " << visited[i] << endl;
    }

    d[in_start] = 0;

//    for (int i = 0; i < n; i++) {
//        cout << d[i] << " " << visited[i] << endl;
//    }

    int minindex;
    int min;

    do {
        minindex = -1;
        min = max;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && (d[i] < min)) {
                min = d[i];
                minindex = i;
            }
        }

        if (minindex != -1) {
            for (int i = 0; i < n; i++) {
                if (M[minindex][i] > 0) {
                    if (min + M[minindex][i] < d[i]) {
                        d[i] = min + M[minindex][i];
                    }
                }
            }

            visited[minindex] = true;
        }
    } while (minindex != -1);

    return d;
}

int main() {
    int* puti = new int[n];
    puti = krot_puti(0);

    for (int i = 0; i < n; i++) {
        cout << puti[i] << ' ';
    }

    delete [] puti;
}