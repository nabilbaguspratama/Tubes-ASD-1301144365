#include "jadwal.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void createlistStasiun(listStasiun &S){
    S.first=Nil;};

void createlistKereta(listkereta &K){
    K.first=Nil;
    K.last=Nil;};

void createlistJadwal(listjadwal &J){
    J.first=Nil;
    J.last=Nil;};

void tambahStasiun(stasiun &s){
    cout<<"================INPUT DATA STASIUN================"<<endl;
    cout<<"Masukkan kode stasiun : ";
    cin>>s.kode_stasiun;
    cout<<"Masukkan nama stasiun : ";
    cin>>s.nama_stasiun;
    cout<<"Masukkan kota stasiun : ";
    cin>>s.kota_stasiun;
    cout<<"Masukkan nama pengelola stasiun : ";
    cin>>s.ketuapengelola;
    cout<<"Masukkan alamat stasiun : ";
    cin>>s.alamat_stasiun;
    cout<<"Masukkan rating stasiun : ";
    cin>>s.rating;
    cout<<"=================================================="<<endl;
    cout<<endl;};

void tambahKereta(kereta &k){
    cout<<"================INPUT DATA KERETA================"<<endl;
    cout<<"Masukkan no kereta           : ";
    cin>>k.no_kereta;
    cout<<"Masukkan nama kereta         : ";
    cin>>k.nama_kereta;
    cout<<"Masukkan kelas kereta        : ";
    cin>>k.kelas;
    cout<<"Masukkan kota asal kereta    : ";
    cin>>k.asal;
    cout<<"Masukkan kota tujuan kereta  : ";
    cin>>k.tujuan;
    cout<<"Masukkan waktu keberangkatan : ";
    cin>>k.waktuberangkat;
    cout<<"Masukkan waktu kedatangan    : ";
    cin>>k.waktudatang;
    cout<<"Masukkan nama masinis        : ";
    cin>>k.masisnis;
    cout<<"Masukkan Slot yang tersedia  : ";
    cin>>k.slot;
    cout<<"================================================"<<endl;
    cout<<endl;};

void tambahJadwal(jadwal &j){
    cout<<"================INPUT JADWAL KERETA================"<<endl;
    cout<<"Masukkan Hari pada jadwal    : ";
    cin>>j.hari;
    cout<<"Masukkan Tanggal pada jadwal : ";
    cin>>j.tanggal;
    j.bulan = 12;
    j.tahun = 2016;
    cout<<"==================================================="<<endl;
    cout<<endl;};

elmlistStasiun *alokasiStasiun(stasiun s){
    adrStasiun p = new elmlistStasiun;
    info(p) = s;
    next(p) = Nil;
    return p;};

elmlistkereta *alokasiKereta(kereta k){
    adrKereta p= new elmlistkereta;
    info(p) = k;
    first(p->stasiunKereta)=Nil;
    next(p) = Nil;
    prev(p) = Nil;
    return p;};

elmlistjadwal *alokasiJadwal(jadwal j){
    adrJadwal p= new elmlistjadwal;
    info(p) = j;
    first(p->keretaapi)=Nil;
    last(p->keretaapi)=Nil;
    next(p) = Nil;
    prev(p) = Nil;
    return p;};

elmlistStasiun *cari_elementStasiun(listStasiun &S, string kode){
    if(S.first==Nil){
        return Nil;}
    else{
        adrStasiun p=S.first;
        while(p!=Nil){
            if(info(p).kode_stasiun==kode){
                return p;}
            p=next(p);}}};

elmlistkereta *cari_elementKereta(listkereta &K, int nomor){
    if(K.first==Nil){
        return Nil;}
    else{
        adrKereta p=K.first;
        while(p!=Nil){
            if(info(p).no_kereta==nomor){
                break;}
            p=next(p);}
        return p;}};

elmlistjadwal *cari_elementJadwal(listjadwal &J, int tanggal){
    if(J.first==Nil){
        return Nil;}
    else{
        adrJadwal p=J.first;
        while(p!=Nil){
            if(info(p).tanggal==tanggal){
                break;}
            p=next(p);}
        return p;}};

void viewStasiun(listStasiun S){
    elmlistStasiun *p;
    int no=1;
    if(S.first==Nil){
        cout<<"Data Kosong !"<<endl;
        cout<<endl;}
    else{
        p=S.first;
        cout<<"============DATA STASIUN============"<<endl;
        while(p!=Nil){
            cout<<no<<". Kode Stasiun : "<<p->info.kode_stasiun<<endl;
            cout<<"  Nama Stasiun  : "<<p->info.nama_stasiun<<endl;
            p = next(p);
            no=no+1;}
        cout<<endl;
        cout<<endl;}};

