#include "HeaderVoting.h"

void UpdatePeserta(setting &S)
{

    if(S.LP.first!=NULL)
    {
        string IDUpdate;
        int pilihan;

        cin>>IDUpdate;
        while((IDUpdate!=S.LP.first->info.id)&&(S.LP.first!=NULL))
            S.LP.first=S.LP.first->next;
        if(IDUpdate==S.LP.first->info.id)
        {
            cout<<"ID Peserta     : " <<S.LP.first->info.id     <<endl;
            cout<<"Nama Peserta   : " <<S.LP.first->info.nama   <<endl;
            cout<<"Asal Peserta   : " <<S.LP.first->info.asal   <<endl;
            cout<<"Alamat Peserta : " <<S.LP.first->info.alamat <<endl<<endl;

            cout<<"Silahkan pilih data yang ingin di update \n"
                <<"1.Nama \n"
                <<"2.Asal \n"
                <<"3.Alamat \n"
                <<">> ";
            cin>>pilihan;

            switch(pilihan)
            {
            case 1 :
            {
                cout<<"Silahkan masukkan Nama Baru : ";
                cin>>S.LP.first->info.nama;
                cout<<endl;
            }
            break;
            case 2 :
            {
                cout<<"Silahkan masukkan Asal Baru : ";
                cin>>S.LP.first->info.asal;
                cout<<endl;
            }
            break;
            case 3 :
            {
                cout<<"Silahkan masukkan Alamat Baru : ";
                cin>>S.LP.first->info.alamat;
                cout<<endl;
            }
            break;
            }

            cout<<"Hasil Update data peserta : \n";
            cout<<"ID Peserta     : " <<S.LP.first->info.id     <<endl;
            cout<<"Nama Peserta   : " <<S.LP.first->info.nama   <<endl;
            cout<<"Asal Peserta   : " <<S.LP.first->info.asal   <<endl;
            cout<<"Alamat Peserta : " <<S.LP.first->info.alamat <<endl<<endl;

            system("PAUSE");
            system("CLS");
        }
        else
        {
            P_Error(2);
            UpdatePeserta(S);
        }
    }
    else
    {
        cout<<"Data dalam keadaan kosong " <<endl;
    }
    P_MenuUpdate(S);
}

void UpdateVoter(setting &S)
{
    if(S.LV.first!=NULL)
    {


        string IDUpdate;
        int pilihan;

        cin>>IDUpdate;
        while((IDUpdate!=S.LV.first->info.id)&&(S.LV.first!=NULL))
            S.LV.first=S.LV.first->next;
        if(IDUpdate==S.LV.first->info.id)
        {
            cout<<"ID Peserta     : " <<S.LV.first->info.id   <<endl;
            cout<<"Nama Peserta   : " <<S.LV.first->info.nama <<endl;
            cout<<"Asal Peserta   : " <<S.LV.first->info.asal <<endl;
            cout<<"Alamat Peserta : " <<S.LV.first->info.umur <<endl<<endl;

            cout<<"Silahkan pilih data yang ingin di update \n"
                <<"1.Nama \n"
                <<"2.Asal \n"
                <<"3.Umur \n"
                <<">> ";
            cin>>pilihan;

            switch(pilihan)
            {
            case 1 :
            {
                cout<<"Silahkan masukkan Nama Baru : ";
                cin>>S.LV.first->info.nama;
                cout<<endl;
            }
            break;
            case 2 :
            {
                cout<<"Silahkan masukkan Asal Baru : ";
                cin>>S.LV.first->info.asal;
                cout<<endl;
            }
            break;
            case 3 :
            {
                cout<<"Silahkan masukkan Alamat Baru : ";
                cin>>S.LV.first->info.umur;
                cout<<endl;
            }
            break;
            }

            cout<<"Hasil Update data peserta : \n";
            cout<<"ID Peserta     : " <<S.LV.first->info.id     <<endl;
            cout<<"Nama Peserta   : " <<S.LV.first->info.nama   <<endl;
            cout<<"Asal Peserta   : " <<S.LV.first->info.asal   <<endl;
            cout<<"Umur Peserta   : " <<S.LV.first->info.umur <<endl<<endl;

            system("PAUSE");
            system("CLS");
        }
        else
        {
            P_Error(3);
            UpdateVoter(S);
        }
    }
    else
    {
        cout<<"Data dalam keadaan kosong " <<endl;
    }
    P_MenuUpdate(S);

}
