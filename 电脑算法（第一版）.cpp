#include<stdio.h>
#include<windows.h>
void Show(int a[][23]);
void Clear(void);
int Machine_easy (int a[][23]);
int Machine_difficult (int a[][23]);
int JugeWhoiswiner(int a[][23],int i,int j,int num);
int Start_live_three(int a[][23],int i,int j);
int Start_live_rush_four(int a[][23],int i,int j);
int Surround (int a[][23],int i,int j);
int Stop_live_four (int a[][23],int i,int j);
int Stop_human_win(int a[][23],int i,int j);
int Start_machine_win(int a[][23]);
int main() {
	int i,j,a[23][23],flag=0;
	for( i=0; i<23; i++) {
		for( j=0; j<23; j++) {
			a[i][j]=-1;//��������Ϊ-1
		}
	}
	for(int i=4; i<19; i++) {
		for(int j=4; j<19; j++) {
			a[i][j]=0;//�м����������Ϊ0
		}
	}
	Show(a);
	while (!flag) {
		printf("input:\n");
		scanf("%d%d",&i,&j);
		Clear();//�������֮������
		i=i+3,j=j+3;
		a[i][j]=1;
		Show(a);
		Sleep(1000);//��������֮��Ľ��չʾ����
		if(JugeWhoiswiner(a,i,j,1)) { //�ж��Ƿ����Ѿ�Ӯ��
			flag=1;
			break;
		}
		Clear();//��������֮��Ľ�����
		if(Stop_human_win(a,i,j) || Stop_live_four(a,i,j)) {
		} else {
			flag=Machine_easy(a);//�򵥵Ļ�������
		}
		Show(a);
		if(flag) {
			break;
		}
	}
	if(flag==1) {
		printf("human win!");
	} else if (flag==2) {
		printf("machine win!");
	}
	return 0;
}
void Show(int a[][23]) {
	for(int i=4; i<19; i++) {
		for(int j=4; j<19; j++) {
			printf("%4d",a[i][j]);
		}
		printf("\n\n");
	}
}
void Clear (void) {
	system("cls");
}
int Machine_easy (int a[][23]) {
	int score_max=0,set_i,set_j,score,i,j;
	if(Start_machine_win(a)) {
		return 2;
	} else {
		for(i=4; i<19; i++) {
			for(j=4; j<19; j++) {
				if(a[i][j]==0) {
					score=Start_live_three(a,i,j)+Start_live_rush_four(a,i,j)+Surround(a,i,j);
					if(score>score_max) {
						score_max=score;
						set_i=i;
						set_j=j;
					}

				}
			}
		}

		a[set_i][set_j]=2;
		return 0;
	}
}
int JugeWhoiswiner(int a[][23],int i,int j,int num) {
	int stx,sty,count,j_flag=0;
// hoizontal
	count=0,stx=i-4;
	while(count!=5 && stx<i+5) {
		if(a[stx][j]==num) {
			count++;
			stx++;
		} else {
			stx++;
			count=0;
		}
	}
	if(count==5) {
		return num;
	}


//void vertical()
	count=0,sty=j-4;
	while(count!=5 && sty<j+5) {
		if(a[i][sty]==num) {
			count++;
			sty++;
		} else {
			sty++;
			count=0;
		}
	}
	if(count==5) {
		return num;
	}


//diagonal_1()
	count=0,sty=j-4,stx=i-4;
	while(count!=5 && sty<j+5) {
		if(a[stx][sty]==num) {
			count++;
			stx++;
			sty++;
		} else {
			sty++;
			stx++;
			count=0;
		}
	}
	if(count==5) {
		return num;
	}
//void diagonal_2():
	count=0,sty=j-4,stx=i+4;
	while(count!=5 && sty<j+5) {
		if(a[stx][sty]==num) {
			count++;
			stx--;
			sty++;
		} else {
			sty++;
			stx--;
			count=0;
		}
	}
	if(count==5) {
		return num;
	} else {
		return 0;
	}
}
int Start_live_three(int a[][23],int i,int j) {
	int score_live_three=0;
	printf("i am Start_live_three\n%d %d\n",i,j);
	//��ֱ����
	if(  a[i+1][j]==2 &&  a[i+2][j]==2 ) {
		if(a[i-1][j]==0 && a[i+3][j]==0) {
			score_live_three+=500;
		}
	} else if ( a[i-1][j]==2 &&  a[i-2][j]==2 ) {
		if(a[i+1][j]==0 && a[i-3][j]==0) {
			score_live_three+=500;
		}
	} else if( a[i-1][j]==2 &&  a[i+1][j]==2) {
		if(a[i-2][j]==0 && a[i+2][j]==0) {
			score_live_three+=500;
		}
	}
	//ˮƽ����
	if(  a[i][j+1]==2 &&  a[i][j+2]==2 ) {
		if(a[i][j-1]==0 && a[i][j+3]==0) {
			score_live_three+=500;
		}
	} else if ( a[i][j-1]==2 &&  a[i][j-2]==2 ) {
		if(a[i][j+1]==0 && a[i][j-3]==0) {
			score_live_three+=500;
		}
	} else if( a[i][j-1]==2 &&  a[i][j+1]==2) {
		if(a[i][j-2]==0 && a[i][j+2]==0) {
			score_live_three+=500;
		}
	}
	//б����һ
	if(  a[i+1][j+1]==2 &&  a[i+1][j+2]==2 ) {
		if(a[i-1][j-1]==0 && a[i+3][j+3]==0) {
			score_live_three+=500;
		}
	} else if ( a[i-1][j-1]==2 &&  a[i-2][j-2]==2 ) {
		if(a[i+1][j+1]==0 && a[i-3][j-3]==0) {
			score_live_three+=500;
		}
	} else if( a[i-1][j-1]==2 &&  a[i+1][j+1]==2) {
		if(a[i-2][j-2]==0 && a[i+2][j+2]==0) {
			score_live_three+=500;
		}
	}
	//б�����
	if(  a[i+1][j-1]==2 &&  a[i+1][j-2]==2 ) {
		if(a[i-1][j+1]==0 && a[i+3][j-3]==0) {
			score_live_three+=500;
		}
	} else if ( a[i-1][j+1]==2 &&  a[i-2][j+2]==2 ) {
		if(a[i+1][j-1]==0 && a[i-3][j+3]==0) {
			score_live_three+=500;
		}
	} else if( a[i-1][j+1]==2 &&  a[i+1][j-1]==2) {
		if(a[i-2][j+2]==0 && a[i+2][j-2]==0) {
			score_live_three+=500;
		}
	}

	return score_live_three;
}
int Start_live_rush_four(int a[][23],int i,int j) {
	int score_live_rush_four=0;
	printf("i am Start_live_rush_four\n%d %d\n",i,j);
	//��ֱ����
	if(  a[i+1][j]==2 &&  a[i+2][j]==2 && a[i+3][j]==2) {
		if(a[i-1][j]==0 && a[i+4][j]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if ( a[i-1][j]==2 &&  a[i-2][j]==2 && a[i-3][j]==2) {
		if(a[i+1][j]==0 && a[i-4][j]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if( a[i-1][j]==2 &&  a[i+1][j]==2 && a[i+2][j]==2) {
		if(a[i-2][j]==0 && a[i+3][j]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if( a[i+1][j]==2 &&  a[i-1][j]==2 && a[i-2][j]==2) {
		if(a[i+2][j]==0 && a[i-3][j]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	}
	//ˮƽ����
	if(  a[i][j+1]==2 &&  a[i][j+2]==2 && a[i][j+3]==2) {
		if(a[i][j-1]==0 && a[i][j+4]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if ( a[i][j-1]==2 &&  a[i][j-2]==2 && a[i][j-3]==2) {
		if(a[i][j+1]==0 && a[i][j-4]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if( a[i][j-1]==2 &&  a[i][j+1]==2 && a[i][j+2]==2) {
		if(a[i][j-2]==0 && a[i][j+3]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if( a[i][j+1]==2 &&  a[i][j-1]==2 && a[i][j-2]==2) {
		if(a[i][j+2]==0 && a[i][j-3]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	}
	//б����һ
	if(  a[i+1][j+1]==2 &&  a[i+2][j+2]==2 && a[i+3][j+3]==2) {
		if(a[i-1][j-1]==0 && a[i+4][j+4]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if ( a[i-1][j-1]==2 &&  a[i-2][j-2]==2 && a[i-3][j-3]==2) {
		if(a[i+1][j+1]==0 && a[i-4][j-4]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if( a[i-1][j-1]==2 &&  a[i+1][j+1]==2 && a[i+2][j+2]==2) {
		if(a[i-2][j-2]==0 && a[i+3][j+3]==0) {
			score_live_rush_four+=1000;
		}
	} else if( a[i+1][j+1]==2 &&  a[i-1][j-1]==2 && a[i-2][j-2]==2) {
		if(a[i+2][j+2]==0 && a[i-3][j-3]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	}
	//б�����
	if(  a[i+1][j-1]==2 &&  a[i+2][j-2]==2 && a[i+3][j-3]==2) {
		if(a[i-1][j+1]==0 && a[i+4][j-4]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if ( a[i-1][j+1]==2 &&  a[i-2][j+2]==2 && a[i-3][j+3]==2) {
		if(a[i+1][j-1]==0 && a[i-4][j+4]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if( a[i-1][j+1]==2 &&  a[i+1][j-1]==2 && a[i+2][j-2]==2) {
		if(a[i-2][j+2]==0 && a[i+3][j-3]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	} else if( a[i+1][j-1]==2 &&  a[i-1][j+1]==2 && a[i-2][j+2]==2) {
		if(a[i+2][j-2]==0 && a[i-3][j+3]==0) {
			score_live_rush_four+=1000;
		} else {
			score_live_rush_four+=500;
		}
	}

	return score_live_rush_four;
}
int Start_machine_win(int a[][23]) {
	int flag_win=0,i,j;
	for(i=4; i<19; i++) {
		for(j=4; j<19; j++) {
			if(a[i][j]==0) {
				printf("i am Start_machine_win\n%d %d\n",i,j);
				//ˮƽ����
				if (a[i+1][j]==2 && a[i+2][j]==2 && a[i+3][j]==2 &&a[i+4][j]==2) {
					flag_win=1;
					break;
				} else if(a[i-1][j]==2 && a[i-2][j]==2 && a[i-3][j]==2 &&a[i-4][j]==2) {
					flag_win=1;
					break;
				} else if(a[i-1][j]==2 && a[i-2][j]==2 && a[i+1][j]==2 &&a[i+2][j]==2) {
					flag_win=1;
					break;
				} else if(a[i-1][j]==2 && a[i-2][j]==2 && a[i-3][j]==2 &&a[i+1][j]==2) {
					flag_win=1;
					break;
				} else if(a[i+1][j]==2 && a[i+2][j]==2 && a[i+3][j]==2 &&a[i-1][j]==2) {
					flag_win=1;
					break;
				}
				//��ֱ����
				if (a[i][j+1]==2 && a[i][j+2]==2 && a[i][j+3]==2 &&a[i][j+4]==2) {
					flag_win=1;
					break;
				} else if(a[i][j-1]==2 && a[i][j-2]==2 && a[i][j-3]==2 &&a[i][j-4]==2) {
					flag_win=1;
					break;
				} else if(a[i][j-1]==2 && a[i][j-2]==2 && a[i][j+1]==2 &&a[i][j+2]==2) {
					flag_win=1;
					break;
				} else if(a[i][j-1]==2 && a[i][j-2]==2 && a[i][j-3]==2 &&a[i][j+1]==2) {
					flag_win=1;
					break;
				} else if(a[i][j+1]==2 && a[i][j+2]==2 && a[i][j+3]==2 &&a[i][j-1]==2) {
					flag_win=1;
					break;
				}
				//б����һ
				if (a[i+1][j+1]==2 && a[i+2][j+2]==2 && a[i+3][j+3]==2 &&a[i+4][j+4]==2) {
					flag_win=1;
					break;
				} else if(a[i-1][j-1]==2 && a[i-2][j-2]==2 && a[i-3][j-3]==2 &&a[i-4][j-4]==2) {
					flag_win=1;
					break;
				} else if(a[i-1][j-1]==2 && a[i-2][j-2]==2 && a[i+1][j+1]==2 &&a[i+2][j+2]==2) {
					flag_win=1;
					break;
				} else if(a[i-1][j-1]==2 && a[i-2][j-2]==2 && a[i-3][j-3]==2 &&a[i+1][j+1]==2) {
					flag_win=1;
					break;
				} else if(a[i+1][j+1]==2 && a[i+2][j+2]==2 && a[i+3][j+3]==2 &&a[i-1][j-1]==2) {
					flag_win=1;
					break;
				}
				//б�����
				if (a[i+1][j-1]==2 && a[i+2][j-2]==2 && a[i+3][j-3]==2 &&a[i+4][j-4]==2) {
					flag_win=1;
					break;
				} else if(a[i-1][j+1]==2 && a[i-2][j+2]==2 && a[i-3][j+3]==2 &&a[i-4][j+4]==2) {
					flag_win=1;
					break;
				} else if(a[i-1][j+1]==2 && a[i-2][j+2]==2 && a[i+1][j-1]==2 &&a[i+2][j-2]==2) {
					flag_win=1;
					break;
				} else if(a[i-1][j+1]==2 && a[i-2][j+2]==2 && a[i-3][j+3]==2 &&a[i+1][j-1]==2) {
					flag_win=1;
					break;
				} else if(a[i+1][j-1]==2 && a[i+2][j-2]==2 && a[i+3][j-3]==2 &&a[i-1][j+1]==2) {
					flag_win=1;
					break;
				}

			}

		}
		if(flag_win==1) {
			a[i][j]=2;
			break;
		}
	}
	return flag_win;
}
int Surround (int a[][23],int i,int j) {
	int score_Surround=0;
	int ai,aj;
	int ax[8]= {1,-1,0,0,1,1,-1,-1};
	int ay[8]= {0,0,1,-1,1,-1,1,-1};
	printf("i am Surround\n");
	for(ai=0; ai<8; ai++) {
		for(aj=0; aj<8; aj++) {
			if(a[i+ax[ai]][j+ay[aj]]!=0 && a[i+ax[ai]][j+ay[aj]]!=-1) {
				score_Surround++;
			}
		}
	}

	return score_Surround;
}
int Stop_human_win(int a[][23],int i,int j) {
	int line_i=i,line_j=j,flag_win=0;
	for(i=line_i-3; i<line_i+4; i++) {
		for(j=line_j-3; j<line_j+4; j++) {//�������i��j��Χ���ж��Ƿ����γ��������ߣ����ĳ������������������ߣ���ô�������롣
			
			
			//�������0���룬������ط�����������Ƿ��ʹ����Ӯ 
			if(a[i][j]==0) {
				printf("i am Stop_human_win\n%d %d\n",i,j);
				//ˮƽ����
				if (a[i+1][j]==1 && a[i+2][j]==1 && a[i+3][j]==1 &&a[i+4][j]==1) {
					flag_win=1;
					break;
				} else if(a[i-1][j]==1 && a[i-2][j]==1 && a[i-3][j]==1 &&a[i-4][j]==1) {
					flag_win=1;
					break;
				} else if(a[i-1][j]==1 && a[i-2][j]==1 && a[i+1][j]==1 &&a[i+2][j]==1) {
					flag_win=1;
					break;
				} else if(a[i-1][j]==1 && a[i-2][j]==1 && a[i-3][j]==1 &&a[i+1][j]==1) {
					flag_win=1;
					break;
				} else if(a[i+1][j]==1 && a[i+2][j]==1 && a[i+3][j]==1 &&a[i-1][j]==1) {
					flag_win=1;
					break;
				}
				//��ֱ����
				if (a[i][j+1]==1 && a[i][j+2]==1 && a[i][j+3]==1 &&a[i][j+4]==1) {
					flag_win=1;
					break;
				} else if(a[i][j-1]==1 && a[i][j-2]==1 && a[i][j-3]==1 &&a[i][j-4]==1) {
					flag_win=1;
					break;
				} else if(a[i][j-1]==1 && a[i][j-2]==1 && a[i][j+1]==1 &&a[i][j+2]==1) {
					flag_win=1;
					break;
				} else if(a[i][j-1]==1 && a[i][j-2]==1 && a[i][j-3]==1 &&a[i][j+1]==1) {
					flag_win=1;
					break;
				} else if(a[i][j+1]==1 && a[i][j+2]==1 && a[i][j+3]==1 && a[i][j-1]==1) {
					flag_win=1;
					break;
				}
				//б����һ
				if (a[i+1][j+1]==1 && a[i+2][j+2]==1 && a[i+3][j+3]==1 && a[i+4][j+4]==1) {
					flag_win=1;
					break;
				} else if(a[i-1][j-1]==1 && a[i-2][j-2]==1 && a[i-3][j-3]==1 && a [i-4][j-4]==1) {
					flag_win=1;
					break;
				} else if(a[i-1][j-1]==1 && a[i-2][j-2]==1 && a[i+1][j+1]==1 &&a [i+2][j+2]==1) {
					flag_win=1;
					break;
				} else if(a[i-1][j-1]==1 && a[i-2][j-2]==1 && a[i-3][j-3]==1 &&a [i+1][j+1]==1) {
					flag_win=1;
					break;
				} else if(a[i+1][j+1]==1 && a[i+2][j+2]==1 && a[i+3][j+3]==1 &&a [i-1][j-1]==1) {
					flag_win=1;
					break;
				}
				//б�����
				if (a[i+1][j-1]==1 && a[i+2][j-2]==1 && a[i+3][j-3]==1 &&a[i+4][j-4]==1) {
					flag_win=1;
					break;
				} else if(a[i-1][j+1]==1 && a[i-2][j+2]==1 && a[i-3][j+3]==1 &&a[i-4][j+4]==1) {
					flag_win=1;
					break;
				} else if(a[i-1][j+1]==1 && a[i-2][j+2]==1 && a[i+1][j-1]==1 &&a[i+2][j-2]==1) {
					flag_win=1;
					break;
				} else if(a[i-1][j+1]==1 && a[i-2][j+2]==1 && a[i-3][j+3]==1 &&a[i+1][j-1]==1) {
					flag_win=1;
					break;
				} else if(a[i+1][j-1]==1 && a[i+2][j-2]==1 && a[i+3][j-3]==1 &&a[i-1][j+1]==1) {
					flag_win=1;
					break;
				}
			}
			
			

		}
		
		
		
		if(flag_win==1) {
			break;
		}//���������ڶ���ѭ�� 
		
		
	}
//����жϣ����Ƿ����Ѿ�����Ӯ�ˣ����ݲ�ͬ�Ľ�����ز�ͬ��ֵ��������һ���жϣ� 
	if(flag_win==1) {
		a[i][j]=2;
		return 1;
	} else {
		return 0;
	}
	
	
}

int Stop_live_four (int a[][23],int i,int j) {
	int line_i=i,line_j=j,flag_live_four=0;
	for(i=line_i-3; i<line_i+4; i++) {

		for(j=line_j-3; j<line_j+4; j++) {//�������i��j��Χ���ж��Ƿ����γ��������ߣ����ĳ������������������ߣ���ô�������롣
			if(a[i][j]==0) {
				if(  a[i+1][j]==1 &&  a[i+2][j]==1 && a[i+3][j]==1) {
					if(a[i-1][j]==0 && a[i+4][j]==0) {
						flag_live_four=1;
						break;
					}
				} else if ( a[i-1][j]==1 &&  a[i-2][j]==1 && a[i-3][j]==1) {
					if(a[i+1][j]==0 && a[i-4][j]==0) {
						flag_live_four=1;
						break;
					}
				} else if( a[i-1][j]==1 &&  a[i+1][j]==1 && a[i+2][j]==1) {
					if(a[i-2][j]==0 && a[i+3][j]==0) {
						flag_live_four=1;
						break;
					}
				} else if( a[i+1][j]==1 &&  a[i-1][j]==1 && a[i-2][j]==1) {
					if(a[i+2][j]==0 && a[i-3][j]==0) {
						flag_live_four=1;
						break;
					}
				}
				
				
					if(  a[i][j+1]==1 &&  a[i][j+2]==1 && a[i][j+3]==1) {
						if(a[i][j-1]==0 && a[i][j+4]==0) {
							flag_live_four=1;
							break;
						}
					} else if( a[i][j-1]==1 &&  a[i][j-2]==1 && a[i][j-3]==1) {
						if(a[i][j+1]==0 && a[i][j-4]==0) {
							flag_live_four=1;
							break;
						}
					} else if( a[i][j-1]==1 &&  a[i][j+1]==1 && a[i][j+2]==1) {
						if(a[i][j-2]==0 && a[i][j+3]==0) {
							flag_live_four=1;
							break;
						}
					} else if( a[i][j+1]==1 &&  a[i][j-1]==1 && a[i][j-2]==1) {
						if(a[i][j+2]==0 && a[i][j-3]==0) {
							flag_live_four=1;
							break;
						}
					}
					//б����һ
					if(  a[i+1][j+1]==1 &&  a[i+2][j+2]==1 && a[i+3][j+3]==1) {
						if(a[i-1][j-1]==0 && a[i+4][j+4]==0) {
							flag_live_four=1;
							break;
						}
					} else if ( a[i-1][j-1]==1 &&  a[i-2][j-2]==1 && a[i-3][j-3]==1) {
						if(a[i+1][j+1]==0 && a[i-4][j-4]==0) {
							flag_live_four=1;
							break;
						}
					} else if( a[i-1][j-1]==1 &&  a[i+1][j+1]==1 && a[i+2][j+2]==1) {
						if(a[i-2][j-2]==0 && a[i+3][j+3]==0) {
							flag_live_four=1;
							break;
						}
					} else if( a[i+1][j+1]==1 &&  a[i-1][j-1]==1 && a[i-2][j-2]==1) {
						if(a[i+2][j+2]==0 && a[i-3][j-3]==0) {
							flag_live_four=1;
							break;
						}
					}
					//б�����
					if(  a[i+1][j-1]==1 &&  a[i+2][j-2]==1 && a[i+3][j-3]==1) {
						if(a[i-1][j+1]==0 && a[i+4][j-4]==0) {
							flag_live_four=1;
							break;
						}
					} else if ( a[i-1][j+1]==1 &&  a[i-2][j+2]==1 && a[i-3][j+3]==1) {
						if(a[i+1][j-1]==0 && a[i-4][j+4]==0) {
							flag_live_four=1;
							break;
						}
					} else if( a[i-1][j+1]==1 &&  a[i+1][j-1]==1 && a[i+2][j-2]==1) {
						if(a[i-2][j+2]==0 && a[i+3][j-3]==0) {
							flag_live_four=1;
							break;
						}
					} else if( a[i+1][j-1]==1 &&  a[i-1][j+1]==1 && a[i-2][j+2]==1) {
						if(a[i+2][j-2]==0 && a[i-3][j+3]==0) {
							flag_live_four=1;
							break;
						}
					}

			}

		}
		
		//���������ڶ���ѭ�� 
		if(flag_live_four==1) {
			break;
		}
	}
	if(flag_live_four==1) {
		a[i][j]=2;
		return 1;
	} else {
		return 0;
	}
}
//�� ��� ��
