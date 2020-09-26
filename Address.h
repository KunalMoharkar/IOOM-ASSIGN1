/*
    ================================================================================================================
    Author - Kunal Moharkar
    Roll no. - BT18CSE018
    ================================================================================================================
*/

//Address class

#ifndef ADDRESS_H    //prevent multiple inclusions
#define ADDRESS_H
#include <string>
using namespace std;

class Address{
    
    private:
        string house_num;
        string street_name;
        string city_name;
    
    public:
        Address();
        Address(string house_num,string street_name,string city_name);
        string getHouse_num();
        string getStreet_name();
        string getCity_name();
        void setHouse_num(string house_num);
        void setStreet_name(string street_name);
        void setCity_name(string city_name);
        void setAddress(string house_num,string street_name,string city_name);   
        void print();    
};

#endif