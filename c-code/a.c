

//#include:包含其后文件至程序;std：标准库；io：input，output；.h：头文件，系统提供；“”：自定义头文件；<>:系统库
//
//main函数：主函数。每一个c语言程序有且只有一个主函数。
//void为返回值
#include "stdio.h"//预处理命令导入头文件

/*
void main()
{
    int num1, num2;

    int average;

    num1 = 1023;
    num2 = 223;

    average = (num1+num2)/2;

    printf("%d和%d的平均数是%d\n",num1,num2,average);
}
*/

/*
    float zhouchang(float r)
    {
         return 2*3.14*r;
    }

    float mianji(float r)
    {
         return 3.14*r*r;
    }

void main()
{
   float r,zhouchang,mianji;
   printf("请输入一个半径:");
   scanf("%f",&r);//f为单精度小数，lf为双精度小数
   zhouchang = zhouchang(r);
   mianji = mianji(r);

   printf("半径是%f的圆的周长是%f，面积是%f\n",r,zhouchang,mianji); 
} 	

*/

/*
#include <stdio.h>
void main()
{
    int a,b,c;
    printf("请输入三个整数以逗号隔开\n");	
    scanf("%d,%d,%d",&a,&b,&c);

    if(a>b && b>c)
    {
        printf("三个数中最大值是%d\n，最小值是%d\n",a,c);	    
    }
}	
*/


/*
//冒泡排序
#include <stdio.h>
void main()
{
    int a,b,c,t;
    printf("请输入三个整数\n");
    scanf("%d,%d,%d",&a,&b,&c);

    if(a>b){
        t = a;b = a;a = t;}//a和b交换值
    if(a>c){
        t = a;a = c;c = t;}
    if(b>c){
        t = b;b = c;c = t;}
    printf("排序后的三个数从小到大是：最小=%d,中等=%d,最大=%d\n",a,b,c);  
  	  
}	

//关系表达式的验证
#include <stdio.h>
void main()
{
    int a,b,c,x,y;
    a = 1,b = 2,c = 3;

    x = a>b;
    y = a<b<c;

    printf("%d,%d\n",x,y)
    printf("%d\n",a=b>=c);//0表示假，1表示真。
}	
*/


/*
//5%d代表右对齐左补空格，%m.nf,m表示输出的整个数据的位数，n表示小数部分的位数。
#include <stdio.h>
void main()
{
    int a=2222,b=-22;
    float c=10.22,d=-10.22;

    printf("%5d\n%5d\n",a,b);
    printf("%8.2f\n%8.2f\n",c,d);
}	
*/


/*
//通过循环在键盘上得到多个字符（键盘缓冲区残余问题）
#include <stdio.h>
void main()
{
    char c;
    do
    {
        printf("请输入一个字符串\n");
        fflush(stdin);
        scanf("%c",&c);
        printf("c = %c\n",c);
        printf("c = %d\n",c);	  
    }	  
    while(c!='N');
}
*/

/*
//单个字符输入函数中的缓冲区残留问题
#include <stdio.h>
void main()
{
    char a,b;
    a=getchar();
    fflush(stdin);
    b=getchar();
    putchar(a'\n');
    putchar(b'\n');
}	
*/


#include <stdio.h>
void main()

/*	
{
    char c;
    printf("请输入一个字符\n");
    c=getchar();

    if(c >= 65 && c <= 90){
        putchar(c+32);}
    
    if(c >= 97 && c <= 122){
        putchar(c-32);
	putchar('\n');}
}	
*/


//多分支结构
/*
{
    int a,b;
    printf("请输入两个整数：");
    scanf("%d,%d",&a,&b);
    if(a!=b){

        if(a>b){
            printf("%d > %d",a,b);}
        else{
	    printf("%d < %d",a,b);}

    else{
        printf("%d=%d",a,b);}

    printf("\n");     
}
*/

/*
{
    int score;
    printf("请输入学生成绩：");
    scanf("%d",&score);

    if(score<0 || score>100){
        printf("成绩无效！\n");
    }	

    else{

        switch(score/10){

	    case 10:
            case 9:
            printf("优秀！\n");break;//switch语句出现break表示结束switch继续向后执行
	    case 8:
	    case 7:
	    case 6:
	    printf("及格！\n");break;
	    default:
	    printf("不及格！\n");
            		    
	}	
    }	    
}	
*/
/*
{
    int i = 1,sum = 0;
    for(;;)//(i=1;i<=100;i++)
    {
	if(i<=100)
	{sum+=i++;}
	else
        {break;}//if和break常一起出现		
    }	    
    printf("1到100的和是%d\n",sum);
}
{
    int i,sum = 0;
    for(i = 1;i <= 100;i++){
        sum += i;
    }
    printf(sum="%d\n",sum);



*/

/*
{
    int i = 1,sum = 0;
    while(i<=100)//循环条件

    { sum += i++; }

    printf("%d\n",sum);/    
}	
*/

/*
{
    int i=1,sum=0;

    do{
        sum += i++;}

    while(i<=100);//循环条件，若真继续循环，若假退出循环。
    
    printf("%d",sum);    
}

*/

/*
{
    int i,score;

    for(i = 1;i <= 45; i++){
        printf("请输入%d号学生成绩：\n",i);
        scanf("%d", &score);

        if(score<0 || score>100){
            printf("成绩无效！\n");}

        else if(score>=60){
            printf("及格！\n");}

        else{
            printf("不及格！\n");}	    
    }	    
}	
*/

