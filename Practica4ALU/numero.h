#ifndef NUMERO_H
#define NUMERO_H
#include <bitset>

#include <vector>

using namespace std;

class Numero
{
public:

    Numero(float numero);

    Numero(vector<int> vectorIEEE);

    void setNuevoNumero(vector<int> vectorIEEE);

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

    int binaryToReal(vector<int> numeroBinario);

    int exponente;
    int pFraccionaria;
    int signo;

    int exponenteBin;


    int getExponente();
    int getpFraccionaria();
    int getSigno();
    void setSigno(int signo);
    void setExponente(int expNuevo);
    float getFloat();
    vector<int> enteroToBinario(int numero, int numByte);
    vector<int> getMantisa();
    vector<int> getIEE();

};

#endif // NUMERO_H
