
#include <iostream>
using namespace std;
class DotArray {   //点阵对象
	//	const int maxcol, maxrow;
	public:
		/*DotArray () {
			maxcol=5;
			maxrow=7;
		}*/
		virtual void showrow(int row) const {};
};
class DA0 : public DotArray {   //0的点阵
	public:
		char m[7][5] {
		    {'*','*','*','*','*'},
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*','*','*','*','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
			cout<<m[row][i];
			}
		};
};
class DA1 : public DotArray {   //1的点阵
	public:
		char m[7][5] {
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
				cout<<m[row][i];
			}
		};
};
class DA2 : public DotArray {   //2的点阵
	public:
		char m[7][5] {
			{'*','*','*','*','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{'*','*','*','*','*'},
			{'*',' ',' ',' ',' '},
			{'*',' ',' ',' ',' '},
			{'*','*','*','*','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
				cout<<m[row][i];
			}
		};
};
class DA3 : public DotArray {   //3的点阵
	public:
		char m[7][5] {
			{'*','*','*','*','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{'*','*','*','*','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{'*','*','*','*','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
				cout<<m[row][i];
			}
		};
};
class DA4 : public DotArray {   //4的点阵
	public:
		char m[7][5] {
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*','*','*','*','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
				cout<<m[row][i];
			}
		};
};
class DA5 : public DotArray {   //5的点阵
	public:
		char m[7][5] {
			{'*','*','*','*','*'},
			{'*',' ',' ',' ',' '},
			{'*',' ',' ',' ',' '},
			{'*','*','*','*','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{'*','*','*','*','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
				cout<<m[row][i];
			}
		};
};
class DA6 : public DotArray {   //6的点阵
	public:
		char m[7][5] {
			{'*','*','*','*','*'},
			{'*',' ',' ',' ',' '},
			{'*',' ',' ',' ',' '},
			{'*','*','*','*','*'},
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*','*','*','*','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
				cout<<m[row][i];
			}
		};
};
class DA7 : public DotArray {   //7的点阵
	public:
		char m[7][5] {
			{'*','*','*','*','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
				cout<<m[row][i];
			}
		};
};
class DA8 : public DotArray {   //8的点阵
	public:
		char m[7][5] {
			{'*','*','*','*','*'},
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*','*','*','*','*'},
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*','*','*','*','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
				cout<<m[row][i];
			}
		};
};
class DA9 : public DotArray {   //9的点阵
	public:
		char m[7][5] {
			{'*','*','*','*','*'},
			{'*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*'},
			{'*','*','*','*','*'},
			{' ',' ',' ',' ','*'},
			{' ',' ',' ',' ','*'},
			{'*','*','*','*','*'},
		};
		virtual void showrow(int row) const {
			for(int i=0; i<5; i++) {
				cout<<m[row][i];
			}
		};
};
class DAPrinter {
	private:
		/*const*/ int num;
		DotArray *das[4]; //最多4个点阵对象
	public:
		DAPrinter (int n) {
			num=n;
		}
		void split();
		void print();
		void reset();
};
void DAPrinter::split() {
	int a[4],i,f_num=1000,d_num=num;
	for(i=0; i<4; i++) {
		a[i]=d_num/f_num;
		d_num%=f_num;
		f_num/=10;
	}
	for(i=0; i<3; i++) {
		if(a[i]!=0)
			break;
	}
	d_num=i;
	for(i=0;i<d_num;i++)
	{
		if(a[i]==0)
		das[i]=NULL;
	}
	for(int i=3; i>d_num-1; i--) {
		switch(a[i]) {
			case 0:
				das[i]=new DA0();
				break;
			case 1:
				das[i]=new DA1();
				break;
			case 2:
				das[i]=new DA2();
				break;
			case 3:
				das[i]=new DA3();
				break;
			case 4:
				das[i]=new DA4();
				break;
			case 5:
				das[i]=new DA5();
				break;
			case 6:
				das[i]=new DA6();
				break;
			case 7:
				das[i]=new DA7();
				break;
			case 8:
				das[i]=new DA8();
				break;
			case 9:
				das[i]=new DA9();
				break;
		}
	}
}
void DAPrinter::print() {
	cout<<num<<":"<<endl;
	for(int row=0;row<7;row++)
	{
		for(int i=0;i<3;i++)
		{
		    if(das[i]!=NULL){
		    	das[i]->showrow(row);
		    	cout<<"  ";
			}
		}
		das[3]->showrow(row);
		cout<<"  "<<endl;
	}
}
void DAPrinter::reset(){
	delete []das;
}
int main() {
	int n,n1;
	std::cin >> n;
	for(int i = 0; i < n; ++i) {
		std::cin >> n1;
		DAPrinter p(n1);
		p.split();
		p.print();
	}
	return 0;
}
