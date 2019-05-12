#include<iostream>
#include<cstring>
using namespace std;
class Table
{
	private:
		int x,y,z;
		string name;
	public:
		Table();
		Table(int x,int y);
		
		void show();
		
		void set(int x,int y,int z);
		void set(int x,int y,string s);
		
		void addRow();
		void addColumn();
		void delRow(int cx);
		void delColumn(int cy);
		~Table();
}; 
int main() {
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
Table::Table(){
	x=0,y=0,z=0;
	name="hi";
	cout<<"¹¹Ôì"<<endl;
}
Table::Table(int x,int y){
	this->x=x;
	this->y=y;
	z=0;
}
void Table::show(){
	cout<<"( "<<x<<" , "<<y<<" )"<<endl;
}
void Table::set(int x,int y,int z){
	this->x=x;
	this->y=y;
	this->z=z; 
}
void Table::set(int x,int y,string s){
	this->x=x;
	this->y=y;
	name=s; 
}
void Table::addRow(){
	x++;
}
void Table::addColumn(){
	y++;
}
void Table::delRow(int cx){
	x-=cx;
}
void Table::delColumn(int cy){
	y-=cy;
}
Table::~Table(){
	cout<<"Îö¹¹"<<endl;
}
