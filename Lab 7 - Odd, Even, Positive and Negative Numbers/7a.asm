	AREA SBCS, CODE, READONLY
ENTRY
	LDR R0, =0X40000000;
	LDR R1, [R0], #04   ; 	LOAD DIVISOR IN R1
	LDR R2, [R0], #04	;	LOAD DIVIDEND INTO R2, HOLDS REMINDER
	MOV R6, #00		;		QUOTIENT
	
LO 	SUBS R2, R2, R1 ;		R2=R2-R1=-1; R2>R1
	ADDCS R6, R6, #1 ;		COUNT NUMBER OF LOOPS
	BCS LO	;				STAY IN LOOP IF BORROW IS ZER0
	ADD R2, R2, R1
	STR R2, [R0], #04
	STR R6, [R0], #04
   
UP  B UP
	END