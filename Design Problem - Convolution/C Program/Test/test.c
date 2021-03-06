#include<lpc21xx.h>
#include<string.h>
#include<math.h>
#include<stdio.h>

void delay(void);
void lcd(unsigned char,int);

char keypad(void);
char k;

int main(void)
{
   float n1,n2,n3;
	 int outs,a1,b1,c1,d1,e1,outl;

   unsigned int i;
   unsigned char ch[]="Enter the number";
   unsigned char ch2[]="Enter a:";
   unsigned char ch3[]="Enter b:";
   unsigned char ch4[]="Enter c:";
   unsigned char ch5[]="Enter d:";
   unsigned char ch6[]="Largest Number:";
	 unsigned char ch7[]="Smallest Number:";
   unsigned char err[]="ERROR/Same input";
   char test=' ';
   char a[16];
   char b[16];
   char c[16];
   char d[16];
	 char e[16];
   char outxs[16];
   char outxl[16];
		
   PINSEL0=PINSEL2=0;	        	//configure pins as GPIO	 
   IODIR0=0x000003ff;				   //pins P0.0 to 9
   IODIR1=0x00f80000;				    //pins P1.19 to 23, P1.16 to 18 is set as 0 hence input pins
   lcd(0x38,0);						      //0x38 is lcd command to initialise lcd in 8 bit mode
   lcd(0x0f,0);					    		//0x0f is command for - display on,cursor blinking
	 
   while(1)
   {	
		a[0]='\0';			//to clear/empty the strings
		b[0]='\0';
		c[0]='\0';
		d[0]='\0';
		outxs[0]='\0';
		outxl[0]='\0';

		n1=0;				//resetting values for current iteration
		n2=0;
		n3=0;
		 
// Code runs from below

 	  	for(i=0;ch[i]!='\0';i++)
	   		lcd(ch[i],1);  
		 
   		while(1)																  	//wait for keypress to clear screen and display next line
     {
       		k=keypad();                             //Obtaining values from keypad(Any random value to initiate and scan)
			break;
     }
		 
	 	lcd(0x01,0);		                              //LCD cmd to clear screen
		  
   		for(i=0;ch2[i]!='\0';i++)
	    	lcd(ch2[i],1);
   		lcd(0x0c0,0);                               //lcd cmd to force cursor to 2nd line
		i=0;
		while(1)								                    	//loop to get a
     {
       		k=keypad();                             //Obtaining values from keypad
			if(k=='E')
			{
			a[i]='\0';
			break;
			}
	   		a[i]=k;                                      // input scan
			i++;
			lcd(k,1);                                      // input live display
     }
		 
   		lcd(0x01,0);																		//LCD cmd to clear screen
		 
		 
		for(i=0;ch3[i]!='\0';i++)
	    	lcd(ch3[i],1);		
   		lcd(0x0c0,0);                         
		i=0;
		while(1)
     {											   //loop to get b
       		k=keypad();                           
			if(k=='E')
			{
			b[i]='\0';
			break;
			}
	   		b[i]=k;
			i++;
			lcd(k,1);
     }
		lcd(0x01,0);
		for(i=0;ch4[i]!='\0';i++)
	    	lcd(ch4[i],1);
   		lcd(0x0c0,0);
		i=0; 
		while(1)
     {											   //loop to get c
       		k=keypad();                           
			if(k=='E')
			{
			c[i]='\0';
			break;
			}
	   		c[i]=k;
			i++;
			lcd(k,1);
     }
		 
		 
		lcd(0x01,0);
		for(i=0;ch5[i]!='\0';i++)
	    	lcd(ch5[i],1);
   		lcd(0x0c0,0);
		i=0;
		while(1)
     {											   //loop to get d
       		k=keypad();                           
			if(k=='E')
			{
			d[i]='\0';
			break;
			}
	   		d[i]=k;
			i++;
			lcd(k,1);
     }
		lcd(0x01,0);
		 
		 
		//code to check if arrays are inititalised properly
		 
		 
		 
		for(i=0;a[i]!='\0';i++)
	    	lcd(a[i],1);
		 
		lcd(0x0c0,0);                               //lcd cmd to force cursor to 2nd line
		 
		 
		for(i=0;b[i]!='\0';i++)
	    	lcd(b[i],1);
		 
		 
		while(1)									//wait for keypress to clear screen and display next line
     	{
       		k=keypad();                            //Obtaining values from keypad
			break;
   		}
			
		lcd(0x01,0); 													//lcd clear screen
			
			
		for(i=0;c[i]!='\0';i++)
	    	lcd(c[i],1);
			
		lcd(0x0c0,0);
			
		for(i=0;d[i]!='\0';i++)
	    	lcd(d[i],1);
		while(1)									//wait for keypress to clear screen and display next line
			
     	{
       		k=keypad();                            //Obtaining values from keypad
			break;
   		}
			
			
		lcd(0x01,0);
			
			
		//code to find largest number-
			
		sscanf(a,"%d",&a1);            //
		sscanf(b,"%d",&b1);            //
		sscanf(c,"%d",&c1);
		sscanf(d,"%d",&d1);
		
		// int	no[4]={a1,b1,c1,d1};
			
		
		if (a1==b1 && d1==c1)
		{
			for(i=0;err[i]!='\0';i++)		       //show error msg if a b c and d both are same
	    		lcd(err[i],1);				
		}
		else 
		
		{
			if (a1>b1 && a1>c1 && a1>d1){ 
				outl=a1;
      if (b1<c1 && b1<d1)
			{
        outs = b1;

      }
      else if (c1<b1 && c1<d1)
			{
       outs = c1;
      }
      else if (d1<b1 && d1<c1)
			{
        outs = d1;
      }
			}
			else if (b1>a1 && b1>c1 && b1>d1) {
				outl=b1;
      if (a1<c1 && a1<d1){
        outs = a1;
      }
      else if(c1<a1 && c1<d1){
        outs = c1;
      }
      else if(d1<a1 && d1<c1){
        outs = d1;
      }
      }
			else if (c1>a1 && c1>b1 && c1>d1)
			{outl=c1;
      if (a1<b1 && a1<d1){
        outs = a1;
      }
      else if(b1<a1 && b1<d1){
        outs = b1;
      }
      else if(d1<a1 && d1<b1){
        outs = d1;
      }
			}
			else if (d1>a1 && d1>b1 && d1>c1) 
			{outl=d1;
      if (a1<b1 && a1<c1){
        outs = a1;
      }
			else if(b1<a1 && b1<c1){
				outs = b1;
			}
			else if(c1<a1 && c1<b1){
				outs = c1;
			}
			}
			
			sprintf(outxs,"%d",(int)outs);
			sprintf(outxl,"%d",(int)outl);
			
			lcd(test,1);
			
			while(1)									//debug support output display
				
     	{
       		k=keypad();                            
			break;
   		}	
			
			lcd(0x01,0);


			for(i=0;ch7[i]!='\0';i++)
	    		lcd(ch7[i],1);
   			lcd(0x0c0,0);					
			for(i=0;outxs[i]!='\0';i++)
	    		lcd(outxs[i],1);	



			while(1)									//debug support output display
				
     	{
       		k=keypad();                            
			break;
   		}	
			
			lcd(0x01,0);

			for(i=0;ch6[i]!='\0';i++)
	    		lcd(ch6[i],1);
   			lcd(0x0c0,0);					
			for(i=0;outxl[i]!='\0';i++)
	    		lcd(outxl[i],1);


			
		}
		while(1)									//wait for keypress to clear screen and display next line
     	{
       		k=keypad();                            //Obtaining values from keypad
			break;
   		}

		lcd(0x01,0);
   }
}
//=========================================================================================================================================//

