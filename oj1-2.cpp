#include <iostream>
using namespace std;
///��1����һ������n����ʾ�����n�����ݡ�
//ÿ������ռһ�У��������ֶ��εĶ�β����a��b��c���ÿո������
//��֪������������С��10��������100��
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class HanXin{
	public:
		HanXin();//��ʼ��Ϊ0 
		void line3(int n1);
		void line5(int n2);
		void line7(int n3);
		void showMany();//����a��b��c���������people
		~HanXin();//���� 
	private:
		int people,x,y,z;
		int a,b,c;//3��5��7 
};
int main() {
    int n,n1,n2,n3;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2 >> n3;
        HanXin hx;  //����
        hx.line3(n1);  //3��һ��
        hx.line5(n2);   //5��һ��
        hx.line7(n3);   //7��һ��
        hx.showMany();
    }
    return 0;
}
HanXin::HanXin(){
	people=10;
	a=0,b=0,c=0;
}
HanXin::~HanXin(){}
void HanXin::line3(int n1){
	a=n1;
}
void HanXin::line5(int n2){
	b=n2;
}
void HanXin::line7(int n3){
	c=n3;
}
void HanXin::showMany(){
	for(int i=10;i<=100;i++,people++)
	{
		if((people%3==a)&&(people%5==b)&&(people%7==c)) 
		{
	    	cout<<people<<endl;
		    break;
		}
		else if(i==100) cout<<"Impossible"<<endl;
	}
}





