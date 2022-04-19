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
   vector<int> mantisa = this->enteroTObinario(this->getExponente(), 23);
   vector<int> mantisaAux;
   mantisaAux.push_back(1);

   for (int i = 0; i < 23; i++) {

       mantisaAux.push_back(mantisa[i]);
   }

   return mantisaAux;
}

vector<int> Numero::enteroTObinario(int numero, int numByte) {          //metodo para pasar un numero entero a binario


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