void lcd(unsigned char a,int b)         //LCD Subroutine
  {
    IOSET0=a<<0;
    IOSET0=b<<8;			//P0.8 is connected to Register select RS, when set to 1, displays data output, when set to 0, treats input as command
    IOSET0=1<<9;			//P0.9 is connected to Lcd Enable
    delay();
    IOCLR0=1<<9;
    IOCLR0=b<<8;
    IOCLR0=a<<0;
  }

char keypad(void)                         //Keypad Scan
 {  
   while(1)
   {
      IOCLR1|=(1<<19);               //Making row1 LOW	(P1.19)
      IOSET1|=(1<<20)|(1<<21)|(1<<22)|(1<<23); //Making rest of the rows '1'
      if(!(IOPIN1&(1<<16)))             //Scan for key press	   (P1.16 is column 1)		   i guess if button is pressed then corresponding bit will be 0
       {
        while(!(IOPIN1&(1<<16)));
        return '1';                           //Returning value to display
       }
      if(!(IOPIN1&(1<<17)))
       { 
         while(!(IOPIN1&(1<<17)));
         return '2';
       }
      if(!(IOPIN1&(1<<18)))
       { 
         while(!(IOPIN1&(1<<18)));
         return '3';
       }

      IOCLR1|=(1<<20);
      IOSET1|=(1<<21)|(1<<22)|(1<<19)|(1<<23);
      if(!(IOPIN1&(1<<16)))
{		
        while(!(IOPIN1&(1<<16)));
        return '4';
      }
      if(!(IOPIN1&(1<<17)))
{		
        while(!(IOPIN1&(1<<17)));
        return '5';
     }
      if(!(IOPIN1&(1<<18)))
{		
        while(!(IOPIN1&(1<<18)));
        return '6';
     }

      IOCLR1|=(1<<21);
      IOSET1|=(1<<22)|(1<<20)|(1<<19)|(1<<23);
      if(!(IOPIN1&(1<<16)))
{		
        while(!(IOPIN1&(1<<16)));
        return '7';
     }
      if(!(IOPIN1&(1<<17)))
{	    
        while(!(IOPIN1&(1<<17)));
        return '8';
    }
      if(!(IOPIN1&(1<<18)))
{		
        while(!(IOPIN1&(1<<18)));
        return '9';
}

      IOCLR1|=(1<<22);
      IOSET1|=(1<<19)|(1<<20)|(1<<21)|(1<<23);
      if(!(IOPIN1&(1<<16)))
{		
        while(!(IOPIN1&(1<<16)));
        return '0';
}
      if(!(IOPIN1&(1<<17)))
{		
        while(!(IOPIN1&(1<<17)));
        return '-';
}
      if(!(IOPIN1&(1<<18)))
{		
        while(!(IOPIN1&(1<<18)));
        return 'E';
}
   }
}
 
void delay(void)                                    //Delay loop
{
  unsigned int i;
  for(i=0;i<=20000;i++);
}


//PINSEL0 controls PORT0 pins P0.0 to P0.15, PINSEL1 controls PORT0 pins P0.16 to P0.31 and PINSEL2 controls PORT1 pins P1.16 to P1.31.
//IOxSET ? To set an output configured pin 
//IOxCLR - To clear an output configured pin
//IOxPIN ? To get logic value on a I/O pin	
//IOxDIR ? To select input /output function (by placing 0/1) for an I/O pin