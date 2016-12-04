#ifndef JADWAL_H_INCLUDED
#define JADWAL_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define Nil NULL
#define info(p) p->info
#define next(p) p->next
#define prev(p) p->prev
#define first(L) ((L).first)
#define last(L) ((L).last)
using namespace std;

typedef struct elmlistStasiun *adrStasiun;
typedef struct elmlistkereta *adrKereta;
typedef struct elmlistjadwal *adrJadwal;

struct stasiun{
    string kode_stasiun;
    string nama_stasiun;
    string kota_stasiun;
    int rating;
    string ketuapengelola;
    string alamat_stasiun;
};

struct elmlistStasiun{
    stasiun info;
    elmlistStasiun *next;
};

struct listStasiun{
    elmlistStasiun *first;
};

struct kereta{
    int no_kereta;
    string nama_kereta;
    string kelas;
    string asal;
    string tujuan;
    int waktuberangkat;
    int waktudatang;
    string masisnis;
    int slot;
};

struct elmlistkereta{
    kereta info;
    elmlistkereta *next;
    elmlistkereta *prev;
    listStasiun stasiunKereta;
};

struct listkereta{
    elmlistkereta *first;
    elmlistkereta *last;
};

struct jadwal{
    string hari;
    int tanggal;
    int bulan;
    int tahun;
};

struct elmlistjadwal{
    jadwal info;
    elmlistjadwal *next;
    elmlistjadwal *prev;
    listkereta keretaapi;
};

struct listjadwal{
    elmlistjadwal *first;
    elmlistjadwal *last;
};

void createlistStasiun(listStasiun &S);
void createlistKereta(listkereta &K);
void createlistJadwal(listjadwal &J);
void tambahStasiun(stasiun &s);
void tambahKereta(kereta &k);
void tambahJadwal(jadwal &j);
elmlistStasiun *alokasiStasiun(stasiun s);
elmlistkereta *alokasiKereta(kereta k);
elmlistjadwal *alokasiJadwal(jadwal j);
elmlistStasiun *cari_elementStasiun(listStasiun &S, string kode);
elmlistkereta *cari_elementKereta(listkereta &K, int nomor);
elmlistjadwal *cari_elementJadwal(listjadwal &J, int tanggal);
void viewStasiun(listStasiun S);
void viewAtKereta(listkereta K);
void viewKereta(listkereta K);
void viewJadwal(listjadwal J);
void insert_last_stasiun(listjadwal &J, int tanggal, int nomor, stasiun s);
void insert_first_kereta(listjadwal &J, int tanggal, kereta k);
void insert_after_kereta(listjadwal &J, int tanggal, kereta k);
void insert_last_kereta(listjadwal &J, int tanggal, kereta k);
void insert_kereta(listjadwal &J, int tanggal, kereta k);
void insert_first_jadwal(listjadwal &J, jadwal j);
void insert_after_jadwal(listjadwal &J, jadwal j);
void insert_last_jadwal(listjadwal &J, jadwal j);
void insert_jadwal(listjadwal &J, jadwal j);
void delete_first_stasiun(listjadwal &J, int tanggal, int nomor, string kode, adrStasiun q);
void delete_after_stasiun(listjadwal &J, int tanggal, int nomor, string kode, adrStasiun q);
void delete_last_stasiun(listjadwal &J, int tanggal, int nomor, string kode, adrStasiun q);
void delete_stasiun(listjadwal &J, int tanggal, int nomor, string kode, adrStasiun q);
void delete_first_kereta(listjadwal &J, int tanggal, int nomor, adrKereta q);
void delete_after_kereta(listjadwal &J, int tanggal, int nomor, adrKereta q);
void delete_last_kereta(listjadwal &J, int tanggal, int nomor, adrKereta q);
void delete_kereta(listjadwal &J, int tanggal, int nomor, adrKereta q);
void delete_first_jadwal(listjadwal &J, int tanggal, adrJadwal q);
void delete_after_jadwal(listjadwal &J, int tanggal, adrJadwal q);
void delete_last_jadwal(listjadwal &J, int tanggal, adrJadwal q);
void delete_jadwal(listjadwal &J, int tanggal, adrJadwal q);
void change_data_stasiun(listjadwal &J, int tanggal, int nomor, string kode);
void change_data_kereta(listjadwal &J, int tanggal, int nomor);
void change_data_jadwal(listjadwal &J, int tanggal);
void tampil_kota(elmlistjadwal induk1, elmlistkereta p);
void view_Kota(listjadwal &J);
void view_nama_kelas(listjadwal &J);
void view_tanggal(listjadwal &J);

#endif // JADWAL_H_INCLUDED
