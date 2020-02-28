/********************************************************************************
** Form generated from reading UI file 'qdrawline.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDRAWLINE_H
#define UI_QDRAWLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDrawLine
{
public:
    QWidget *centralwidget;
    QLineEdit *vertice1;
    QLabel *label;
    QPushButton *botoncrear;
    QPushButton *dikstra;
    QLabel *label_2;
    QLineEdit *vertice2;
    QLabel *label_3;
    QLabel *resultado;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QDrawLine)
    {
        if (QDrawLine->objectName().isEmpty())
            QDrawLine->setObjectName(QStringLiteral("QDrawLine"));
        QDrawLine->resize(802, 483);
        centralwidget = new QWidget(QDrawLine);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        vertice1 = new QLineEdit(centralwidget);
        vertice1->setObjectName(QStringLiteral("vertice1"));
        vertice1->setGeometry(QRect(630, 130, 113, 25));
        vertice1->setStyleSheet(QStringLiteral("background-color :rgb(255, 255, 255)"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(510, 130, 101, 20));
        botoncrear = new QPushButton(centralwidget);
        botoncrear->setObjectName(QStringLiteral("botoncrear"));
        botoncrear->setGeometry(QRect(560, 40, 161, 25));
        dikstra = new QPushButton(centralwidget);
        dikstra->setObjectName(QStringLiteral("dikstra"));
        dikstra->setGeometry(QRect(510, 250, 241, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(510, 170, 91, 20));
        vertice2 = new QLineEdit(centralwidget);
        vertice2->setObjectName(QStringLiteral("vertice2"));
        vertice2->setGeometry(QRect(630, 170, 113, 25));
        vertice2->setStyleSheet(QStringLiteral("background-color :rgb(255, 255, 255)"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(510, 300, 181, 17));
        resultado = new QLabel(centralwidget);
        resultado->setObjectName(QStringLiteral("resultado"));
        resultado->setGeometry(QRect(700, 300, 67, 17));
        QDrawLine->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QDrawLine);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 802, 22));
        QDrawLine->setMenuBar(menubar);
        statusbar = new QStatusBar(QDrawLine);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QDrawLine->setStatusBar(statusbar);

        retranslateUi(QDrawLine);

        QMetaObject::connectSlotsByName(QDrawLine);
    } // setupUi

    void retranslateUi(QMainWindow *QDrawLine)
    {
        QDrawLine->setWindowTitle(QApplication::translate("QDrawLine", "QDrawLine", Q_NULLPTR));
        label->setText(QApplication::translate("QDrawLine", "Desde Vertice", Q_NULLPTR));
        botoncrear->setText(QApplication::translate("QDrawLine", "Crear Grafo Random ", Q_NULLPTR));
        dikstra->setText(QApplication::translate("QDrawLine", "Aplicar Algoritmo de Dijkstra", Q_NULLPTR));
        label_2->setText(QApplication::translate("QDrawLine", "Hasta Vertice", Q_NULLPTR));
        label_3->setText(QApplication::translate("QDrawLine", "El camino m\303\241s corto es de:", Q_NULLPTR));
        resultado->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QDrawLine: public Ui_QDrawLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDRAWLINE_H
