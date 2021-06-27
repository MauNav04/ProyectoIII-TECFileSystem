//
// Created by mavros on 26/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_cesearch.h" resolved

#include "../Headers/cesearch.h"
#include "ui_cesearch.h"


cesearch::cesearch(QWidget *parent) :
        QWidget(parent), ui(new Ui::cesearch) {
    ui->setupUi(this);
}

cesearch::~cesearch() {
    delete ui;
    ::close(connManager.getSock());
}

