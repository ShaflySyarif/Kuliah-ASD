//Latihan insertion sort (straight)

#include <iostream>
#include <cstdlib>
#include <time.h>
#define MAX 10

using namespace std;

int Data[MAX];

void StraightInsertSort()
{
    int i, j, x;
    int comparisons = 0;
    int shifts = 0;

    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;

        while (j >= 0 && x > Data[j]) {
            Data[j + 1] = Data[j];
            j--;
            comparisons++;
        }

        Data[j + 1] = x;
        shifts++;

        cout << "Iterasi " << i << ": ";
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
        cout << endl;
    }

    cout << "Total perbandingan: " << comparisons << endl;
    cout << "Total pergeseran: " << shifts << endl;
}

int main()
{
    int i;

    srand(time(0));

    cout << "Data sebelum pengurutan: ";
    for (i = 0; i < MAX; i++) {
        Data[i] = (int)rand() / 1000 + 1;
        cout << Data[i] << " ";
    }
    cout << endl;

    StraightInsertSort();

    cout << "Data setelah pengurutan: ";
    for (i = 0; i < MAX; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;

    return 0;
}
