#include<reg51.h>

sbit s2 = P1^0;
sbit s1 = P1^1;
sbit m2 = P1^2;
sbit m1 = P1^3;

char digit[10] = {0x77,0x14,0xB3,0xB6,0xD4,0xE6,0xE7,0x34,0xF7,0xF6};
char digitdp[10] = {0x7F,0x1C,0xBB,0xBE,0xDC,0xEE,0xEF,0x3C,0xFF,0xFE};

void delay()
{
int i,j;
for(i=0;i<20;i++)
 for(j=0;j<31;j++);	
}

//void delay_s()
//{
//int count=0;
//  while(count != 20)	
//	 {
//		 TMOD = 0x01;
//		 TH0 = 0X4B;
//		 TL0 = 0XFD;
//		 TR0 = 1;
//		 while(TF0 == 0);
//		 TF0 = 0;
//		 TR0 = 0;
//     count++;		 
//	 } 
//}


void main()
{
int m=0,n=0,x=0,y;

  while(1)
  {	
	//while(n<=60)
		//{
		y = 0;
		while(x<48)
		{
		s2 = 1;
		P2 = digit[n%10];
		delay();
		s2 = 0;
		s1 = 1;	
		P2 = digit[n/10];
		delay();
		s1 = 0;	
		m2 = 1;
		P2 = digitdp[m%10];
		delay();
		m2 = 0;
		m1 = 1;
		P2 = digit[m/10];
		delay();
		m1 = 0;
			x++;
		}
	//delay_s();	
		n++;	
		x = 0;
   //}
		if(n==60)
  	{	
	    	n=0;
        m++;		
	    }	
		
	  if(m == 100)
		{
			m=0;		
			}
			
		if(m!=0&&m%5==0&&y==0)
		{
		n = 1;		
		y = 1;	
    }	
    
 }

}
