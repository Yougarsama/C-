//////�����麯�������Ͷ�̬�󶨻��ƣ�������Դ���

#include<iostream>   
#include<string.h>     
using namespace std; 

const int LEN = 50;                             //����һ����������ʾ�ַ����鳤��

// CEducation�������������������
class CEducation 
{
public:
	CEducation( ){}; // ���캯��
	CEducation( char cSchool[], char cDegree );    //���ع��캯����Ϊ���ݳ�Ա����ֵ
	void GetEdu( void ) ;                  //��������������й�����	
	void PutEdu( void ) const;                  //��������������й���Ϣ
private:
	char m_cSchool[LEN];                    //��ҵѧУ
	char m_cDegree;                         //���ѧ����ר��H������B��˶��M������D
};

CEducation::CEducation( char cSchool[ ], char cDegree ) 
{
	strcpy( m_cSchool, cSchool );
	m_cDegree = cDegree;
}
void CEducation::GetEdu( void ) 
{
	cout << endl <<"  ��ҵѧУ��";
	cin >> m_cSchool;
	cout << endl <<"  ���ѧ������ר��H������B��˶��M������D��";
	cin >> m_cDegree;
	// ��toupper�������û������ѧ���淶Ϊ��д�ַ�
	m_cDegree = toupper( m_cDegree );	
}

