#include "dbhelper.h"


QString DBHelper::getNumber(QString text)
{
    QString out="";
    for (int var = 0; var < text.length(); ++var) {
        if(text.at(var)>= '0' && text.at(var)<='9'){
            out=out+text.at(var);
        }
    }
    return out;
}

DBHelper::DBHelper()
{

}

void DBHelper::open()
{
    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("data.sqlite");
    if (!dbase.open()) {
        qDebug() << "Что-то пошло не так!";
    }else{
        qDebug()<<"База данных открыта";
    }
}

vector<Person> DBHelper::getAllContact(){
    QSqlQuery query;
    QString queryString = "SELECT * from book";
    if(!query.exec(queryString)){
        qDebug()<<"Ошибка при запросе Контактов";
    }
    QSqlRecord rec = query.record();
    vector<Person> contacts;
    while(query.next()){
        Person person;
        person = Person(query.value(rec.indexOf("id")).toInt(),query.value(rec.indexOf("name")).toString(),
                        query.value(rec.indexOf("number")).toString());
        contacts.push_back(person);
    }
    //    for (int i = 0; i < contacts.size(); ++i) {
    //        qDebug()<<"ID"<<contacts.at(i).getId()<<"name"<<contacts.at(i).getName()<<"number"<<contacts.at(i).getNumber();
    //    }
    return contacts;
}

void DBHelper::addContact(QString name, QString number)
{
    QSqlQuery query;
    query.prepare("INSERT INTO book (name, number) VALUES (:name,:number);");
    query.bindValue(":name",name);
    query.bindValue(":number",number);
    query.exec();
}

void DBHelper::deleteContact(QString number)
{
    number = getNumber(number);
    QSqlQuery query;
    query.prepare("DELETE FROM book WHERE number = ?");
    query.addBindValue(number);
    query.exec();
}

