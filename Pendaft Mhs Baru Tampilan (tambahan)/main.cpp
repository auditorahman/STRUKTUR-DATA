#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

struct mahasiswa
{
    string nama;
    char ttl [35];
    char alamat [50];
} dataMahasiswa[10];

main ()
{
    int chooseMenu, add = 0, jumlah;
    bool exit = false;
    char kembali;

    do
    {
        system("cls");
        cout<<"====================================="<<endl;
        cout<<"PENDAFTARAN MAHASISWA BARU ITATS 2018"<<endl;
        cout<<"====================================="<<endl;
        cout<<"          Mulai Registrasi           "<<endl;
        cout<<"1. Registrasi Mahasiswa\n2. Mahasiswa Terdaftar\n3. Exit\nPILIH : "<<endl;
        cin >> chooseMenu;
        switch(chooseMenu)
        {
        case 1 :

            system("cls");
            cin.sync();
            cout << "============="<<endl;
            cout << "INPUT DATA :"<<endl;
            cout << "============="<<endl;
            cout << "Jumlah Mahasiswa = ";
            cin >> jumlah;
            for (int i=1; i<=jumlah; i++)
            {
                 add++;
                cin.sync();
                cout << "1. Nama Lengkap              : ";
                getline(cin,dataMahasiswa[add].nama);
                cout << "2. Tempat, Tanggal Lahir     : ";
                cin.getline(dataMahasiswa[add].ttl, 35);
                cout << "3. Alamat Lengkap            : ";
                cin.getline(dataMahasiswa[add].alamat, 50);
                cout << endl;
            }
            break;
        case 2 :
            system("cls");
            cout << " T A M P I L A N\n" <<endl;
            for (int i=1; i<=add; i++)
            {
                cin.sync();
                cout << "1. Nama Lengkap             : " <<dataMahasiswa[i].nama <<endl;
                cout << "2. Jenis Kelamin (P/L)      : " <<dataMahasiswa[i].kelamin <<endl;
                cout << "3. Tempat, Tanggal Lahir    : " <<dataMahasiswa[i].ttl <<endl;
                cout << "4. Alamat Lengkap           : " <<dataMahasiswa[i].alamat <<endl;
                cout << "5. Agama                    : " <<dataMahasiswa[i].agama <<endl;
                cout << "6. Jenis Prodi yang dipilih : " <<dataMahasiswa[i].prodi <<endl;
                cout << "7. Nomor Telepon            : " <<dataMahasiswa[i].telp <<endl;
                cout << "8. Nomor Induk Sekolah Nasional  : " <<dataMahasiswa[i].nisn <<endl;
                cout << "9. Nomor Induk Kependudukan : " <<dataMahasiswa[i].nik <<"\n\n";
            }
            break;
        case 3 :
            exit = true;
        }
        cout << "Kembali ke menu (y/t) ?";
        cin >> kembali;
    }
    while(kembali=='y' || kembali=='Y');
}
