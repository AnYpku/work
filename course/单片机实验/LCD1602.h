/*****************************************************************************
 文件名：LCD1602.h
 说明  ：LCD1602显示驱动程序
 功能  ：在lcd1602上显示单个字符；显示字符串；滚动显示字符串；存入自定义字符
 使用  ：1.初始化  2.功能函数
******************************************************************************/
#include<string.h>	
#define LCD_DB P0
sbit  LCD_RS = P2^6;
sbit  LCD_RW = P2^5;  
sbit  LCD_E  = P2^7;

#define uchar unsigned char
#define uint unsigned int


void LCD_init(void);//初始化函数
void LCD_write_command(uchar command);//写指令函数
void LCD_write_data(uchar dat);//写数据函数
void LCD_disp_char(uchar x,uchar y,uchar dat);//在某个屏幕位置上显示一个字符,X（0-16),y(1-2)
//void LCD_check_busy(void);//检查忙函数。我没用到此函数，因为通过率极低。
void delay_n40us(uint n);//延时函数


//********************************
//*******初始化函数***************
void LCD_init(void)
{
LCD_write_command(0x38);//6.设置8位格式，2行，5x7
LCD_write_command(0x0c);//整体显示，关光标，不闪烁
LCD_write_command(0x06);//设定输入方式，增量不移位
LCD_write_command(0x01);//清除屏幕显示
delay_n40us(81);//实践证明，我的LCD1602 上，用for 循环200 次就能可靠完成清屏指令。
}
//********************************
//********写指令函数************
void LCD_write_command(uchar dat)
{
LCD_DB=dat;
LCD_RS=0;//指令
LCD_RW=0;//写入
LCD_E=1;//下降沿~允许
LCD_E=0;
delay_n40us(1);//实践证明，我的LCD1602 上，用for 循环1 次就能完成普通写指令。
}
//*******************************
//********写数据函数*************
void LCD_write_data(uchar dat)
{
LCD_DB=dat;
LCD_RS=1;//数据
LCD_RW=0;//写入
LCD_E=1;//下降沿~允许
LCD_E=0;
delay_n40us(1);
}
//********************************
//*******显示一个字符函数*********
void LCD_disp_char(uchar x,uchar y,uchar dat)
{
	uchar address,j;
	delay_n40us(100);
	if(y==1)
	j=0x80;
	else
	j=0xc0;
	address=x + j;
	LCD_write_command(address);
	LCD_write_data(dat);
}
//********************************
//*******显示一个字符串***********
void LCD_show_str(uchar y,char str[]){
	uchar i, j,address ;
	if(y==1)
	j=0x80;
	else
	j=0xc0;
	for(i = 0;i<strlen(str);i++){
	address=i + j;
	LCD_write_command(address);
	LCD_write_data(str[i]);
	}
}
//********************************
//*******滚动显示一个字符串***********
void LCD_cro_str(char str[]){
	uchar i,j, address ; 
	for(j=16;j>0;j--){
		for(i = 0;i<strlen(str);i++){
			address=(i+j)%16 + 0xc0;
			LCD_write_command(address);
			LCD_write_data(str[i]);
		}
		delay_n40us(8000);
	}						
}

void show_int(uchar x,uchar y,uint dat){
	uint address,j;
	delay_n40us(100);
	if(y==1)
	j=0x80;
	else
	j=0xc0;
	address=x + j;
	LCD_write_command(address);
	LCD_write_data('0'+(dat%1000)/100);
	LCD_write_command(address+1);
	LCD_write_data('0'+(dat%100)/10);
	LCD_write_command(address+2);
	LCD_write_data('0'+dat%10);
	LCD_write_command(address+3);
	LCD_write_data('0'+dat%10);
}
//******************************/
//********延时函数***************
void delay_n40us(uint n)
{ uint i;
uchar j;
for(i=n;i>0;i--)
for(j=0;j<2;j++); //在这个延时循环函数中我只做了2次循环，
}