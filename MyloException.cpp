#include <iostream>
#include <cstring>
#include <fstream> 
using namespace std;
class MyloException//异常信息类，便于返回异常信息 
{
public:
    MyloException(const string messa){ message=messa; };
    ~MyloException(){};
    const string getMessage() { return message; }//一个返回异常信息的函数 
private:
    string message;
};

struct Student//学生结构体，便于建立结构体数组 
{
	string name;
	int idnumber;
	int score;
};

int main() 
{
	cout<<"输入数据："<<endl; 
	Student stu[3];//建立含3个学生信息的结构体，用于存储信息 
	cout<<"输入学生信息的格式为以下形式："<<endl;
	cout<<"姓名 学号(2018xxxx) C++分数(0~100)"<<endl;
	try{
/*		double a,b;
		cout<<"在try块："<<endl;
		cin>>a>>b;
		if(b==0) throw MyloException("除数不能为零");
		else if(a<b) throw (MyloException("a<b"));
		a/=b;
		cout<<"a/b="<<a<<endl;*/
		cout<<"进入try块"<<endl;
		for(int i=0;i<3;i++){
			cin>>stu[i].name>>stu[i].idnumber>>stu[i].score;
			//开始判断数据问题，异常则抛出 
			if(stu[i].idnumber<20180000||stu[i].idnumber>20189999) throw MyloException("学号错误");
			else if(stu[i].score<0||stu[i].score>100) throw MyloException("分数错误"); 
		}
	}
	catch(MyloException ee){
		cout<<"发现一个异常: "<<ee.getMessage()<<endl;
	}
	cout<<"继续执行主函数: "<<endl;
	cout<<"建立文件"<<endl;
	fstream my("myFile.dat",ios::out|ios::binary);
	my.close();
	cout<<"再次打开文件"<<endl;
	my.open("myFile.dat",ios::in|ios::out|ios::binary);
	if(my.fail()){
		cout<<"打开文件失败"<<endl;
		return 0;
	}
	cout<<"开始写入数据"<<endl;
	for(int j=0;j<3;j++){
		my.write((char*)&stu[j],sizeof(stu));
	}
	cout<<"开始读出数据"<<endl;
	Student s;
	my.seekg(0);
	int k=0;
	while(k<3){
		my.read((char*)&s,sizeof(Student));
		cout<<s.name<<" "<<s.idnumber<<" "<<s.score<<endl;
		k++; 
	}
	my.close();
    return 0;
}


