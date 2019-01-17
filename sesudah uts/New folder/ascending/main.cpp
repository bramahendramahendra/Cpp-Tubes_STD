#include <iostream>
#include<conio.h>
using namespace std;

void ascending()
{

}

int main()
{

    char str[100],temp;
    int i,j;
    cout<<"enter string: ";
    cin.getline(str,100);
    cout<<"ascending ",str;
    for (i=0; str[i]; i++)
    {
        for(j=i+1; str[j]; j++)
        {
            if(str[j]<str[i])
            {
                temp=str[j];
                str[j]=str[i];
                str[i]=temp;
            }
        }
    }
    cout<<str;
    return 0;
}
