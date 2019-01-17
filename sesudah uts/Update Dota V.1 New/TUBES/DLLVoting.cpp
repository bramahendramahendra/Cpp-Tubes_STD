#include "HeaderVoting.h"

void P_CreateListDLL(list_voter &LV)
{
    LV.first=NULL;
    LV.last=NULL;
}

bool F_isEmptyListDLL(list_voter LV)
{
    if ((LV.first == NULL)&&(LV.last == NULL))
        return true;
    else
        return false;
}

adr_voter F_AlokasiDLL(infotype_voter IV)
{
    adr_voter AV =  new elm_voter;
    AV->info.id = IV.id;
    AV->info.nama = IV.nama;
    AV->info.asal = IV.asal;
    AV->info.umur = IV.umur;
    AV->next = NULL;
    AV->prev = NULL;
    return AV;
}

adr_voter F_DealokasiDLL(adr_voter AV)
{
    delete AV;

    return AV;
}

void P_InsertFirstDLL(list_voter &LV,adr_voter AV)
{
    if(F_isEmptyListDLL(LV))
    {
        LV.first=AV;
        LV.last=AV;
    }
    else
    {
        bool status=false;
        adr_voter temp = LV.first;
        while(status != true)
        {
            if(temp==NULL)
                status=true;
            else if(temp->info.id==AV->info.id)
                status=true;
            else
                temp=temp->next;
        }
        if(temp==NULL)
        {
            AV->next=LV.first;
            LV.first->prev=AV;
            LV.first=AV;
            cout<<"coba:"<<LV.first->info.id;
        }
    }
}

void P_DeleteLastDLL(list_voter &LV)
{
    adr_voter AV;
    if(LV.first->next!=NULL)
    {
        AV = LV.first;
        LV.first=NULL;
        F_DealokasiDLL(AV);
    }
    else
    {
        while(LV.first->next->next!=NULL)
            LV.first=LV.first->next;
        AV = LV.first->next;
        LV.first->next=NULL;
        F_DealokasiDLL(AV);
    }

}
