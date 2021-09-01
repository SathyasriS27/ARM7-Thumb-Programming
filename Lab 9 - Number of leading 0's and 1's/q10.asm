	AREA SBCS, CODE, READONLY

	ENTRY
    LDR R0,=0X40001000 
    LDR R10,=0X40001050

	LDR R3, =0XEEEEEEEE     
    LDR R4, =0XAAAAAAAA 

    LDR R5, [R0], #04         ; N (no. of numbers)
    SUB R5, R5, #01			  ; counter
    LDR R2, [R0], #04         
   

START

XQ  LSRS R6, R2, #1; 

    BCS ODD
    BCC EVEN

ODD
    STR R4, [R10], #04        ;
    B FINALLY

EVEN
    STR R3, [R10], #04        ;
    B FINALLY

FINALLY
    SUBS R5, R5, #01
    LDR R2, [R0], #04
    BCS START	 

UP B UP
    END