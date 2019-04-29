#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Data
{
    int nilai;
    Data *next;
};

Data *head;

void awal ()//fungsi menjadikan head NULL
{
    head=NULL;
}

bool isEmpty()
{
    if (head==NULL)
        return true;
    return false;
}

void tambahDataDepan (int DataBaru)//fungsi untuk menambahkan data di depan
{
    Data *baru;
    baru = (Data*) malloc (sizeof (Data));
    baru -> nilai = DataBaru;
    baru -> next = baru;
    if (isEmpty())
    {
        head = baru;
        head->next=head;
    }
    else
    {
        Data *bantu;
        bantu=head;
        while (bantu->next!=head)
        {
            bantu=bantu->next;
        }
        baru->next=head;
        head=baru;
        bantu->next=head;
    }
}

void tambahDataBelakang (int DataBaru)//fungsi untuk menambahkan data di belakang
{
    Data *baru;//penggunaan variabel baru di data
    baru=(Data*) malloc(sizeof (Data));
    baru->nilai=DataBaru;//untuk menunjuk ke DataBaru
    baru->next=baru;//untuk mrnuju ke data didepannya
    if (isEmpty())
    {
        head=baru;
        head->next=head;
    }
    else
    {
        Data *bantu;
        bantu=head;
        while (bantu->next!=head)
        {
            bantu=bantu->next;
        }
        bantu->next=baru;
        baru->next=head;
    }
}

void hapusDepan ()//fungsi untuk meghapus data bagian depan
{
    if (!isEmpty())
    {
        int tmp;
        if (head->next!=head)
        {
            Data *hapus;
            hapus=head;
            tmp=head->nilai;
            Data *bantu;
            bantu=head;
            while (bantu->next!=head)
            {
                bantu=bantu->next;
            }
            bantu->next=head->next;
            head=head->next;
            delete hapus;
        }
        else
        {
            tmp=head->nilai;
            awal();
        }
        cout << tmp << " Dihapus" << endl;
    }
    else
    {
        cout << "Data kosong\n";
    }
}

void hapusBelakang () //fungsi untuk mengahpus data dibelakangg
{
    Data *hapus, *bantu;//pendeklarasian hapus dan bantu kedalaam fungsi
    int tmp;
    if (!isEmpty())
    {
        hapus=head;
        if (head->next==head)
        {
            tmp=head->nilai;
            head=NULL;
        }
        else
        {
        bantu=head;
        while (bantu->next->next!=head)
        {
            bantu=bantu->next;
        }
        hapus=bantu->next;
        bantu->next=head;
        tmp=hapus->nilai;
        delete hapus;
    }
    cout << tmp << " Dihapus" << endl;
    }
    else cout << "Data kosong\n ";
}

void Cetak ()//fungsi untuk mencetak data
{
    if (!isEmpty())
    {
        Data *bantu;
        bantu=head;
        do
        {
            cout << bantu->nilai<< " ";
            bantu=bantu->next;
        }
        while (bantu!=head);
        cout << endl;
    }
}

int panjang ()
{
    int count=0;
    if (!isEmpty())
    {
        count=1;
        Data *bantu;
        bantu=head;
        if (bantu->next==head)
        {
            count=1;
        }
        else
        {
            do
            {
                count++;
                bantu=bantu->next;
            }
            while (bantu->next!=head);
        }
    }
    else
    {
        count=0;
    }
    return count;
}


int main()//untuk memanggil fungsi utama program
{
    awal();
    tambahDataBelakang(8);
    tambahDataDepan(5);
    tambahDataBelakang(30);
    tambahDataBelakang(10);
    tambahDataBelakang(20);
    tambahDataBelakang(5);
    cout << "Data pada single linked list circular:" << endl;
    Cetak();
    cout << "Data paling depan dihapus:" << endl;
    hapusDepan();
    cout << "Data paling belakang dihapus:" << endl;
    hapusBelakang();
    cout << "Data pada single linked list circlar:" << endl;
    Cetak();
    cout << "Panjang linked list :" << endl;
    cout << panjang();

    return 0;
}