void viewAtKereta(listkereta K){
    elmlistkereta *p;
    int no=1;
    if(K.first==Nil){
        cout<<"Data Kosong !"<<endl;
        cout<<endl;}
    else{
        p=K.first;
        cout<<"============DATA KERETA============"<<endl;
        while(p!=Nil){
            cout<<no<<". No Kereta     : "<<p->info.no_kereta<<endl;
            cout<<"  Nama Kereta   : "<<p->info.nama_kereta<<endl;
            viewStasiun(p->stasiunKereta);
            p=next(p);
            no=no+1;}}};

void viewKereta(listkereta K){
    elmlistkereta *p;
    int no=1;
    if(K.first==Nil){
        cout<<"Data Kosong !"<<endl;
        cout<<endl;}
    else{
        p=K.first;
        cout<<"============DATA KERETA============"<<endl;
        while(p!=Nil){
            cout<<no<<". No Kereta     : "<<p->info.no_kereta<<endl;
            cout<<"  Nama Kereta   : "<<p->info.nama_kereta<<endl;
            cout<<"  Kelas Kereta  : "<<p->info.kelas<<endl;
            cout<<"  Nama Masinis  : "<<p->info.masisnis<<endl;
            cout<<"  Kota Asal     : "<<p->info.asal<<endl;
            cout<<"  Kota Tujuan   : "<<p->info.tujuan<<endl;
            cout<<"  Keberangkatan : "<<p->info.waktuberangkat<<endl;
            cout<<"  Kedatangan    : "<<p->info.waktudatang<<endl;
            cout<<"  Sisa kursi    : "<<p->info.slot<<endl;
            viewStasiun(p->stasiunKereta);
            p=next(p);
            no=no+1;}}};

void viewJadwal(listjadwal J){
    elmlistjadwal *p;
    if(J.first==Nil){
        cout<<"Data Kosong !"<<endl;
        cout<<endl;}
    else{
        p=J.first;
        while(p!=Nil){
            cout<<"============JADWAL KERETA============"<<endl;
            cout<<"Hari    : "<<p->info.hari<<endl;
            cout<<"Tanggal : "<<p->info.tanggal<<endl;
            viewAtKereta(p->keretaapi);
            p=next(p);}
        cout<<"===================================="<<endl;}};

void insert_last_stasiun(listjadwal &J, int tanggal, int nomor, stasiun s){
    cout<<"================INSERT STASIUN================"<<endl;
    cout<<"Masukkan tanggal pada jadwal : ";
    cin>>tanggal;
    cout<<"Masukkan no kereta           : ";
    cin>>nomor;
    cout<<"=============================================="<<endl;
    cout<<endl;
    if(J.first!=Nil){
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal Tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            if(first(induk1->keretaapi)!=Nil){
                elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi,nomor);
                if(induk2==Nil){
                    cout<<"Data kereta tidak ditemukan !"<<endl;
                    cout<<endl;}
                else{
                    tambahStasiun(s);
                    cout<<endl;
                    elmlistStasiun *p=alokasiStasiun(s);
                        if(first(induk2->stasiunKereta)==Nil){
                            first(induk2->stasiunKereta)=p;
                            next(p)=Nil;
                            cout<<"Tambah Data Stasiun Berhasil !"<<endl;
                            cout<<endl;}
                        else{
                            elmlistStasiun *q=first(induk2->stasiunKereta);
                            while(next(q)!=Nil){
                                q=next(q);}
                            next(q)=p;
                            next(p)=Nil;
                            cout<<"Tambah Data Stasiun Berhasil !"<<endl;
                            cout<<endl;}}}
             else{
                cout<<"Data kereta kosong!"<<endl;
                cout<<endl;}}}
    else{
        cout<<"Jadwal Kosong !"<<endl;
        cout<<endl;}};

