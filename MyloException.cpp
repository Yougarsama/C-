#include <iostream>
#include <cstring>
#include <fstream> 
using namespace std;
class MyloException//�쳣��Ϣ�࣬���ڷ����쳣��Ϣ 
{
public:
    MyloException(const string messa){ message=messa; };
    ~MyloException(){};
    const string getMessage() { return message; }//һ�������쳣��Ϣ�ĺ��� 
private:
    string message;
};

struct Student//ѧ���ṹ�壬���ڽ����ṹ������ 
{
	string name;
	int idnumber;
	int score;
};

int main() 
{
	cout<<"�������ݣ�"<<endl; 
	Student stu[3];//������3��ѧ����Ϣ�Ľṹ�壬���ڴ洢��Ϣ 
	cout<<"����ѧ����Ϣ�ĸ�ʽΪ������ʽ��"<<endl;
	cout<<"���� ѧ��(2018xxxx) C++����(0~100)"<<endl;
	try{
/*		double a,b;
		cout<<"��try�飺"<<endl;
		cin>>a>>b;
		if(b==0) throw MyloException("��������Ϊ��");
		else if(a<b) throw (MyloException("a<b"));
		a/=b;
		cout<<"a/b="<<a<<endl;*/
		cout<<"����try��"<<endl;
		for(int i=0;i<3;i++){
			cin>>stu[i].name>>stu[i].idnumber>>stu[i].score;
			//��ʼ�ж��������⣬�쳣���׳� 
			if(stu[i].idnumber<20180000||stu[i].idnumber>20189999) throw MyloException("ѧ�Ŵ���");
			else if(stu[i].score<0||stu[i].score>100) throw MyloException("��������"); 
		}
	}
	catch(MyloException ee){
		cout<<"����һ���쳣: "<<ee.getMessage()<<endl;
	}
	cout<<"����ִ��������: "<<endl;
	cout<<"�����ļ�"<<endl;
	fstream my("myFile.dat",ios::out|ios::binary);
	my.close();
	cout<<"�ٴδ��ļ�"<<endl;
	my.open("myFile.dat",ios::in|ios::out|ios::binary);
	if(my.fail()){
		cout<<"���ļ�ʧ��"<<endl;
		return 0;
	}
	cout<<"��ʼд������"<<endl;
	for(int j=0;j<3;j++){
		my.write((char*)&stu[j],sizeof(stu));
	}
	cout<<"��ʼ��������"<<endl;
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


