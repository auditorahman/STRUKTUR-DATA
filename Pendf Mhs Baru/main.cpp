#include <iostream>
#include <string>

using namespace std;

struct
{
    string nama;
    char alamat [30];
    char ttl [35];

}dataMahasiswa;

int main()
{
    cout << "====================================="<<endl;
    cout << "PENDAFTARAN MAHASISWA BARU ITATS 2018"<<endl;
    cout << "====================================="<<endl;
    cout << "          Mulai Registrasi           "<<endl;
    cout << "Nama Lengkap              : ";
    getline(cin, dataMahasiswa.nama);
    cout << "Alamat Lengkap            : ";
    cin.getline(dataMahasiswa.alamat, 30);
    cout << "Tempat, Tanggal Lahir     : ";
    cin.getline(dataMahasiswa.ttl, 35);



    return 0;
}