//ʵ����CEducation�ĳ�Ա����PutEdu�������Ϣ
void CEducation::PutEdu( void ) const
{
	cout << endl <<"  ��ҵѧУ��"<< m_cSchool << endl;
	cout << endl <<"  ���ѧ����";
	switch ( m_cDegree )         
	{
		case 'H': 
			cout <<"ר��"<< endl;
			break;
		case 'B': 
			cout <<"����"<< endl;
			break;
		case 'M': 
			cout <<"˶��"<< endl;
			break;
		case 'D': 
			cout <<"����"<< endl;
			break;
		default:  
			cout <<"��"<< endl;  //�����ѧ����ѡ��֮����Ϊ"��"
			break;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Ա���ࣨ�������ࡢ����ࣩ
class Staff                                   
{
public:
	Staff( void ){};                          //���캯��	
	~Staff( void ){};                         //����������		
	virtual void CalculateSal( void ) const{};              //����ʵ������
	virtual void OutPut() const;                      //���Ա��������Ϣ
	void InPut( void );                       //����Ա��������Ϣ

protected: 
	CEducation Edu;                         //��������
	int m_iStaffNum;                        //�������
	char m_cName[LEN];         	 	//����
	float m_fRateOfAttend;    		//������
	float m_fBasicSal ;         		//��������
	float m_fPrize ;       		        //����
	static int s_iCount;                    //��̬�ۼ���
};

int Staff::s_iCount = 1000;                   //��ʼ����̬���ݳ�Աs_iCount
// ʵ����Staff�ĳ�Ա����InPut������Ա����������
void Staff:: InPut( void )
{
	m_iStaffNum = ++s_iCount;     //��̬�ۼ����Լ�1�󸳸��������
	cout << endl << "��������Ϊ"<< m_iStaffNum <<"��Ա����������";
	cin >> m_cName;	         //����Ա������
	Edu.GetEdu( );               //�Ӷ��������CEducation�Ľӿ�GetEdu��������������������	
	cout << endl << "  �������ʣ�";
	cin >> m_fBasicSal;          //�����������
	cout << endl << "  ����";
	cin >> m_fPrize;             //���뽱��
	cout << endl <<"  �����ʣ�";
	cin >> m_fRateOfAttend;      //���������

	//�淶�û�����ĳ����ʵ�ֵ
	if ( m_fRateOfAttend > 1.0 )
	{
		m_fRateOfAttend = 1.0;
	}
	else if ( m_fRateOfAttend < 0 )
	{
		m_fRateOfAttend = 0;
	}
}
//ʵ����Staff�ĳ�Ա����OutPut�����Ա����Ϣ
void Staff:: OutPut( void ) const
{
	cout<<"����Ա����"<<endl; 
	cout << endl << "��ʾԱ��" << m_cName <<"�Ļ������ݣ�";
	cout << endl << "  ������ţ�" << m_iStaffNum;
	Edu.PutEdu( );            //ͨ���Ӷ��������CEducation�Ľӿ�PutEdu
	cout << endl << "  �������ʣ�" << m_fBasicSal;
	cout << endl << "  ����" << m_fPrize;	
	cout << endl << "  �����ʣ�" <<  m_fRateOfAttend * 100 << "%";
}



///////////////////////////////////////////////////////////////////////////////////////////////
//���������ࣺCAdminStaff��������Ա��
class CAdminStaff : public Staff             
{
public:	
	CAdminStaff ( ){};                     //�����๹�캯��
	~ CAdminStaff ( ){};                   //�����๹�캯��
	void CalculateSal( void ) const;                      	
};

void CAdminStaff::CalculateSal( void ) const                        
{
	cout<<"����������Ա��"<<endl; 
	cout << endl <<" ����ʵ�����ʣ�"
		<< m_fBasicSal + m_fPrize * m_fRateOfAttend <<"Ԫ"<< endl;
}



///////////////////////////////////////////////////////////////////////////////////////////////
//���������ࣺCManager������
class CManager : virtual public Staff           //��Staffָ��Ϊ�����         
{
public:
	CManager( ){};                        //���캯��
	void SetMData( void );                  //���뾭������
	void CalculateSal( void ) const;                          	
protected:
	float m_fDeductTRate;                  //������ɱ���
	float m_fTAmount;                     //�����۶�
};

void CManager::SetMData( void )      //���뾭������
{
	cout << endl <<"  ��˾�����۶";
	cin >> m_fTAmount;
	cout << endl <<"  ��ɱ�����";
	cin >> m_fDeductTRate;
}

//���㾭���ʵ�ʷ��Ź��ʣ��������ʣ������۶����ɱ���
void CManager::CalculateSal( void ) const                          
{
	cout<<"����������"<<endl; 
	cout << endl <<"  ����ʵ�ʷ��Ź��ʣ�";
	cout << m_fBasicSal + m_fTAmount * m_fDeductTRate <<"Ԫ"<< endl;
}



///////////////////////////////////////////////////////////////////////////////////////////////
//���������ࣺCSaleman��������Ա��
class CSaleman : virtual public Staff // ��Staffָ��Ϊ�����
{
public:
	CSaleman ( ){};                       //���캯��
	void SetSData( void );                  //��������Ա����
	void CalculateSal( void ) const;           	
protected:
	float m_fDeductRate;                   //����Ա��ɱ���
	float m_fPersonAmount;                //�������۶�
};

void CSaleman::SetSData( void )      //��������Ա����
{
	cout << endl <<"  �������۶";
	cin >> m_fPersonAmount;
	cout << endl <<"  ��ɱ�����";
	cin >> m_fDeductRate;
}
 //��������Ա��ʵ�ʷ��Ź��ʣ��������ʣ��������۶����ɱ���
void CSaleman::CalculateSal( void ) const             
{
	cout<<"��������Ա��"<<endl; 
	cout << endl <<"  ����ʵ�ʷ��Ź��ʣ�";
	cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate <<"Ԫ"<< endl;
}



///////////////////////////////////////////////////////////////////////////////////////////////
//���������ࣺCSaleManager�����۾���
class CSaleManager : public CSaleman, public CManager 
{
public:
	CSaleManager( ){};                                    
	void CalculateSal( void ) const;                     	
};
	
/* 	�������۾���ʵ������: 
	�������ʣ��������۶������Ա��ɱ����������۶��������ɱ���
*/
void CSaleManager::CalculateSal( void ) const
{
	cout<<"�������۾�����"<<endl; 
	cout << endl <<"  ����ʵ�ʷ��Ź��ʣ�";
	cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate 
			+ m_fTAmount * m_fDeductTRate; 
	cout <<"Ԫ"<< endl;
}

//////////////��д�������ú���ʵ�ֶ�̬�� 
void Reference(const Staff &re){
	re.OutPut();
	re.CalculateSal();
}

///////////////////////////////////////////////////////////////////////////////////////////////
//���Գ���
int main( void )
{
	char flag ='Y';                        //�����ж��Ƿ����¼��ı�־����ʼ��Ϊ'Y'

	while ( toupper( flag ) == 'Y')
	{
		cout <<"��ѡ��¼�����1.����2.����Ա3.���۾���4.������Ա��";
		int n;
		cin >> n;

		switch ( n )
		{
			case 1:
			{
				CManager staff;        //����һ�����������
				staff.InPut( );          //���û���Ľӿ�
		 		staff.SetMData( );	  //���þ�����Ľӿ�
		 		Reference(staff);
//				staff.OutPut( );        //���û���Ľӿ�
//				staff.CalculateSal( );    //���þ�����Ľӿ�
				break;
			}
			case 2:
			{
				CSaleman staff;       //����һ��������Ա�����
				staff.InPut( );
		 		staff.SetSData( );
		 		Reference(staff);
//				staff.OutPut( );
//				staff.CalculateSal( );   //����������Ա��Ľӿ�
				break;
			}
			case 3:
			{
				CSaleManager staff;   //����һ�����۾��������
				staff.InPut( );
				staff.SetMData( );
		 		staff.SetSData( );	 				
		 		Reference(staff);
//				staff.OutPut( );
//				staff.CalculateSal( );   //�������۾�����Ľӿ�
				break;
			}
			case 4:
			{
				CAdminStaff staff;     //����һ��������Ա�����
				staff.InPut( ); 	 				
				Reference(staff);
//				staff.OutPut( );
//				staff.CalculateSal( );    //����������Ա��Ľӿ�
				break;
			}
			default: 
			{
				cout << "ѡ������!"<< endl;
				break;
			}
		}
		
		cout << endl <<"�Ƿ����¼����Ϣ����Y/N��";
		cin >> flag;		
	}
	return 0;
}

