#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Country{
	public:
		Country();
		void guide();//读入数据与计算 
		void adj();//判断 
		void out(int ad);//输出数据 
		~Country();
	private:
		string country;
		double people;
		double area; 
		double averpeople;//人口密度
		static double bigarea;//面积最大 ==1
		static double mostpeople;//人最多 ==2
		static double mostaver;//人口密度最大 ==3
};
double Country::bigarea=0;//面积最大 
double Country::mostpeople=0;//人最多 
double Country::mostaver=0;//人口密度最大 

int main(int argc, char** argv) {
	Country *c=new Country[40];
	for(int i=0;i<40;i++)
	{
		c[i].guide();
		c[i].adj();
	}
	for(int j=0;j<40;j++) c[j].out(1);
	for(int k=0;k<40;k++) c[k].out(2);
	for(int m=0;m<40;m++) c[m].out(3);
	delete []c;
	return 0;
}

Country::Country(){}
void Country::guide(){
	cout<<"依次输入国家名字、人口数目、国土面积 ："<<endl;
	cin>>country>>people>>area;
	averpeople=people/area;
}
void Country::adj(){
	if(area>bigarea) bigarea=area;
	if(people>mostpeople) mostpeople=people;
	if(averpeople>mostaver) mostaver=averpeople;
}
void Country::out(int ad){
	if(area==bigarea&&ad==1) cout<<"面积最大国家 ："<<country<<endl; 
	if(people==mostpeople&&ad==2) cout<<"人口最多国家 ："<<country<<endl; 
	if(averpeople==mostaver&&ad==3) cout<<"人口密度最大国家 ："<<country<<endl; 
}
Country::~Country(){} 
