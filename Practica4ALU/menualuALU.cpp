#include "menualuALU.h"
#include "ui_menualuALU.h"
#include "numero.h"

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

    float valor=ui->textoRealOp1->text().toFloat();

    Numero numero(valor);

}

