/*
    ================================================================================================================
    Author - Kunal Moharkar
    Roll no. - BT18CSE018
    ================================================================================================================
*/

#include<iostream>
#include "Person.h"

int Person::count = 0;

Person::Person(string name,Department dept,string house_num,string street_name,string city_name):MAX(6)
{   
    count++;
    this->name = name;
    this->dept = dept;
    this->address.setAddress(house_num,street_name,city_name);   
}

string Person::getName()
{
    return this->name;
}

Department Person::getDept()
{
    return this->dept;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setDept(Department dept)
{
    this->dept = dept;
}

void Person::changeName(string name)
{
    this->setName(name);
}

void Person::changeAddress(string house_num,string street_name,string city_name)
{
    this->address.setAddress(house_num,street_name,city_name);
}

int Person::getID()
{
    return count;
}

void Person::print()
{
    cout<<"\nPerson Details:\n";
    cout<<"Name:"<<this->name<<"\n";
    cout<<"Department:"<<this->dept.name<<"\n";
    this->address.print();
}

void Person::printAddress()
{
    cout<<"\nAddress Details\n";
    cout<<"House number:"<<this->address.getHouse_num()<<"\n";
    cout<<"Street name:"<<this->address.getStreet_name()<<"\n";
    cout<<"City name:"<<this->address.getCity_name()<<"\n";
}