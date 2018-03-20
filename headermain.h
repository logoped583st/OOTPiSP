#pragma once

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    static Person *begin;
    Person *next;
    void add_1(Person *a);
    void add_2();
    Person();

    virtual ~Person();
    void show();

    virtual void param();
    static void show_list();
};