#include "HeaderVoting.h"

void P_PrintInfo(int sistem,setting S)
{
    switch(sistem)
    {
    case 1 :
        {
            cout<<"List Peserta : \n";
            cout<<"KODE : NAMA  \n"
                <<"------------------ \n";
            while (S.LP.first != NULL)
                {
                    cout<<S.LP.first->info.id <<" : " <<S.LP.first->info.nama <<endl;
                    S.LP.first=S.LP.first->next;
                }
        }break;
    case 2 :
        {
            adr_peserta AP=S.LP.first;
            while(AP != NULL)
            {
                cout<<"Berikut ini merupakan Data list Peserta dan yang voting \n"
                    <<"ID            : " <<AP->info.id <<"\n"
                    <<"Nama          : " <<AP->info.nama <<"\n"
                    <<"Alamat        : " <<AP->info.alamat <<"\n"
                    <<"Asal          : " <<AP->info.asal <<"\n"
                    <<"Tanggal Lahir : " <<AP->info.tanggal_lahir.tanggal <<" "
                    <<AP->info.tanggal_lahir.bulan <<" "
                    <<AP->info.tanggal_lahir.tahun <<"\n\n";

                if(AP->first_list_voting!=NULL)
                {
                    adr_voting AV1 = AP->first_list_voting;
                    adr_voting AV2 = AP->last_list_voting;
                    cout<<"Berikut merupakan list voting yang memilih peserta diatas : \n";
                    while(AV1->list_voter->info.id!=AV2->list_voter->info.id)
                    {
                        cout<<"Nama Pemilih : " <<AV1->list_voter->info.nama <<"\n";
                        AV1=AV1->next;
                    }
                    cout<<"Nama Pemilih : " <<AV1->list_voter->info.nama <<"\n";
                }
                else
                {
                    cout<<"List voting masih dalam keadaan kosong \n";
                }
                AP=AP->next;
            }
            system("PAUSE");
        }break;
    case 3 :
        {
            cout<<"Berikut list dari Voter \n";
            adr_voter AV=S.LV.first;

            if(AV!=NULL)
            {
                while(AV!=NULL)
                {
                    cout<<"Nama : "<<AV->info.nama <<endl;
                    AV=AV->next;
                }
            }
            else
            {
                cout<<"List voting masih dalam keadaan kosong \n";
            }
            system("PAUSE");
        }break;
    case 4 :
        {
            cout<<"Berikut list dari Peserta \n";
            adr_peserta AP=S.LP.first;
            while (AP != NULL)
            {
                cout<<"Nama : " <<AP->info.nama <<endl;
                AP=AP->next;
            }

            cout<<"\n \n Berikut list dari Voter \n";
            adr_voter AV=S.LV.first;

            if(AV!=NULL)
            {
                while(AV!=NULL)
                {
                    cout<<"Nama : " <<AV->info.nama <<endl;
                    AV=AV->next;
                }
            }
            else
            {
                cout<<"List voting masih dalam keadaan kosong \n";
            }
            system("PAUSE");
        }break;
    case 5 :
        {
            cout<<"Berikut list dari Peserta \n";
            adr_peserta AP=S.LP.first;
            while (AP != NULL)
            {
                cout<<"Nama : " <<AP->info.nama <<endl;
                AP=AP->next;
            }
            system("PAUSE");
        }break;
    }
}

