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
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
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
        label->setGeometry(QRect(380, 10, 81, 81));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 90, 141, 31));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 90, 121, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(99, 134, 31, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 170, 51, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(55, 210, 71, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(350, 370, 101, 20));
        label_7->setFont(font1);
        suma = new QPushButton(centralwidget);
        suma->setObjectName(QString::fromUtf8("suma"));
        suma->setGeometry(QRect(260, 270, 71, 71));
        QFont font2;
        font2.setPointSize(48);
        suma->setFont(font2);
        multiplicacion = new QPushButton(centralwidget);
        multiplicacion->setObjectName(QString::fromUtf8("multiplicacion"));
        multiplicacion->setGeometry(QRect(370, 270, 71, 71));
        multiplicacion->setFont(font2);
        division = new QPushButton(centralwidget);
        division->setObjectName(QString::fromUtf8("division"));
        division->setGeometry(QRect(480, 270, 71, 71));
        division->setFont(font2);
        textoRealOp1 = new QLineEdit(centralwidget);
        textoRealOp1->setObjectName(QString::fromUtf8("textoRealOp1"));
        textoRealOp1->setGeometry(QRect(140, 130, 261, 28));
        textoIEEEOp1 = new QLineEdit(centralwidget);
        textoIEEEOp1->setObjectName(QString::fromUtf8("textoIEEEOp1"));
        textoIEEEOp1->setEnabled(true);
        textoIEEEOp1->setGeometry(QRect(140, 170, 261, 28));
        textoHexadecimalOp1 = new QLineEdit(centralwidget);
        textoHexadecimalOp1->setObjectName(QString::fromUtf8("textoHexadecimalOp1"));
        textoHexadecimalOp1->setEnabled(true);
        textoHexadecimalOp1->setGeometry(QRect(140, 210, 261, 28));
        textoRealOp2 = new QLineEdit(centralwidget);
        textoRealOp2->setObjectName(QString::fromUtf8("textoRealOp2"));
        textoRealOp2->setGeometry(QRect(410, 130, 241, 28));
        textoIEEEOp2 = new QLineEdit(centralwidget);
        textoIEEEOp2->setObjectName(QString::fromUtf8("textoIEEEOp2"));
        textoIEEEOp2->setEnabled(true);
        textoIEEEOp2->setGeometry(QRect(410, 170, 241, 28));
        textoHexadecimalOp2 = new QLineEdit(centralwidget);
        textoHexadecimalOp2->setObjectName(QString::fromUtf8("textoHexadecimalOp2"));
        textoHexadecimalOp2->setEnabled(true);
        textoHexadecimalOp2->setGeometry(QRect(410, 210, 241, 28));
        resultadoReal = new QLineEdit(centralwidget);
        resultadoReal->setObjectName(QString::fromUtf8("resultadoReal"));
        resultadoReal->setEnabled(true);
        resultadoReal->setGeometry(QRect(260, 400, 291, 28));
        resultadoIEEE = new QLineEdit(centralwidget);
        resultadoIEEE->setObjectName(QString::fromUtf8("resultadoIEEE"));
        resultadoIEEE->setEnabled(true);
        resultadoIEEE->setGeometry(QRect(260, 440, 291, 28));
        resultadoHexadecimal = new QLineEdit(centralwidget);
        resultadoHexadecimal->setObjectName(QString::fromUtf8("resultadoHexadecimal"));
        resultadoHexadecimal->setEnabled(true);
        resultadoHexadecimal->setGeometry(QRect(260, 480, 291, 28));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 440, 41, 20));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(174, 480, 71, 20));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(220, 400, 21, 20));
        menuALU->setCentralWidget(centralwidget);
        menubar = new QMenuBar(menuALU);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        textoRealOp1->setPlaceholderText(QCoreApplication::translate("menuALU", "Introduce un operando", nullptr));
        textoRealOp2->setPlaceholderText(QCoreApplication::translate("menuALU", "Introduce un operando", nullptr));
        label_8->setText(QCoreApplication::translate("menuALU", "IEEE 754", nullptr));
        label_9->setText(QCoreApplication::translate("menuALU", "Hexadecimal", nullptr));
        label_10->setText(QCoreApplication::translate("menuALU", "Real", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuALU: public Ui_menuALU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUALUALU_H
