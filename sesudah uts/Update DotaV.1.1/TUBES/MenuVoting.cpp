#include "HeaderVoting.h"

void P_MenuPembuka(setting &S,Program &P)
{
    system("CLS");
    cout<<"----------------------------------\n"
        <<" Silahkan Pilih Menu di bawah ini \n"
        <<"----------------------------------\n"
        <<"1. Login  \n"
        <<"2. Daftar \n"
        <<"3. Voting \n"
        <<">> ";

    cin>> S.menu;

    switch(S.menu)
    {
    case 1 :
        {
            P_Login(P,S);
        }break;
    case 2 :
        {
            system("CLS");
            P_DafterVoting(S,P);
        }break;
    case 3 :
        {
            P_MenuAcara(S);
            P_MenuPembuka(S,P);
        }break;
    default :
        {
            P_Error(0);
            P_MenuPembuka(S,P);
        }break;
    }
}

int F_MenuAcara(setting S)
{
    system("CLS");
    cout<<"Silahkan Pilih menu \n"
        <<"1. Insert  \n"
        <<"2. Delete \n"
        <<"3. Update \n"
        <<"4. Search \n"
        <<"5. View \n"
        <<"6. Report \n"
        <<"0. Exit \n"
        <<"Pilih menu nomor : \n"
        <<">> ";

    cin>>S.menu;
    system("cls");

    return S.menu;
}

void P_MenuAcara(setting &S)
{
    switch (F_MenuAcara(S))
    {
        case 1 : {P_MenuInsert(S);}break;
        case 2 : {
            if(F_isEmptyListSLL(S.LP))
            {
                cout<<"Data masih dalam keadaan kosong" <<endl;
                system("PAUSE");
                system("CLS");
                P_MenuAcara(S);
            }
            else
                P_MenuDelete(S);
        }break;
        case 3 : {
            if(F_isEmptyListSLL(S.LP))
            {
                cout<<"Data masih dalam keadaan kosong" <<endl;
                system("PAUSE");
                system("CLS");
                P_MenuAcara(S);
            }
            else
            {
                P_MenuUpdate(S);
            }
        }break;
        case 4 : {
            if(F_isEmptyListSLL(S.LP))
            {
                cout<<"Data masih dalam keadaan kosong" <<endl;
                system("PAUSE");
                system("CLS");
                P_MenuAcara(S);
            }
            else
            {
                P_MenuSearchVoting(S);
            }
        }break;
        case 5 : {
            if(F_isEmptyListSLL(S.LP))
            {
                cout<<"Data masih dalam keadaan kosong" <<endl;
                system("PAUSE");
                system("CLS");
                P_MenuAcara(S);
            }
            else
            {
                P_MenuView(S);P_MenuAcara(S);
            }
        }break;
        case 6 : {
            if(F_isEmptyListSLL(S.LP))
            {
                cout<<"Data masih dalam keadaan kosong" <<endl;
                system("PAUSE");
                system("CLS");
                P_MenuAcara(S);
            }
            else
            {
                P_MenuReport(S);P_MenuAcara(S);
            }
        }break;
        case 0 : {exit(0);} break;
        default :{P_Error(0);P_MenuAcara(S);}break;
    }
}

//Bagian Insert
int F_MenuInsert(setting S)
{
    system("CLS");
    cout <<"Silahkan Pilih Menu Input \n"
         <<"1. Insert Peserta \n"
         <<"2. Insert Voting \n"
         <<"0. Back \n"
         <<">> ";

    cin>>S.menu;
    system("CLS");

    return S.menu;
}

void P_MenuInsert(setting &S)
{
    switch (F_MenuInsert(S))
    {
        case 1 : {P_MenuInsertPeserta(1,S);}break;
        case 2 : {
            if(S.LP.first!=NULL)
                P_MenuInsertVoting(1,S);
            else
                cout<<"Dats masih dalam keadaan kosong";
            }break;
        case 0 : {P_MenuAcara(S);}break;
        default : {P_Error(0);P_MenuInsert(S);}break;
    }
}

