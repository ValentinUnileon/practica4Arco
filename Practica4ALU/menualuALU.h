#ifndef MENUALU_H
#define MENUALU_H

#include <QMainWindow>

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

    vector<int> suma();
    vector<int> multiplicacion();

private slots:
    void on_suma_clicked();
    vector<int> enteroTObinario(int numero, int numByte);

    void on_multiplicacion_clicked();

    QString binarytoHexadecimal(vector<int> cadenaIEEE);
    int binaryToReal(vector<int> cuatros);

private:
    Ui::menuALU *ui;
};
#endif // MENUALU_H
