#ifndef NUMERO_H
#define NUMERO_H
#include <bitset>


class Numero
{
public:
    Numero(float numero);



    struct{
        unsigned int partFrac : 23;
        unsigned int expo : 8;
        unsigned int sign : 1;
    }bitfield;

    float numero;
    unsigned int numerox;

    void floattoIEE ();
    void floattoIEE2 ();
    void IEEtofloat ();
    void IEEtofloat2 ();





};

#endif // NUMERO_H
