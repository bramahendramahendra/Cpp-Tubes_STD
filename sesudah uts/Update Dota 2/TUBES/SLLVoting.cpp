#include "HeaderVoting.h"

void P_CreateListSLL(list_peserta &LP)
{
    LP.first = NULL;
    LP.last = NULL;
}

bool F_isEmptyListSLL(list_peserta LP)
{
    if ((LP.first == NULL)&&(LP.last == NULL))
        return true;

    else
        return false;
}

adr_peserta F_AlokasiSLL(infotype_peserta IP)
{
    adr_peserta AP =  new elm_peserta;

    AP->info.id = IP.id;
    AP->info.nama = IP.nama;
    AP->info.alamat = IP.alamat;
    AP->info.asal = IP.asal;
    AP->info.tanggal_lahir = IP.tanggal_lahir;

    P_CreateListMCDLL(AP);

    AP->next = NULL;

    return AP;
}

adr_peserta F_DealokasiSLL(adr_peserta P)
{
    delete P;

    return P;
}

void P_InsertAscendingSLL(list_peserta &LP, adr_peserta AP)
{
    if(F_isEmptyListSLL(LP))
    {
        LP.first = AP;
        LP.last = AP;
    }
    else
    {
        if(AP->info.nama < LP.first->info.nama)
        {
            AP->next=LP.first;
            LP.first=AP;
        }
        else if(AP->info.nama > LP.last->info.nama)
        {
            LP.last->next=AP;
            LP.last=LP.last->next;
        }
        else
        {
            while (AP->info.nama > LP.first->next->info.nama)
                LP.first=LP.first->next;
            AP->next=LP.first->next;
            LP.first->next=AP;
        }
    }
}

void P_DeleteAfterSLL(list_peserta &LP,string hapus)
{
    if(F_isEmptyListSLL(LP))
        cout<<"List Peserta masih dalam keadaan kosong. Silahkan input dahulu";
    else
    {
        adr_peserta AP;
        if(LP.first->next!=NULL)
        {
            AP=LP.first;
            LP.first=NULL;
            LP.last=NULL;
            F_DealokasiSLL(AP);
        }
        else
        {
            adr_peserta temp=LP.first;
            while ((hapus!=temp->info.id)and(temp!=NULL))
                temp=temp->next;
            if(hapus==temp->info.id)
            {
                AP=temp;
                temp=temp->next;
                F_DealokasiSLL(AP);
            }
            else
                cout<<"Data yang anda masukkan tidak valid";
        }
    }
}
