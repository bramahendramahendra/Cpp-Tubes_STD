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
            while(S.LP.first != NULL)
            {
                cout<<"Berikut ini merupakan Data list Peserta dan yang voting \n"
                    <<"ID            : " <<S.LP.first->info.id <<"\n"
                    <<"Nama          : " <<S.LP.first->info.nama <<"\n"
                    <<"Alamat        : " <<S.LP.first->info.alamat <<"\n"
                    <<"Asal          : " <<S.LP.first->info.asal <<"\n"
                    <<"Tanggal Lahir : " <<S.LP.first->info.tanggal_lahir.tanggal <<" "
                    <<S.LP.first->info.tanggal_lahir.bulan <<" "
                    <<S.LP.first->info.tanggal_lahir.tahun <<"\n\n";

                if(S.LP.first->first_list_voting!=NULL)
                {
                    cout<<"Berikut merupakan list voting yang memilih peserta diatas : \n";
                    while(S.LP.first->first_list_voting->list_voter->info.id!=S.LP.first->last_list_voting->list_voter->info.id)
                    {
                        cout<<"Nama Pemilih : " <<S.LP.first->first_list_voting->list_voter->info.nama <<"\n";
                        S.LP.first->first_list_voting=S.LP.first->first_list_voting->next;
                    }
                    cout<<"Nama Pemilih : " <<S.LP.first->first_list_voting->list_voter->info.nama <<"\n";
                }
                S.LP.first=S.LP.first->next;
            }
            system("PAUSE");
        }break;
    case 3 :
        {
            cout<<"Berikut list dari Voter";
            while(S.LV.first!=NULL)
            {
                cout<<"Nama : "<<S.LV.first->info.nama <<endl;
                S.LV.first=S.LV.first->next;
            }
            system("PAUSE");
        }break;
    case 4 :
        {
            cout<<"Berikut list dari Peserta \n";
            while (S.LP.first != NULL)
            {
                cout<<"Nama : " <<S.LP.first->info.nama <<endl;
                S.LP.first=S.LP.first->next;
            }
            cout<<"\n \n Berikut list dari Voter \n";
            while(S.LV.first!=NULL)
            {
                cout<<"Nama : " <<S.LV.first->info.nama <<endl;
                S.LV.first=S.LV.first->next;
            }
            system("PAUSE");
        }break;
    case 5 :
        {
            cout<<"Berikut list dari Peserta \n";
            while (S.LP.first != NULL)
            {
                cout<<"Nama : " <<S.LP.first->info.nama <<endl;
                S.LP.first=S.LP.first->next;
            }
            system("PAUSE");
        }break;
    }
}

