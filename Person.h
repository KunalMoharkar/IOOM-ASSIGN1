/*
    ================================================================================================================
    Author - Kunal Moharkar
    Roll no. - BT18CSE018
    ================================================================================================================
*/

//person class
#ifndef PERSON_H    //prevent multiple inclusions
#define PERSON_H
#include<string>
#include "Address.h"
using namespace std;

typedef struct Department{

    int id;
    string name;

}Department;

class Person{
    private:
        string name;
        Address address;
        static int count;
        const int MAX;
        Department dept;
    
    public:
       Person(string name,Department dept,string house_num,string street_name,string city_name);
       string getName();
       Department getDept();
       void setName(string name);
       void setDept(Department dept);
       void changeName(string name);
       void changeAddress(string house_num,string street_name,string city_name);
       static int getID();
       void printAddress();
       virtual void print();
};

#endif