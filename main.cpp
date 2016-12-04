#include "jadwal.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main()
{
    listStasiun S;
    listjadwal J;
    listkereta K;
    jadwal j;
    kereta k;
    stasiun s;
    int tanggal, nomor;
    string kode;
    createlistStasiun(S);
    createlistJadwal(J);
    createlistKereta(K);
    int pil;
    while(pil!=3){
        system("cls");
        cout<<"=====SELAMAT DATANG DI MENU UTAMA======"<<endl;
        cout<<"         1. Login Admin                "<<endl;
        cout<<"         2. Login User (Umum)          "<<endl;
        cout<<"Masukkan Pilihan : ";
        cin>>pil;
        switch(pil){
            case 1 :{
                        system("cls");
                        string user, pass;
                        cout<<"Masukkan Username : ";
                        cin>>user;
                        cout<<"Masukkan Password : ";
                        cin>>pass;
                        cout<<endl;
                        cout<<endl;
                        if((user!="q")||(pass!="q")){
                                cout<<"Gagal Masuk ! Username atau Password salah !"<<endl;}
                        else if((user=="q")&&(pass=="q")){
                            int pil2;
                                cout<<"==========MENU ADMIN=========="<<endl;
                                cout<<"     1. Insert Data           "<<endl;
                                cout<<"     2. Change Data           "<<endl;
                                cout<<"     3. Delete Data           "<<endl;
                                cout<<"     4. View Data             "<<endl;
                                cout<<"     5. Keluar                "<<endl;
                                cout<<"Masukkan Pilihan : ";
                                cin>>pil2;
                                cout<<endl;
                                cout<<endl;
                                switch(pil2){
                                    case 1 :{
                                                system("cls");
                                                int pil3;
                                                    cout<<"===========INSERT DATA==========="<<endl;
                                                    cout<<"     1. Insert Jadwal Kereta     "<<endl;
                                                    cout<<"     2. Insert Data Kereta       "<<endl;
                                                    cout<<"     3. Insert Data Stasiun      "<<endl;
                                                    cout<<"     4. Keluar                   "<<endl;
                                                    cout<<"Masukkan Pilihan : ";
                                                    cin>>pil3;
                                                    cout<<endl;
                                                    cout<<endl;
                                                    switch(pil3){
                                                        case 1 :{
                                                                    system("cls");
                                                                    insert_jadwal(J,j);
                                                                    getch();
                                                                    break;}
                                                        case 2 :{
                                                                    system("cls");
                                                                    insert_kereta(J,tanggal,k);
                                                                    getch();
                                                                    break;}
                                                        case 3 :{
                                                                    system("cls");
                                                                    insert_last_stasiun(J,tanggal,nomor,s);
                                                                    getch();
                                                                    break;}}
                                                        break;}
                                    case 2 :{
                                                system("cls");
                                                int pil4;
                                                    cout<<"===========CHANGE DATA==========="<<endl;
                                                    cout<<"     1. Change Jadwal Kereta     "<<endl;
                                                    cout<<"     2. Change Data Kereta       "<<endl;
                                                    cout<<"     3. Change Data Stasiun      "<<endl;
                                                    cout<<"     4. Keluar                   "<<endl;
                                                    cout<<"Masukkan Pilihan : ";
                                                    cin>>pil4;
                                                    cout<<endl;
                                                    cout<<endl;
                                                    switch(pil4){
                                                        case 1 :{
                                                                    system("cls");
                                                                    change_data_jadwal(J,tanggal);
                                                                    getch();
                                                                    break;}
                                                        case 2 :{
                                                                    system("cls");
                                                                    change_data_kereta(J,tanggal,nomor);
                                                                    getch();
                                                                    break;}
                                                        case 3 :{
                                                                    system("cls");
                                                                    change_data_stasiun(J,tanggal,nomor,kode);
                                                                    getch();
                                                                    break;}}
                                                break;}
                                    case 3 :{
                                                system("cls");
                                                int pil5;
                                                    cout<<"===========DELETE DATA==========="<<endl;
                                                    cout<<"     1. Delete Jadwal Kereta     "<<endl;
                                                    cout<<"     2. Delete Data Kereta       "<<endl;
                                                    cout<<"     3. Delete Data Stasiun      "<<endl;
                                                    cout<<"     4. Keluar                   "<<endl;
                                                    cout<<"Masukkan Pilihan : ";
                                                    cin>>pil5;
                                                    cout<<endl;
                                                    cout<<endl;
                                                    switch(pil5){
                                                        case 1 :{
                                                                    system("cls");
                                                                    adrJadwal p;
                                                                    delete_jadwal(J,tanggal,p);
                                                                    getch();
                                                                    break;}
                                                        case 2 :{
                                                                    system("cls");
                                                                    adrKereta q;
                                                                    delete_kereta(J,tanggal,nomor,q);
                                                                    getch();
                                                                    break;}
                                                        case 3 :{
                                                                    system("cls");
                                                                    adrStasiun r;
                                                                    delete_stasiun(J,tanggal,nomor,kode,r);
                                                                    getch();
                                                                    break;}}
                                                    break;}
                                    case 4 :{
                                                system("cls");
                                                int pil6;
                                                    cout<<"========================VIEW DATA========================"<<endl;
                                                    cout<<"     1. View All Data                                    "<<endl;
                                                    cout<<"     2. View Data berdasarkan kota asal dan kota tujuan  "<<endl;
                                                    cout<<"     3. View Data berdasarkan nama dan kelas kereta      "<<endl;
                                                    cout<<"     4. View Data berdasarkan tanggal pada jadwal        "<<endl;
                                                    cout<<"     5. Keluar                                           "<<endl;
                                                    cout<<"Masukkan Pilihan : ";
                                                    cin>>pil6;
                                                    cout<<endl;
                                                    cout<<endl;
                                                    switch(pil6){
                                                        case 1 :{
                                                                    system("cls");
                                                                    viewJadwal(J);
                                                                    getch();
                                                                    break;}
                                                        case 2 :{
                                                                    system("cls");
                                                                    view_Kota(J);
                                                                    getch();
                                                                    break;}
                                                        case 3 :{
                                                                    system("cls");
                                                                    view_nama_kelas(J);
                                                                    getch();
                                                                    break;}
                                                        case 4 :{
                                                                    system("cls");
                                                                    view_tanggal(J);
                                                                    getch();
                                                                    break;}}}
                                                break;}}
                        getch();
                        break;}
            case 2 :{
                        system("cls");
                        int pil7;
                            cout<<"============MENU USER============"<<endl;
                            cout<<"     1. View Data                "<<endl;
                            cout<<"     2. Keluar                   "<<endl;
                            cout<<"Masukkan Pilihan : ";
                            cin>>pil7;
                            cout<<endl;
                            cout<<endl;
                            switch(pil7){
                                case 1 :{
                                            system("cls");
                                            int pil8;
                                                cout<<"========================VIEW DATA========================"<<endl;
                                                cout<<"     1. View All Data                                    "<<endl;
                                                cout<<"     2. View Data berdasarkan kota asal dan kota tujuan  "<<endl;
                                                cout<<"     3. View Data berdasarkan nama dan kelas kereta      "<<endl;
                                                cout<<"     4. View Data berdasarkan tanggal pada jadwal        "<<endl;
                                                cout<<"     5. Keluar                                           "<<endl;
                                                cout<<"Masukkan Pilihan : ";
                                                cin>>pil8;
                                                cout<<endl;
                                                cout<<endl;
                                                switch(pil8){
                                                    case 1 :{
                                                                system("cls");
                                                                viewJadwal(J);
                                                                getch();
                                                                break;}
                                                    case 2 :{
                                                                system("cls");
                                                                view_Kota(J);
                                                                getch();
                                                                break;}
                                                    case 3 :{
                                                                system("cls");
                                                                view_nama_kelas(J);
                                                                getch();
                                                                break;}
                                                    case 4 :{
                                                                system("cls");
                                                                view_tanggal(J);
                                                                getch();
                                                                break;}}
                                            getch();
                                            break;}}
                        getch();
                        break;}}}};
