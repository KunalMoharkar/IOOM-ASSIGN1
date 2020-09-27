/*
    ================================================================================================================
    Author - Kunal Moharkar
    Roll no. - BT18CSE018
    ================================================================================================================
*/
#include "Person.cpp"
#include "Address.cpp"
#include "Student.cpp"
#include "Faculty.cpp"

#define DEPT_COUNT 7
#define DESIGNATION_COUNT 4

enum roles {FACULTY=1,STUDENT=2}; //roles


void print_all(Person *p)
{
    p->print();
}


int main()
{   
   
    const Department departments[DEPT_COUNT] = {{1,"CSE"},{2,"ECE"},{3,"EEE"},{4,"MECH"},{5,"CHEM"},{6,"META"},{7,"MIN"}}; //dept list
    const Designation designations[DESIGNATION_COUNT] = {{1,"HOD"},{2,"PROFESSOR"},{3,"ASSISTANT PROFESSOR"},{4,"TEACHER ASSISTANT"}};//desig list

    int action=1,i,dept_id,desig_id,role,grade;
    string name,course,house_num,street_name,city_name;

    while(action)       //User interface
    {   

        cout<<"\nSELECT YOUR ACTION:\n";
        cout<<"1.Add new User"<<"\n";
        cout<<"2.quit"<<"\n";
        cin>>action;

        if(action==2)   //quit the system
        {
            break;
        }

        cout<<"1.Enter Name:";                  //perso Credentails
        cin>>name;
        cout<<"2.Choose Department:\n";
        cout<<"Id"<<"\t"<<"Name\n";
        for(i=0;i<DEPT_COUNT;i++)
        {
            cout<<departments[i].id<<"\t"<<departments[i].name<<"\n";
        }

        cout<<"Enter Department Id:";
        cin>>dept_id;
        cout<<"\nEnter Address Details\n";
        cout<<"Enter House number:";
        cin>>house_num;
        cout<<"Enter Street name:";
        cin>>street_name;
        cout<<"Enter City name:";
        cin>>city_name;

        cout<<"\nChoose Role:\n";
        cout<<"press 1 for Faculty\n";
        cout<<"press 2 for Student\n";
        cin>>role;

        if(role==FACULTY)                 //add  attributes of Faculty
        {
            cout<<"2.Choose Designation:\n";
            cout<<"Id"<<"\t"<<"Name\n";
            for(i=0;i<DESIGNATION_COUNT;i++)
            {
                cout<<designations[i].id<<"\t"<<designations[i].name<<"\n";
            }

            cout<<"Enter Designation Id:";
            cin>>desig_id;

            Faculty *fac = new Faculty(name,departments[dept_id-1],designations[desig_id-1],house_num,street_name,city_name);
            cout<<"\nFaculty Successfully Added\n";

            cout<<"\nSelect Action:\n";
            cout<<"1.Add course\n";
            cout<<"2.quit\n";
            cin>>action;

            if(action==2)
            {
                break;
            }
            
            while(action)
            {   
                cout<<"\nPress 1 to continue adding -1 to exit\n";
                cin>>action;
                if(action==-1)
                {
                    break;
                }
                cout<<"\ncurrent courses:\n";
                fac->getCourses();
                cout<<"Enter Course Name:";
                cin>>course;
                if(!fac->addCourses(course))
                {
                    cout<<"Max limit of Courses exceeded\n";
                }
            }   
            
            cout<<"\nNEW USER ADDED WITH CREDENTIALS\n";
            cout<<"========================================================================================"<<"\n";
            fac->print();
            cout<<"========================================================================================"<<"\n";

        }
        else   //attributes for student
        {
            Student *stu = new Student(name,departments[dept_id-1],house_num,street_name,city_name);
            cout<<"\nStudent Successfully Added\n";
            cout<<"\nSelect Action:\n";
            cout<<"1.Add course\n";
            cout<<"3.quit\n";
            cin>>action;

            if(action==3)
            {
                break;
            }

            while(action)       //add courses
            {   
                    cout<<"\nPress 1 to continue adding -1 to exit\n";
                    cin>>action;
                    if(action==-1)
                    {
                        break;
                    }
                    cout<<"\ncurrent courses:\n";
                    stu->getCourses();
                    cout<<"Enter Course Name:";
                    cin>>course;
                    if(!stu->addCourse(course))
                    {
                        cout<<"Max limit of Courses exceeded\n";
                    }
            }   
            
        
            while(action) //add grades
            {   
                cout<<"\nPress 1 to continue adding grades -1 to exit\n";
                cin>>action;
                if(action==-1)
                {
                    break;
                }
                cout<<"\ncurrent courses and grades:\n";
                stu->printGrade();
                cout<<"Enter Course Name:";
                cin>>course;
                cout<<"Enter grade:";
                cin>>grade;
                if(!stu->addCoursesGrade(course,grade))
                {
                    cout<<"Not a valid input\n";
                }
                   
            }
            
            cout<<"\nNEW USER ADDED WITH CREDENTIALS\n";
            cout<<"========================================================================================"<<"\n";
            stu->print();
            cout<<"========================================================================================"<<"\n";

        }        
    }



    //Run time polymorphism exhibited as virtual methods print is used
    cout<<"======================================================================================================"<<"\n";
    cout<<"Demonstration of Print all method\n";

    Person *personArray[3]; // array of pointers to person type

    Person *p = new Person("DummyPerson",departments[0],"1","Laxmi Nagar Road","Nagpur");//dummmyPerson

    Student *s = new Student("DummyStudent",departments[0],"34","Mhalgi Nagar Road","Nagpur");//dummyStudent
    s->addCourse("IOOM");
    s->addCourse("OS");
    s->addCourse("TOC");
    s->addCoursesGrade("IOOM",9);
    s->addCoursesGrade("OS",8);
    s->addCoursesGrade("TOC",10);

    Faculty *f = new Faculty("DummyFaculty",departments[0],designations[1],"122","Ram Nagar Road","Mumbai");//DummyFac
    f->addCourses("CPL");
    f->addCourses("ML");
    f->addCourses("AI");

    personArray[0] = p;
    personArray[1] = s;
    personArray[2] = f;

    for(i=0;i<3;i++)
    {
        print_all(personArray[i]);
    }

    cout<<"======================================================================================================"<<"\n";
}

