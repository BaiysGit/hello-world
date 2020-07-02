/************************ 
    
改造想法，把这个改成可以翻动的日历，参考test1。
	 
*************************/
//日历：打印指定月份 

#include<stdio.h>
#include<stdlib.h>
int W_Year(int y);
int Is_leap(int y);
int Max_Day(int y,int m,int x);
int W_Year(int y,int m);
void Month_Printf(int y,int Max_Day);

/***********************************************************/

int main()
{
	int y,m,d,w,max;int x;char ch,temp;
	printf("Year Month:");
	scanf("%d %d", &y, &m);
	//while((ch = getchar()) != '\n' && ch != EOF);
	//while(1) 
 //{
	x=Is_leap(y);
	w=W_Year(y,m);
	max=Max_Day(y,m,x);
    Month_Printf(w,max);   
    /* 实现导航  */
    //scanf("%c",&temp);
    //while((ch = getchar()) != '\n' && ch != EOF);
    //ch=getchar();
    /*switch(ch){
    case 27:exit(0);break;//Esc
    case -32:ch=getchar();break;//Navigator
    if(ch==77)
    {//Right
       y+=(m==12)?1:0;
       m=m%12+1;
    }
    else if(ch==75)
    {//Left
       y-=(m==1)?1:0;
       m=(m-2+12)%12+1;
    }
    else if(ch==72)
    {//Up
       y--;
    }
    else if(ch==80)
    {//Down
       y++;
    }
    default:printf("Illeagle input");break;
    } */
 //}	
	return 0;
}

/**************************函数*******************************/ 

int Is_leap(int y)//判断是否是闰年，便于打印2月， 
{
	if( y%400==0 || (y%4==0&&y%100!=0) ) return 1;
	else return 0;
}

int W_Year(int y, int m)//求出这月的1号是周几 
{
	int w,c;
	if(m==1||m==2)
	{
		m+=12;
		y--;
	}
	c=y/100;
	y=y%100;
	w=y+y/4+c/4-2*c+(13*(m+1))/5;
	if(w<0)
	{
		while(w<0) w+=7;
	}
	if(w>7)
	{
		while(w>7) w-=7;
	}
	return w;		
}


int Max_Day(int y,int m,int x)//该月最大天数 
{
	int Max[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(x)Max[1]=29;
	return Max[m-1];
}


void Month_Printf(int w,int Max_Day)//打印日历 
{
	int i,j;
	int m=0,n=0,k=1;
	printf("\nSUN MON TUE WED THU FRI SAT\n");
	char space=' ';
	for(i=0;i<w;i++) 
	{
		printf("%-4c",space);
		m++;
	}
	
	while(k<=Max_Day)
	{
		for(m;m<7;m++)
		{
		   printf("%-4d",k);
		   k++;
		   if(k>Max_Day)break;	
		}
		m=0;
		printf("\n");
	}
	/*printf("Left....Prev Month\n");
    printf("Right...Next Month\n");
    printf("Up......Prev Year\n");
    printf("Down....Next Year\n");
    printf("Esc.....Exit\n");*/
}
