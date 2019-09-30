#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct datapendaftaran
{
    char nama [50];
    char alamat [50];
    char ttl [50];
};

struct node
{
    datapendaftaran pendaftaran;
    node *next, *prev;
};

node *awal=NULL, *akhir=NULL, *bantu, *baru, *hapus;

void tambahdepan();
void tambahbelakang();
void view();
void hapusDepan();
void hapusBelakang();

int main()
{
    int menu;
    do
    {
        system("cls");
        cout << "===================" << endl;
        cout << "  Menu Linked List " << endl;
        cout << "==================="<<endl;
        cout << "1. Tambah Depan"<<endl;
        cout << "2. Tambah Belakang"<<endl;
        cout << "3. Hapus Depan"<<endl;
        cout << "4. Hapus Belakang"<<endl;
        cout << "5. Lihat Data" <<endl;
        cout << "6. Exit" <<endl;
        cout << "=================="<<endl;
        cout << "> Pilih Menu = ";
        cin  >> menu;
        system("cls");
        if (menu==1)
        {
            tambahdepan();
        }
        else if (menu==2)
        {
            tambahbelakang();
        }
        else if (menu==3)
        {
            hapusDepan();
        }
        else if (menu==4)
        {
            hapusBelakang();
        }

        else if (menu==5)
        {
            view();
        }
        else if (menu==6)
        {
            exit(0);
        }
    }
    while(true);
    return 0;
}

void tambahdepan()
{
    baru= new node;
    cout << "======================="<<endl;
    cout << "      TAMBAH DEPAN     " <<endl;
    cout << "======================="<<endl;
    cin.sync();
    cout << "Nama Lengkap          = ";
    cin.getline(baru->pendaftaran.nama, 50);
    cout << "Alamat                = ";
    cin.getline(baru->pendaftaran.alamat, 50);
    cin.sync();
    cout << "Tempat, Tanggal Lahir = ";
    cin.getline(baru->pendaftaran.ttl, 50);
    cin.sync();
    baru->next=NULL;
    baru->prev=NULL;
    if (awal==NULL)
    {
        awal=akhir=baru;
    }
    else
    {
        baru->next=awal;
        awal->prev=baru;
        awal=baru;
    }
}

void tambahbelakang()
{
    baru= new node;
    cout << "======================="<<endl;
    cout << "     Tambah Belakang   " <<endl;
    cout << "======================="<<endl;
    cin.sync();
    cout << "Nama Lengkap          = ";
    cin.getline(baru->pendaftaran.nama, 50);
    cout << "Alamat                = ";
    cin.getline(baru->pendaftaran.alamat, 50);
    cin.sync();
    cout << "Tempat, Tanggal Lahir = ";
    cin.getline(baru->pendaftaran.ttl, 50);
    cin.sync();
    baru->next=NULL;
    baru->prev=NULL;
    if (awal==NULL)
    {
        awal=akhir=baru;
    }
    else
    {
        akhir->next=baru;
        baru->prev=akhir;
        akhir=baru;
    }
}

void hapusDepan()
{
    if (awal==NULL)
    {
        cout << "Data Kosong Mas Bro!!";
    }
    else if (awal->next==NULL)
    {
        hapus=awal;
        awal=NULL;
        akhir=NULL;
        delete hapus;
    }
    else
    {
        hapus=awal;
        awal=hapus->next;
        awal->prev=NULL;
        delete hapus;
        cout << "Data Depan Sudah Dihapus!!" <<endl;
    }
    getch();
}

void hapusBelakang()
{
    if (awal==NULL)
    {
        cout << "Data Kosong Mas Bro!!";
    }
    else if (awal->next==NULL)
    {
        hapus=awal;
        awal=NULL;
        akhir=NULL;
        delete hapus;
    }
    else
    {
        hapus=akhir;
        akhir=hapus->prev;
        akhir->next=NULL;
        delete hapus;
        cout << "Data Belakang Sudah Dihapus!!" <<endl;
    }
    getch();
}

void view()
{
    cout << "======================="<<endl;
    cout << "        ISI DATA       " <<endl;
    cout << "======================="<<endl;
    bantu=awal;
    while(bantu !=NULL)
    {
        cout << "Nama Lengkap          = " <<bantu->pendaftaran.nama<<endl;
        cout << "Alamat                = " <<bantu->pendaftaran.alamat<<endl;
        cout << "Tempat, Tanggal Lahir = " <<bantu->pendaftaran.ttl<<endl;
        bantu=bantu->next;
        cout <<endl <<endl;
    }
    cout << "Tekan enter untuk kembali ke menu....";
    getch();
}
