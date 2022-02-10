#include <iostream>
#include <list>
using namespace std;

class Employee{
private:
    /* data */
protected:
    int Age;
    string Name;
public: 
    Employee(int age, string name){
        Age = age;
        Name = name;
    }
    virtual void Information(){
        cout << "Employee Name is: " << Name << " and his/her age is: " << Age << endl;
    }
};
class Teacher: public Employee{
private:
    /* data */
public: 
    Teacher(int age, string name): Employee(age, name){
    }
    void Information(){
        cout << "Teacher Name is: " << Name << " and his/her age is: " << Age << endl;
    }
};
//*********************************//
//***********   Main   ************//
//*********************************//
int main()
{

    Employee emp1 (35, "Rasoul");
    Teacher tec1(27, "Ida");

//-------- Static Binding ---------//    
/*  emp1.Information();
    tec1.Information(); */

//-------- Dynamic Binding --------//
    list<Employee*> employees;
    employees.push_back(& emp1);
    employees.push_back(& tec1);

    for (Employee* empPtr : employees)
    {
        empPtr -> Information();
    }

    return 0;
}