void insert_kereta(listjadwal &J, int tanggal, kereta k){
    cout<<"================INSERT KERETA================"<<endl;
    cout<<"Masukkan tanggal pada jadwal : ";
    cin>>tanggal;
    cout<<"============================================="<<endl;
    cout<<endl;
    if(J.first!=Nil){
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal Tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            tambahKereta(k);
            cout<<endl;
            elmlistkereta *p=alokasiKereta(k);
            if(first(induk1->keretaapi)==Nil){
                first(induk1->keretaapi) = p;
                last(induk1->keretaapi) = p;
                cout<<"Tambah Data Kereta Berhasil !"<<endl;
                cout<<endl;}
            else{
                elmlistkereta *q = first(induk1->keretaapi);
                while (q->info.no_kereta < k.no_kereta){
                    if (q!= last(induk1->keretaapi)){
                        q = next(q);
                    } else {
                        break;
                    }
                }
                if ((q == first(induk1->keretaapi))&&(q!=last(induk1->keretaapi))){
                    insert_first_kereta(J,tanggal,k);
                } else if (q == last(induk1->keretaapi)){
                    insert_last_kereta(J,tanggal,k);
                } else {
                    insert_after_kereta(J,tanggal,k);
                }
                cout<<"Tambah Data Kereta Berhasil !"<<endl;
                cout<<endl;}}}
    else{
        cout<<"Jadwal Kosong !"<<endl;
        cout<<endl;}};

void insert_first_kereta(listjadwal &J, int tanggal, kereta k){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    elmlistkereta *p=alokasiKereta(k);
    first(induk1->keretaapi)=p;
    last(induk1->keretaapi)=p;
    next(p)=Nil;
};

void insert_after_kereta(listjadwal &J, int tanggal, kereta k){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    elmlistkereta *p=alokasiKereta(k);
    elmlistkereta *q = first(induk1->keretaapi);
    while (q->info.no_kereta < p->info.no_kereta){
        q = next(q);
    }
    prev(q) = p;
    next(prev(q)) = p;
    next(p) = q;
    prev(p) = prev(q);
};

void insert_last_kereta(listjadwal &J, int tanggal, kereta k){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    elmlistkereta *p=alokasiKereta(k);
    elmlistkereta *q = last(induk1->keretaapi);
    next(q) = p;
    prev(p) = q;
    next(p) = Nil;
    last(induk1->keretaapi) = p;
};

void insert_first_jadwal(listjadwal &J, jadwal j){
    elmlistjadwal *p=alokasiJadwal(j);
    prev(first(J))=p;
    next(p)=first(J);
    first(J)=p;
};

void insert_after_jadwal(listjadwal &J, jadwal j){
    elmlistjadwal *q = J.first;
    elmlistjadwal *p=alokasiJadwal(j);
    while (q->info.tanggal < p->info.tanggal){
        q = next(q);
    }
    prev(q) = p;
    next(prev(q)) = p;
    next(p) = q;
    prev(p) = prev(q);
};

void insert_last_jadwal(listjadwal &J, jadwal j){
    elmlistjadwal *q = J.last;
    elmlistjadwal *p=alokasiJadwal(j);
    next(q) = p;
    prev(p) = q;
    next(p) = Nil;
    J.last = p;
};

void insert_jadwal(listjadwal &J, jadwal j){
    tambahJadwal(j);
    cout<<endl;
    elmlistjadwal *p=alokasiJadwal(j);
    if(J.first==Nil){
        first(J)=p;
        last(J)=p;
        cout<<"Tambah Jadwal Berhasil !"<<endl;
        cout<<endl;}
    else{
        elmlistjadwal *q = J.first;
        while(q->info.tanggal < p->info.tanggal){
            if (q!= J.last){
                q = next(q);
            } else {
                break;
            }
        }
        if ((q == J.first)&&(q!=J.last)){
            insert_first_jadwal(J,j);
        } else if (q == J.last){
            insert_last_jadwal(J,j);
        } else {
            insert_after_jadwal(J,j);
        }
        cout<<"Tambah Jadwal Berhasil !"<<endl;
        cout<<endl;}};

void delete_first_stasiun(listjadwal &J, int tanggal, int nomor, string kode, adrStasiun q){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
    elmlistStasiun *anak=cari_elementStasiun(induk2->stasiunKereta,kode);
    q=first(induk2->stasiunKereta);
    first(induk2->stasiunKereta)=next(q);
    next(q)=Nil;
};

void delete_after_stasiun(listjadwal &J, int tanggal, int nomor, string kode, adrStasiun q){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
    elmlistStasiun *anak=cari_elementStasiun(induk2->stasiunKereta,kode);
    q=first(induk2->stasiunKereta);
    while(next(q)!=anak){
        q=next(q);}
    next(q)=next(next(q));
    next(anak)=Nil;
};

