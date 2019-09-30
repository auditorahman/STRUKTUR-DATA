#include<iostream>
#define max 5
using namespace std;

struct dataMahasiswa
{
    char nama[50];
    char alamat[50];
    char ttl[50];
};
struct node
{
    dataMahasiswa mhs;
    int data;
    node *next;

}*front=NULL,*rear=NULL,*n,*temp,*temp1;
int nomor=1;

void enqueue()
{
    n=new node;

    cout << "\n"  ;
    cout << "============ Pendaftaran Mahasiswa ============ " << endl ;
    cout << "\n"  ;
    cout << "Nama Lengkap           : " ;
    cin.sync();
    cin.getline(n->mhs.nama, 50) ;
    cout << "Alamat                 : "  ;
    cin.getline(n->mhs.alamat, 50) ;
    cout << "Tempat, Tanggal Lahir  : "  ;
    cin.getline(n->mhs.ttl, 50) ;
    cout << endl;

    if(front==NULL)
    {
        front=n;
        rear=n;
        rear->next=front;
    }
    else if(nomor==max)
    {
        cout<<"\nAntrian Penuh Boss!!!\n";
    }
    else
    {
        rear->next=n;
        rear=n;
        rear->next=front;
        nomor++;
    }

}

void dequeue()
{

    temp=front;
    if(front==NULL)
    {
        cout<<"\nAntrian Kosong!!!";
    }
    else
    {
        if(front==rear)
        {
            delete(temp);
            front=NULL;
            rear=NULL;
        }
        else
        {
            front=front->next;
            rear->next=front;
            delete(temp);
            nomor--;
        }
        cout<<"\nData Dihapus!!\n";
    }

}

void view()
{
    temp=front;
    temp1=NULL;
    if(front==NULL)
    {
        cout<<"\n\nAntrian Kosong!!!";
    }
    else
    {
        cout<<"\nDaftar Antrian :\n\n";
        while(temp!=temp1)
        {
            cout << " <- [Nama Lengkap : " << temp->mhs.nama << ", Alamat : " << temp->mhs.alamat << ", Tempat dan Tanggal Lahir : " << temp->mhs.ttl << "]";
            temp=temp->next;
            temp1=front;
        }
        cout<<endl;
    }
}

int main()
{

    int pil;

    do
    {
        cout<<"\n1. Enqueue\n2. Dequeue\n3. View\n4. Exit\n\nMasukkan Pilihan: ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            enqueue();
            view();
            break;
        case 2:
            dequeue();
            view();
            break;
        case 3:
            view();
            break;
        case 4:
            break;
        default:
            cout<<"\n\nInput yang benar!!";
        }
    }
    while(pil!=4);

    return 0;
}
