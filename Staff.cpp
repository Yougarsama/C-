//////利用虚函数技术和动态绑定机制，精简测试代码

#include<iostream>   
#include<string.h>     
using namespace std; 

const int LEN = 50;                             //定义一个常量，表示字符数组长度

// CEducation（教育背景）类的声明
class CEducation 
{
public:
	CEducation( ){}; // 构造函数
	CEducation( char cSchool[], char cDegree );    //重载构造函数，为数据成员赋初值
	void GetEdu( void ) ;                  //输入教育背景的有关数据	
	void PutEdu( void ) const;                  //输出教育背景的有关信息
private:
	char m_cSchool[LEN];                    //毕业学校
	char m_cDegree;                         //最高学历：专科H、本科B、硕研M、博研D
};

CEducation::CEducation( char cSchool[ ], char cDegree ) 
{
	strcpy( m_cSchool, cSchool );
	m_cDegree = cDegree;
}
void CEducation::GetEdu( void ) 
{
	cout << endl <<"  毕业学校：";
	cin >> m_cSchool;
	cout << endl <<"  最高学历：（专科H、本科B、硕研M、博研D）";
	cin >> m_cDegree;
	// 用toupper函数将用户输入的学历规范为大写字符
	m_cDegree = toupper( m_cDegree );	
}

