#include "HeaderVoting.h"

void P_DeletePeserta(setting &S)
{
    string hapus;
    cin>>hapus; cout<<endl;

    P_DeleteAfterSLL(S.LP,hapus);
    P_MenuDeletePeserta(2,S);
}

void P_DeleteVoting(setting &S)
{
    string hapus;
    cin>>hapus;
    P_DeleteMCDLL(S.LP,hapus);
}

void P_DeleteVoter(setting &S)
{
    if(F_isEmptyListDLL(S.LV))
    {
        cout<<"List dalam keadaan kosong ";
        system("PAUSE");
        system("CLS");
    }
    else
    {
        P_DeleteLastDLL(S.LV);
        P_PrintInfo(3,S);
    }
}
