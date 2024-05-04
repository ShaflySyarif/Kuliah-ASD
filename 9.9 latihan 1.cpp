//Latihan seleksi sort

#include <iostream>
#include <cstdlib>
#include <time.h>
#define MAX 10

using namespace std;

int Data[MAX];

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort() {
    int i, j, k, comparisons = 0, shifts = 0;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        for (j = i + 1; j < MAX; j++) {
            comparisons++;
            if (Data[k] < Data[j]) {
                k = j;
            }
        }
        Swap(&Data[i], &Data[k]);
        shifts++;
        cout << "Iterasi " << i + 1 << ": ";
        for (int l = 0; l < MAX; l++) {
            cout << Data[l] << " ";
        }
        cout << endl;
    }
    cout << "Perbandingan: " << comparisons << endl;
    cout << "Pergeseran: " << shifts << endl;
}

int main() {
    int i;
    srand(time(0));
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << ": " << Data[i] << endl;
    }
    SelectionSort();
    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << ": " << Data[i] << endl;
    }
}