//实现类CEducation的成员函数PutEdu，输出信息
void CEducation::PutEdu( void ) const
{
	cout << endl <<"  毕业学校："<< m_cSchool << endl;
	cout << endl <<"  最高学历：";
	switch ( m_cDegree )         
	{
		case 'H': 
			cout <<"专科"<< endl;
			break;
		case 'B': 
			cout <<"本科"<< endl;
			break;
		case 'M': 
			cout <<"硕研"<< endl;
			break;
		case 'D': 
			cout <<"博研"<< endl;
			break;
		default:  
			cout <<"空"<< endl;  //输入的学历在选项之外则为"空"
			break;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
//员工类（公共基类、组合类）
class Staff                                   
{
public:
	Staff( void ){};                          //构造函数	
	~Staff( void ){};                         //空析构函数		
	virtual void CalculateSal( void ) const{};              //计算实发工资
	virtual void OutPut() const;                      //输出员工基本信息
	void InPut( void );                       //输入员工基本信息

protected: 
	CEducation Edu;                         //教育背景
	int m_iStaffNum;                        //工作编号
	char m_cName[LEN];         	 	//姓名
	float m_fRateOfAttend;    		//出勤率
	float m_fBasicSal ;         		//基本工资
	float m_fPrize ;       		        //奖金
	static int s_iCount;                    //静态累加器
};

int Staff::s_iCount = 1000;                   //初始化静态数据成员s_iCount
// 实现类Staff的成员函数InPut，输入员工各项数据
void Staff:: InPut( void )
{
	m_iStaffNum = ++s_iCount;     //静态累加器自加1后赋给工作编号
	cout << endl << "请输入编号为"<< m_iStaffNum <<"号员工的姓名：";
	cin >> m_cName;	         //输入员工姓名
	Edu.GetEdu( );               //子对象调用类CEducation的接口GetEdu，输入教育背景相关数据	
	cout << endl << "  基本工资：";
	cin >> m_fBasicSal;          //输入基本工资
	cout << endl << "  奖金：";
	cin >> m_fPrize;             //输入奖金
	cout << endl <<"  出勤率：";
	cin >> m_fRateOfAttend;      //输入出勤率

	//规范用户输入的出勤率的值
	if ( m_fRateOfAttend > 1.0 )
	{
		m_fRateOfAttend = 1.0;
	}
	else if ( m_fRateOfAttend < 0 )
	{
		m_fRateOfAttend = 0;
	}
}
//实现类Staff的成员函数OutPut，输出员工信息
void Staff:: OutPut( void ) const
{
	cout<<"派生员工类"<<endl; 
	cout << endl << "显示员工" << m_cName <<"的基本数据：";
	cout << endl << "  工作编号：" << m_iStaffNum;
	Edu.PutEdu( );            //通过子对象调用类CEducation的接口PutEdu
	cout << endl << "  基本工资：" << m_fBasicSal;
	cout << endl << "  奖金：" << m_fPrize;	
	cout << endl << "  出勤率：" <<  m_fRateOfAttend * 100 << "%";
}



///////////////////////////////////////////////////////////////////////////////////////////////
//声明派生类：CAdminStaff（行政人员）
class CAdminStaff : public Staff             
{
public:	
	CAdminStaff ( ){};                     //派生类构造函数
	~ CAdminStaff ( ){};                   //派生类构造函数
	void CalculateSal( void ) const;                      	
};

void CAdminStaff::CalculateSal( void ) const                        
{
	cout<<"派生行政人员类"<<endl; 
	cout << endl <<" 当月实发工资："
		<< m_fBasicSal + m_fPrize * m_fRateOfAttend <<"元"<< endl;
}



///////////////////////////////////////////////////////////////////////////////////////////////
//声明派生类：CManager（经理）
class CManager : virtual public Staff           //将Staff指定为虚基类         
{
public:
	CManager( ){};                        //构造函数
	void SetMData( void );                  //输入经理数据
	void CalculateSal( void ) const;                          	
protected:
	float m_fDeductTRate;                  //经理提成比例
	float m_fTAmount;                     //总销售额
};

void CManager::SetMData( void )      //输入经理数据
{
	cout << endl <<"  公司总销售额：";
	cin >> m_fTAmount;
	cout << endl <<"  提成比例：";
	cin >> m_fDeductTRate;
}

//计算经理的实际发放工资：基本工资＋总销售额×提成比例
void CManager::CalculateSal( void ) const                          
{
	cout<<"派生经理类"<<endl; 
	cout << endl <<"  当月实际发放工资：";
	cout << m_fBasicSal + m_fTAmount * m_fDeductTRate <<"元"<< endl;
}



///////////////////////////////////////////////////////////////////////////////////////////////
//声明派生类：CSaleman（销售人员）
class CSaleman : virtual public Staff // 将Staff指定为虚基类
{
public:
	CSaleman ( ){};                       //构造函数
	void SetSData( void );                  //设置销售员数据
	void CalculateSal( void ) const;           	
protected:
	float m_fDeductRate;                   //销售员提成比例
	float m_fPersonAmount;                //个人销售额
};

void CSaleman::SetSData( void )      //设置销售员数据
{
	cout << endl <<"  个人销售额：";
	cin >> m_fPersonAmount;
	cout << endl <<"  提成比例：";
	cin >> m_fDeductRate;
}
 //计算销售员的实际发放工资：基本工资＋个人销售额×提成比例
void CSaleman::CalculateSal( void ) const             
{
	cout<<"派生销售员类"<<endl; 
	cout << endl <<"  当月实际发放工资：";
	cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate <<"元"<< endl;
}



///////////////////////////////////////////////////////////////////////////////////////////////
//声明派生类：CSaleManager（销售经理）
class CSaleManager : public CSaleman, public CManager 
{
public:
	CSaleManager( ){};                                    
	void CalculateSal( void ) const;                     	
};
	
/* 	计算销售经理实发工资: 
	基本工资＋个人销售额×销售员提成比例＋总销售额×经理提成比例
*/
void CSaleManager::CalculateSal( void ) const
{
	cout<<"派生销售经理类"<<endl; 
	cout << endl <<"  当月实际发放工资：";
	cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate 
			+ m_fTAmount * m_fDeductTRate; 
	cout <<"元"<< endl;
}

//////////////编写测试引用函数实现动态绑定 
void Reference(const Staff &re){
	re.OutPut();
	re.CalculateSal();
}

///////////////////////////////////////////////////////////////////////////////////////////////
//测试程序
int main( void )
{
	char flag ='Y';                        //设置判断是否继续录入的标志并初始化为'Y'

	while ( toupper( flag ) == 'Y')
	{
		cout <<"请选择录入类别（1.经理2.销售员3.销售经理4.行政人员）";
		int n;
		cin >> n;

		switch ( n )
		{
			case 1:
			{
				CManager staff;        //创建一个经理类对象
				staff.InPut( );          //调用基类的接口
		 		staff.SetMData( );	  //调用经理类的接口
		 		Reference(staff);
//				staff.OutPut( );        //调用基类的接口
//				staff.CalculateSal( );    //调用经理类的接口
				break;
			}
			case 2:
			{
				CSaleman staff;       //创建一个销售人员类对象
				staff.InPut( );
		 		staff.SetSData( );
		 		Reference(staff);
//				staff.OutPut( );
//				staff.CalculateSal( );   //调用销售人员类的接口
				break;
			}
			case 3:
			{
				CSaleManager staff;   //创建一个销售经理类对象
				staff.InPut( );
				staff.SetMData( );
		 		staff.SetSData( );	 				
		 		Reference(staff);
//				staff.OutPut( );
//				staff.CalculateSal( );   //调用销售经理类的接口
				break;
			}
			case 4:
			{
				CAdminStaff staff;     //创建一个行政人员类对象
				staff.InPut( ); 	 				
				Reference(staff);
//				staff.OutPut( );
//				staff.CalculateSal( );    //调用行政人员类的接口
				break;
			}
			default: 
			{
				cout << "选择有误!"<< endl;
				break;
			}
		}
		
		cout << endl <<"是否继续录入信息？（Y/N）";
		cin >> flag;		
	}
	return 0;
}

