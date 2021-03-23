#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct node {
     int nim;
    char nama[20];
    int alamat;
    float ip;
    node *next;
 } *head;
 node *posisi;
 int pilih;

void CariData(int nmr)
{
bool ketemu=false;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->nim == nmr){
            ketemu = true;
            system("cls");
            cout<<"DATA BERHASIL DITEMUKAN"<<endl;
            cout<<"NIM : "<<temp->nim<<"  ";
            cout<<"NAMA : "<<temp->nama<<"  ";
            cout<<"ALAMAT : "<<temp->alamat<<"  ";
            cout<<"IP : "<<temp->ip<<"  ";
            cout<<"\nEnter Melanjutkan proses";
            getch();
        }
    temp=temp->next;
    }
    if(ketemu == false)
    {
        system("cls");
        cout<<"MAAF DATA DENGAN NIM "<<nmr<<" TIDAK DI TEMUKAN\nEnter Melanjutkan proses";
        getch();
    }
}
void inputDataMhs(int nmr)
 {
    struct node *temp;
    cout << "Masukkan Nama     : ";   cin >> temp->nama;
    cout << "Masukkan alamat  : ";   cin >> temp->alamat;
    cout << "Masukkan ip    : ";   cin >> temp->ip;
    temp->nim=nmr;
 }
 void cetak_tengah(int brs, char *teks) 
 		{
		cout<<teks;
		
		}
int count()
{
    struct node *n;
    int c=1;
    n=head;
    while(n!=NULL)
    {
    n=n->next;
    c++;
    }
    return c;
}

bool cekData(int nmr)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->nim == nmr)
            return false;
        else
            return true;
    temp=temp->next;
    }
    return true;
}


 void tambah(int nmr )
{
    struct node *temp;
    temp = new node;
    inputDataMhs(nmr);
    if (head== NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}


 void tambah_tengah_list(int nmr, int posisi_sisip) 
 {
     node *temp, *bantu;
     bantu=head;
     temp =new node;
     for(int i=1;i<posisi_sisip-1;i++)
     {
        if(bantu->next != NULL)
            bantu=bantu->next;
        else
            break;
     }       
    cout << "Masukkan Nama     : ";   cin >> temp->nama;
    cout << "Masukkan alamat  : ";   cin >> temp->alamat;
    cout << "Masukkan ip    : ";   cin >> temp->ip;
    temp->nim=nmr;
    temp->next=bantu->next;   
    bantu->next=temp;
}


void tambah_simpul_awal(int nmr) 
{
  node *temp;
  temp = new node;
  inputDataMhs(nmr);
  temp->next = NULL;
  
  temp->next = head;
  head = temp;
  
} 


void tambah_simpul_akhir(int nmr)
 {
    node *temp, *temp2; 
    temp=new node;
    inputDataMhs(nmr);
    temp->next=NULL;
    
    temp2=head;
     while(temp2->next != NULL)
       {
          temp2 = temp2->next;
       }
       temp2->next=temp;
 }
 
 
void InputData(int nmr)
{   
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        tambah(nmr);
        system("cls");
        cout<<"Data Tersimpan.\nEnter Melanjutkan proses";
        getch();
    }
    else
    {
        if(cekData(nmr) == false)
        {
            system("cls");
            cout<<"NIM sudah pernah di inputkan";
            getch();
        }   
        else
        {
            while(temp!=NULL)
            {
                if(temp->nim<nmr)
                   c++;
                temp=temp->next;
            }
            if(c==0)
                tambah_simpul_awal(nmr);
            else if(c<count())
            {
                tambah_tengah_list(nmr,++c);
            }
            else
            {
                tambah_simpul_akhir(nmr);
            }
            system("cls");
            cout<<"Data Tersimpan.\nEnter Melanjutkan proses";
            getch();
        }
    }
}


 int Hapus(int nim)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->nim==nim)
        {
            if(temp==head)
            {
                head=temp->next;
                return 1;
            }
            else
            {
                prev->next=temp->next;
                return 1;
            }
        }
        else
        {
            prev=temp;
            temp= temp->next;
        }
    }
    return 0;
}


 void tampil_senarai()
 {
    node *temp;
    temp = head;
    if(temp == NULL)
       cout<<"List kosong"<<endl;
    else
    {
        int i=1;
        cout<<endl;
		cout<<"No.";
     	cout<<"NIM";
   	 	cout<<"NAMA";
    	cout<<"ALAMAT";
    	cout<<"IP";
       while(temp != NULL)
       {
        cout<<i;        
        cout<<temp->nim;
        cout<<temp->nama;
        cout<<temp->alamat;
        cout<<temp->ip;
       }
       
    }
} 

 
void EditData(int nmr)
{
    bool ketemu=false;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->nim == nmr){
            ketemu = true;
            system("cls");
            cout<<"EDIT DATA BERIKUT INI"<<endl;
            cout<<"NIM    : "<<temp->nim<<"  "<<endl;
            cout<<"NAMA   : "<<temp->nama<<"  "<<endl;
            cout<<"ALAMAT   : "<<temp->alamat<<"  "<<endl;
            cout<<"IP : "<<temp->ip<<" "<<endl;
            cout<<"Edit data berhasil.\nEnter Melanjutkan proses";
            getch();
        }
    temp=temp->next;
    }
    if(ketemu == false)
    {
        system("cls");
        cout<<"Data dengan NIM  "<<nmr<<" Tidak ditemukan\nEnter Melanjutkan proses"<<endl;
        getch();
    }
}

int main() 
{
    int nmr;
    head=NULL;
    do
    {
      system("cls");
      tampil_senarai();
      cout<<endl<<endl<<"======================"<<endl;
      cout<<"Menu Pilihan"<<endl;
      cout<<"1. Input"<<endl;
      cout<<"2. Cari"<<endl;
      cout<<"3. Hapus"<<endl;
      cout<<"4. Edit"<<endl;
     cout<<"5. Exit"<<endl;
      cout<<"Pilihan >> ";cin>>pilih;
      switch(pilih)
       {
        case 1: cout<<"Masukkan NIM      : ";
              cin>>nmr;
              InputData(nmr);
              break;
        case 2: cout<<"Masukkan NIM      : ";
              cin>>nmr;
              CariData(nmr);
              break;
        case 3: cout<<"Masukkan NIM      : ";
              cin>>nmr;
              if(Hapus(nmr)){
                system("cls");
                cout<<"Berhasil Dihapus.\nEnter Melanjutkan proses";
                getch();
              }
              else{
                system("cls");
                cout<<"Gagal Dihapus.\nEnter Melanjutkan proses";
                getch();
              }
              break;
        case 4: cout<<"Masukkan NIM      : ";
              cin>>nmr;
              EditData(nmr);
              break;
      default:
            cout<<"Pilihan yang anda masukkan salah, \ntEnter untuk Melanjutkan ";
       }
    }
  while(pilih !=5);
}