void delete_last_stasiun(listjadwal &J, int tanggal, int nomor, string kode, adrStasiun q){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
    elmlistStasiun *anak=cari_elementStasiun(induk2->stasiunKereta,kode);
    q=first(induk2->stasiunKereta);
    while(next(next(q))!=Nil){
        q=next(q);}
    next(q)=Nil;
};

void delete_stasiun(listjadwal &J, int tanggal, int nomor, string kode, adrStasiun q){
    cout<<"=============HAPUS DATA STASIUN============="<<endl;
    cout<<"Masukkan tanggal pada jadwal : ";
    cin>>tanggal;
    cout<<"Masukkan nomor kereta        : ";
    cin>>nomor;
    cout<<"Masukkan kode stasiun        : ";
    cin>>kode;
    cout<<"============================================"<<endl;
    if(J.first!=Nil){
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            if(first(induk1->keretaapi)!=Nil){
                elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
                if(induk2==Nil){
                    cout<<"Data kereta tidak ditemukan !"<<endl;
                    cout<<endl;}
                else{
                    if(first(induk2->stasiunKereta)!=Nil){
                        elmlistStasiun *anak=cari_elementStasiun(induk2->stasiunKereta,kode);
                        if(anak==Nil){
                            cout<<"Data stasiun tidak ditemukan !"<<endl;
                            cout<<endl;}
                        else{
                            if(next(first(induk2->stasiunKereta))==Nil){
                                first(induk2->stasiunKereta)=Nil;
                                cout<<"Hapus Data Stasiun Berhasil !"<<endl;
                                cout<<endl;}
                            else{
                                q=first(induk2->stasiunKereta);
                                if(anak==first(induk2->stasiunKereta)){
                                    delete_first_stasiun(J,tanggal,nomor,kode,q);
                                    cout<<"Hapus Data Stasiun Berhasil !"<<endl;
                                    cout<<endl;}
                                else{
                                    if(next(anak)==Nil){
                                        delete_last_stasiun(J,tanggal,nomor,kode,q);
                                        cout<<"Hapus Data Stasiun Berhasil !"<<endl;
                                        cout<<endl;}
                                    else{
                                        delete_after_stasiun(J,tanggal,nomor,kode,q);
                                        cout<<"Hapus Data Stasiun Berhasil !"<<endl;
                                        cout<<endl;}}}}}
                    else{
                        cout<<"Data stasiun kosong !"<<endl;
                        cout<<endl;}}}
            else{
                cout<<"Data kereta kosong !"<<endl;
                cout<<endl;}}}
        else{
            cout<<"Jadwal kosong !"<<endl;
            cout<<endl;}};

void delete_first_kereta(listjadwal &J, int tanggal, int nomor, adrKereta q){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
    q=first(induk1->keretaapi);
    first(induk1->keretaapi)=next(q);
    next(q)=Nil;
};

void delete_after_kereta(listjadwal &J, int tanggal, int nomor, adrKereta q){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
    q=first(induk1->keretaapi);
    while(next(q)!=induk2){
        q=next(q);}
    next(q)=next(next(q));
    next(induk2)=Nil;
};

void delete_last_kereta(listjadwal &J, int tanggal, int nomor, adrKereta q){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
    q=first(induk1->keretaapi);
    while(next(next(q))!=Nil){
        q=next(q);}
    next(q)=Nil;
};

void delete_kereta(listjadwal &J, int tanggal, int nomor, adrKereta q){
    cout<<"===============HAPUS DATA KERETA==============="<<endl;
    cout<<"Masukkan tanggal pada jadwal : ";
    cin>>tanggal;
    cout<<"Masukkan nomor kereta        : ";
    cin>>nomor;
    cout<<"==============================================="<<endl;
    if(J.first!=Nil){
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            if(first(induk1->keretaapi)!=Nil){
                elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
                if(induk2==Nil){
                    cout<<"Data kereta tidak ditemukan !"<<endl;
                    cout<<endl;}
                else{
                    if(next(first(induk1->keretaapi))==Nil){
                        first(induk1->keretaapi)=Nil;
                        cout<<"Hapus Data Kereta Berhasil !"<<endl;
                        cout<<endl;}
                    else{
                        q=first(induk1->keretaapi);
                        if(induk2==first(induk1->keretaapi)){
                            delete_first_kereta(J,tanggal,nomor,q);
                            cout<<"Hapus Data Kereta Berhasil !"<<endl;
                            cout<<endl;}
                        else{
                            if(next(induk2)==Nil){
                                delete_last_kereta(J,tanggal,nomor,q);
                                cout<<"Hapus Data Kereta Berhasil !"<<endl;
                                cout<<endl;}
                            else{
                                delete_after_kereta(J,tanggal,nomor,q);
                                cout<<"Hapus Data Kereta Berhasil !"<<endl;
                                cout<<endl;}}}}}
            else{
                cout<<"Data kereta kosong !"<<endl;
                cout<<endl;}}}
        else{
            cout<<"Jadwal kosong !"<<endl;
            cout<<endl;}};

