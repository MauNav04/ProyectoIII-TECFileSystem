//
// Created by mavros on 26/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_cesearch.h" resolved

#include <iostream>
#include "../Headers/cesearch.h"
#include "ui_cesearch.h"
#include "QFileDialog"
#include "QDir"
#include "QMessageBox"
#include "QFileInfo"


cesearch::cesearch(QWidget *parent) :
        QWidget(parent), ui(new Ui::cesearch) {
    ui->setupUi(this);
}

cesearch::~cesearch() {
    delete ui;
    ::close(connManager.getSock());
}

void cesearch::on_OpenFile_clicked() {
    std::string respuestaServer;
    std::string bookPath;
    std::string bookTitle;
    QDir dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
            foreach(QFileInfo books,dir.entryInfoList()){
            if(books.isFile() && books.suffix() == "txt") {
                ui->BookList->addItem("Book :" + books.absoluteFilePath());
                bookPath = books.absoluteFilePath().toUtf8().constData();
                bookTitle = books.baseName().toUtf8().constData();
                respuestaServer = connManager.mandarPeticion("{\"petition\" : \"addBook\", \"bookTitle\" : \""+bookTitle+"\", \"bookAuthor\" : \"unknown\", \"bookPath\" : \""+bookPath+"\"}");
            }
        }
}

