#include<iostream>
using namespace std;

class Person{
	protected:
		string name;
		int age;
		
	public:
		Person(string n,int a){
			name = n;
			age = a;
		}	
		void display(){
			cout<<"Name :"<<name<<"Age :"<<age<<endl;
		}
};

class Student : virtual public Person{
	protected:
		int rollNumber;
		string branch;
		int marks;
		
	public:
		Student(string n,int a,int rn,string b,int m){
			name = n;
			age = a;
			rollNumber = rn;
			branch = b;
			marks = m;
		}
		
		void calculateCGPA(){
			return marks / 10;
		}
		
		void display() const override{
			cout<<"Student Details:"<<endl;
			cout<<"Name: "<<name<<",Age: "<<age<<endl;
			cout<<"Roll Number: "<<rollNumber<<endl;
			cout<<"Branch: "<<branch<<endl;
			cout<<"Marks: "<<marks<<",CGPA: "<<calculateCGPA()<<endl;
		}	
	
	friend class Administration;	
};

class Faculty : virtual public Person{
	protected:
		int facultyID;
		string department;
		float salary;
	
	public:
		Faculty(string n,int a,int id,string dept,float sal){
			name = n;
			age = a;
			facultyID = id;
			department = dept;
			salary = sal;
		}	
		
		void display() override{
			cout<<"Faculty Details:"<<endl;
			cout<<"Name: "<<name<<",Age: "<<age<<endl;
			cout<<"Faculty ID: "<<facultyId<<endl;
			cout<<"Department: "<<department<<endl;
			cout<<"Salary: "<<salary<<endl;
		}
};

class TeachingAssistant() : public Student, public Faculty {
	public:
		TeachingAssistant(string n,int a,int rn,string b,int id,string dept,float sal){
			name = n;
			age = a;
			rollNumber = rn;
			facultyID = id;
			department = dept;
			salary = sal;	
		}
		
		void display() override{
			cout<<"Teaching Assistant Detail:"<<endl;
			cout<<"Name: "<<name<<",Age: "<<age<<endl;
			cout<<"Roll Number: "<<rollNumber<<endl;
			cout<<"Branch: "<<branch<<endl;
			cout<<"Faculty ID: "<<facultyID<<endl;
			cout<<"Department: "<<department<<endl;
			cout<<"Salary: "<<salary1<<endl;			
		}
};

class Administration{
	public:
		void displayDetails(Student &s, Faculty &f){
			cout<<"Administration Friend Function:"<<endl;
			cout<<"Name "<<s.name<<"from "<<s.branch<<"scored "<<s.marks<<"marks."<<endl;
			cout<<"Faculty "<<f.name<<"teaches "<<f.department<<"."<<endl;
		}
};
int main()
{

	Student s("Raj Malhotra",20,2023101,"CSE (AI-ML)",89);
	Faculty f("Dr. A. Sharma",45,1001,"Computer Science",120000);
	TeachingAssistant ta("Priya Desai",25,1923105,"CSE (AI-ML)",2005,"Atrificial Intelligence,35000");
	Administration ad;
	
	s.display();
	cout<<endl;
	
	f.display();
	cout<<endl;
	
	ta.display();
	cout<<endl;
	
	ad.displayDetails(s,f);
	return 0;
}
