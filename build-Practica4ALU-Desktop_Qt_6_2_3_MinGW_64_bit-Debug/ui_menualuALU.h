/********************************************************************************
** Form generated from reading UI file 'menualuALU.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUALUALU_H
#define UI_MENUALUALU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menuALU
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *suma;
    QPushButton *multiplicacion;
    QPushButton *division;
    QLineEdit *textoRealOp1;
    QLineEdit *textoIEEEOp1;
    QLineEdit *textoHexadecimalOp1;
    QLineEdit *textoRealOp2;
    QLineEdit *textoIEEEOp2;
    QLineEdit *textoHexadecimalOp2;
    QLineEdit *resultadoReal;
    QLineEdit *resultadoIEEE;
    QLineEdit *resultadoHexadecimal;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *menuALU)
    {
        if (menuALU->objectName().isEmpty())
            menuALU->setObjectName(QString::fromUtf8("menuALU"));
        menuALU->resize(800, 600);
        centralwidget = new QWidget(menuALU);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 81, 81));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 130, 101, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 190, 101, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 100, 101, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 100, 101, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(440, 100, 101, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 330, 101, 20));
        suma = new QPushButton(centralwidget);
        suma->setObjectName(QString::fromUtf8("suma"));
        suma->setGeometry(QRect(160, 230, 71, 71));
        QFont font1;
        font1.setPointSize(48);
        suma->setFont(font1);
        multiplicacion = new QPushButton(centralwidget);
        multiplicacion->setObjectName(QString::fromUtf8("multiplicacion"));
        multiplicacion->setGeometry(QRect(260, 230, 71, 71));
        multiplicacion->setFont(font1);
        division = new QPushButton(centralwidget);
        division->setObjectName(QString::fromUtf8("division"));
        division->setGeometry(QRect(370, 230, 361, 71));
        division->setFont(font1);
        textoRealOp1 = new QLineEdit(centralwidget);
        textoRealOp1->setObjectName(QString::fromUtf8("textoRealOp1"));
        textoRealOp1->setGeometry(QRect(150, 130, 113, 28));
        textoIEEEOp1 = new QLineEdit(centralwidget);
        textoIEEEOp1->setObjectName(QString::fromUtf8("textoIEEEOp1"));
        textoIEEEOp1->setGeometry(QRect(290, 130, 113, 28));
        textoHexadecimalOp1 = new QLineEdit(centralwidget);
        textoHexadecimalOp1->setObjectName(QString::fromUtf8("textoHexadecimalOp1"));
        textoHexadecimalOp1->setGeometry(QRect(430, 130, 113, 28));
        textoRealOp2 = new QLineEdit(centralwidget);
        textoRealOp2->setObjectName(QString::fromUtf8("textoRealOp2"));
        textoRealOp2->setGeometry(QRect(150, 180, 113, 28));
        textoIEEEOp2 = new QLineEdit(centralwidget);
        textoIEEEOp2->setObjectName(QString::fromUtf8("textoIEEEOp2"));
        textoIEEEOp2->setGeometry(QRect(290, 180, 113, 28));
        textoHexadecimalOp2 = new QLineEdit(centralwidget);
        textoHexadecimalOp2->setObjectName(QString::fromUtf8("textoHexadecimalOp2"));
        textoHexadecimalOp2->setGeometry(QRect(430, 180, 113, 28));
        resultadoReal = new QLineEdit(centralwidget);
        resultadoReal->setObjectName(QString::fromUtf8("resultadoReal"));
        resultadoReal->setGeometry(QRect(140, 330, 211, 28));
        resultadoIEEE = new QLineEdit(centralwidget);
        resultadoIEEE->setObjectName(QString::fromUtf8("resultadoIEEE"));
        resultadoIEEE->setGeometry(QRect(390, 330, 113, 28));
        resultadoHexadecimal = new QLineEdit(centralwidget);
        resultadoHexadecimal->setObjectName(QString::fromUtf8("resultadoHexadecimal"));
        resultadoHexadecimal->setGeometry(QRect(520, 330, 113, 28));
        menuALU->setCentralWidget(centralwidget);
        menubar = new QMenuBar(menuALU);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuALU->setMenuBar(menubar);
        statusbar = new QStatusBar(menuALU);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        menuALU->setStatusBar(statusbar);

        retranslateUi(menuALU);

        QMetaObject::connectSlotsByName(menuALU);
    } // setupUi

    void retranslateUi(QMainWindow *menuALU)
    {
        menuALU->setWindowTitle(QCoreApplication::translate("menuALU", "menuALU", nullptr));
        label->setText(QCoreApplication::translate("menuALU", "ALU", nullptr));
        label_2->setText(QCoreApplication::translate("menuALU", "Operando 1", nullptr));
        label_3->setText(QCoreApplication::translate("menuALU", "Operando 2", nullptr));
        label_4->setText(QCoreApplication::translate("menuALU", "Real", nullptr));
        label_5->setText(QCoreApplication::translate("menuALU", "IEEE 754", nullptr));
        label_6->setText(QCoreApplication::translate("menuALU", "Hexadecimal", nullptr));
        label_7->setText(QCoreApplication::translate("menuALU", "Resultado", nullptr));
        suma->setText(QCoreApplication::translate("menuALU", "+", nullptr));
        multiplicacion->setText(QCoreApplication::translate("menuALU", "x", nullptr));
        division->setText(QCoreApplication::translate("menuALU", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuALU: public Ui_menuALU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUALUALU_H
