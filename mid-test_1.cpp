/*
 * Author : Nadhifal
 * NPM : 140810180048
 * Kelas : B
 * Deskripsi :
 * Tanggal : APRIL 2019
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct node{
    string makanan;
    int harga;
    int jumlah;
    node* next;
};


void createNode(node*& p){
    p=new node;
    cout<<"Nama Makanan : ";getline(cin,p->makanan);
    p->jumlah = 0;
    cout<<"Harga : ";cin>>p->harga;
    p->next=NULL;

}

void insertLast(node*& head, node* pBaru){
	node* last;
	if(head==NULL){
		head=pBaru;
	}else if(head->next==NULL){
		head->next=pBaru;
	}else{
		last=head;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void traversal(node* head){
    int i=1;
    if(head==NULL){
        cout<<"List Kosong "<<endl;
    }
    else{
        cout<<setfill(' ')<<setw(5)<<"No"<<setw(15)<<"Nama"<<setw(18)<<"Harga"<<setw(18)<<"Jumlah"<<endl;
        while(head != NULL){
            cout<<setw(5)<<i<<setw(15)<<head->makanan<<setw(18)<<head->harga<<setw(18)<<head->jumlah<<endl;
            i++;
            head=head->next;
        }
    }
}

void update(node* head){
    node* p=head;

    while(p != NULL){
        cout<<"Jumlah Pesanan untuk menu "<<p->makanan<<" : ";cin>>p->jumlah;
        p=p->next;
    }
}

void sortingByjumlah(node* &head) {
  node* travNode = head;

  while (travNode != NULL) {
    node* currNode = head;

    while (currNode != NULL) {
      if (currNode->jumlah > travNode->jumlah) {
        // swap them
        node temp = *currNode;
        currNode->makanan = travNode->makanan;
        currNode->harga = travNode->harga;
        currNode->jumlah = travNode->jumlah;

        travNode->makanan = temp.makanan;
        travNode->harga = temp.harga;
        travNode->jumlah = temp.jumlah;
      } else {
        currNode = currNode->next;
      }
    }

    travNode = travNode->next;
  }
}

main(){
    node* head = NULL;
    node* pbaru = NULL;
    char choice;

    cout<<"Masukan Daftar Menu"<<endl;

    for(int i=0;i<5;i++){

        createNode(pbaru);
        insertLast(head, pbaru);
        cin.ignore(256,'\n');
    }
    traversal(head);

    cout<<"Update Jumlah makanan"<<endl;
    update(head);
    //sortingByjumlah(head);
    traversal(head);
}
