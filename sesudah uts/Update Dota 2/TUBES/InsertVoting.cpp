#include "HeaderVoting.h"

infotype_peserta F_InputanPeserta(infotype_peserta IP)
{
    cout<<"Masukkan ID Peserta      : ";        cin>>IP.id;                      cout<<endl;
    cout<<"Masukkan Nama Peserta    : ";        cin>>IP.nama;                    cout<<endl;
    cout<<"Masukkan Alamat Peserta  : ";        cin>>IP.alamat;                  cout<<endl;
    cout<<"Masukkan Asal Peserta    : ";        cin>>IP.asal;                    cout<<endl;
    cout<<"Masukkan Tanggal Lahir Peserta : ";                                   cout<<endl;
    cout<<"Masukkan Tanggal : ";                cin>>IP.tanggal_lahir.tanggal;   cout<<endl;
    cout<<"Masukkan Bulan   : ";                cin>>IP.tanggal_lahir.bulan;     cout<<endl;
    cout<<"Masukkan Tahun   : ";                cin>>IP.tanggal_lahir.tahun;     cout<<endl;
    return IP;
}

void P_InsertPeserta(setting &S)
{
    S.IP = F_InputanPeserta(S.IP);
    S.AP = F_AlokasiSLL(S.IP);
    P_InsertAscendingSLL(S.LP,S.AP);
}

infotype_voter F_InputanVoter(infotype_voter IV)
{
    cout<<"Masukkan ID Voting : ";              cin>>IV.id;                      cout<<endl;
    cout<<"Masukkan Nama voting : ";            cin>>IV.nama;                    cout<<endl;
    cout<<"Masukkan Asal Voting : ";            cin>>IV.asal;                    cout<<endl;
    cout<<"Masukkan Umur Voting : ";            cin>>IV.umur;                    cout<<endl;

    return IV;
}

string F_inputanVoting(setting S)
{
    cout<<"Silahkan Pilih Nama Peserta : \n";

    P_PrintInfo(1,S);

    cout<<"Silhkan masukkan kode peserta yang anda pilih: ";

    string pilih;
    cin>>pilih;

    while ((S.LP.first!=NULL) and(S.LP.first->info.id!=pilih))
    {
        S.LP.first=S.LP.first->next;
    }

    if(S.LP.first->info.id==pilih)
    {
        return S.LP.first->info.nama;

    }
    else //dibenerin nanti pakai switch
        cout<<"Pilihan yang anda masukkan tidak valid";
}

void P_InsertVoter(setting &S)
{
    S.IV = F_InputanVoter(S.IV);
    S.AV = F_AlokasiDLL(S.IV);
    S.AI = F_AlokasiMCDLL(S);
    P_InsertLastMCDLL(S.LP,S.LV,S.AI,S.AV);


    //P_InsertVoterTambahan(S);
}

//void P_InsertVoterTambahan(setting &S)
//{

//}

void P_InsertVoting(setting &S)
{
    S.AI = F_AlokasiMCDLL(S);
    P_InsertLastMCDLL(S.LP,S.LV,S.AI,S.AV);
}
