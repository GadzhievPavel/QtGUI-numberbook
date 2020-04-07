#ifndef PERSON_H
#define PERSON_H
#include <QString>
using namespace std;
class Person
{
private:
    int id;
    QString name,number;
public:
    Person();
    Person(int id, QString name, QString number );
    int getId();
    QString getName();
    QString getNumber();
    void setId(int id);
    void setName(QString name);
    void setNumber(QString number);
};

#endif // PERSON_H
