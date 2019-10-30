#include<reg51.h>
#include<string.h>	

#define LCD_DB P0
sbit  LCD_RW = P2^5;
sbit  LCD_RS = P2^6;
sbit  LCD_E  = P2^7;

#define uchar unsigned char
#define uint unsigned int

sbit  K1=P3^2;
sbit  K2=P3^3;
uchar count1,count2,time,x1,x2,y1,y2,z1,z2;
unsigned char Disp[] ={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};

//*******函数列表***************
void LCD_init(void);//初始化函数
void LCD_check_busy(void);//检查忙函数
void LCD_write_command(uchar command);//写指令函数
void LCD_write_data(uchar dat);//写数据函数
void delay(uint n);//延时函数

//********LCD显示模块************* 


//*******初始化函数***************
void LCD_init(void)
{
	LCD_write_command(0x38);//6.设置8位格式，2行，5x7
	LCD_write_command(0x0c);//整体显示，关光标，不闪烁
	LCD_write_command(0x06);//设定输入方式，增量不移位
	LCD_write_command(0x01);//清除屏幕显示
}

//********检查忙函数*************
void LCD_check_busy(void)           //忙检测函数，判断bit7是0，允许执行；1禁止
{
	unsigned char sta;      //
	LCD_DB = 0xff;
    LCD_RS = 0;
    LCD_RW = 1;
    do
    {
    	LCD_E= 1;
        sta = LCD_DB;
        LCD_E= 0;    //使能，用完就拉低，释放总线
    }while(sta & 0x80);
}

//********************************
//********写指令函数************
void LCD_write_command(uchar dat)
{
	LCD_check_busy();
	LCD_DB=dat;
 	LCD_RS=0;//指令
	LCD_RW=0;//写入
	LCD_E=1;//下降沿~允许
	LCD_E=0;
	delay(1);
}

//*******************************
//********写数据函数*************
void LCD_write_data(uchar dat)
{
	LCD_check_busy();
	LCD_DB=dat;
	LCD_RS=1;//数据
	LCD_RW=0;//写入
	LCD_E=1;//下降沿~允许
	LCD_E=0;
	delay(1);
}


//*******显示一个字符串***********
void LCD_show_str(char y, char k, char str[])  //y为行数 k为显示起点
{
 
	uchar i,j, address ;
	if(y==1)
	{
	   j=0x80;
	}
	else j=0xc0;
	for(i = 0;i<strlen(str);i++)
	{
	   address=i+j+k;
	   LCD_write_command(address);
	   LCD_write_data(str[i]);
	}
}

//*******显示变量***********
void LCD_show_var(char y,char z, char v1,v2)   //y为行数，z为计数器编号
{
 
	uchar j, address ;
	if(y==1)
	{
	   j=0x80;
	}
	else j=0xc0;
	address=5*z+j;
	LCD_write_command(address);
	LCD_write_data(v1);
	address=5*z+1+j;
	LCD_write_command(address);
	LCD_write_data(v2);
}






//********延时函数***************
void delay(uint n)
{ 
   uint i;
   uchar j;
   for(i=n;i>0;i--)
   for(j=0;j<2;j++); 
}
