//
// Created by mavros on 26/6/21.
//

#ifndef PROYECTOIII_TECFILESYSTEM__CESEARCH_H
#define PROYECTOIII_TECFILESYSTEM__CESEARCH_H

#include <QWidget>
#include <unistd.h>
#include "ConnectionManager.h"


QT_BEGIN_NAMESPACE
namespace Ui { class cesearch; }
QT_END_NAMESPACE

/**
 * Ventana con el ceROBOT
 */
class cesearch : public QWidget {
Q_OBJECT

public:

    /**
     * Constructor de la ventana
     * @param parent
     */
    explicit cesearch(QWidget *parent = nullptr);

    /**
     * Destructor de la ventana. También se encarga de cerrar la conexión de los sockets
     */
    ~cesearch() override;

private slots:

    /**
     * Busca y guarda un archivo de texto en el server
     */
    void on_OpenFile_clicked();

private:

    /**
     * Contiene los elementos de la ventana
     */
    Ui::cesearch *ui;

    /**
     * Conexión con sockets
     */
    ConnectionManager connManager;
};


#endif //PROYECTOIII_TECFILESYSTEM__CESEARCH_H
