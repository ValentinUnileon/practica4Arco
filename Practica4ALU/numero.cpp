#include "numero.h"
#include <iostream>

using namespace std;

Numero::Numero(float numero)
{
        this->numero=numero;
}

void Numero::floattoIEE (){

    union Code a;
    printf ("Introduce un número: ");
    scanf ("%f", &a.numero);

    printf("Signo: %u \n",a.bitfield.sign);
    printf("Exponente: %u \n",a.bitfield.expo);
    printf("Parte Fraccionaria : %u \n", a.bitfield.partFrac);

}
