#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//函数模板//用于改变数组中某个选取的特定地址的值
template<class T>
void setarray(T *str){
	T s;
	int i;
	cout<<"选取改变的地址（第 i 个元素地址）：";
	cin>>i; 
	cout<<"重新设定该地址的值为 ：";
	cin>>s;
	*(str+i-1)=s;
	cout<<"改变后的该地址元素 ："<<*(str+i-1)<<endl;
};

//类模板//用于存储与显示某个数据 
template<class T>
class Data{
	private:
		int idnum;
		T da;///////////////////////////////////存储的数据 
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
	cout<<"已构造"<<endl;
}
template<class T>
Data<T>::Data(T da,int idnum){
	this->idnum=idnum;
	this->da=da;
	allow=true;
	cout<<"已构造"<<endl;
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
		cout<<"数据编号："<<idnum<<"->无数据"<<endl;
		exit(1);
	}
	return da;
}

template<class T>
void Data<T>::outputdata(){
	if(allow) cout<<"数据编号："<<idnum<<"->"<<Data<T>::returndata()<<endl;
}
template<class T>
Data<T>::~Data(){
	cout<<"数据编号："<<idnum<<" 已析构"<<endl;
}
int main() 
{
	cout<<"以下为函数模板测试样例："<<endl;
	int s1[]={12,43,14,43,1};
	setarray(s1);
	double s2[]={21.31,11.11,334.2,66.2};
	setarray(s2);
	cout<<endl; 
	
	cout<<"以下为类模板测试样例："<<endl;
	Data<int> d1;
	d1.setdata(10000,1);
	d1.outputdata();
	Data<double> d2(3.14,2);
	d2.outputdata();
	
	return 0;
}