void delete_first_jadwal(listjadwal &J, int tanggal, adrJadwal q){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    q=J.first;
    J.first=next(q);
    next(q)=Nil;
};

void delete_after_jadwal(listjadwal &J, int tanggal, adrJadwal q){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    q=J.first;
    while(next(q)!=induk1){
        q=next(q);}
    next(q)=next(next(q));
    next(induk1)=Nil;
};

void delete_last_jadwal(listjadwal &J, int tanggal, adrJadwal q){
    elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
    q=J.first;
    while(next(next(q))!=Nil){
        q=next(q);}
    next(q)=Nil;
};

void delete_jadwal(listjadwal &J, int tanggal, adrJadwal q){
    cout<<"=============HAPUS JADWAL KERETA============="<<endl;
    cout<<"Masukkan tanggal pada jadwal : ";
    cin>>tanggal;
    cout<<"============================================="<<endl;
    if(J.first!=Nil){
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            if(next(J.first)==Nil){
                J.first=Nil;
                cout<<"Hapus Jadwal Berhasil !"<<endl;
                cout<<endl;}
            else{
                q=J.first;
                if(induk1==J.first){
                    delete_first_jadwal(J,tanggal,q);
                    cout<<"Hapus Jadwal Berhasil !"<<endl;
                    cout<<endl;}
                else{
                    if(next(induk1)==Nil){
                        delete_last_jadwal(J,tanggal,q);
                        cout<<"Hapus Jadwal Berhasil !"<<endl;
                        cout<<endl;}
                    else{
                        delete_after_jadwal(J,tanggal,q);
                        cout<<"Hapus Jadwal Berhasil !"<<endl;
                        cout<<endl;}}}}}
    else{
        cout<<"Jadwal kosong !"<<endl;
        cout<<endl;}};

void change_data_stasiun(listjadwal &J, int tanggal, int nomor, string kode){
    cout<<"=============UBAH DATA STASIUN============="<<endl;
    cout<<"Masukkan tanggal pada jadwal : ";
    cin>>tanggal;
    cout<<"Masukkan nomor kereta        : ";
    cin>>nomor;
    cout<<"Masukkan kode stasiun        : ";
    cin>>kode;
    cout<<"==========================================="<<endl;
    if(J.first!=Nil){
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            if(first(induk1->keretaapi)!=Nil){
                elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
                if(induk2==Nil){
                    cout<<"Data kereta tidak ditemukan !"<<endl;
                    cout<<endl;}
                else{
                    if(first(induk2->stasiunKereta)!=Nil){
                        elmlistStasiun *anak=cari_elementStasiun(induk2->stasiunKereta,kode);
                        if(anak==Nil){
                            cout<<"Data stasiun tidak ditemukan !"<<endl;
                            cout<<endl;}
                        else{
                            stasiun s;
                            tambahStasiun(s);
                            info(anak)=s;
                            cout<<"Ubah Data Stasiun Berhasil ! "<<endl;
                            cout<<endl;}}
                    else{
                        cout<<"Data stasiun kosong !"<<endl;
                        cout<<endl;}}}
            else{
                cout<<"Data kereta kosong !"<<endl;
                cout<<endl;}}}
        else{
            cout<<"Jadwal kosong !"<<endl;
            cout<<endl;}};

void change_data_kereta(listjadwal &J, int tanggal, int nomor){
    cout<<"===============UBAH DATA KERETA==============="<<endl;
    cout<<"Masukkan tanggal pada jadwal : ";
    cin>>tanggal;
    cout<<"Masukkan nomor kereta        : ";
    cin>>nomor;
    cout<<"=============================================="<<endl;
    if(J.first!=Nil){
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            if(first(induk1->keretaapi)!=Nil){
                elmlistkereta *induk2=cari_elementKereta(induk1->keretaapi, nomor);
                if(induk2==Nil){
                    cout<<"Data kereta tidak ditemukan !"<<endl;
                    cout<<endl;}
                else{
                    kereta k;
                    tambahKereta(k);
                    info(induk2)=k;
                    cout<<"Ubah Data Kereta Berhasil !"<<endl;
                    cout<<endl;}}
            else{
                cout<<"Data kereta kosong !"<<endl;
                cout<<endl;}}}
        else{
            cout<<"Jadwal kosong !"<<endl;
            cout<<endl;}};

