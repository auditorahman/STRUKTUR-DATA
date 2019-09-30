#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct node
{
    string nama;
    int umur;
    node *next;
};

int total=0;

node *awal=NULL, *akhir=NULL, *bantu, *baru;

void add();
void view();

int main()
{
    int menu;
    do
    {
        system("cls");
        cout << "> Jumlah Data = " <<total <<endl;
        cout << "==============="<<endl;
        cout << "1. Tambah Data "<<endl;
        cout << "2. View"<<endl;
        cout << "==============="<<endl;
        cout << "> Pilih Menu = ";
        cin  >> menu;
        system("cls");
        if (menu==1)
        {
            add();
        }
        else if (menu==2)
        {
            view();
        }
    }
    while(true);
    return 0;
}

void add()
{
    baru= new node;
    cout << "===========" <<endl;
    cout << "TAMBAH DATA" <<endl;
    cout << "===========" <<endl;
    cout << "Nama Lengkap = ";
    cin  >> baru->nama;
    cout << "Umur         = ";
    cin  >> baru->umur;
    baru->next=NULL;
    if (awal==NULL)
    {
        awal=akhir=baru;
    }
    else
    {
        baru->next=awal;
        awal=baru;
    }
    total++;
}

void view()
{
    cout <<"==============="<<endl;
    cout <<"T A M P I L A N" <<endl;
    cout <<"==============="<<endl;
    cout <<"> isi data = "<<total <<endl <<endl;
    bantu=awal;
    while(bantu != NULL)
    {
        cout << "[Nama = " << bantu->nama << " dan Umurnya = " <<bantu->umur << "] ->";
        bantu=bantu->next;
    }
    cout << "\n\Tekan enter untuk kembali ke menu ";
    getch();
}
