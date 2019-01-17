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
        while ((hapus!=LP.first->info.id)and(LP.first!=NULL))
            LP.first=LP.first->next;
        if(hapus==LP.first->info.id)
        {
            adr_peserta AP=LP.first;
            LP.first=LP.first->next;
            F_DealokasiSLL(AP);
        }
        else
            cout<<"Data yang anda masukkan tidak valid";
    }
}



/*void P_InsertEmptySLL(list_peserta &L, adr_peserta P)
{
    L.first = P;
    L.last = P;
}

void P_InsertFirstSLL(list_peserta &L, adr_peserta P)
{
    if (F_isEmptyListSLL(L))
    {
        P_InsertEmptySLL(L,P);
    }
    else
    {
        P->next = L.first;
        L.first = P;
    }
}

void P_InsertLastSLL(list_peserta &L, adr_peserta P)
{
    if (F_isEmptyListSLL(L))
    {
        P_InsertEmptySLL(L,P);
    }
    else
    {
        adr_peserta Q = L.first;
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}



void P_DeleteFirstSLL(list_peserta &l, adr_peserta &p)
{
    if(l.first ==NULL)
    {
        cout<<"Kosong";
    }
    else
    {
        p = l.first;
        l.first = p->next;
        p = p->next;
        F_DealokasiSLL(p);
    }
}
void P_DeleteLastSLL(list_peserta &l, adr_peserta &p)
{
    if (l.first == NULL)
    {

    }
    else
    {
        adr_peserta q = l.first;
        if (p->next == NULL)
        {
            l.first = NULL;
        }
        else
        {
            while (q->next->next != NULL)
            {
                q = q->next;
            }
            p = q->next;
            q->next = NULL;
            F_DealokasiSLL(p);
        }
    }
}

void P_DeleteAfterSLL()
{

}
void PrintInfoSLL(list_peserta L)
{
    adr_peserta output = L.first;
    while (output!=NULL)
    {
        cout<<output->info.id;
        cout<<output->info.nama;
        cout<<output->info.alamat;
        cout<<output->info.asal;
        output=output->next;
        cout<<endl;
    }

}
*/
