#include "numero.h"
#include <iostream>
#include <math.h>

using namespace std;

Numero::Numero(float numero)
{
        this->numero=numero;
        floattoIEE();

}

Numero::Numero(vector<int> vectorIEEE)
{
        int signoNumero = vectorIEEE[0];
        vector<int> exponenteNumero;
        vector<int> pFraccionariaNumero;

        for(int i=1; i<9; i++){

            exponenteNumero.push_back(vectorIEEE[i]);
        }

        for(int i=9; i<32; i++){

            pFraccionariaNumero.push_back(vectorIEEE[i]);
        }

        union Code a;

        a.bitfield.sign = signoNumero;
        a.bitfield.expo = this->binaryToReal(exponenteNumero);
        a.bitfield.partFrac = this->binaryToReal(pFraccionariaNumero);

        this->numero = a.numero;

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

int Numero::binaryToReal(vector<int> cuatros){

    int resultado=0;

    for(int i=0; i<(int)cuatros.size(); i++){


        if(cuatros[i]==1){
            resultado=resultado+ pow(2, cuatros.size()-1-i);
        }

    }

    return resultado;


}
