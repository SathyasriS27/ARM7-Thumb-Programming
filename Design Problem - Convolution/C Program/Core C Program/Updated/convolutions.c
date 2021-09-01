#include<lpc21xx.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

// Function initializations
void delay(void);
void delay_long(void);
void lcd(unsigned char,int);
void intStr(int num, char* str);
void reverse(char* strs, char* dest);

char keypad(void);
char k;

// Main function for execution
int main(void)
{
   int x1, h1, outl, tempx1, temph1, tempN1, tempy1, N1;

   unsigned int i, j;
   unsigned char chN[] = "Enter N:";
   unsigned char chx[] = "Enter x(n):";
   unsigned char chh[] = "Enter h(n):";
   unsigned char dispx[] = "x(n):";
   unsigned char disph[] = "h(n):";
   unsigned char tester[] = "Made it here 1.";

   unsigned char chy[] = "Output sequence y(n):";
   unsigned char err[]="ERROR.";
   char N[15];
   char x[50];
   int x1x[50];
   int h1x[50];
   int y1x[50];
   char h[50];
   int itempx[50];
   int itemph[50];
   char tempx[50];
   char tempy[50];
   char temph[50];
   char outxl[16];
		
   PINSEL0=PINSEL2=0;	    // Configure pins as GPIO	 
   IODIR0=0x000003ff;		// Pins P0.0 to 9
   IODIR1=0x00f80000;		// Pins P1.19 to 23, P1.16 to 18 is set as 0 hence input pins
   lcd(0x38,0);				// Command to initialize LCD in 8 bit mode
   lcd(0x0f,0);				// Command to turn on display and blink cursor
	 
   while(1) {	
		N[0]='\0';			// Initialize the strings
		x[0]='\0';
		h[0]='\0';
		outxl[0]='\0';
		 
		// Printing "Enter N:"  
   		for(i = 0; chN[i] != '\0'; i++)
	    	lcd(chN[i], 1);
   		lcd(0x0c0, 0);       // Move to next line on LCD
		i=0;

		// Loop to obtain N
		while(1) {
       		k = keypad();   //Obtaining values from keypad

			// If "E" is pressed on keypad, input N
			if(k == 'E') {
				N[i]='\0';
				N1 = atoi(N);
				break;
			}
	   		N[i]=k;         // Scan input on keypad
			i++;
			lcd(k, 1);      // Print the input on LCD
     	}
		
				
   		lcd(0x01,0);		// Clear the LCD Screen

			 
		j = 0;

		// Get N numbers for x(n) 
		while (j < N1) { 

			// Printing "Enter x(n):"
			lcd(0x01, 0);
			for(i=0; chx[i] != '\0'; i++)
	    		lcd(chx[i], 1);		
			lcd(0x0c0,0);                         
			i=0;

			// Loop to obtain x(n)
			while(1) {											   
				k=keypad();                           
				if(k=='E') {
					x[i]='\0';

					// Converting keypad input to integer
					itempx[j] = atoi(x);
					break;
				}
				x[i]=k;
				i++;
				lcd(k, 1);	// Print the input on LCD
			} 
			j++;
		}

		j = 0;

		// Get N numbers for h(n)
		while (j < N1) {

			// Printing "Enter h(n):"
			lcd(0x01, 0);
			for(i=0; chh[i]!='\0'; i++)
	    		lcd(chh[i], 1);		
			lcd(0x0c0,0);                         
			i=0;

			// Loop to get h(n)
			while(1) {											   
				k=keypad();                           
				if(k=='E') {
					h[i]='\0';

					// Converting keypad input to integer
					itemph[j] = atoi(h);
					break;
				}
				h[i]=k;
				i++;
				lcd(k, 1);	// Print the input on LCD
			} 
			j++;
		} 

		tempx[N1] = '\0';
		temph[N1] = '\0';
		 
		// Display entered arrays to check if they're correct 
		lcd(0x01, 0); 
		for(i=0; N[i]!='\0'; i++)
	    	lcd(N[i], 1);

		while(1) {
       		k=keypad();         	    // Receive input from keypad
			break;
   		}
			
		lcd(0x01,0); 				   // Clear the LCD Screen

		// Displaying all numbers in x(n) sequentially
		for (i = 0; i < N1; i++) {

			// Printing "x(n):"
			for(j=0; dispx[j]!='\0'; j++)
	    		lcd(dispx[j], 1);
			lcd(0x0c0, 0); 

			tempx1 = itempx[i];
			intStr(tempx1, tempx);	 // Convert x[i] to integer for displaying

			// Printing the x[i] value on LCD
			for(j=0; tempx[j]!='\0'; j++)
	    		lcd(tempx[j], 1);
			
			while(1) {
				k = keypad();         // Receive input from keypad
				break;
   			}
			lcd(0x01, 0);
		}

		// Displaying all numbers in h(n) sequentially
		for (i = 0; i < N1; i++) {

			//Printing "h(n):"
			for(j=0; disph[j]!='\0'; j++)
	    		lcd(disph[j], 1);
			lcd(0x0c0, 0); 

			temph1 = itemph[i];
			intStr(temph1, temph);	// Convert h[i] to integer for displaying

			for(j=0; temph[j]!='\0'; j++)
	    		lcd(temph[j], 1);
			
			while(1) {
				k = keypad();         // Receive input from keypad
				break;
   			}
			lcd(0x01, 0);
		}

		lcd(0x01, 0); 


		// Convolution starts here
		
		for (i = N1; i <= ((2 * N1) - 1); i++) {
			itempx[i] = 0;
		}

		for (i = N1; i <= ((2 * N1) - 1); i++) {
			itemph[i] = 0;
		}

		for (i = 0; i < ((2 * N1) - 1); i++) {
			y1x[i] = 0;

			for(j = 0; j <= i; j++) {
				// Convolution operation (overlap and summation)
				y1x[i] = y1x[i] + (itempx[j] * itemph[i - j]);
			}

			tempy1 = y1x[i];

			lcd(0x01, 0);
			
			// Printing "Output Sequence:"
			for(j=0; chy[j]!='\0'; j++)
				lcd(chy[j], 1);
			lcd(0x0c0,0);

			// Converting y[i] to integer for printing
			intStr(tempy1, outxl);

			// Printing y[i] on LCD
			for(j=0; outxl[j]!='\0'; j++)
				lcd(outxl[j], 1);

			// Wait for key press before proceeding
			while(1) {
				k = keypad();
				break;
			}
		}

		// Display next y[i] only after keypress
		while(1) {							
       		k = keypad();                   
			break;
   		}

		// Clear screen for next number
		lcd(0x01,0);

   }
}

