#include <iostream>

using namespace std;

struct simpul
{
    int data;
    simpul *next;
};

simpul *awal=NULL, *baru;

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
        cout << " \nData sudah penuh! " <<endl;
        cout << endl;
    }
    else
    {
        cout<<">> Input Data = ";
        cin>>input;
        baru=new simpul;
        baru->data=input;
        baru->next=NULL;
        if(awal!=NULL)
            baru->next=awal;
        awal=baru;
        cout << "---------------------------" <<endl;
        cout << " Data berhasil dimasukkan! " <<endl;
        cout << "---------------------------" <<endl;
        top++;
        cout<<endl;
    }
}

void pop()
{
    simpul *bantu;
    if(isEmpty())
    {
        cout << " Data kosong! " <<endl;
        cout << endl;
    }
    else
    {
        bantu=awal;
        awal=awal->next;
        cout << "----------------------------" <<endl;
        cout << " Data [" <<bantu->data<< "] berhasil dihapus!" <<endl;
        cout << "----------------------------" <<endl;
        delete bantu;
        top--;
        cout<<endl;
    }
}

void view()
{
    simpul *bantu=awal;
    if(isEmpty())
    {
        cout << " Stack Kosong!! " <<endl;
        cout << endl;
    }
    else
    {
        while(bantu!=NULL)
        {
            for (int i=top; i>=0; i--)
            {
                cout << "Data ke-" << i << " = ";
                cout<< "[" <<bantu->data<<"]" <<endl;
                bantu=bantu->next;
            }
        }
    }
}

int main()
{
    int menu;
    cout << ">> Input Batas : ";
    cin >> batas;
    do
    {
        cout << "==============" <<endl;
        cout << "  Menu Stack  " <<endl;
        cout << "==============" <<endl;
        cout << "1. Push" <<endl;
        cout << "2. Pop" <<endl;
        cout << "3. Exit" <<endl;
        cout << ">> Pilih Menu = ";
        cin>>menu;
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
            return 0;
        }
        else
        {
            cout <<"Input yang benar!"<<endl;
        }
        view();
    }
    while(true);
}
