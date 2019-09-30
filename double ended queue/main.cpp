#include <iostream>
#include <stdio.h>
#define MAX 3

using namespace std;

struct mahasiswa {
    string nama[MAX];
    int umur[MAX];
    int front;
    int rear;
}mhs;

void inisialisasi () {
    mhs.front = -1;
    mhs.rear = MAX;
}

bool isEmpty () {
    return mhs.front == -1 && mhs.rear == MAX;
}

bool isFull () {
    return mhs.front == mhs.rear - 1;
}

void enqueueFront () {
    if(isFull()){
        printf("ERROR!!Data Penuh");
    } else {
        mhs.front++;
        printf("Nama : "); cin >> mhs.nama[mhs.front];
        printf("Umur : "); cin >> mhs.umur[mhs.front];
    }
}

void enqueueRear () {
    if (isFull()) {
        printf("ERROR!!Data Penuh");
    } else {
        mhs.rear--;
        printf("Nama : "); cin >> mhs.nama[mhs.rear];
        printf("Umur : "); cin >> mhs.umur[mhs.rear];
    }
}

void dequeueFront () {
    if(isEmpty()){
        printf("ERROR!! Data Kosong");
    } else {
        for (int i = 0; i < mhs.front; i++) {
            mhs.nama[i] = mhs.nama[i+1];
            mhs.umur[i] = mhs.umur[i+1];
        }
        mhs.front--;
    }
}

void dequeueRear () {
    if(isEmpty()){
        printf("ERROR!! Data Kosong");
    } else {
        for (int i = MAX - 1; i > mhs.rear; i--) {
            mhs.nama[i] = mhs.nama[i-1];
            mhs.umur[i] = mhs.umur[i-1];
        }
        mhs.rear++;
    }
}
void view () {
    if (isEmpty()){
        printf("Data Kosong!!!");
    } else {
        for (int i = 0; i <= mhs.front; i++){
            cout << " <- Nama : "<< mhs.nama[i] << " Umur : " << mhs.umur[i];
        }

        for (int i = mhs.rear; i < MAX; i++) {
            cout << " Nama : "<< mhs.nama[i] << " Umur : " << mhs.umur[i] << " -> ";
        }
    }
}

main () {
    bool exit = false;
    int chooseMenu;
    inisialisasi();
    do {
        printf("\n[1]. Enqueue Front\n[2]. Enqueue Rear\n[3]. Dequeue Front\n[4]. Dequeue Rear\n[5]. View\nChoose : "); cin >> chooseMenu;
        switch(chooseMenu){
            case 1:
                enqueueFront();
                break;
            case 2:
                enqueueRear();
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                view();
                break;
        }
    } while (exit == false);

}
