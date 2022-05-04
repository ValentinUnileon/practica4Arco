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

    vector<int> mantisa1=numero1.getMantisa();
    vector<int> mantisa2=numero2.getMantisa();
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

        for(int i=0; i<24; i++){
            if(mantisa2[i]==0){
                mantisa2[i]=1;
            }else{
                mantisa2[i]=0;
            }
        }

        vector<int> ceros={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
        int acarreo=0;


        for(int j= 23; j>=0; j--){

           if(mantisa2[j]+ceros[j]+acarreo==3){
                 mantisa2[j]=1;
                 acarreo=1;
           }else if(mantisa2[j]+ceros[j]+acarreo==2){
                 mantisa2[j]=0;
                 acarreo=1;
           }else if(mantisa2[j]+ceros[j]+acarreo==1){
                 mantisa2[j]=1;
                 acarreo=0;
           }else{
                 mantisa2[j]=0;
                 acarreo=0;
           }
       }

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

   //Bit sticky

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

        for(int j=0; j<d; j++){

            for(int i=P.size()-1; i>0; i--){
                P[i]=P[i-1];
            }

            P[0]=0;

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



    vector<int> mantisaSumaNormalizada;

    for(int i=1; i<24; i++){
       mantisaSumaNormalizada.push_back(mantisaSuma[i]);
    }
    mantisaSumaNormalizada.push_back(0);


    vector<int> resultado;
    resultado.push_back(signoSuma);

    vector<int> exponenteSumaEnBinario=enteroTObinario(expSuma, 8);

    resultado.insert(resultado.end(), exponenteSumaEnBinario.begin(), exponenteSumaEnBinario.end());
    resultado.insert(resultado.end(), mantisaSumaNormalizada.begin(), mantisaSumaNormalizada.end());


    QString hola;
    for(int i=0; i<(int)resultado.size(); i++){

        hola.append(QString::number(resultado[i]));
    }

    ui->resultadoReal->setText(hola);

}

vector<int> menuALU::enteroTObinario(int numero, int numByte) {          //metodo para pasar un numero entero a binario


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







vector<int> menuALU::multiplicacion(){

    float valor1=ui->textoRealOp1->text().toFloat();
    float valor2=ui->textoRealOp2->text().toFloat();


    Numero numero1(valor1);
    Numero numero2(valor2);


   int s1=numero1.getSigno();
   int s2=numero2.getSigno();
   int exp1=numero1.getExponente();
   int exp2=numero2.getExponente();

   //Paso1

   int signoProducto=s1*s2;

   //Paso2
   int expProducto=exp1+exp2 -127;  //IMPORTANTE  IMPORTANTEIMPORTANTEIMPORTANTEIMPORTANTEIMPORTANTEIMPORTANTEIMPORTANTEIMPORTANTE

   //Paso3

   //Paso 3.1

    //AlgoritmoProductoEnterosSinSIgno

   vector<int> mantisaP;

   //*Paso1

   //*Paso 1.1

   vector<int> m1=numero1.getMantisa();
   vector<int> m2=numero2.getMantisa();
   vector<int> P;

   int acarreo=0;

   for(int i=0; i<24; i++){
       P.push_back(0);
   }

    //*Paso1.2
   for(int i=0; i<24; i++){

       if(m1[23]==1){

           acarreo=0;
           for(int j= 23; j>=0; j--){

               if(P[j]+m2[j]+acarreo==3){
                   P[j]=1;
                   acarreo=1;
                }else if(P[j]+m2[j]+acarreo==2){
                   P[j]=0;
                   acarreo=1;
                }else if(P[j]+m2[j]+acarreo==1){
                   P[j]=1;
                   acarreo=0;
                }else{
                   P[j]=0;
                   acarreo=0;
                   }
           }
       }else{
           acarreo=0;
       }


       int auxP=P[23];

       for(int j=23; j>0; j--){
           m1[j]=m1[j-1];
       }

       m1[0]=auxP;


       for(int j=23; j>0; j--){
           P[j]=P[j-1];
       }

       P[0]=acarreo;

    }





   //FIN AlgoritmoProductoEnterosSinSIgno

   //Paso 3.2

   if(P[0]==0){

       for(int j=0; j<(int)P.size()-1; j++){
          P[j]=P[j+1];
       }

       P[23]=m1[0];

       for(int j=0; j<(int)m1.size()-1; j++){
          m1[j]=m1[j+1];
       }
       m1[23]=0;




   }else{
       expProducto= expProducto +1;
   }

   //Paso 3.3


   int r= m1[0];

   //Paso 3.4

   int st=0;

   for(int i=1; i<24 && st==0; i++){
       if(m1[i]==1){
          st=1;
       }
   }

   //Paso 3.5

   if( (r==1 && st==1) || (r==1 && st==0 && P[23]==1) ){

       vector<int> uno={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
       int acarreo=0;


       for(int j= 23; j>=0; j--){

          if(P[j]+uno[j]+acarreo==3){
                P[j]=1;
                acarreo=1;
          }else if(P[j]+uno[j]+acarreo==2){
                P[j]=0;
                acarreo=1;
          }else if(P[j]+uno[j]+acarreo==1){
                P[j]=1;
                acarreo=0;
          }else{
                P[j]=0;
                acarreo=0;
          }
      }


   }


   //DESBORDAMIENTOS



   if (expProducto > 255) { //OVERFLOW

       //infinito, todo a 1s (menos el signo) y FFFFFFF

       expProducto = 255;
       P = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


   }else if (expProducto < 1){

       int t = 1 - expProducto;

       if(t >= 24){

           // HAY UNDERFLOW
           //Todo a ceros TODO TODO

           expProducto = 1;
           P = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


       }else{

           for(int i=0; i<t; i++){

               for(int j=(int)P.size(); j>0; j--){
                  P[j]=P[j-1];
               }

               P[0] = 0;
           }

           expProducto = 1;
       }

   }

   //Denormales

   //1
   //2

   if(expProducto>1){
       int t1 = expProducto-1;
       int t2=0;
       bool encontrado=false;

       for(int i=0; i<(int)P.size() && encontrado!=true ; i++){

           if(P[i]==1){
               encontrado=true;
           }else{
               t2=t2+1;
           }

       }

       int tMin = min(t1, t2);
       expProducto=expProducto-tMin;

       for(int i = 0; i<tMin;i++){

           for(int j=0; j<(int)P.size(); j++){
              P[j]=P[j+1];
           }

           P[23] = 0;
       }

   }

   //3   :(

   if( expProducto==1){

       //PREGUNTAR POR CORREO IMPORTANTE IMPORTANTE IMPORTANTE IMPORTANTE IMPORTANTE IMPORTANTE
       //poner NAN

   }



   //falta OPERANDOS CERO







   vector<int> mantisaProductoNormalizada;
   mantisaP=P;
   for(int i=1; i<24; i++){
      mantisaProductoNormalizada.push_back(mantisaP[i]);
   }

   // mantisaProductoNormalizada.push_back(0);

   vector<int> resultado;
   resultado.push_back(signoProducto);

   vector<int> exponenteProductoEnBinario=enteroTObinario(expProducto, 8);

   resultado.insert(resultado.end(), exponenteProductoEnBinario.begin(), exponenteProductoEnBinario.end());
   resultado.insert(resultado.end(), mantisaProductoNormalizada.begin(), mantisaProductoNormalizada.end());


    return resultado;

   //Desbordamientos comprobacion

   //FALTA hacer desbordamiento infinito :(

   //Desbordamiento a cero
}


void menuALU::on_multiplicacion_clicked()
{
    vector<int> resultado= this->multiplicacion();

    QString hola;
    for(int i=0; i<(int)resultado.size(); i++){

        hola.append(QString::number(resultado[i]));
    }

    ui->resultadoReal->setText(hola);
    ui->resultadoHexadecimal->setText(binarytoHexadecimal(resultado));


}


QString menuALU::binarytoHexadecimal(vector<int> cadenaIEEE){


    int numeroResultado=0;
    vector<int> cuatros={0,0,0,0};
    QString final="";



    for (int i=0; i<8; i++){

       cuatros.clear();

       for(int j=i*4; j<(i*4)+4; j++){

         cuatros.push_back(cadenaIEEE[j]);


       }

       numeroResultado = binaryToReal(cuatros);

       if(numeroResultado < 10){

           final.append(QString::number(numeroResultado));

       }else{

           switch(numeroResultado){
            case 10:
                final.append("A");
            break;

            case 11:
                final.append("B");
            break;

            case 12:
                final.append("C");
            break;

            case 13:
                final.append("D");
            break;

            case 14:
                final.append("E");
            break;

            case 15:
                final.append("F");
            break;

           }

       }

    }


    return final;
}



int menuALU::binaryToReal(vector<int> cuatros){

    int resultado=0;

    for(int i=0; i<4; i++){


        if(cuatros[i]==1){
            resultado=resultado+ pow(2, 3-i);
        }

    }

    return resultado;


}





