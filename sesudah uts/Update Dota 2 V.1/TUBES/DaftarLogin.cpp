#include "HeaderVoting.h"

Type_User F_IsiDaftarVoting(Program &P)
{
    Type_User T;
    T.Nama = "0";
    T.Username = "0";
    T.password = "0";
    T.Alamat = "0";
    T.Asal = "0";
    T.email = "0";
    T.umur = 0;

    int tanggal;
    bool status=false;
    bool perstatus=true;

    while(status!=true)
    {
        if(perstatus==true)
        {
            cout<<"Silahkan isi form daftar berikut ini : \n";
            if(T.Username == "0")
            {
                char kata[150];
                int jumlah,x;
                cout<<"Username : ";
                cin.getline(kata,sizeof(kata));
                jumlah=0;
                for(x=0; kata[x]; x++)
                    jumlah++;

                if(jumlah>=10)
                {
                    T.Username=kata[0];
                    for(x=1; kata[x]; x++)
                        T.Username=T.Username+kata[x];
                }
                else if(jumlah<10 && jumlah>0)
                {
                    system("CLS");
                    cout<<"Minimal 10 karakter untuk username";
                    perstatus=false;
                }
                else
                {
                    system("CLS");
                    perstatus =false;
                }
            }
            else
                cout<<"Username : "<<T.Username<<endl;
        }

        if(perstatus==true)
        {
            if(T.password == "0")
            {
                int jumlah;
                char pas;
                string password;

                cout<<"Password : ";
                pas= getch();
                jumlah=0;
                while(pas!=13)
                {
                    password.push_back(pas);
                    cout<<"*";
                    jumlah++;
                    pas=getch();
                }
                if(jumlah>=10)
                {
                    perstatus =true;
                    T.password=password;
                }
                else
                {
                    system("CLS");
                    cout<<"Minimal 10 karakter untuk password";
                    perstatus = false;
                }
                cout<<endl;
            }
            else
                cout<<"Password : " <<"**********"<<endl;
        }

        if(perstatus==true)
        {
            if(T.Nama == "0")
            {
                cout<<"Nama     : ";
                cin>>T.Nama;
            }
            else
                cout<<"Nama     : "<<T.Nama<<endl;
        }

        if(perstatus==true)
        {

            if(T.Alamat == "0")
            {
                cout<<"Alamat   : ";
                cin>>T.Alamat;
            }
            else
                cout<<"Alamat   : " <<T.Alamat<<endl;

        }

        if(perstatus==true)
        {
            if(T.Asal == "0")
            {
                cout<<"Asal     : ";
                cin>>T.Asal;
            }
            else
                cout<<"Asal     : " <<T.Asal<<endl;
        }


        if(perstatus==true)
        {
            if(T.email == "0")
            {
                cout<<"Email    : ";
                cin>>T.email;
            }
            else
                cout<<"Email    : " <<T.email<<endl;
        }

        if(perstatus==true)
        {
            cout<<"Tanggal Lahir " <<endl;

            bool booleantanggal=true;
            type_tanggal_lahir TT;
            int angka;
            string text;

            if(booleantanggal==true)
            {
                cout <<"Tanggal : ";
                cin>>TT.tanggal;
                cout<<endl;

                text = TT.tanggal;
                istringstream convertTA(text);
                if(!(convertTA>>angka))
                    angka=0;
                if(angka==0)
                {
                    cout<<"Data yang anda masukkan tidak valid ";
                    booleantanggal = false;
                }
                else if(angka>=31 && angka<1)
                {
                    cout<<"Tanggal yang anda masukkam salah";
                    booleantanggal = false;
                }
                else
                {
                    tanggal=angka;
                    booleantanggal = true;
                    T.tanggal_lahir.tanggal=TT.tanggal;
                }

            }

            if(booleantanggal==true)
            {
                cout <<"Bulan   : ";
                cin>>TT.bulan;
                cout<<endl;

                text = TT.bulan;
                istringstream convertTA(text);
                if(!(convertTA>>angka))
                    angka=0;
                if(angka==0)
                {
                    cout<<"Data yang anda masukkan tidak valid ";
                    booleantanggal = false;
                }
                else if(angka>=12 && angka<1)
                {
                    cout<<"Tanggal yang anda masukkam salah";
                    booleantanggal = false;
                }
                else
                {
                    if((angka==1)||(angka==3)||(angka==5)||(angka==7)||(angka==8)||(angka==10)||(angka==12))
                    {
                        if(tanggal<=31)
                        {
                            booleantanggal = true;
                            T.tanggal_lahir.bulan=TT.bulan;
                        }
                        else
                            booleantanggal = false;
                    }
                    else if((angka==4)||(angka==6)||(angka==9)||(angka==11))
                    {
                        if(tanggal<=30)
                        {
                            booleantanggal = true;
                            T.tanggal_lahir.bulan=TT.bulan;
                        }
                        else
                            booleantanggal = false;
                    }
                    else if(angka==2)
                    {
                        if(tanggal<=29)
                        {
                            booleantanggal = true;
                            T.tanggal_lahir.bulan=TT.bulan;
                        }
                        else
                            booleantanggal =false;
                    }
                }

            }

            if(booleantanggal==true)
            {
                cout <<"Tahun : ";
                cin>>TT.tahun;
                cout<<endl;

                text = TT.tahun;
                istringstream convertTA(text);
                if(!(convertTA>>angka))
                    angka=0;
                if(angka==0)
                {
                    cout<<"Data yang anda masukkan tidak valid ";
                    booleantanggal = false;
                }
                else if(angka<=1900)
                {
                    cout<<"Tanggal yang anda masukkam salah";
                    booleantanggal = false;
                }
                else
                {
                    booleantanggal = true;
                    T.tanggal_lahir.tahun=TT.tahun;
                }

            }

            if(booleantanggal==true)
            {
                perstatus = true;
                tanggal=angka;
            }
            else
                perstatus = false;
        }

        if(perstatus==true)
        {
            T.umur=2016-tanggal;
        }

        if(perstatus ==true)
            status=true;
        else
            perstatus=true;
    }
    return T;
}

