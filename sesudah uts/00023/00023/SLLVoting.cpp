#include "HeaderVoting.h"
void P_CreateListSLL(list_peserta &l)
{
    l.first = NULL;
    l.last = NULL;
}
adr_peserta F_AlokasiSLL(infotype_peserta x)
{
    adr_peserta p =  new elm_peserta;
    p->info.id = x.id;
    p->info.nama = x.nama;
    p->info.alamat = x.alamat;
    p->info.asal = x.asal;
    p->info.tanggal_lahir = x.tanggal_lahir;
    p->next = NULL;
    return p;
}
adr_peserta F_DealokasiSLL(adr_peserta &p)
{
    delete p;
    return p;
}
void P_InsertFirslSLL(list_peserta &l, adr_peserta p)
{
    if (l.first == NULL)
    {
        l.first = p;
    }
    else
    {
        p->next = l.first;
        l.first = p;
    }
}
void P_InsertLastSLL(list_peserta &l, adr_peserta p)
{
    if (l.first == NULL)
    {
        l.first = p;
    }
    else
    {
        adr_peserta q = l.first;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}
void P_InsertAfterSLL()
{

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
