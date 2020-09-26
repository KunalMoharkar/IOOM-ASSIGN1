/*
====================================================================================================================
        Author:Kunal Moharkar
        Roll no:BT18CSE018
===================================================================================================================        
*/

// Faculty Class

#ifndef FACUTLY_H  //prevent multiple inclusions
#define FACULTY_H
#include <string>
#include "Person.h"

using namespace std;

typedef struct Designation{

    int id;
    string name;

}Designation;

class Faculty : public Person{

    private:
        const int F_ID;
        int num_courses;
        string *courses;
        Designation desig;
        
    public:
        Faculty(string name,Department dept,Designation desig,string house_num,string street_name,string city_name);
        int getId();
        Designation getDesignation();
        void getCourses();
        bool addCourses(string course);
        bool removeCourses(string course);
        virtual void print();
};

#endif