#include "menualuALU.h"
#include "ui_menualuALU.h"
#include "numero.h"

#include <vector>

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
    int acarreo=0;

    vector<int> mantisa1;
    vector<int> mantisa2;

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

        if(mantisa1[i]+P[i]+acarreo==3){
            P[i]=1;
            acarreo=1;
         }else if(mantisa1[i]+P[i]+acarreo==2){
            P[i]=0;
            acarreo=1;
         }else if(mantisa1[i]+P[i]+acarreo==1){
            P[i]=1;
            acarreo=0;
         }else{
            P[i]=0;
            acarreo=0;
            }
        }
    }

//Buenas noches, hasta mañana
