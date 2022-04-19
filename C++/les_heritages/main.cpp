#include <iostream>
#include "Personnage.h"
#include "Guerrier.h"

using namespace std;

int main()
{
   Personnage marcel("Marcel");
   marcel.sePresenter();

   Guerrier lancelot("Lancelot du Lac");
   lancelot.sePresenter();

   return 0;
}
