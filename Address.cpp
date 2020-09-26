/*
    ================================================================================================================
    Author - Kunal Moharkar
    Roll no. - BT18CSE018
    ================================================================================================================
*/
#include <iostream>
#include "Address.h"

Address::Address(){}

Address::Address(string house_num,string street_name,string city_name)
{
    this->house_num = house_num;
    this->street_name = street_name;
    this->city_name = city_name;
}

string Address::getHouse_num(){
    return this->house_num;
}

string Address::getStreet_name(){
    return this->street_name;
}

string Address::getCity_name(){
    return this->city_name;
}

void Address::setHouse_num(string house_num)
{
    this->house_num = house_num;
}

void Address::setStreet_name(string street_name)
{
    this->street_name = street_name;
}

void Address::setCity_name(string city_name)
{
    this->city_name = city_name;
}

void Address::setAddress(string house_num,string street_name,string city_name)
{
    this->house_num = house_num;
    this->street_name = street_name;
    this->city_name = city_name;
}

void Address::print()
{
    cout<<"\nAddress Details\n";
    cout<<"House Number:"<<this->house_num<<"\n";
    cout<<"Street Name:"<<this->street_name<<"\n";
    cout<<"City Name:"<<this->city_name<<"\n";
}