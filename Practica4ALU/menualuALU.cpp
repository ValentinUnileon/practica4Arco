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

vector<int> menuALU::suma(Numero numero1, Numero numero2){



    //Paso 1
    int g= 0;
    int r= 0;
    int st= 0;
    int n= 24;
    int d=0;
    int acarreo1=0;
    int acarreo2=0;
    int signoSuma=0;


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

    vector<int> mantisa1=numero1.getMantisa();
    vector<int> mantisa2=numero2.getMantisa();

    if(numero1.getExponente() < 1){

        numero1.setExponente(1);
        mantisa1[0]=0;
    }

    if(numero2.getExponente() < 1){

        numero2.setExponente(1);
        mantisa2[0]=0;
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

    if(d!=0){                   //TODO CUIDADO
        g= P[23-d+1];
    }

   //bit de redondeo

   if(d>=2){
       r= P[23-d+2];           // ESTO DA ERROR AVISO CUIDADO
   }

   //Bit sticky

   int var=0;

   if(d>=3){
        for(int i=3; i<(int)P.size(); i++){
            if(P[23-d+i]==1){
                var=1;

            }
        }
         st=var;
   }

//Paso 7
    if(numero1.getSigno()!= numero2.getSigno()){

        for(int j=0; j<d; j++){

            for(int i=P.size()-1; i>0; i--){
                P[i]=P[i-1];
            }

            P[0] = 1;
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

        r=P[23];

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


    if( (r==1 && st==1) || (r==1 && st==0 && P[23]==1) ) {

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

        acarreo2=acarreoAUX;

        if(acarreo2==1){

            for(int j=23; j>0; j--){
               P[j]=P[j-1];
            }
            P[0]=acarreo2;

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

    vector<int> resultado;
    resultado.push_back(signoSuma);

    vector<int> exponenteSumaEnBinario=enteroTObinario(expSuma, 8);

    resultado.insert(resultado.end(), exponenteSumaEnBinario.begin(), exponenteSumaEnBinario.end());
    resultado.insert(resultado.end(), mantisaSumaNormalizada.begin(), mantisaSumaNormalizada.end());

    return resultado;
}


void menuALU::on_suma_clicked()
{


    QString cadena1=ui->textoRealOp1->text();
    QString cadena2=ui->textoRealOp2->text();

    QString aux1;
    QString aux2;

    float valor1 = 0;
    float valor2 = 0;

    int encontrado = 0;
    int posicion1 = -1;
    int posicion2 = -1;

    for (int i =0; i<cadena1.length(); i++){

        if (cadena1.at(i) == 'E'){

            encontrado = 1;
            posicion1 = i;
        }
    }

    for (int i =0; i<cadena2.length(); i++){

        if (cadena2.at(i) == 'E'){

            encontrado = 1;
            posicion2 = i;
        }
    }

    if (encontrado == 1){

        if(posicion1 != -1){

            aux1 = cadena1.mid(posicion1+1,(cadena1.length()-posicion1+1));
            aux2 = cadena1.mid(0, posicion1);

            valor1 = aux2.toFloat()*pow(10, aux1.toFloat());
        } else{

            valor1=ui->textoRealOp1->text().toFloat();
        }

        if(posicion2 != -1){

            aux1 = cadena2.mid(posicion2+1,(cadena2.length()-posicion2+1));
            aux2 = cadena2.mid(0, posicion2);

            valor2 = aux2.toFloat()*pow(10, aux1.toFloat());
        } else {

            valor2=ui->textoRealOp2->text().toFloat();
        }

    }else{

        valor1=ui->textoRealOp1->text().toFloat();
        valor2=ui->textoRealOp2->text().toFloat();
    }



    Numero numero1(valor1);
    Numero numero2(valor2);

    vector<int> ieee1;
    vector<int> ieee2;
    vector<int> exponente1 = this->enteroTObinario(numero1.getExponente(), 8);
    vector<int> exponente2 = this->enteroTObinario(numero2.getExponente(), 8);
    vector<int> pFraccionaria1 = this->enteroTObinario(numero1.getpFraccionaria(), 23);
    vector<int> pFraccionaria2 = this->enteroTObinario(numero2.getpFraccionaria(), 23);

    ieee1.push_back(numero1.getSigno());
    ieee2.push_back(numero2.getSigno());

    for(int i=0; i<8; i++){

        ieee1.push_back(exponente1[i]);
        ieee2.push_back(exponente2[i]);
    }

    for(int i=0; i<23; i++){

        ieee1.push_back(pFraccionaria1[i]);
        ieee2.push_back(pFraccionaria2[i]);
    }

    QString cadenaHexadeci1 = binarytoHexadecimal(ieee1);
    QString cadenaHexadeci2 = binarytoHexadecimal(ieee2);

    this->ui->textoHexadecimalOp1->setText(cadenaHexadeci1);
    this->ui->textoHexadecimalOp2->setText(cadenaHexadeci2);

    QString cadenaIEEE1;
    QString cadenaIEEE2;

    for(int i=0; i<32; i++){

        cadenaIEEE1.append(QString::number(ieee1[i]));
        cadenaIEEE2.append(QString::number(ieee2[i]));
    }

    this->ui->textoIEEEOp1->setText(cadenaIEEE1);
    this->ui->textoIEEEOp2->setText(cadenaIEEE2);

    vector<int> resultado=suma(numero1, numero2);

    QString hola;

    for(int i=0; i<32; i++){

        hola.append(QString::number(resultado[i]));
    }

    ui->resultadoIEEE->setText(hola);
    ui->resultadoHexadecimal->setText(binarytoHexadecimal(resultado));

    Numero resultadoAux(resultado);

    QString stringReal = QString::number(resultadoAux.numero);

    ui->resultadoReal->setText(stringReal);


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



void menuALU::on_multiplicacion_clicked()
{

    QString cadena1=ui->textoRealOp1->text();
    QString cadena2=ui->textoRealOp2->text();

    QString aux1;
    QString aux2;

    float valor1 = 0;
    float valor2 = 0;

    int encontrado = 0;
    int posicion1 = -1;
    int posicion2 = -1;

    for (int i =0; i<cadena1.length(); i++){

        if (cadena1.at(i) == 'E'){

            encontrado = 1;
            posicion1 = i;
        }
    }

    for (int i =0; i<cadena2.length(); i++){

        if (cadena2.at(i) == 'E'){

            encontrado = 1;
            posicion2 = i;
        }
    }

    if (encontrado == 1){

        if(posicion1 != -1){

            aux1 = cadena1.mid(posicion1+1,(cadena1.length()-posicion1+1));
            aux2 = cadena1.mid(0, posicion1);

            valor1 = aux2.toFloat()*pow(10, aux1.toFloat());
        } else{

            valor1=ui->textoRealOp1->text().toFloat();
        }

        if(posicion2 != -1){

            aux1 = cadena2.mid(posicion2+1,(cadena2.length()-posicion2+1));
            aux2 = cadena2.mid(0, posicion2);

            valor2 = aux2.toFloat()*pow(10, aux1.toFloat());
        } else {

            valor2=ui->textoRealOp2->text().toFloat();
        }

    }else{

        valor1=ui->textoRealOp1->text().toFloat();
        valor2=ui->textoRealOp2->text().toFloat();
    }

    Numero numero1(valor1);
    Numero numero2(valor2);

    vector<int> ieee1;
    vector<int> ieee2;
    vector<int> exponente1 = this->enteroTObinario(numero1.getExponente(), 8);
    vector<int> exponente2 = this->enteroTObinario(numero2.getExponente(), 8);
    vector<int> pFraccionaria1 = this->enteroTObinario(numero1.getpFraccionaria(), 23);
    vector<int> pFraccionaria2 = this->enteroTObinario(numero2.getpFraccionaria(), 23);

    ieee1.push_back(numero1.getSigno());
    ieee2.push_back(numero2.getSigno());

    for(int i=0; i<8; i++){

        ieee1.push_back(exponente1[i]);
        ieee2.push_back(exponente2[i]);
    }

    for(int i=0; i<23; i++){

        ieee1.push_back(pFraccionaria1[i]);
        ieee2.push_back(pFraccionaria2[i]);
    }

    QString cadenaHexadeci1 = binarytoHexadecimal(ieee1);
    QString cadenaHexadeci2 = binarytoHexadecimal(ieee2);

    this->ui->textoHexadecimalOp1->setText(cadenaHexadeci1);
    this->ui->textoHexadecimalOp2->setText(cadenaHexadeci2);

    QString cadenaIEEE1;
    QString cadenaIEEE2;

    for(int i=0; i<32; i++){

        cadenaIEEE1.append(QString::number(ieee1[i]));
        cadenaIEEE2.append(QString::number(ieee2[i]));
    }

    this->ui->textoIEEEOp1->setText(cadenaIEEE1);
    this->ui->textoIEEEOp2->setText(cadenaIEEE2);

    vector<int> resultado= this->multiplicacion(numero1, numero2);

    QString hola;
    int esInfinito=1;
    int esCero=1;

    for(int i=0; i<32; i++){

        hola.append(QString::number(resultado[i]));

        if (i!=0){

            if (resultado[i]==0){

                esInfinito=0;
            }

            if (resultado[i]==1){

                esCero=0;
            }
        }
    }

    ui->resultadoIEEE->setText(hola);
    ui->resultadoHexadecimal->setText(binarytoHexadecimal(resultado));

    Numero resultadoAux(resultado);



    if (esInfinito == 1){

        ui->resultadoReal->setText("Inf");
    } else if(valor1 == 0 || valor2 == 0){

        hola = "00000000000000000000000000000000";
        resultado = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        ui->resultadoReal->setText("0");

        ui->resultadoIEEE->setText(hola);
        ui->resultadoHexadecimal->setText(binarytoHexadecimal(resultado));

    }else if (esCero == 1){

        ui->resultadoReal->setText("NaN");

    }else {
        QString stringReal = QString::number(resultadoAux.numero);
        ui->resultadoReal->setText(stringReal);
    }


}



vector<int> menuALU::multiplicacion(Numero numero1, Numero numero2){




   int s1=numero1.getSigno();
   int s2=numero2.getSigno();
   int exp1=numero1.getExponente();
   int exp2=numero2.getExponente();

   //Paso1

   int signoProducto=0;

   if (s1+s2 ==1){

       signoProducto = 1;
   }

   //Paso2
   int expProducto=exp1+exp2 -127;

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
           //Todo a ceros

           expProducto = 0;
           P = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


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

   vector<int> mantisaProductoNormalizada;
   mantisaP=P;
   for(int i=1; i<24; i++){
      mantisaProductoNormalizada.push_back(mantisaP[i]);
   }

   vector<int> resultado;
   resultado.push_back(signoProducto);

   vector<int> exponenteProductoEnBinario=enteroTObinario(expProducto, 8);

   resultado.insert(resultado.end(), exponenteProductoEnBinario.begin(), exponenteProductoEnBinario.end());
   resultado.insert(resultado.end(), mantisaProductoNormalizada.begin(), mantisaProductoNormalizada.end());


    return resultado;
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

    for(int i=0; i<(int)cuatros.size(); i++){


        if(cuatros[i]==1){
            resultado=resultado+ pow(2, cuatros.size()-1-i);
        }

    }

    return resultado;


}






void menuALU::on_division_clicked()
{

    QString cadena1=ui->textoRealOp1->text();
    QString cadena2=ui->textoRealOp2->text();

    QString aux1;
    QString aux2;

    float valor1 = 0;
    float valor2 = 0;

    int encontrado = 0;
    int posicion1 = -1;
    int posicion2 = -1;

    for (int i =0; i<cadena1.length(); i++){

        if (cadena1.at(i) == 'E'){

            encontrado = 1;
            posicion1 = i;
        }
    }

    for (int i =0; i<cadena2.length(); i++){

        if (cadena2.at(i) == 'E'){

            encontrado = 1;
            posicion2 = i;
        }
    }

    if (encontrado == 1){

        if(posicion1 != -1){

            aux1 = cadena1.mid(posicion1+1,(cadena1.length()-posicion1+1));
            aux2 = cadena1.mid(0, posicion1);

            valor1 = aux2.toFloat()*pow(10, aux1.toFloat());
        } else{

            valor1=ui->textoRealOp1->text().toFloat();
        }

        if(posicion2 != -1){

            aux1 = cadena2.mid(posicion2+1,(cadena2.length()-posicion2+1));
            aux2 = cadena2.mid(0, posicion2);

            valor2 = aux2.toFloat()*pow(10, aux1.toFloat());
        } else {

            valor2=ui->textoRealOp2->text().toFloat();
        }

    }else{

        valor1=ui->textoRealOp1->text().toFloat();
        valor2=ui->textoRealOp2->text().toFloat();
    }


    Numero numero1(valor1);
    Numero numero2(valor2);


   int s1=numero1.getSigno();
   int s2=numero2.getSigno();
   int exp1=numero1.getExponente();
   int exp2=numero2.getExponente();
   vector<int> mantisa1 = numero1.getMantisa();
   vector<int> mantisa2 = numero2.getMantisa();

   float valorEscalado1 = 1;
   float valorEscalado2 = 1;

   //Paso 1
   // Sacamos el valor decimal de la parte entera de la mantisa
   for (int i=1; i<=23; i++){

      if (mantisa1[i]==1){

          valorEscalado1=valorEscalado1+(1/pow(2, i));
      }

      if (mantisa2[i]==1){

          valorEscalado2=valorEscalado2+(1/pow(2, i));
      }
   }

   //Tabla para aproximar el inverso de un numero real
   float bPrima = 0.8;

   if (valorEscalado2<1.25){

     bPrima=1;
   }




   Numero numeroA(valorEscalado1);
   Numero numeroBPrima(bPrima);
   Numero numeroB(valorEscalado2);


   vector<int> x=multiplicacion(numeroA, numeroBPrima);
   vector<int> xAnterior= x;
   vector<int> y=multiplicacion(numeroB, numeroBPrima);
   vector<int> yAnterior=y;
   vector<int> r = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

   Numero constante(y);

   Numero rNumero(r);

   Numero xNuevo(x);
   Numero yNuevo(y);
   Numero xViejo(xAnterior);
   Numero yViejo(yAnterior);

   Numero dos(2);

               //Numero prueba1(1.20000005);
                //Numero prueba2(1.20000005);





   Numero negativoXAnterior(-xViejo.getFloat());
   Numero comparacion(suma(xNuevo, negativoXAnterior));
                //Numero comparacion(suma(prueba1, prueba2));



   Numero condicion(pow(10, -4));




   //Comparacionfinalizacion es (x1-x0)-10 a la -4
   //Numero comparacionFinalizacion(suma(comparacion, condicion));

   int aux = 1;


   while(aux == 1){



       yViejo.setSigno(1);
       rNumero.setNuevoNumero(suma(dos, yViejo));
       yViejo.setSigno(0);

       yNuevo.setNuevoNumero(multiplicacion(yViejo, rNumero));
       xNuevo.setNuevoNumero(multiplicacion(xViejo, rNumero));


       //Rehacemos la condicion para comprobar si vuelve a entrar en el while

       xNuevo.setSigno(1);
       comparacion.setNuevoNumero(suma(xViejo, xNuevo));
       xNuevo.setSigno(0);

       //comparacionFinalizacion.setNuevoNumero(suma(comparacion, condicion));

       xViejo.setNuevoNumero(xNuevo.getIEE());
       yViejo.setNuevoNumero(yNuevo.getIEE());

       comparacion.setSigno(0);

       if (comparacion.getFloat() < condicion.getFloat()){

           aux = 0;
       } else {

           aux = 1;
       }



   }

   //Calculo de exponente y mantisa de X

   int exponenteX = xNuevo.getExponente();
   vector<int> mantisaX = xNuevo.getMantisa();

   //Calculo del signo de la division
   int signoDivision=0;

   if (s1!=s2){
       signoDivision=1;
   }

   //Calculo del exponente de la division


   Numero expA(exp1);
   Numero expB(exp2);
   Numero expX(exponenteX);

   expB.setSigno(1);
   Numero temporal(suma(expA, expB));
   expB.setSigno(0);

   Numero exponenteDivision(suma(temporal, expX));

   vector<int> exponenteFinal = this->enteroTObinario(exponenteDivision.getFloat(), 8);

   //Obtenemos el resultado final

   vector<int> vectorFinal;

   vectorFinal.push_back(signoDivision);

   for(int i=0; i<8; i++){

       vectorFinal.push_back(exponenteFinal[i]);
   }

   for(int i=1; i<24; i++){

       vectorFinal.push_back(mantisaX[i]);
   }

   if (numero2.getFloat() == 0){

       ui->resultadoReal->setText("NaN");

       QString excepcion ="";
       excepcion.append(QString::number(numero1.getSigno()));

       for(int i=0; i<31; i++){

           excepcion.append("1");
       }

       ui->resultadoIEEE->setText(excepcion);
       ui->resultadoHexadecimal->setText("7FFFFFFF");
   } else{

       QString hola;

       for(int i=0; i<32; i++){

           hola.append(QString::number(vectorFinal[i]));
       }

       ui->resultadoIEEE->setText(hola);
       ui->resultadoHexadecimal->setText(binarytoHexadecimal(vectorFinal));

       Numero resultadoAux(vectorFinal);

       QString stringReal = QString::number(resultadoAux.numero);

       ui->resultadoReal->setText(stringReal);
   }


}
