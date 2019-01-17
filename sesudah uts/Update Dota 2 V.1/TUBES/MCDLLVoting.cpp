#include "HeaderVoting.h"

void P_CreateListMCDLL(adr_peserta &AP)
{
    AP->first_list_voting = NULL;
    AP->last_list_voting = NULL;
}

bool F_isEmptyListMCDLL(adr_peserta AP)
{
    if ((AP->first_list_voting == NULL)&&(AP->last_list_voting == NULL))
        return true;
    else
        return false;
}

adr_voting F_AlokasiMCDLL(setting S)
{
    adr_voting AI = new elm_voting;
    AI->list_voter = S.AV;
    AI->namapilihan = F_inputanVoting(S);
    AI->next = NULL;
    AI->prev = NULL;

    return AI;
}

adr_voting F_DealokasiMCDLL(adr_voting P)
{
    delete P;
    return P;
}

void P_InsertLastMCDLL(list_peserta &LP,list_voter &LV,adr_voting AI,adr_voter AV)
{
    adr_peserta AP = LP.first;
    while(AP->info.nama!=AI->namapilihan)
    {
        AP=AP->next;
    }
    if(F_isEmptyListMCDLL(AP))
    {
        AP->first_list_voting = AI;
        AP->last_list_voting = AI;
        AP->first_list_voting->prev = AP->last_list_voting;
        AP->first_list_voting->next = AP->last_list_voting;
        AP->last_list_voting->next = AP->first_list_voting;
        AP->last_list_voting->prev = AP->first_list_voting;
        P_InsertFirstDLL(LV,AV);
    }
    else
    {

        AI->prev=AP->last_list_voting;
        AP->last_list_voting->next=AI;
        AP->last_list_voting=AI;
        AP->last_list_voting->next=AP->first_list_voting;
        AP->first_list_voting->prev=AP->last_list_voting;
        P_InsertFirstDLL(LV,AV);
    }
}

void P_DeleteMCDLL(list_peserta &LP,string hapus)
{
    while ((hapus!=LP.first->info.id)and(LP.first!=NULL))
           LP.first=LP.first->next;
    LP.first->first_list_voting=NULL;
    LP.first->last_list_voting=NULL;
}
