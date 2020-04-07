#ifndef DBHELPER_H
#define DBHELPER_H
#include <QtSql>
#include <vector>
#include <string>
#include <person.h>
class DBHelper
{
private:
   QSqlDatabase dbase;
   QString getNumber(QString text);

public:
    DBHelper();
    void open();
    vector<Person> getAllContact();
    void addContact(QString name,QString number);
    void deleteContact(QString number);
};

#endif // DBHELPER_H
