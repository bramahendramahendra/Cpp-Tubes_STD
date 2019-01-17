#include "HeaderVoting.h"

void P_SeacrhPeserta(setting S,string NamaSearching)
{
    if(S.LP.first!=NULL)
    {

    while((S.LP.first->info.nama!=NamaSearching)&&(S.LP.first!=NULL))
        S.LP.first=S.LP.first->next;
    if(S.LP.first->info.nama==NamaSearching)
    {
        cout<<"ID Peserta     : " <<S.LP.first->info.id     <<endl;
        cout<<"Nama Peserta   : " <<S.LP.first->info.nama   <<endl;
        cout<<"Asal Peserta   : " <<S.LP.first->info.asal   <<endl;
        cout<<"Alamat Peserta : " <<S.LP.first->info.alamat <<endl;
        cout<<"Berikut Hasil Data Voting : ";
        if(S.LP.first->first_list_voting!=NULL)
        {
            while(S.LP.first->first_list_voting->list_voter->info.id!=S.LP.first->last_list_voting->list_voter->info.id)
            {
                cout<<"id Voting   : ; " <<S.LP.first->first_list_voting->list_voter->info.id   <<endl;
                cout<<"Nama Voting : ; " <<S.LP.first->first_list_voting->list_voter->info.nama <<endl;
                cout<<"Asal Voting : ; " <<S.LP.first->first_list_voting->list_voter->info.asal <<endl;
                cout<<"Umur Voting : ; " <<S.LP.first->first_list_voting->list_voter->info.umur <<endl;
                S.LP.first->first_list_voting=S.LP.first->first_list_voting->next;
            }
            cout<<"id Voting   : ; " <<S.LP.first->first_list_voting->list_voter->info.id   <<endl;
            cout<<"Nama Voting : ; " <<S.LP.first->first_list_voting->list_voter->info.nama <<endl;
            cout<<"Asal Voting : ; " <<S.LP.first->first_list_voting->list_voter->info.asal <<endl;
            cout<<"Umur Voting : ; " <<S.LP.first->first_list_voting->list_voter->info.umur <<endl;
        }
    }
    else
    {
        P_Error(1);
        P_SeacrhPeserta(S,NamaSearching);
    }
    }
    else
    {
        cout<<"Data peserta masih belum terisi dan dalam keadaan kosong ";
    }

    system("PAUSE");
    system("CLS");
}
