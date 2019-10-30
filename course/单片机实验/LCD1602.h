/*****************************************************************************
 �ļ�����LCD1602.h
 ˵��  ��LCD1602��ʾ��������
 ����  ����lcd1602����ʾ�����ַ�����ʾ�ַ�����������ʾ�ַ����������Զ����ַ�
 ʹ��  ��1.��ʼ��  2.���ܺ���
******************************************************************************/
#include<string.h>	
#define LCD_DB P0
sbit  LCD_RS = P2^6;
sbit  LCD_RW = P2^5;  
sbit  LCD_E  = P2^7;

#define uchar unsigned char
#define uint unsigned int


void LCD_init(void);//��ʼ������
void LCD_write_command(uchar command);//дָ���
void LCD_write_data(uchar dat);//д���ݺ���
void LCD_disp_char(uchar x,uchar y,uchar dat);//��ĳ����Ļλ������ʾһ���ַ�,X��0-16),y(1-2)
//void LCD_check_busy(void);//���æ��������û�õ��˺�������Ϊͨ���ʼ��͡�
void delay_n40us(uint n);//��ʱ����


//********************************
//*******��ʼ������***************
void LCD_init(void)
{
LCD_write_command(0x38);//6.����8λ��ʽ��2�У�5x7
LCD_write_command(0x0c);//������ʾ���ع�꣬����˸
LCD_write_command(0x06);//�趨���뷽ʽ����������λ
LCD_write_command(0x01);//�����Ļ��ʾ
delay_n40us(81);//ʵ��֤�����ҵ�LCD1602 �ϣ���for ѭ��200 �ξ��ܿɿ��������ָ�
}
//********************************
//********дָ���************
void LCD_write_command(uchar dat)
{
LCD_DB=dat;
LCD_RS=0;//ָ��
LCD_RW=0;//д��
LCD_E=1;//�½���~����
LCD_E=0;
delay_n40us(1);//ʵ��֤�����ҵ�LCD1602 �ϣ���for ѭ��1 �ξ��������ͨдָ�
}
//*******************************
//********д���ݺ���*************
void LCD_write_data(uchar dat)
{
LCD_DB=dat;
LCD_RS=1;//����
LCD_RW=0;//д��
LCD_E=1;//�½���~����
LCD_E=0;
delay_n40us(1);
}
//********************************
//*******��ʾһ���ַ�����*********
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
//*******��ʾһ���ַ���***********
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
//*******������ʾһ���ַ���***********
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
//********��ʱ����***************
void delay_n40us(uint n)
{ uint i;
uchar j;
for(i=n;i>0;i--)
for(j=0;j<2;j++); //�������ʱѭ����������ֻ����2��ѭ����
}