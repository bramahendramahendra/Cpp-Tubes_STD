#include <iostream>
#include <conio.h>
using namespace std;

void login(string username,string password)
{
    int ulang;
    char ch;
    cout << "============================\n";
    cout << "Selamat Datang di Form Login \n";
    cout << "============================\n";
    for(ulang=1; ulang<=3; ulang++)
    {
        username = "";
        password = "";
        cout << "Username : ";
        cin>> username;
        cout << "Password : ";
            ch = _getch();
            while(ch != 13)
            password.push_back(ch);
            cout<< '*';
            ch = _getch();
        if(username == "username" && password == "password")
        {


            cout << "Anda berhasil login" << endl;
//            return 0;
        }
        else
        {
            cout<<" Maaf Username Atau Password anda ada yang salah. ";
        }
    }



}
int main()
{
    string username,password;
    int ulang;
    char ch;
    cout << "============================\n";
    cout << "Selamat Datang di Form Login \n";
    cout << "============================\n";
    for(ulang=1; ulang<=3; ulang++)
    {
        username = "";
        password = "";
        cout << "Username : ";
        cin>> username;
        cout << "Password : ";
            ch = _getch();
            while(ch != 13)
            password.push_back(ch);
            cout<< "*";
            ch = _getch();
        if(username == "username" && password == "password")
        {


            cout << "Anda berhasil login" << endl;
            return 0;
        }
        else
        {
            cout<<" Maaf Username Atau Password anda ada yang salah. ";
        }
    }
    while(ulang <= 3);
    {
        cout << "Anda sudah memasukan Username & Password yang salah ";
        cout << "Maaf akun kami blokir untuk sementara ";
    }
}
