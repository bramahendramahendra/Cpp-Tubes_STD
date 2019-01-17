#include "tubesdll.h"
using namespace std;

void insertfirstDLL(list_voter &l, adr_voter p)
{
    if((l.first == NULL) && (l.last == NULL))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p->next=l.first;
        l.first->prev = p;
        l.first = p;
    }
}

