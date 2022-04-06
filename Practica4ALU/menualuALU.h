#ifndef MENUALU_H
#define MENUALU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class menuALU; }
QT_END_NAMESPACE

class menuALU : public QMainWindow
{
    Q_OBJECT

public:
    menuALU(QWidget *parent = nullptr);
    ~menuALU();

private slots:
    void on_suma_clicked();

private:
    Ui::menuALU *ui;
};
#endif // MENUALU_H
