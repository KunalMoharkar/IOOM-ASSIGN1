/*
    ================================================================================================================
    Author - Kunal Moharkar
    Roll no. - BT18CSE018
    ================================================================================================================
*/

#include<iostream>
#include "Student.h"

Student::Student(string name,Department dept,string house_num,string street_name,string city_name)
        :Person(name,dept,house_num,street_name,city_name),
        STUD_ID(Person::getID())
{   
        this->num_courses=0;
        this->courses = new string[6];
        this->grade = new int[6];
        
        for(int i=0;i<6;i++)       //initialize all grades to zero
        {
            this->grade[i] = 0;
        }
}   

Student::~Student()   //destructor to avoid memory leak due to dynamic allocation 
{ 
    delete[] this->courses;
    delete[] this->grade;
}

int Student::getNumCourses()
{
    return this->num_courses;
}

double Student::getAvgGrade()
{
    int i,sum=0;
    double avg;
    for(i=0;i<num_courses;i++)
    {
        sum+=this->grade[i];
    }

    avg = (double)sum/num_courses;

    return avg;
}

bool Student::addCourse(string course)
{   
    if(num_courses<6)
    {
        this->courses[num_courses] = course;
        this->num_courses++;
        return true;
    }

    return false;
}

int Student::getCourseIndex(string course)
{
    int i;
    for(i=0;i<this->num_courses;i++)
    {
        if(!course.compare(this->courses[i]))
        {
            return i;
        }
    }

    return -1;
}

bool Student::addCoursesGrade(string course,int grade)
{   
    int index = this->getCourseIndex(course);
    if(index!=-1)
    {
        this->grade[index] = grade;
        return true;
    }

    return false;
}

bool Student::dropCourse(string course)
{
    int index = this->getCourseIndex(course);
    int i;
    if(index!=-1)
    {
        for(i=index;i<this->num_courses-1;i++)
        {
            this->courses[i] = this->courses[i+1];
        }

        this->num_courses--;
        return true;
    }

    return false;
}

void Student::printGrade()
{   
    int i;
    cout<<"\nStudent Report:\n";
    cout<<"Sr.no"<<"\t"<<"Course"<<"\t"<<"Grade\n";
    for(i=0;i<num_courses;i++)
    {
        cout<<i+1<<"\t"<<this->courses[i]<<"\t"<<this->grade[i]<<"\n";
        
    }
}

void Student::getCourses()
{   
    int i;
    cout<<"\nCourse List:\n";
    cout<<"Sr.no"<<"\t"<<"Course"<<"\n";
    for(i=0;i<this->num_courses;i++)
    {
        cout<<i+1<<"\t"<<this->courses[i]<<"\n";
    }
 
}

void Student::print()
{
    cout<<"\nStudent Details:\n";
    this->printAddress();
    cout<<"Name:"<<this->getName()<<"\n";
    cout<<"Deparment:"<<this->getDept().name<<"\n";
    cout<<"Student Id:"<<this->STUD_ID<<"\n";
    cout<<"Number of courses:"<<this->num_courses<<"\n";
    this->printGrade();
}