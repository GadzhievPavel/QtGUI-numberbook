#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.open();
    ui->mode->setText(mode);
    makeWidget();
}
vector<Person> contacts;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString name = ui->name->toPlainText();
    QString number = ui->number->toPlainText();
    db.addContact(name,number);
    mode="Контакт добавлен";
    ui->mode->setText(mode);
    ui->listWidget->clear();
    makeWidget();
}

void MainWindow::on_delete_2_clicked()
{
    if(mode!="Режим удаления"){
        mode="Режим удаления";
        ui->delete_2->setText("Не удалять");

    }else{
        mode="Режим добавления номеров";
        ui->delete_2->setText("Удалить");
    }
    ui->mode->setText(mode);
}

void MainWindow::makeWidget()
{
    contacts = db.getAllContact();
    for(int i =0; i<contacts.size();i++){
        ui->listWidget->addItem(contacts.at(i).getName()+"  "+contacts.at(i).getNumber());
    }
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if(mode =="Режим удаления"){
        QString s = item->text();
        db.deleteContact(s);
        ui->listWidget->clear();
        makeWidget();
    }
}
