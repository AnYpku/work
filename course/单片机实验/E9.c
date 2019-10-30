#include"LCD.h"
#include <intrins.h>

sbit IRIN = P3^2;
unsigned char IRCOM[4];
unsigned char a,b;              //缓冲数据


void delay1(uchar x); 
void delay2(int ms);
/*************************主函数*****************************/
main()
{
   IE = 0x81;                 //允许总中断中断,使能 INT1 外部中断
   IRIN=1;                    //接口初始化
   delay2(10);                //延时
   LCD_init();                //初始化LCD
   while(1);

} 


/************************中断函数*************************/
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
                           //确认IR信号出现
   while (!IRIN)            //等IR变为高电平，跳过9ms的前导低电平信号。
   {
      delay1(1);
   }

   for (j=0;j<4;j++)           //收集四组数据
   {
      for (k=0;k<8;k++)        //每组数据有8位
      {
         while (IRIN)            //等 IR 变为低电平，跳过4.5ms的前导高电平信号。
         {
            delay1(1);
         }
         while (!IRIN)          //等 IR 变为高电平
         {
            delay1(1);
         }
         while (IRIN)           //计算IR高电平时长
         {
            delay1(1);
            N++;
            if (N>=30)
            {
               EX0=1;
               return;
            }                  //0.14ms计数过长自动离开。
         }                        //高电平计数完毕
         IRCOM[j]=IRCOM[j] >> 1;                  //数据最高位补“0”
         if (N>=8)
         {
            IRCOM[j] = IRCOM[j] | 0x80;
         }                                   //数据最高位补“1”
         N=0;
      }                                      
   	}                                         

   	if (IRCOM[2]!=~IRCOM[3])
   	{
        EX0=1;
        return;
   	}

   	b=IRCOM[2] & 0x0F;     //取键码的低四位
   	a=IRCOM[2] >> 4;       //右移4次，高四位变为低四位
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
