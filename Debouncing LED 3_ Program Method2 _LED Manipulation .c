//debouncing LED Project
#include<p18f4580.h>
#define SW1 PORTCbits.RC0 //0x01
#define LED1 PORTCbits.RC1 //0x02
#define LED2 PORTCbits.RC2 //0x04
#define LED3 PORTCbits.RC3 //0x08


void delay()
{
	int i,j;
	for(i = 0; i < 200; i++)
	for(j = 0; j < 100; j++);
}




void main()
{
	
      	TRISC=0x01;  // means the RC0 pins in input and rest are output
	//TRISC = 1;	//PORTC will work as OUTPUT
	PORTC=0;      // ALL the pins in PORT C are low =0
	while(1)
	{
	
		static int count =1;
		
			if (PORTCbits.RC0==0 && count==1 )
			{
                PORTCbits.RC1=1;  // LED 1 ON
				PORTCbits.RC2=0;
				PORTCbits.RC3=0;
			    while(PORTCbits.RC0==0);
			    count++;
             }
         		
         		
         	if (count ==2 && PORTCbits.RC0==0 )
			{  
				
				PORTCbits.RC2=1;  // LED 2 ON
				PORTCbits.RC1=0;
                PORTCbits.RC3=0;

			    while(PORTCbits.RC0==0);
                count++;
             }
			
			if (count ==3 && PORTCbits.RC0==0 )
			{
				
				PORTCbits.RC3=1;  // LED 3 ON
				PORTCbits.RC2=0;
				PORTCbits.RC1=0;
			    while(PORTCbits.RC0==0);	    
                count=1;
             } 
		
    
            

	}

}