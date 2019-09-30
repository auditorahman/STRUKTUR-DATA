#include <iostream>
#include <windows.h>

using namespace std;

struct dataMahasiswa
{
    char nama[50], alamat[50], ttl[50];
};

struct simpul
{
    dataMahasiswa mhs;
    simpul *next;
};

simpul *awal=NULL, *akhir=NULL, *baru, *bantu;

int batas, top=-1;

bool isEmpty()
{
    return top==-1;
}

bool isFull()
{
    return top==batas-1;
}

void push()
{
    int input;
    if(isFull())
    {
        cout << "> ERROR: DATA PENUH!" <<endl <<endl;
        system("pause");
    }
    else
    {
        cout << "> Batas : " << batas <<endl;
        cout << "==========================" <<endl;
        cout << "        TAMBAH DATA       " <<endl;
        cout << "==========================" <<endl;
        baru=new simpul;
        cin.sync();
        cout << "1. Nama                  = ";
        cin.getline(baru->mhs.nama, 50);
        cout << "2. Alamat                = ";
        cin.getline(baru->mhs.alamat, 50);
        cout << "3. Tempat, Tanggal Lahir = ";
        cin.getline(baru->mhs.ttl, 50);
        baru->next=NULL;
        if(awal==NULL){
            awal=akhir=baru;
            cout<<"\n> Data berhasil dimasukkan!" <<endl;
        }else{
            akhir->next = baru;
            akhir = baru;
        }
        cout << endl;
        top++;
        system("pause");
    }
}

void pop()
{
    simpul *bantu;
    if(isEmpty())
    {
        cout<<"> Data kosong!" <<endl<<endl;
        system("pause");
    }
    else
    {
        cout << "=======================" <<endl;
        cout << "       HAPUS DATA      " <<endl;
        cout << "=======================" <<endl;
        bantu = akhir;
        akhir->next = NULL;
        cout << "> Data berikut berhasil dihapus :" <<endl;
        cout << "1. Nama                  = " << bantu->mhs.nama <<endl;
        cout << "2. Alamat                = " << bantu->mhs.alamat <<endl;
        cout << "3. Tempat, Tanggal Lahir = " << bantu->mhs.ttl <<endl<<endl;
        delete bantu;
        top--;
        system("pause");
    }
}

void view()
{
    bantu=awal;
    if(isEmpty())
    {
        cout<<"Stack Belum ada isinya!" <<endl;
        system("pause");
    }
    else
    {
        cout << "> Batas : " << batas <<endl;
        cout << "> Total : " << top+1 <<endl;
        cout << "==========================" <<endl;
        cout << "         LIHAT DATA       " <<endl;
        cout << "==========================" <<endl;
        {
            for (int i=0; i<=top; i++)
            {
                cout << "> Pendaftaran ke-" <<i+1 <<endl;
                cout << "1. Nama                  = " << bantu->mhs.nama <<endl;
                cout << "2. Alamat                = " << bantu->mhs.alamat <<endl;
                cout << "3. Tempat, Tanggal Lahir = " << bantu->mhs.ttl <<endl<<endl;
                bantu=bantu->next;
            }
        }
        system("pause");
    }
}

int main()
{
    int menu;
    cout << "> Input Batas : ";
    cin >> batas;
    do
    {
        system("cls");
        if (batas!=NULL)
        {
            cout << "> Batas : " << batas <<endl;
        }
        cout << "==============" <<endl;
        cout << "      Menu    " <<endl;
        cout << "==============" <<endl;
        cout << "1. Push" <<endl;
        cout << "2. Pop" <<endl;
        cout << "3. View" <<endl;
        cout << "4. Exit" <<endl;
        cout << "\n> Pilih Menu = ";
        cin>>menu;
        system("cls");
        if (menu == 1)
        {
            push();
        }
        else if (menu == 2)
        {
            pop();
        }
        else if (menu == 3)
        {
            view();
        }
        else if (menu == 4)
        {
            return 0;
        }
        else
        {
            cout << "Input yang benar! " << endl;
        }
    }
    while(true);
}