//=====================================================Helper functions=====================================================//

// Subroutine for interfacing LCD Display
void lcd(unsigned char a,int b)         
  {
    IOSET0=a<<0;
    IOSET0=b<<8;			// Set to 1 = Displays data output. Set to 0 = Treats input as command
    IOSET0=1<<9;			// Connected to LCD Enable
    delay();
    IOCLR0=1<<9;
    IOCLR0=b<<8;
    IOCLR0=a<<0;
  }

// Function to obtain input from keypad
char keypad(void)                         
 {  
   while(1)
   {
      IOCLR1|=(1<<19);               			//Making Row 1 low
      IOSET1|=(1<<20)|(1<<21)|(1<<22)|(1<<23);  //Making rest of the rows '1'
      if(!(IOPIN1&(1<<16)))             		//Scan for key press	   
       {
        while(!(IOPIN1&(1<<16)));
        return '1';                           	//Returning value to display
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

// Function for delay (while printing on LCD)
void delay(void)                                    
{
  unsigned int i;
  for(i=0;i<=200000;i++);
}

// Longer delay function
void delay_long(void)                              	
{
  unsigned int i;
  for(i=0;i<=20000000;i++);
}

// Function to convert integers to string for LCD
void intStr(int num, char* strx) {
	char str1[50];
	char tempc;
	int i, j, temp, length;

	strx[0] = '\0';
	i = 0;

	while (num != 0) {
		temp = num % 10;
		str1[i] = temp + '0';
		num = num / 10;

		if (num == 0) {
			str1[(i + 1)] = '\0';
			break;
		}
		i++;
	}

	length = 0;
	while (str1[length] != '\0') {
		length++;
	}

	j = length - 1;
	for (i = 0; i < length; i++) {
		tempc = str1[j];
		strx[i] = tempc;
		j--;
	}
	strx[length] = '\0';
	
}