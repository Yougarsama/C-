#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//����ģ��//���ڸı�������ĳ��ѡȡ���ض���ַ��ֵ
template<class T>
void setarray(T *str){
	T s;
	int i;
	cout<<"ѡȡ�ı�ĵ�ַ���� i ��Ԫ�ص�ַ����";
	cin>>i; 
	cout<<"�����趨�õ�ַ��ֵΪ ��";
	cin>>s;
	*(str+i-1)=s;
	cout<<"�ı��ĸõ�ַԪ�� ��"<<*(str+i-1)<<endl;
};

//��ģ��//���ڴ洢����ʾĳ������ 
template<class T>
class Data{
	private:
		int idnum;
		T da;///////////////////////////////////�洢������ 
		bool allow;
	public:
		Data();
		Data(T da,int idnum);
		void setdata(T da,int idnum); 
		T returndata();
		void outputdata();
		~Data();
}; 
template<class T>
Data<T>::Data(){
	allow=false;
	cout<<"�ѹ���"<<endl;
}
template<class T>
Data<T>::Data(T da,int idnum){
	this->idnum=idnum;
	this->da=da;
	allow=true;
	cout<<"�ѹ���"<<endl;
}
template<class T>
void Data<T>::setdata(T da,int idnum){
	this->idnum=idnum;
	this->da=da;
	allow=true; 
}
template<class T>
T Data<T>::returndata(){
	if(!allow){
		cout<<"���ݱ�ţ�"<<idnum<<"->������"<<endl;
		exit(1);
	}
	return da;
}

template<class T>
void Data<T>::outputdata(){
	if(allow) cout<<"���ݱ�ţ�"<<idnum<<"->"<<Data<T>::returndata()<<endl;
}
template<class T>
Data<T>::~Data(){
	cout<<"���ݱ�ţ�"<<idnum<<" ������"<<endl;
}
int main() 
{
	cout<<"����Ϊ����ģ�����������"<<endl;
	int s1[]={12,43,14,43,1};
	setarray(s1);
	double s2[]={21.31,11.11,334.2,66.2};
	setarray(s2);
	cout<<endl; 
	
	cout<<"����Ϊ��ģ�����������"<<endl;
	Data<int> d1;
	d1.setdata(10000,1);
	d1.outputdata();
	Data<double> d2(3.14,2);
	d2.outputdata();
	
	return 0;
}
