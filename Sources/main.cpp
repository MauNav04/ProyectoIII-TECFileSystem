//
// Created by mavros on 26/6/21.
//

#include "../Headers/cesearch.h"

#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    cesearch w;
    w.show();
    return a.exec();
}
