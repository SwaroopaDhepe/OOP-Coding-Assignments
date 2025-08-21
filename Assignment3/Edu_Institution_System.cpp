/*Educational Institution System
Design an educational Institution that maintains a database
of all staff members where the database is segregated into a
number of classes having hierarchical relationships. Define
all classes with suitable data members and required
member functions to build the database and fetch individual
details.*/

#include<iostream>
using namespace std;
//Base Class
class staff{
protected:
    string name, dept;
    int staff_id;
public:
    void accept();
    void display();
};
void staff::accept(){
    cout<<"Enter staff name: ";
    cin>>name;
    cout<<"Enter staff ID: ";
    cin>>staff_id;
    cout<<"Enter staff department: ";
    cin>>dept;
}
void staff::display(){
	cout<<"\n----------------------------------\n";
	cout<<"Staff Information\n";
	cout<<"----------------------------------\n";
    cout<<"Name      : "<<name<<endl;
    cout<<"Staff ID  : "<<staff_id<<endl;
    cout<<"Department: "<<dept<<endl;
}
//Derived class 1
class teacher : public staff{
    string role, experience;
public:
    void accept2();
    void display2();
};
void teacher::accept2(){
    accept();
    cout<<"Enter Subject: ";
    cin>>role;
    cout<<"Enter staff experience(in years): ";
    cin>>experience;
}
void teacher::display2(){
    display();
    cout<<"Staff Subject   : "<<role<<endl;
    cout<<"Staff experience: "<<experience<<endl;
}
//Derived class 2
class support : public staff{
    string rolee, section;
public:
    void accept3();
    void display3();
};
void support::accept3(){
    accept();
    cout<<"Enter support staff role: ";
    cin >>rolee;
    cout<<"Enter staff section: ";
    cin>>section;
}
void support::display3(){
    display();
    cout<<"Support Staff Role: "<< rolee<<endl;
    cout<<"Staff Section     : "<< section<<endl;
}
int main(){
		int n;
		cout<<"========== Teacher Registration ==========\n";
        cout<<"How many teachers do you want to add: ";
        cin>>n;
        teacher teachers[n];
        for(int i=0; i<n; i++){
            cout<<"\nEnter details for teacher "<<i+1<<"\n";
            teachers[i].accept2();
        }
        cout<<"\n------All Teacher Details------\n";
        for(int i = 0; i < n; i++){
            cout<<"\nTeacher "<<i+1<<"\n";
            teachers[i].display2();
        }
		int m;
		cout<<"\n========== Support Staff Registration ==========\n";
		cout<<"How many Support staff do you want to add: ";
		cin>>m;
		support supports[m];
		for(int i=0; i<m; i++){
			cout<<"\nEnter information of support staff "<<i+1<<endl;
			supports[i].accept3();
		}
		cout<<"\n------All Support Staff Details------\n";
        for(int i=0; i<m; i++){
            cout<<"\nSupport Staff "<<i+1<<"\n";
            supports[i].display3();
        }
	
    return 0;
}

