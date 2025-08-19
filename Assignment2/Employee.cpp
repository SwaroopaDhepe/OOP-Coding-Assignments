/*Employee Information System
Develop a program in C++ to create a database of an
employee's information system containing the following
fields: Name, employee ID, Department, Date of Joining,
Contact address, Telephone number etc. Construct the
database with suitable member functions to accept and
print employee details. Make use of constructor types,
destructor, static members, inline function and dynamic
memory allocation using operators-new and delete*/


#include <iostream>
#include <string>
using namespace std;
class employee{
private:
    string name, dept, address;
    int id, jdate, num;
    static int count;//static member
public:
   //Inline function
   inline void printEmployeeHeader() {
    cout << "\n------Employee Information------";
}
    //Default constructor
    employee(){
        name = dept = address = "";
        id = jdate = num = 0;
        count++;
        cout << "\n[Default constructor called]";
    }
    //Parameterized constructor
    employee(string n, string d, string a, int i, int dt, int no){
        name = n;
        dept = d;
        address = a;
        id = i;
        jdate = dt;
        num = no;
        count++;
        cout << "\n[parameterized constructor called]";
    }
    //Copy constructor
    employee(const employee &e){
        name = e.name;
        dept = e.dept;
        address = e.address;
        id = e.id;
        jdate = e.jdate;
        num = e.num;
        count++;
        cout << "\n[Copy constructor called]";
    }
    //Destructor
    ~employee(){
        count--;
        cout << "\n[Destructor called for employee: " << name << "]";
    }
    void accept();
    void display();
    static void show_total_count(){
        cout<<"\nTotal count: "<<count<<endl;
    }
};
int employee::count = 0;

void employee::accept(){
    cin.ignore();
    cout << "\nEnter name: ";
    getline(cin, name);
    cout << "Enter department: ";
    getline(cin, dept);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter joining date (yyyymmdd): ";
    cin >> jdate;
    cout << "Enter phone number: ";
    cin >> num;
}
void employee::display(){
    printEmployeeHeader(); // calling inline function
    cout << "\nName: " << name;
    cout << "\nDepartment: " << dept;
    cout << "\nAddress: " << address;
    cout << "\nEmployee ID: " << id;
    cout << "\nJoining Date: " << jdate;
    cout << "\nPhone Number: " << num << endl;
}
int main(){
    employee emp1, emp2;
    cout << "\nEnter details for Employee 1:";
    emp1.accept();
    cout << "\nEnter details for Employee 2:";
    emp2.accept();
    cout << "\nDisplaying details of Employee 1:";
    emp1.display();
    cout << "\nDisplaying details of Employee 2:";
    emp2.display();
    // Create employee 3 as a copy of employee 1
    employee emp3 = emp1;
    cout << "\nDisplaying details of Employee 3 (copied from Employee 1):";
    emp3.display();
    //New 
    employee *ptr = new employee( "Jui", "tech", "pune", 1987, 12, 345678912);
    cout<<"\nDisplaying newly created employee (ptr): ";
    ptr->display();
    //Delete
    delete ptr;
    employee::show_total_count();
    return 0;
}
