/*
    ================================================================================================================
    Author - Kunal Moharkar
    Roll no. - BT18CSE018
    ================================================================================================================
*/
#include<iostream>
#include "Faculty.h"

Faculty::Faculty(string name,Department dept,Designation desig,string house_num,string street_name,string city_name)
        :Person(name,dept,house_num,street_name,city_name),
        F_ID(Person::getID())
{   
    int maxCourses = this->getMAX();
    this->num_courses = 0;
    this->desig = desig;
    this->courses = new string[maxCourses];
}

Faculty::~Faculty()    //prevent memory leak with dynamic allocation
{
    delete[] this->courses;
}

void Faculty::getCourses()
{
    int i;
    cout<<"\nCourse List:\n";
    cout<<"Sr.no"<<"\t"<<"Course"<<"\n";
    for(i=0;i<this->num_courses;i++)
    {
        cout<<i+1<<"\t"<<this->courses[i]<<"\n";
    }
}

bool Faculty::addCourses(string course)
{
    if(this->num_courses<this->getMAX()) //if courses are less than max limit
    {
        this->courses[this->num_courses] = course;
        this->num_courses++;
        return true;
    }

    return false;
}

bool Faculty::removeCourses(string course)
{
    int i=0,index;
    while(i<this->getMAX()&&course.compare(this->courses[i])!=0) //get index of entered course
    {
        i++;
    }
    index = i;

    if(index<this->getMAX())       //course exists
    {
        for(i=index;i<this->num_courses-1;i++)
        {
            this->courses[i]=this->courses[i+1];
        }
        this->num_courses--;
        return true;
    }

    return false;
}

Designation Faculty::getDesignation()
{
    return this->desig;
}

void Faculty::print()
{
    cout<<"\nFaculty Details\n";
    cout<<"Faculty Id:"<<this->F_ID<<"\n";
    cout<<"Name:"<<this->getName()<<"\n";
    cout<<"Deparment:"<<this->getDept().name<<"\n";
    cout<<"Designation:"<<this->getDesignation().name<<"\n";
    this->printAddress();
    this->getCourses();
}


