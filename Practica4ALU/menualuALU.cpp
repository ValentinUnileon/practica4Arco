#include "menualuALU.h"
#include "ui_menualuALU.h"
#include "numero.h"



using namespace std;

menuALU::menuALU(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menuALU)
{
    ui->setupUi(this);
}

menuALU::~menuALU()
{
    delete ui;





}


void menuALU::on_suma_clicked()
{

    float valor1=ui->textoRealOp1->text().toFloat();
    float valor2=ui->textoRealOp2->text().toFloat();


    Numero numero1(valor1);
    Numero numero2(valor2);

    //Paso 1
    int g= 0;
    int r= 0;
    int st= 0;
    int n= 24;
    int d;
    int acarreo1=0;
    int acarreo2=0;
    int signoSuma;

    vector<int> mantisa1;
    vector<int> mantisa2;
    vector<int> mantisaSuma;

    vector<int> P;

    int expSuma=0;


    bool operandosInter= false;
    bool complementadoP=false;

    //Paso 2

    if(numero1.getExponente()<numero2.getExponente()){
      Numero aux=numero1;
      numero1=numero2;
      numero2=aux;

      operandosInter=true;
    }

    //Paso 3
    expSuma=numero1.getExponente();
    d= numero1.getExponente()-numero2.getExponente();

    //Paso 4

    if(numero1.getSigno() != numero2.getSigno()){
        mantisa2= numero2.getMantisa();
    }

    //Paso 5
    P= mantisa2;

//Paso 6
    //bit de guarda
    if(d!=0){
        g= P[d-1];
    }
   //bit de redondeo
   if(d>=2){
       r= P[d-2];
   }

   int var=0;

   if(d>=3){
        for(int i=3; i<(int)P.size(); i++){
            if(P[d-i]==1){
                var=1;

            }
        }
         st=var;
   }

//Paso 7
    if(numero1.getSigno()!= numero2.getSigno()){

        for(int i=P.size()-1; i>0; i--){
            P[i]=P[i-1];
        }

        for(int i=0; i<d; i++){
            P[i]=1;
        }

    }else{
        for(int i=P.size()-1; i>0; i--){
            P[i]=P[i-1];
        }

        for(int i=0; i<d; i++){
            P[i]=0;
        }
    }

//Paso 8
    for(int i= 23; i>=0; i--){

        if(mantisa1[i]+P[i]+acarreo1==3){
            P[i]=1;
            acarreo1=1;
         }else if(mantisa1[i]+P[i]+acarreo1==2){
            P[i]=0;
            acarreo1=1;
         }else if(mantisa1[i]+P[i]+acarreo1==1){
            P[i]=1;
            acarreo1=0;
         }else{
            P[i]=0;
            acarreo1=0;
            }
     }

//Paso 9

    if(numero1.getSigno()!= numero2.getSigno() && P[n-1]==1 && acarreo1==0){

        for(int i=0; i<(int)P.size(); i++){

            if(P[i]==1){
                P[i]=0;
            }else{
                P[i]=1;
            }

        }

        vector<int> aux ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
        int acarreoAUX=0;

        for(int i= 23; i>=0; i--){

            if(aux[i]+P[i]+acarreoAUX==3){
                P[i]=1;
                acarreoAUX=1;
             }else if(aux[i]+P[i]+acarreoAUX==2){
                P[i]=0;
                acarreoAUX=1;
             }else if(aux[i]+P[i]+acarreoAUX==1){
                P[i]=1;
                acarreoAUX=0;
             }else{
                P[i]=0;
                acarreoAUX=0;
             }
        }

        complementadoP=true;
    }

//Paso 10

    if(numero1.getSigno()== numero2.getSigno() && acarreo1==1){

        if(g+r+st==0){
            st=0;
        }else{
            st=1;
        }

        r=P[0];

        for(int i=P.size()-1; i>0; i--){
            P[i]=P[i-1];
        }

        P[0]=acarreo1;

        expSuma=expSuma+1;



    }else{

        int k=0;
        bool encontrado=false;

        for(int i=0; i<(int)P.size() && encontrado==false ; i++ ){

            if(P[i]!=1){
               k++;
            }else{
                encontrado=true;
            }
        }


        if(k==0){

           if(r+st==0){
              st=0;
           }else{
              st=1;
           }

            r=g;

        }else if(k>1){

            r=0;
            st=0;
        }


        for(int i=0; i<k; i++){

            for(int j=0; j<(int)P.size()-1; j++){
               P[j]=P[j+1];
            }
            P[23]=g;

        }

        expSuma=expSuma-k;
    }

//Paso 11


    if( (r==1 && st==1) || (r==1 && st==0 && P[0]==1) ) {

        vector<int> aux ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
        int acarreoAUX=0;

        for(int i= 23; i>=0; i--){

            if(aux[i]+P[i]+acarreoAUX==3){
                P[i]=1;
                acarreoAUX=1;
             }else if(aux[i]+P[i]+acarreoAUX==2){
                P[i]=0;
                acarreoAUX=1;
             }else if(aux[i]+P[i]+acarreoAUX==1){
                P[i]=1;
                acarreoAUX=0;
             }else{
                P[i]=0;
                acarreoAUX=0;
             }
        }

        acarreo2=acarreo1;

        if(acarreo2==1){

            for(int j=23; j<0; j++){
               P[j]=P[j-1];
            }
            P[0]=1;

            expSuma=expSuma+1;
        }

    }

    mantisaSuma=P;

//Paso 12

    if(!operandosInter && complementadoP){
        signoSuma=numero2.getSigno();
    }else{
        signoSuma=numero1.getSigno();
    }


//Paso 13


    vector<int> resultado;
    resultado.push_back(signoSuma);

    vector<int> exponenteSumaEnBinario=enteroTObinario(expSuma, 8);

    resultado.insert(resultado.end(), exponenteSumaEnBinario.begin(), exponenteSumaEnBinario.end());
    resultado.insert(resultado.end(), mantisaSuma.begin(), mantisaSuma.end());





}

vector<int> menuALU::enteroTObinario(int numero, int numByte) {          //metodo para pasar un numero entero a binario

    int decimal=numero;
    vector<int> binario;

    for(int i=0; i<numByte; i++){

        if(decimal < 2){
            binario[i] = decimal % 2;
            decimal /= 2;
        }


    }

    if(binario.size()==22){
        binario.insert(binario.begin()+1, 0);
    }

    return binario;
}











