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

vector<int> Numero::enteroToBinario(int numero, int numByte) {          //metodo para pasar un numero entero a binario


    vector<int> binario;

    if (numero > 0) {
        while (numero > 0) {
            if (numero%2 == 0) {

                binario.insert(binario.begin(), 0);
            } else {
                binario.insert(binario.begin(), 1);
            }
            numero = (int) numero/2;
        }
    }

    if(numByte==8 && (int)binario.size()<(int)numByte){

        while((int)binario.size()<(int)numByte){
           binario.insert(binario.begin(), 0);
        }


    }

    if(numByte==23 && (int)binario.size()<(int)numByte){

        while((int)binario.size()<(int)numByte){
           binario.insert(binario.begin(), 0);
        }


    }



    return binario;
}


vector<int> Numero::getMantisa(){

    vector<int> aux;

    aux=this->enteroToBinario(this->getpFraccionaria(), 23);

    vector<int> aux2;
    aux2.push_back(1);

    for(int i=0; i<23; i++){
       aux2.push_back(aux[i]);
    }



    return aux2;

}
