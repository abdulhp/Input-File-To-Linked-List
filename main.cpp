#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;

struct node{
    string data;
    node* next;
};

node *head;

void initHead(){
    head = NULL;
}

bool isEmpty(){
     return (head == NULL);
}

void insertToNode(string databaru){
    node *baru, *bantu;
    baru = new node;
    baru->data = databaru;
    baru->next = NULL;

    if(isEmpty()){
        head = baru;
        head->next = NULL;
    }else{
        bantu = head;
        while(bantu->next != NULL){
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void inputTeks(string teks){
    int i = 0;
    string tmp;

    while(i < (int)teks.length()){
        if(teks[i] != ' '){
            tmp += teks[i];
        }else{
            insertToNode(tmp);
            tmp = "";
        }
        i++;
    }
}

bool cariData(string kunci){
    node *bantu;
    bool ketemu;

    bantu = head;
    while(bantu != NULL){
        if(bantu->data == kunci){
            ketemu = true;
            break;
        }else{
            if(bantu->next == NULL){
                ketemu = false;
                break;
            }else{
                bantu = bantu->next;
            }
        }
    }
    return ketemu;
}

void tampilList(){
    node *bantu;

    bantu = head;
    if(isEmpty()){
        cout << "Data Kosong" << endl;
    }else{
        while(bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
}

void bukaFile(){
    string line;
    ifstream myfile("Teks.txt");
    if (myfile.is_open())
    {
        while(getline(myfile,line)){
            inputTeks(line);
        }
        myfile.close();
    }else{
        cout << "Unable to open file";
    }
}

int main(){
    int menu = 0;
    string text = "Lorem Ipsum is simply dummy text of the printing and typesetting industry";
    string datadicari;

    do{
        cout << "M E N U" << endl;
        cout << "1. Masukkan file" << endl;
        cout << "2. Cari kata" << endl;
        cout << "3. Tampilkan semua kata" << endl;
        cout << "99. Exit" << endl;
        cout << endl;
        cout << "Pilih menu = ";
        cin >> menu;

        switch(menu){
        case 1:
            bukaFile();
            //inputTeks(text);
            cout << "Data telah dimasukkan" << endl;
            system("pause");
            break;
        case 2:
            cout << "Masukkan kata yang ingin dicari : ";
            cin >> datadicari;

            if(cariData(datadicari)){
                cout << "Data Ketemu" << endl;
            }else{
                cout << "Data tidak ditemukan" << endl;
            }

            system("pause");
            break;
        case 3:
            tampilList();
            system("pause");
            break;
        case 99:
            break;
        default:
            cout << "Menu tidak terdaftar" << endl;
        }
        system("cls");
    }while(menu != 99);

    return 0;
}
