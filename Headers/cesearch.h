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

class cesearch : public QWidget {
Q_OBJECT

public:
    explicit cesearch(QWidget *parent = nullptr);

    ~cesearch() override;

private slots:
    void on_OpenFile_clicked();

private:
    Ui::cesearch *ui;
    ConnectionManager connManager;
};


#endif //PROYECTOIII_TECFILESYSTEM__CESEARCH_H
