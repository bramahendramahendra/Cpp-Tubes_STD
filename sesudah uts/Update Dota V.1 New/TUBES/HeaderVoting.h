#ifndef HEADERVOTING_H_INCLUDED
#define HEADERVOTING_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define nil NULL

//typedef umum
typedef struct elm_voter *adr_voter;
typedef struct elm_voting *adr_voting;
typedef struct elm_peserta *adr_peserta;

//variabel Type untuk type infotype
struct type_tanggal_lahir
{
    string tanggal;
    string bulan;
    string tahun;
};


//Semua Infotype Program
struct infotype_peserta
{
    string id;
    string nama;
    string alamat;
    string asal;
    type_tanggal_lahir tanggal_lahir;
};

struct infotype_voter
{
    string id;
    string nama;
    string asal;
    int umur;
};

//Semua elmen list program
struct elm_peserta
{
    infotype_peserta info;
    adr_peserta next;
    adr_voting first_list_voting;
    adr_voting last_list_voting;
};

struct elm_voting
{
    adr_voter list_voter;
    string namapilihan;
    adr_voting next;
    adr_voting prev;
};

struct elm_voter
{
    infotype_voter info;
    adr_voter next;
    adr_voter prev;
};

//Semua list program
struct list_peserta
{
    adr_peserta first;
    adr_peserta last;
};

struct list_voter
{
    adr_voter first;
    adr_voter last;
};

// strutur data utama
struct setting
{
    int menu;
    list_peserta LP;
    list_voter LV;
    infotype_peserta IP;
    infotype_voter IV;
    adr_peserta AP;
    adr_voter AV;
    adr_voting AI;
};

//struktur data program aplikasi
struct Type_User
{
    string Nama;
    string Alamat;
    string Asal;
    type_tanggal_lahir tanggal_lahir;
    int umur;
    string email;
    string Username;
    string password;
};

struct Program
{
    Type_User user[100];
    int NoCounter;
    int ID_User;
};

//Daftar Login
void P_DafterVoting(setting &S,Program &P);
Type_User F_IsiDaftarVoting(Program &P);
void P_Login(Program &P,setting &S);

//Proses voting
void AllProsesProgram();
void SystemProses(int system, setting &S,Program &P);
void PembukaanProgram();

//Menu voting
void P_MenuPembuka(setting &S,Program &P);
int F_MenuAcara(setting S);
void P_MenuAcara(setting &S);
int F_MenuInsert(setting S);
void P_MenuInsert(setting &S);
int F_MenuInsertPeserta(int sistem,setting S);
void P_MenuInsertPeserta(int sistem,setting &S);
int F_MenuInsertVoting(int sistem,setting S);
void P_MenuInsertVoting(int sistem,setting &S);
int F_MenuDelete(setting S);
void P_MenuDelete(setting &S);
void P_MenuDeletePeserta(int sistem,setting &S);
void P_MenuDeleteVoting(setting &S);
void P_MenuDeleteVoter(setting &S);
void P_MenuSearchVoting(setting &S);
int F_MenuUpdate(setting S);
void P_MenuUpdate(setting &S);
int F_MenuUpdatePeserta(setting S);
void P_MenuUpdatePeserta(setting &S);
void P_MenuUpdateVoter(setting &S);
void P_MenuView(setting &S);
void P_MenuReport(setting &S);
void P_Error(int sistem);

//Insert Voting
infotype_peserta F_InputanPeserta(infotype_peserta IP);
void P_InsertPeserta(setting &S);
infotype_voter F_InputanVoter(infotype_voter IV);
void P_InsertVoter(setting &S);
string F_inputanVoting(setting S);
void P_InsertVoting(setting &S);

//Delete Voting
void P_DeletePeserta(setting &S);
void P_DeleteVoting(setting &S);
void P_DeleteVoter(setting &S);

//Update Voting
void UpdatePeserta(setting &S);
void UpdateVoter(setting &S);

//Search Voting
void P_SeacrhPeserta(setting S,string NamaSearching);

//Report Voting
void P_ReportVoting(setting S);

//SLL voting
void P_CreateListSLL(list_peserta &LP);
bool F_isEmptyListSLL(list_peserta LP);
adr_peserta F_AlokasiSLL(infotype_peserta IP);
adr_peserta F_DealokasiSLL(adr_peserta P);
void P_InsertAscendingSLL(list_peserta &LP, adr_peserta AP);
void P_DeleteAfterSLL(list_peserta &LP,string hapus);

//MCDLL voting
void P_CreateListMCDLL(adr_peserta &AP);
bool F_isEmptyListMCDLL(adr_peserta AP);
adr_voting F_AlokasiMCDLL(setting S);
adr_voting F_DealokasiMCDLL(adr_voting P);
void P_InsertLastMCDLL(list_peserta &LP,list_voter &LV,adr_voting AI,adr_voter AV);
void P_DeleteMCDLL(list_peserta &LP,string hapus);

//DLL Voting
void P_CreateListDLL(list_voter &LV);
bool F_isEmptyListDLL(list_voter LV);
adr_voter F_AlokasiDLL(infotype_voter IV);
adr_voter F_DealokasiDLL(adr_voter AV);
void P_InsertFirstDLL(list_voter &LV,adr_voter AV);
void P_DeleteLastDLL(list_voter &LV);

//Print voting
void P_PrintInfo(int system,setting S);

//FileDat Voting
void SaveDataVoting(Program P,setting S);
void LoadDataVoting(Program P,setting S);

#endif // HEADERVOTING_H_INCLUDED
