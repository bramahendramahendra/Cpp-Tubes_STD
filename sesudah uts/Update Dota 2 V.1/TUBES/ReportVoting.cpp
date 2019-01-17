#include "HeaderVoting.h"

void P_ReportVoting(setting S)
{

    int voting=0;
    adr_peserta AP=S.LP.first;
    while( AP!= NULL)
    {
        cout<<"Berikut ini merupakan Data list Peserta dan Jumlah voting \n"
            <<"Nama          : " <<AP->info.nama <<"\n";

        if(AP->first_list_voting!=NULL)
        {
            adr_voting AV1=AP->first_list_voting;
            adr_voting AV2=AP->last_list_voting;
            while(AV1->list_voter->info.id!=AV2->list_voter->info.id)
            {
                ++voting;
                AV1=AV1->next;
            }
            cout<<"Jumlah yang Vote = " <<++voting;
        }
        else
        {
            cout<<"Jumlah yang Vote = 0";
        }
        AP=AP->next;
        cout<<endl;
    }
    cout<<endl;
    system("PAUSE");
}
