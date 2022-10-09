/*

- Polymorphism :
- Design patterns
    - Singleton pattern
    - Factory pattern
- static




*/

#include<string>
#include <iostream>
#include <vector>


/******************* Define the base class *******************/ 
class Person { 

    static int person_count;
    protected: 
        std::string name; // name
        std::string idNum; // university ID number
        int age; // Age
    
    public:
        // Functions are declared public 
        Person(std::string name, std::string idNum, int age); // constructor
        ~Person(); // Destructor
        void getInfo(); // print information
        std::string getName(); // retrieve name
        std::string getIdNum(); // retrieve idNum
        int getAge(); // retrieve age
        int get_person_count();
};

int Person::person_count = 0;

Person::Person(std::string name, std::string idNum, int age){
    person_count++;
    this->name = name;
    this->idNum = idNum;
    this->age = age;
    std::cout << "Person constructed successfully!" << std::endl;
}
Person::~Person(){
    std::cout << "Person destructed successfully!" << std::endl;
    person_count--;
}
void Person::getInfo() { 
    std::cout << "Name : " << name << std::endl;
    std::cout << "IDnum : " << idNum << std::endl;
    std::cout << "Age : " << age << std::endl;
}
std::string Person::getName(){
    return name;
}
std::string Person::getIdNum(){
    return idNum;
}
int Person::getAge(){
    return age;
}
int Person::get_person_count()
{
    return person_count;
}


/******************* Define the first child class *******************/
class Student : public Person {
    private:
        std::string major; // major subject
        int gradYear; // graduation year
    
    public:
        Student(std::string name, std::string idNum, int age); // Constructor
        ~Student(); // destructor
        void changeMajor(const std::string& newMajor); // change major
};


Student::Student(std::string name, std::string idNum, int age)
    :Person(name, idNum, age){
        std::cout << "Student object constructed successfully!" << std::endl;
}
Student::~Student(){
    std::cout << "Student object destructed successfully!" << std::endl;
}



/******************* Define the second child class *******************/
class Employee : public Person{
    private:
        float salary;
        std::string company;

    public:
        // Constructor & destructor
        Employee(std::string name, std::string idNum, 
                int age, float salary, std::string company);
        ~Employee();
        float getSalary();
        std::string getCompany();

};

Employee::~Employee()
{
    std::cout << "Employee destructed successfully !" << std::endl;
}
Employee::Employee(std::string name, std::string idNum, 
                int age, float salary, std::string company):Person(name, idNum, age)
                {
                    this->salary = salary;
                    this->company = company;
                }
float Employee::getSalary(){return salary;}
std::string Employee::getCompany(){return company;}





/******************* The main function *******************/


int main()
{

    Employee emp1("hamza", "N145896", 23, 2500, "STmic");
    
    std::cout << emp1.getName() << std::endl;
    std::cout << emp1.get_person_count() << std::endl;




    //cout << student1.name << endl;


    /*
    Person person("Mary", "12-345");


    vector<int> v = {1, 2, 3};

    
    v.insert(v.begin() + 1, 5);

    cout << v[0] << endl;


    // Elements
    cout << v[1] << endl;
    cout << v.front() << v.back() << endl;
    cout << v.size() << endl;

    v.push_back(4);
    cout << v.size() << endl;

    //cout << "Value poped back  : " << endl;
    v.pop_back();


    cout << v.size() << endl;
    */
    return 0;
}