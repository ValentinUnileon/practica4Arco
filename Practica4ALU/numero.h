#ifndef NUMERO_H
#define NUMERO_H
#include <bitset>

#include <vector>

using namespace std;

class Numero
{
public:

    Numero(float numero);



    union Code {

        struct{
            unsigned int partFrac : 23;
            unsigned int expo : 8;
            unsigned int sign : 1;
        }bitfield;

        float numero;
        unsigned int numerox;
    };

    float numero;
    unsigned int numerox;

    void floattoIEE ();
    void floattoIEE2 ();
    void IEEtofloat ();
    void IEEtofloat2 ();

    int exponente;
    int pFraccionaria;
    int signo;

    int exponenteBin;


    int getExponente();
    int getpFraccionaria();
    int getSigno();
    vector<int> enteroToBinario(int numero, int numByte);
    vector<int> getMantisa();


};

#endif // NUMERO_H
