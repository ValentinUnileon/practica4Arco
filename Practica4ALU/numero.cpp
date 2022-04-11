#include "numero.h"
#include <iostream>

using namespace std;

Numero::Numero(float numero)
{
        this->numero=numero;
        floattoIEE();

}

void Numero::floattoIEE (){

    union Code a;

    a.numero=this->numero;
    this->signo=a.bitfield.sign;
    this->exponente=a.bitfield.expo;
    this->pFraccionaria=a.bitfield.partFrac;

}

int Numero::getExponente(){

    return exponente;
}

int Numero::getSigno(){
    return signo;
}

int Numero::getpFraccionaria(){
    return pFraccionaria;
}

//Arreglar
vector<int> Numero::getMantisa(){
    return NULL;
}
