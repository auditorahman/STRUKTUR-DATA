#include <iostream>

using namespace std;

int main()
{
    int batas, cari;
    int angka [100];
    cout << " Banyak Data : ";
    cin >> batas;
    cout << endl;

    for (int i = 0; i < batas; i++) {
        cout << " Data ke- " << i + 1 << " : ";
        cin >> angka[i];
    }

    for (int i = 0; i < batas; i++) {
        for (int j = i + 1; j < batas; j++) {
            if (angka[i] > angka[j]) {
                int x = angka[i];
                angka [i] = angka[j];
                angka[j] = x;
            }
        }
    }
    cout << endl;
    cout << "Hasil Pengurutannya adalah : ";

    for (int i = 0; i < batas; i++) {
            cout << angka[i] << ", ";
    };
}
