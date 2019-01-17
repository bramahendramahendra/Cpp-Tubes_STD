#include "HeaderVoting.h"

void AllProsesProgram()
{
    setting S;
    Program P;

    SystemProses(1,S,P);
    SystemProses(2,S,P);
}

void SystemProses(int system, setting &S,Program &P)
{
    switch(system)
    {
    case 1 :
        {
            PembukaanProgram();
            P_CreateListSLL(S.LP);
            P_CreateListDLL(S.LV);
            P.NoCounter=0;
        } break;
    case 2 :{P_MenuPembuka(S,P);} break;
    default : break;
    };
}


void PembukaanProgram()
{
    cout<<"   Selamat Datang di Program Kami    \n"
        <<"         yang bertemakan             \n"
        <<endl
        <<"       Peserta<Voting>Voter          \n"
        <<"        Kami dari Kelompok 3         \n"
        <<"           Kelas IF 39 03            \n"
        <<endl
        <<"              Anggota :              \n"
        <<"         BRAMA HENDRA MAHENDRA       \n"
        <<"         ARIS AFRIANTO               \n";

    cout<<endl;
    cout<<endl;
    cout<<endl;

    system("PAUSE");
    system("CLS");
}
