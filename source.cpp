#include "headermain.h"

class Prepod:public Person {
    int year;
public:
    Prepod() :Person() {
        cout << "Prepod " << this << endl;
    }

    virtual void show() {
        cout <<  " Prepod name: " << name << endl;
        cout << "Prepod yers: " << year << endl;
    }
    void param() {
        string str;
        int y;
        cout << "Prepod name ";
        cin >> str;
        name = str;
        cout << "Years: ";
        cin >> y;
        year = y;
    }
    ~Prepod() {
        cout << "Destructor Prepod" << this << endl;
    }
};

class Student :public Person {
    string type;
public:
    Student() :Person() {
        cout << "Constructor Student " << this << endl;
    }
    void show() {
        cout << "Student name " << name << endl;
        cout << " Student name" << type << endl;
    }

    ~Student() {
        cout << "Destructor Student" << this << endl;
    }

    void param() {
            string str;
            string typ;
            cout << "Student name: ";
            cin >> str;
            name = str;
            cout << "Student kurs ";
            cin >> typ;
            type = typ;
        }
};

class ZavKaf :public Prepod{
    string detailname;

public:
    ZavKaf() :Prepod() {
        cout << "Constructor ZavKaf" << this << endl;
    }
    void show() {
        cout << "ZavKaf name: " << name << endl;
        cout << "ZavKaf SecondName: " << detailname << endl;
    }


    void setSecondName(){
        string text;
        cout<<"vvedite second name zaf kaf";
        cin>>text;
        this->detailname=text;
    }

    ~ZavKaf() {
        cout << "Destructor for ZavKaf" << this << endl;
    }
};

Person *Person::begin;

int main()
{
    Person::begin = NULL;
    auto *prepod= new Prepod();
    auto *person = new Student();
    auto *zav=new ZavKaf();
    string text;
    cout << "Prepod:" << endl;
    prepod->param();
    cout << "Student:" << endl;
    person->param();
    cout << "ZavKaf:" << endl;
    zav->param();
    zav->setSecondName();

    cout << endl;
    prepod->show();
    person->show();
    zav->show();
    cout << endl;
    Person :: show_list();
    cout << endl;

    delete zav;
    delete person;
    delete prepod;

    system("pause");
    return 0;
}
