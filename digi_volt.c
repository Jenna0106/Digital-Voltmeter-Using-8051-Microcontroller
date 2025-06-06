#include<reg51.h>
#define lcd P0
#define dat P3
sbit rs=P2^0;
sbit e=P2^1;


void delay (int);
void display (unsigned char);
void cmd (unsigned char);
void init (void);
void string (char *);
void intro (void);
char i=0;

void delay (int d)
{
	unsigned char i=0;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}
void cmd (unsigned char c)
{
	lcd=c;
	rs=0;
	e=1;
	delay(10);
	e=0;
}
void display (unsigned char c)
{
	lcd=c;
	rs=1;
	e=1;
	delay(10);
	e=0;
}
void string (char *c)
{
	while(*c)
	{
		display(*c++);
	}
}
void init (void)
{
	cmd(0x38);
	cmd(0x01);
  cmd(0x0c);
	cmd(0x80);
}
void intro (void)
{
	string("    Digital    ");
	cmd(0xc0);
	string("   Voltmeter   ");
	delay(1000);
	cmd(0x01);
	cmd(0x86);
	string("Volts");
	
}

void main()
{
  float val=0.0;
	unsigned int temp=0;
	unsigned int val1=0;
	init();
	intro();
	dat=0xff;
	while(1)
	{
		val=dat*0.02;
		val1=val*100;
		cmd(0x80);
		
		temp=(((val1/100)%10)+48);
		display(temp);
		
		display('.');
		
		temp=(((val1/10)%10)+48);
		display(temp);
		
		temp=((val1%10)+48);
		display(temp);
 
		delay(300);
	}
	while(1);
}
