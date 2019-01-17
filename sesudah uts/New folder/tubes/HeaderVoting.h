#ifndef HEADERVOTING_H_INCLUDED
#define HEADERVOTING_H_INCLUDED

#include <iostream>
#include <conio.h>
using namespace std;
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

typedef elm_peserta *adr_peserta;

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

typedef elm_voter *adr_voter
{
    infotype_voter info;
    adr_voter next;
    adr_voter prev;
};

typedef elm_voting *adr_voting
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

#endif // HEADERVOTING_H_INCLUDED