int F_MenuInsertPeserta(int sistem,setting S)
{
    switch (sistem)
    {
    case 1 :
        {
            system("CLS");
            cout<<"Silahkan isi Biodata peserta dibawah ini : "
                <<endl;
        } break;
    case 2 :
        {
            system("CLS");
            P_PrintInfo(1,S);
            cout<<"Data yang sudah anda isi telah tersimpan \n"
                <<"Apakah anda ingin mengisi Data Peserta kembali : \n"
                <<"1.yes        2.no   \n"
                <<">> ";
            cin>>S.menu;
            system("CLS");
            return S.menu;
        }
    }
}

void P_MenuInsertPeserta(int sistem,setting &S)
{
    switch (sistem)
    {
        case 1 :
            {
                F_MenuInsertPeserta(1,S);
                P_InsertPeserta(S);
                P_MenuInsertPeserta(2,S);
            }break;
        case 2 :
            {
                switch (F_MenuInsertPeserta(2,S))
                {
                    case 1 : {P_MenuInsertPeserta(1,S);}break;
                    case 2 : {P_MenuInsert(S);}break;
                    default : {P_Error(0);P_MenuInsertPeserta(2,S);}break;
                }
            }break;
    }
}

int F_MenuInsertVoting(int sistem,setting S)
{
    switch (sistem)
    {
    case 1 :
        {
            cout<<"Silahkan isi Biodata Voting dibawah ini : "
                <<endl;
        } break;
    case 2 :
        {
            system("CLS");
            cout<<"Anda telah memilih peserta dalam voing ini dan telah tersimpan \n"
                <<"Silahkan pilih menu selanjutnya : \n"
                <<"1.Tambah Voting   \n"
                <<"2.Voting Peserta lain   \n"
                <<"3.kembali ke menu insert   \n"
                <<">> ";
            cin>>S.menu;
            return S.menu;
        }
    }
}

void P_MenuInsertVoting(int sistem,setting &S)
{
    switch (sistem)
    {
    case 1 :
        {
            F_MenuInsertVoting(1,S);
            P_InsertVoter(S);
            P_MenuInsertVoting(2,S);
        } break;
    case 2 :
        {
            switch (F_MenuInsertVoting(2,S))
            {
            case 1 : {P_MenuInsertVoting(1,S);} break;
            case 2 : {P_InsertVoting(S); P_MenuInsertVoting(2,S);} break;
            case 3 : {P_MenuInsert(S);} break;
            default : {P_Error(0);P_MenuInsertVoting(1,S);} break;
            }
        }break;
    default: break;
    }
}

//Bagian Delete
int F_MenuDelete(setting S)
{
    system("CLS");
    cout <<"Silahkan Pilih Menu Delete \n"
         <<"1. Delete Peserta \n"
         <<"2. Delete Voting \n"
         <<"3. Delete Voter \n"
         <<"0. Back \n"
         <<">> ";

    cin>>S.menu;
    system("CLS");

    return S.menu;
}

void P_MenuDelete(setting &S)
{
    switch (F_MenuDelete(S))
    {
        case 1 : {P_MenuDeletePeserta(1,S);}break;
        case 2 : {P_MenuDeleteVoting(S);}break;
        case 3 : {P_MenuDeleteVoter(S);} break;
        case 0 : {P_MenuAcara(S);}break;
        default : {P_Error(0);P_MenuDelete(S);}break;
    }
}


void P_MenuDeletePeserta(int sistem,setting &S)
{
    switch (sistem)
    {
    case 1 :
        {
            cout<<"Silahkan masukkan id data yang ingin di hapus : ";
            P_DeletePeserta(S);
        }break;
    case 2 :
        {
            cout<<"Anda Telah menghapus data"
                <<"Tekan enter untuk kembali ke menu Delete ";
            system("CLS");
            P_MenuDelete(S);
        }
    }
}


void P_MenuDeleteVoting(setting &S)
{
    cout<<"Semua data voting akan di delete \n"
        <<"Silahkan tuliskan id peserta : \n";
    P_DeleteVoting(S);
    P_MenuDelete(S);
}

