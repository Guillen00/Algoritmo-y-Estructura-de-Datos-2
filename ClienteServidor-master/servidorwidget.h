/**@Guille00
  *@data 02/03/2020
  *@brief Descripción: A continuación se describe la clase ServidorSocket  , la cual se encarga de comunicar y tener acceso a todas las caracteristicas de la interfase
  *
  */

#ifndef SERVIDORWIDGET_H
#define SERVIDORWIDGET_H
#include <iostream>
#include <QWidget>


/** Se crean las funciones slots para hacer uso de los botones de la interfase
 * Se crean metodos que facilitarán el crear los grafos en pantalla y dibujar las lineas haciendo representación de las aristas
  *
  */

namespace Ui {
class ServidorWidget;
}

class ServidorSocket;

class ServidorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ServidorWidget(QWidget *parent = nullptr);
    ~ServidorWidget();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_encenderButton_clicked();
    void on_clientesConectadosListwidget_clicked(const QModelIndex &index);
private:
    Ui::ServidorWidget *ui;
    ServidorSocket *mServidorSocket;
    ServidorSocket *makeServidor();

public:
    void CrearGrafo();
    void aristasdobles(std::string uno, std::string dos,int peso);
};

#endif // SERVIDORWIDGET_H
