#ifndef HEADERVOTING_H_INCLUDED
#define HEADERVOTING_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

typedef struct elm_voter *adr_voter;
typedef struct elm_voting *adr_voting;
typedef struct elm_peserta *adr_peserta;

struct type_tanggal_lahir
{
    string tanggal;
    string bulan;
    string tahun;
};

struct infotype_peserta
{
    string id;
    string nama;
    string alamat;
    string asal;
    type_tanggal_lahir tanggal_lahir;
};

struct elm_peserta
{
    infotype_peserta info;
    adr_peserta next;
    adr_voting first_list_voting;
    adr_voting last_list_voting;
};

struct infotype_voter
{
    string id;
    string nama;
    string asal;
    string umur;
};

struct elm_voter
{
    infotype_voter info;
    adr_voter next;
    adr_voter prev;
};

struct elm_voting
{
    adr_voter list_voter;
    adr_voting next;
    adr_voting last;
};

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

void P_CreateListSLL(list_peserta &l);
adr_peserta F_AlokasiSLL(infotype_peserta x);
adr_peserta F_DealokasiSLL(adr_peserta &p);
void P_InsertFirslSLL(list_peserta &l, adr_peserta p);
void P_InsertLastSLL(list_peserta &l, adr_peserta p);
void P_InsertAfterSLL();
void P_DeleteFirstSLL(list_peserta &l, adr_peserta &p);
void P_DeleteLastSLL(list_peserta &l, adr_peserta &p);
void P_DeleteAfterSLL();

#endif // HEADERVOTING_H_INCLUDED
