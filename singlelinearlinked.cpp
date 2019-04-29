#include <iostream>
#include <string>

using namespace std;

struct mahasiswa{

int no_peserta;
int nim;
char kelas;
mahasiswa*next;//Nama_struct*next.
};
};
void printlist(mahasiswa*n) //membuat tipe data struct yang berfunsi menyimpan beberapa tipe data yang berbeda.
{
 while(n!=NULL)       //syarat n tidak sama dengan NULL
 {

      cout<<"no peserta :"<<->no_peserta<<" "endl;
      cout<<"nim  :"<<n->nim<<" "<<endl;
      cout<<"kelas    :"<<n->kelas<<" "<endl;
      cout<<" "endl;
 n=n->next;//n-.data adalah sebuah variable yang akan di panggil
   }
 }
   int main()
   {
     mahasiswa*head = NULL;
     mahasiswa*second = NULL;
     mahasiswa*third = NULL;
     
     
     head = new mahasiswa();
     second = new mahasiswa();
     third = new mahasiswa();
     
     
     head->no_peserta=01;
     head->nim =1829140022;
     head->kelas='b';
     head->next =second;
     
     
     second->no_peserta = 02;
     second->nim = 1829140022;
     second->kelas = 'b';
     second->next = third;
     
     
     third->no_peserta = 03;
     third->nim = 1829140022;
     third->kelas ='c';
     third->next=NULL;
     
     printlist(head);
     
     cin.get();
     return 0;
  }
     
