#include "HeaderVoting.h"

void P_ReportVoting(setting S)
{
    int voting=0;
    while(S.LP.first != NULL)
    {
        cout<<"Berikut ini merupakan Data list Peserta dan Jumlah voting \n"
            <<"Nama          : " <<S.LP.first->info.nama <<"\n";

        if(S.LP.first->first_list_voting!=NULL)
        {
            cout<<"Berikut merupakan list voting yang memilih peserta diatas : \n";
            while(S.LP.first->first_list_voting->list_voter->info.id!=S.LP.first->last_list_voting->list_voter->info.id)
            {
                ++voting;
                S.LP.first->first_list_voting=S.LP.first->first_list_voting->next;
            }
            cout<<"Jumlah yang Vote = " <<++voting;
        }
        else
        {
            cout<<"Jumlah yang Vote = 0";
        }
        S.LP.first=S.LP.first->next;
        cout<<endl;
    }
    cout<<endl;
    system("PAUSE");
}