void P_MenuDeleteVoter(setting &S)
{
    cout<<"Data Voter yang paling lama akan di delete \n"
        <<"Apakah anda yakin ingin mendelet data tersebut \n"
        <<"1. yes   2.no";
    cin>>S.menu;

    switch(S.menu)
    {
        case 1 : {P_DeleteVoter(S);P_MenuDelete(S);} break;
        case 2 : {P_MenuDelete(S);} break;
        default : {P_Error(0);P_MenuDeleteVoter(S);} break;
    }
}

//Bagian Search
void P_MenuSearchVoting(setting &S)
{
    string NamaSearching;
    cout<<"Silahkan Masukkan nama peserta yang ingin dicari : ";
    cin>>NamaSearching;
    P_SeacrhPeserta(S,NamaSearching);
    P_MenuAcara(S);
}

//Bagian Update
int F_MenuUpdate(setting S)
{
    system("CLS");
    cout <<"Silahkan Pilih Menu Update \n"
         <<"1. Update Peserta \n"
         <<"2. Update Voter \n"
         <<"0. Back \n"
         <<">> ";

    cin>>S.menu;
    system("CLS");

    return S.menu;
}

void P_MenuUpdate(setting &S)
{
    switch(F_MenuUpdate(S))
    {
    case 1 : {P_MenuUpdatePeserta(S);} break;
    case 2 : {P_MenuUpdateVoter(S);} break;
    case 0 : {P_MenuAcara(S);} break;
    default : {P_Error(0);P_MenuUpdate(S);} break;
    }
}

void P_MenuUpdatePeserta(setting &S)
{
    cout<<"Silahkan masukkan id peserta yang ingin di Update : \n";
    UpdatePeserta(S);
}

void P_MenuUpdateVoter(setting &S)
{
    cout<<"Silahkan masukkan id voter yang ingin di Update : \n";
    UpdateVoter(S);
}


//Bagian View
void P_MenuView(setting &S)
{
    system("CLS");
    cout <<"Silahkan Pilih Menu View \n"
         <<"1. View Peserta \n"
         <<"2. View Voter \n"
         <<"3. View Peserta dan Voter \n"
         <<"0. Back \n"
         <<">> ";

    cin>>S.menu;
    system("CLS");

    switch(S.menu)
    {
    case 1 : {P_PrintInfo(5,S);P_MenuView(S);} break;
    case 2 : {P_PrintInfo(3,S);P_MenuView(S);} break;
    case 3 : {P_PrintInfo(4,S);P_MenuView(S);} break;
    case 0 : {P_MenuAcara(S);} break;
    default : {P_Error(0);P_MenuView(S);} break;
    }
}


//Bagian Report
void P_MenuReport(setting &S)
{
    system("CLS");
    cout <<"Silahkan Pilih Menu View \n"
         <<"1. Report Hasil Voting sementara \n"
         <<"2. Report Data yang Voting \n"
         <<"0. Back \n"
         <<">> ";

    cin>>S.menu;
    system("CLS");

    switch(S.menu)
    {
    case 1 : {P_ReportVoting(S);cout<<"Error : " <<S.LP.first->first_list_voting->list_voter->info.id; system("PAUSE");P_MenuReport(S);} break;
    case 2 : {P_PrintInfo(2,S);P_MenuReport(S);} break;
    case 0 : {P_MenuAcara(S);} break;
    default : {P_Error(0);P_MenuReport(S);} break;
    }
}

//Bagian Error
void P_Error(int sistem)
{
    switch(sistem)
    {
    case 0 :
        {
            system("CLS");
            cout<<"Angka yang anda masukkan salah \n"
                <<"Tekan ENTER untuk kembali ke menu semula \n";
            system("PAUSE");
            system("CLS");
        }break;
    case 1 :
        {
            system("CLS");
            cout<<"Maaf nama yang anda cari tidak ditemukan silahkan masukkan nama dengan benar ";
            system("PAUSE");
            system("CLS");
        }break;
    case 2 :
        {
            system("CLS");
            cout<<"Maaf ID Peserta yang anda cari tidak ditemukan \n"
                <<"Silahkan Coba lagi \n";
            system("PAUSE");
            system("CLS");
        }break;
    case 3 :
        {
            system("CLS");
            cout<<"Maaf ID Voter yang anda cari tidak ditemukan \n"
                <<"Silahkan Coba lagi \n";
            system("PAUSE");
            system("CLS");
        }break;
    }

}
