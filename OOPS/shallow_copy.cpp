/*A shallow copy of an object copies all the memebres value from one object to another.
 shallow copy copies the same address.
hence you change any memeber value of object, it will reflect for another object.
*/

//Note:- if any member created using DMA so, that time create your own "Deep Copy Constructor."
#include<iostream>
using namespace std;
class Student
{
    public: string name;
             double *cgpaPtr;
    
            void showdata();
            Student(string name, double cgpa)
            {
                this->name = name;
                this->cgpaPtr = new double;
                *this->cgpaPtr = cgpa;
            }
            Student(Student &C)
            {
                this->name=C.name;
                this->cgpaPtr=C.cgpaPtr;
            }
            ~Student()
            {
                cout<<"Deleting Everyting....!\n";
            }
};

void Student::showdata()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Cgpa: "<<*cgpaPtr<<endl;
}
int main()
{
    Student s1("Tejas",5.8);
    s1.showdata();

    Student s2(s1);
    s2.showdata();

    *(s2.cgpaPtr)=9.8;
    cout<<"---------------"<<endl;
    s1.showdata();
    s2.showdata();

}