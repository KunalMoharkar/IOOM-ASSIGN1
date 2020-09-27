/*
====================================================================================================================
        Author:Kunal Moharkar
        Roll no:BT18CSE018
===================================================================================================================        
*/
//Student class

#ifndef STUDENT_H //prevent multiple inclusions
#define STUDENT_H
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person{

    private:
        const int STUD_ID;
        int num_courses;
        string *courses;
        int *grade;
        int getId();
    public:
        Student(string name,Department dept,string house_num,string street_name,string city_name);
        ~Student();
        int getNumCourses();
        double getAvgGrade();
        bool addCourse(string course);
        bool addCoursesGrade(string course,int grade);
        bool dropCourse(string course);
        void printGrade();
        virtual void print();
        int getCourseIndex(string course);
        void getCourses();

};

#endif