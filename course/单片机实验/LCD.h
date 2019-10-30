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

//*******�����б�***************
void LCD_init(void);//��ʼ������
void LCD_check_busy(void);//���æ����
void LCD_write_command(uchar command);//дָ���
void LCD_write_data(uchar dat);//д���ݺ���
void delay(uint n);//��ʱ����

//********LCD��ʾģ��************* 


//*******��ʼ������***************
void LCD_init(void)
{
	LCD_write_command(0x38);//6.����8λ��ʽ��2�У�5x7
	LCD_write_command(0x0c);//������ʾ���ع�꣬����˸
	LCD_write_command(0x06);//�趨���뷽ʽ����������λ
	LCD_write_command(0x01);//�����Ļ��ʾ
}

//********���æ����*************
void LCD_check_busy(void)           //æ��⺯�����ж�bit7��0������ִ�У�1��ֹ
{
	unsigned char sta;      //
	LCD_DB = 0xff;
    LCD_RS = 0;
    LCD_RW = 1;
    do
    {
    	LCD_E= 1;
        sta = LCD_DB;
        LCD_E= 0;    //ʹ�ܣ���������ͣ��ͷ�����
    }while(sta & 0x80);
}

//********************************
//********дָ���************
void LCD_write_command(uchar dat)
{
	LCD_check_busy();
	LCD_DB=dat;
 	LCD_RS=0;//ָ��
	LCD_RW=0;//д��
	LCD_E=1;//�½���~����
	LCD_E=0;
	delay(1);
}

//*******************************
//********д���ݺ���*************
void LCD_write_data(uchar dat)
{
	LCD_check_busy();
	LCD_DB=dat;
	LCD_RS=1;//����
	LCD_RW=0;//д��
	LCD_E=1;//�½���~����
	LCD_E=0;
	delay(1);
}


//*******��ʾһ���ַ���***********
void LCD_show_str(char y, char k, char str[])  //yΪ���� kΪ��ʾ���
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

//*******��ʾ����***********
void LCD_show_var(char y,char z, char v1,v2)   //yΪ������zΪ���������
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






//********��ʱ����***************
void delay(uint n)
{ 
   uint i;
   uchar j;
   for(i=n;i>0;i--)
   for(j=0;j<2;j++); 
}
