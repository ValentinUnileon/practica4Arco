#ifndef MENUALU_H
#define MENUALU_H

#include <QMainWindow>
#include <numero.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class menuALU; }
QT_END_NAMESPACE

class menuALU : public QMainWindow
{
    Q_OBJECT

public:
    menuALU(QWidget *parent = nullptr);
    ~menuALU();

    vector<int> suma(Numero numero1, Numero numero2);
    vector<int> multiplicacion(Numero numero1, Numero numero2);

private slots:
    void on_suma_clicked();
    vector<int> enteroTObinario(int numero, int numByte);

    void on_multiplicacion_clicked();

    QString binarytoHexadecimal(vector<int> cadenaIEEE);
    int binaryToReal(vector<int> cuatros);

    void on_division_clicked();

private:
    Ui::menuALU *ui;
};
#endif // MENUALU_H
