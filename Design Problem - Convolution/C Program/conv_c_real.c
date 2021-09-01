#include<lpc21xx.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>

void delay(void);
void lcd(unsigned char,int);

char keypad(void);
char k;

int main(void)
{
   float n1,n2,n3;
	int outs,N1,x1,h1,d1,e1,outl, noNos;

   unsigned int i, j, q;
   unsigned char chN[]="Enter N:";
   unsigned char chx[] = "Enter the first sequence x(n):";
   unsigned char chh[] = "Enter the second sequence h(n):";
   unsigned char tester[] = "Made it here 1.";

   unsigned char chy[] = "Output sequence y(n):";
   unsigned char err[]="ERROR.";
   char test=' ';		 
   char tempChary[5];
   char tempCharx[5];
   unsigned char N[16];
   unsigned char x[50];
   int x1x[50];
   int h1x[50];
   int y1x[50];
   unsigned char h[50];
   int itempx[50];
   int itemph[50];
   unsigned char tempx[50];
   unsigned char tempy[50];
   unsigned char temph[50];
   // char d[16];
   // char e[16];
   unsigned char outxs[16];
   unsigned char outxl[16];
		
   PINSEL0=PINSEL2=0;	    //configure pins as GPIO	 
   IODIR0=0x000003ff;		//pins P0.0 to 9
   IODIR1=0x00f80000;		//pins P1.19 to 23, P1.16 to 18 is set as 0 hence input pins
   lcd(0x38,0);				//0x38 is lcd command to initialise lcd in 8 bit mode
   lcd(0x0f,0);				//0x0f is command for - display on, cursor blinking
	 
   while(1) {	
		N[0]='\0';			//to clear/empty the strings
		x[0]='\0';
		h[0]='\0';
		outxs[0]='\0';
		outxl[0]='\0';

		n1=0;				//resetting values for current iteration
		n2=0;
		n3=0;
		 
// Code runs from below
		/*
 	  	for(i=0; chN[i]!='\0'; i++)
	   		lcd(chN[i], 1);  
		 
   		while(1) {			//wait for keypress to clear screen and display next line
       		k=keypad();     //Obtaining values from keypad (Any random value to initiate and scan)
			break;
     	}
		*/ 
	 	lcd(0x01,0);		//LCD command to clear screen
		  
   		for(i=0;chN[i]!='\0';i++)
	    	lcd(chN[i],1);
   		lcd(0x0c0,0);       //lcd cmd to force cursor to 2nd line
		i=0;

		// Loop to get N
		while(1) {
       		k=keypad();     //Obtaining values from keypad
			if(k=='E') {
				N[i]='\0';
				break;
			}
	   		N[i]=k;         // input scan
			i++;
			lcd(k, 1);      // input live display
     	}
		 
   		lcd(0x01,0);		//LCD cmd to clear screen
		
		/*
		// Test code
		for(i=0; tester[i]!='\0'; i++)
	   		lcd(tester[i], 1);
		*/		
		// noNos = sscanf(N,"%d",&N1);

		N1 = atoi(N);

		for(i=0; chx[i]!='\0'; i++)
	    	lcd(chx[i],1);		
		lcd(0x0c0,0);   
			 
		j = 0;
		while (j < N1) {
			for(i=0; chx[i]!='\0'; i++)
	    		lcd(chx[i],1);		
			lcd(0x0c0,0);                         
			i=0;

			// Loop to get x(n)
			while(1) {											   
				k=keypad();                           
				if(k=='E') {
					tempx[j] = x[(i - 1)];
					x[i]='\0';
					break;
				}
				x[i]=k;
				i++;
				lcd(k, 1);
			} 
			j++;
		}

		j = 0;
		while (j < N1) {
			lcd(0x01, 0);
			for(i=0; chh[i]!='\0'; i++)
	    		lcd(chh[i], 1);		
			lcd(0x0c0,0);                         
			i=0;

			// Loop to get x(n)
			while(1) {											   
				k=keypad();                           
				if(k=='E') {
					temph[j] = h[(i - 1)];
					h[i]='\0';
					break;
				}
				h[i]=k;
				i++;
				lcd(k, 1);
			} 
			j++;
		} 
		 
		// Display entered arrays to check if they're correct 
		 
		for(i=0; N[i]!='\0'; i++)
	    	lcd(N[i], 1);

		// Wait for keypress to clear screen and display next line 
		while(1) {
       		k=keypad();         // Obtaining values from keypad
			break;
   		}
			
		lcd(0x01,0); 			// LCD clear screen
		 
		 
		for(i=0; x[i]!='\0'; i++)
	    	lcd(tempx[i], 1);
		lcd(0x0c0, 0);           // Force cursor to 2nd line	
			
		for(i=0; h[i]!='\0';i++)
	    	lcd(temph[i], 1);

		// Wait for keypress to clear screen and display next line
		while(1) {
       		k=keypad();         //Obtaining values from keypad
			break;
   		}
			
		lcd(0x01,0);
			
			
		// Code to convolve two arrays: 

		for (i = 0; i < N1; i++) {
			tempCharx[0] = tempx[i];
			tempChary[0] = tempy[i];
			tempCharx[1] = '\0';
			tempChary[1] = '\0';
			sscanf(tempCharx, "%d", &x1x[i]);
			sscanf(tempChary, "%d", &h1x[i]);
		}           

		/*
		q = x1;
		i = 0;

		// Store x(n) in an array
		while (math.floor((q / 10)) != 0) {
			r = q % 10;
			q = q / 10;
			itempx[i] = r;
			i++
		}

		q = h1;
		i = 0;

		// Store h(n) in an array
		while (math.floor((q / 10)) != 0) {
			r = q % 10;
			q = q / 10;
			itempx[i] = r;
			i++
		}

		// Flipping itempx and itempy to 
		// obtain x(n) and h(n)
		j = 0;
		for (i = (N - 1); i = -1; i--) {
			x1[j] = itempx[i];
			h1[j] = itemph[i];
			j++;
		}
		*/

		// Convolution starts here

		for (i = N1; i <= ((2 * N1) - 1); i++) {
			x1x[i] = 0;
		}

		for (i = N1; i <= ((2 * N1) - 1); i++) {
			h1x[i]=0;
		}

		for(i=0; i <= ((2 * N1) - 1); i++) {
			y1x[i] = 0;

			for(j = 0; j <= i; j++) {
				y1x[i] = y1x[i] + (x1x[j] * h1x[i - j]);
			}

			lcd(0x01,0);
			for(i=0; chy[i]!='\0'; i++)
	   			lcd(chy[i], 1);
			lcd(0x0c0,0);
			sprintf(outxl, "%d", (int) y1x[i]);

			for(i=0; outxl[i]!='\0'; i++)
	    		lcd(outxl[i], 1);

		}

		// Convolution ends here
		
		/*
		int	no[4]={a1,b1,c1,d1};
			
		
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
		*/
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
//IOxSET � To set an output configured pin 
//IOxCLR - To clear an output configured pin
//IOxPIN � To get logic value on a I/O pin	
//IOxDIR � To select input /output function (by placing 0/1) for an I/O pin