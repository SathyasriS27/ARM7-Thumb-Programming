	AREA SBCS, CODE, READONLY

	ENTRY
    LDR R0,=0X40001000 
    LDR R10,=0X40001050

	LDR R3, =0XFFFFFFFF     
    LDR R4, =0X20000000 

    LDR R5, [R0], #04         ; N (no. of numbers)
    SUB R5, R5, #01			  ; counter
    LDR R2, [R0], #04         
   

START

XQ  LSLS R6, R2, #1; 

    BCS NEG
    BCC POS

NEG
    STR R4, [R10], #04        ;
    B FINALLY

POS
    STR R3, [R10], #04        ;
    B FINALLY

FINALLY
    SUBS R5, R5, #01
    LDR R2, [R0], #04
    BCS START	 

UP B UP
    END