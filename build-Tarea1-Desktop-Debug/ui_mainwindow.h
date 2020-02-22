/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *botoncrear;
    QLineEdit *vertice1;
    QLineEdit *vertice2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *dikstra;
    QLabel *label_3;
    QLabel *resultado;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(883, 460);
        QIcon icon;
        icon.addFile(QStringLiteral("../Downloads/maxresdefault.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(224, 212, 212)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 491, 411));
        frame->setCursor(QCursor(Qt::CrossCursor));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        botoncrear = new QPushButton(centralwidget);
        botoncrear->setObjectName(QStringLiteral("botoncrear"));
        botoncrear->setGeometry(QRect(600, 30, 161, 25));
        vertice1 = new QLineEdit(centralwidget);
        vertice1->setObjectName(QStringLiteral("vertice1"));
        vertice1->setGeometry(QRect(670, 120, 113, 25));
        vertice1->setStyleSheet(QStringLiteral("background-color :rgb(255, 255, 255)"));
        vertice2 = new QLineEdit(centralwidget);
        vertice2->setObjectName(QStringLiteral("vertice2"));
        vertice2->setGeometry(QRect(670, 160, 113, 25));
        vertice2->setStyleSheet(QStringLiteral("background-color :rgb(255, 255, 255)"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(550, 120, 101, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(550, 160, 91, 20));
        dikstra = new QPushButton(centralwidget);
        dikstra->setObjectName(QStringLiteral("dikstra"));
        dikstra->setGeometry(QRect(550, 240, 241, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(550, 290, 181, 17));
        resultado = new QLabel(centralwidget);
        resultado->setObjectName(QStringLiteral("resultado"));
        resultado->setGeometry(QRect(740, 290, 67, 17));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Algoritmo de Dijkstra", Q_NULLPTR));
        botoncrear->setText(QApplication::translate("MainWindow", "Crear Grafo Random ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Desde Vertice", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Hasta Vertice", Q_NULLPTR));
        dikstra->setText(QApplication::translate("MainWindow", "Aplicar Algoritmo de Dijkstra", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "El camino m\303\241s corto es de:", Q_NULLPTR));
        resultado->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
