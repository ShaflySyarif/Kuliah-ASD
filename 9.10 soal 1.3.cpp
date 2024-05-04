//insertion binary sort

#include <iostream>
#include <cstdlib>
#include <time.h>
#define MAX 50

using namespace std;

int Data[MAX];

// Fungsi pengurutan penyisipan biner
void BinaryInsertSort()
{
    int i, j, l, r, m, x;
    int comparisons = 0;
    int shifts = 0;

    for (i = 1; i < MAX; i++) {
        x = Data[i];
        l = 0;
        r = i - 1;

        while (l <= r) {
            m = (l + r) / 2;
            comparisons++;

            if (x > Data[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        for (j = i - 1; j >= l; j--) {
            Data[j + 1] = Data[j];
        }

        Data[l] = x;
        shifts++;
        
        cout << "Iterasi " << i << ": ";
        for (j = 0; j < MAX; j++) {
            cout << Data[j] << " ";
        }
        cout << endl << endl;
    }

    cout << "Jumlah perbandingan: " << comparisons << endl;
    cout << "Jumlah pergeseran: " << shifts << endl;
}

int main()
{
    int i;
    srand(time(0));

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = (int)rand() % 100 + 1;
        cout << "Data ke " << i << ": " << Data[i] << endl;
    }
	cout << endl;
    BinaryInsertSort();

    // Data setelah terurut
    cout << "DATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << ": " << Data[i] << endl;
    }

    return 0;
}