void P_DafterVoting(setting &S,Program &P)
{
    Type_User T = F_IsiDaftarVoting(P);
    bool loop;

    do
    {
        system("CLS");
        cout<<"Apakah anda akan menyimpan data ini : "
            <<endl
            <<"Nama             : " <<T.Nama                <<endl
            <<"Username         : " <<T.Username            <<endl
            <<"Password         : " <<T.password            <<endl
            <<"Alama            : " <<T.Alamat              <<endl
            <<"Asal             : " <<T.Asal                <<endl
            <<"Email            : " <<T.email               <<endl
            <<"Tanggal Lahir    : " <<T.tanggal_lahir.tanggal <<" " <<T.tanggal_lahir.bulan <<" " <<T.tanggal_lahir.tahun <<endl
            <<"Umur             : " <<T.umur <<endl;

        cout<<endl
            <<"Apakah anda yakin ingin menyimpan data ini : \n"
            <<"1. yes   \n"
            <<"2. no    \n"
            <<">> ";
            cin>>S.menu;

            loop=false;

            if((S.menu==1)||(S.menu==2))
                loop=true;
    }
    while(loop!=true);

    switch(S.menu)
    {
    case 1 :
    {
        P.NoCounter++;
        P.user[P.NoCounter].Nama = T.Nama;
        P.user[P.NoCounter].Username = T.Username;
        P.user[P.NoCounter].password = T.password;
        P.user[P.NoCounter].Alamat = T.Alamat;
        P.user[P.NoCounter].Asal = T.Asal;
        P.user[P.NoCounter].email = T.email;
        P.user[P.NoCounter].tanggal_lahir.tanggal = T.tanggal_lahir.tanggal;
        P.user[P.NoCounter].tanggal_lahir.bulan = T.tanggal_lahir.bulan;
        P.user[P.NoCounter].tanggal_lahir.tahun = T.tanggal_lahir.tahun;
        P.user[P.NoCounter].umur = T.umur;

        P_MenuPembuka(S,P);
    }
    break;
    case 2 :
    {
        P_MenuPembuka(S,P);
    }
    break;
    }
}

void P_Login(Program &P,setting &S)
{
    system("CLS");
    cout<<"----------------------------------------------\n"
        <<" Silahkan Masukkan Username dan Password anda \n"
        <<"----------------------------------------------\n";

    string username,password;

    cout<<"Username : ";cin>> username; cout<<endl;

    char pas;
    cout<<"Password : "; pas= getch();

    while(pas!=13)
    {
        password.push_back(pas);
        cout<<"*";
        pas=getch();
    }
    cout<<endl;

    int counter=1;
    while((counter<=P.NoCounter)&&(username!=P.user[counter].Username)&&(password!=P.user[counter].password))
        counter++;

    if((username==P.user[counter].Username)&&(password==P.user[counter].password))
        {
            system("CLS");
            P_MenuAcara(S);
        }
    else
        {
            system("CLS");
            cout<<"Username dan Password yang anda masukkan salah"<< endl;
            cout<<"Tekan Enter Ulangin Login atau Tekan tombol sembarang untuk Kembali ke menu awal ";
            char menu=getch();
            if(menu==13)
                P_Login(P,S);
            else
                P_MenuPembuka(S,P);
        }
}