void change_data_jadwal(listjadwal &J, int tanggal){
    cout<<"=============UBAH JADWAL KERETA============="<<endl;
    cout<<"Masukkan tanggal pada jadwal : ";
    cin>>tanggal;
    cout<<"============================================"<<endl;
    if(J.first!=Nil){
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            jadwal j;
            tambahJadwal(j);
            info(induk1)=j;
            cout<<"Ubah Jadwal Berhasil !"<<endl;
            cout<<endl;}}
    else{
        cout<<"Jadwal kosong !"<<endl;
        cout<<endl;}};

void tampil_kota(elmlistjadwal *induk1, elmlistkereta *p){
    cout<<"================JADWAL KERETA================"<<endl;
    cout<<"Hari    : "<<induk1->info.hari<<endl;
    cout<<"Tanggal : "<<induk1->info.tanggal<<endl;
    cout<<"=================DATA KERETA================="<<endl;
    cout<<"No Kereta     : "<<p->info.no_kereta<<endl;
    cout<<"Nama Kereta   : "<<p->info.nama_kereta<<endl;
    cout<<"Kelas Kereta  : "<<p->info.kelas<<endl;
    cout<<"Nama Masinis  : "<<p->info.masisnis<<endl;
    cout<<"Kota Asal     : "<<p->info.asal<<endl;
    cout<<"Kota Tujuan   : "<<p->info.tujuan<<endl;
    cout<<"Keberangkatan : "<<p->info.waktuberangkat<<endl;
    cout<<"Kedatangan    : "<<p->info.waktudatang<<endl;
    cout<<"Sisa kursi    : "<<p->info.slot<<endl;
    viewStasiun(p->stasiunKereta);};

void view_Kota(listjadwal &J){
    string asalkota, tujuankota;
    int tanggal;
    cout<<"Masukkan tanggal pada jadwal kereta : ";
    cin>>tanggal;
    cout<<"Masukkan kota asal : ";
    cin>>asalkota;
    cout<<"Masukkan kota tujuan : ";
    cin>>tujuankota;
    if(J.first==Nil){
        cout<<"Jadwal Kosong !"<<endl;
        cout<<endl;}
    else{
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            adrKereta p=first(induk1->keretaapi);
            int i=0;
            while(p!=Nil){
            if((info(p).asal==asalkota)&&(info(p).tujuan==tujuankota)){
                tampil_kota(induk1,p);
                i=i+1;}
            p=next(p);}
            if(i==0){
                cout<<"Data ridak ditemukan !"<<endl;
                cout<<endl;}}}};

void view_nama_kelas(listjadwal &J){
    string nama, kelaskereta;
    int tanggal;
    cout<<"Masukkan tanggal pada jadwal kereta : ";
    cin>>tanggal;
    cout<<"Masukkan nama kereta : ";
    cin>>nama;
    cout<<"Masukkan kelas kereta : ";
    cin>>kelaskereta;
    if(J.first==Nil){
        cout<<"Jadwal Kosong !"<<endl;
        cout<<endl;}
    else{
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            adrKereta p=first(induk1->keretaapi);
            int i=0;
            while(p!=Nil){
            if((info(p).nama_kereta==nama)&&(info(p).kelas==kelaskereta)){
                tampil_kota(induk1,p);
                i=i+1;}
            p=next(p);}
            if(i==0){
                cout<<"Data ridak ditemukan !"<<endl;
                cout<<endl;}}}};

void view_tanggal(listjadwal &J){
    int tanggal;
    cout<<"Masukkan tanggal pada jadwal kereta : ";
    cin>>tanggal;
    if(J.first==Nil){
        cout<<"Jadwal Kosong !"<<endl;
        cout<<endl;}
    else{
        elmlistjadwal *induk1=cari_elementJadwal(J,tanggal);
        if(induk1==Nil){
            cout<<"Jadwal tidak ditemukan !"<<endl;
            cout<<endl;}
        else{
            cout<<"================JADWAL KERETA================"<<endl;
            cout<<"Hari    : "<<induk1->info.hari<<endl;
            cout<<"Tanggal : "<<induk1->info.tanggal<<endl;
            viewKereta(induk1->keretaapi);}}};
