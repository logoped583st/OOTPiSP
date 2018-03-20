#include "headermain.h"

void Person::add_1(Person *a)
{
    a->next = begin;
    begin = a;
}

void Person::add_2()
{
    Person *a = this;
    a->next = begin;
    begin = a;
}

Person::Person()
{
    cout << "Constructor for Person: " << this << endl;
    add_1(this);
}

Person::~Person()
{cout << "Destructor for Person: " << this << endl;}

void Person::show()
{cout << "Person name: " << name << endl;}

void Person::param()
{
    string str;
    cout << "Person name: ";
    cin >> str;
    name = str;
}

void Person::show_list()
{
    Person *q = begin;

    while (q)
    {
        q->show();
        q = q->next;
    }
}
