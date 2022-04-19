#include <iostream>
#include "Duree.h"

using namespace std;

ostream &operator<<( ostream &flux, Duree const& duree);


int main()
{
    Duree duree1(2, 25, 28), duree2(0, 16, 33),duree3;
duree3=duree1+duree2;
    cout << duree1 << " et " << duree2 << " = " << duree3 << endl;

    return 0;
}



