#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Student{
	public:
		Student(); 
		void setstudent(string nm,int nu,int math,int english);
		void guide();
		void showbase();//显示基本数据函数 
		void showstatic();//显示静态数据函数 
		~Student();
	private:
		string name;
		int num,mathscore,englishscore;
		static int mathtotalscore;
		static int englishtotalscore;
		static int count;
};
int Student::mathtotalscore=0;
int Student::englishtotalscore=0;
int Student::count=0;
int main(int argc, char** argv) {
	int n;
	cout<<"How many students will you record?"<<endl;
	cin>>n;
	Student *stu=new Student[100];
	for(int i=0;i<n;i++)
	{
		stu[i].guide();
		string nm;
		int nu,math,english;
		cin>>nm;
		cin>>nu>>math>>english;
		stu[i].setstudent(nm,nu,math,english);
	}
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	char adjout;
	cout<<"Whether to output data?"<<endl<<"Y or N"<<endl;
	cin>>adjout;
	if(adjout=='Y')
	{
		for(int j=0;j<n;j++)
		{
			stu[j].showbase();
			stu[j].showstatic();
			cout<<endl;
			delete []stu;
		}
	}
	delete stu;
	return 0;
}
Student::Student(){
	name='\0';
	num=0;
	mathscore=0,englishscore=0;
	mathtotalscore+=mathscore;
	englishtotalscore+=englishscore;
	count++;
}
void Student::setstudent(string nm,int nu,int math,int english){
	name=nm;
	num=nu;
	mathscore=math,englishscore=english;
	mathtotalscore+=mathscore;
	englishtotalscore+=englishscore;
	count++;
}
void Student::guide(){
	cout<<"Please enter the data about the student : "<<endl;
	cout<<"name   number   math-score   English-score"<<endl;
}
void Student::showbase(){
	cout<<"The No."<<num<<" student's information : "<<endl;
	cout<<"Name : "<<name<<endl;
	cout<<"Math score : "<<mathscore<<endl;
	cout<<"English score : "<<englishscore<<endl;
}
void Student::showstatic(){
	cout<<"The total math score : "<<mathtotalscore<<endl;
	cout<<"The total English score : "<<englishtotalscore<<endl;
}
Student::~Student(){}




