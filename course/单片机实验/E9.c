#include"LCD.h"
#include <intrins.h>

sbit IRIN = P3^2;
unsigned char IRCOM[4];
unsigned char a,b;              //��������


void delay1(uchar x); 
void delay2(int ms);
/*************************������*****************************/
main()
{
   IE = 0x81;                 //�������ж��ж�,ʹ�� INT1 �ⲿ�ж�
   IRIN=1;                    //�ӿڳ�ʼ��
   delay2(10);                //��ʱ
   LCD_init();                //��ʼ��LCD
   while(1);

} 


/************************�жϺ���*************************/
void IR_IN() interrupt 0 using 0
{
   unsigned char j,k,N=0;
   EX0 = 0;
   delay(15);
   if (IRIN==1)
   {
      EX0 =1;
	   return;
   }
                           //ȷ��IR�źų���
   while (!IRIN)            //��IR��Ϊ�ߵ�ƽ������9ms��ǰ���͵�ƽ�źš�
   {
      delay1(1);
   }

   for (j=0;j<4;j++)           //�ռ���������
   {
      for (k=0;k<8;k++)        //ÿ��������8λ
      {
         while (IRIN)            //�� IR ��Ϊ�͵�ƽ������4.5ms��ǰ���ߵ�ƽ�źš�
         {
            delay1(1);
         }
         while (!IRIN)          //�� IR ��Ϊ�ߵ�ƽ
         {
            delay1(1);
         }
         while (IRIN)           //����IR�ߵ�ƽʱ��
         {
            delay1(1);
            N++;
            if (N>=30)
            {
               EX0=1;
               return;
            }                  //0.14ms���������Զ��뿪��
         }                        //�ߵ�ƽ�������
         IRCOM[j]=IRCOM[j] >> 1;                  //�������λ����0��
         if (N>=8)
         {
            IRCOM[j] = IRCOM[j] | 0x80;
         }                                   //�������λ����1��
         N=0;
      }                                      
   	}                                         

   	if (IRCOM[2]!=~IRCOM[3])
   	{
        EX0=1;
        return;
   	}

   	b=IRCOM[2] & 0x0F;     //ȡ����ĵ���λ
   	a=IRCOM[2] >> 4;       //����4�Σ�����λ��Ϊ����λ
  	if(a>9)
   	{
   		a+=0x37;
	}
	else a+=0x30;
	if(b>9)
   	{
   		b+=0x37;
	}
	else b+=0x30;


   LCD_show_var(1,0,a,b);
   EX0 = 1;
}


/**********************************************************/
void delay1(unsigned char x)    
{
 	unsigned char i;
  	while(x--)
 	{
 		 for (i = 0; i<13; i++) {}
 	}
}

/**********************************************************/
void delay2(int ms)
{
	unsigned char y;
	while(ms--)
 	{
  		for(y = 0; y<250; y++)
  		{
   			_nop_();
   			_nop_();
   			_nop_();
   			_nop_();
  		}
 	}
}
