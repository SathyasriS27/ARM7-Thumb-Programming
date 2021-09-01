	AREA SBCS, CODE, READONLY
	ENTRY
	LDR R0,=0X40000000				 ;Divisor
	LDR R1, [R0], #04				 ;Dividend
	LDR R2, [R0], #04				 ;Remainder
	MOV R6, #00						 
LO	SUB R2, R1, R2					 ;R1 > R2
	ADDCS R6, R6, #1				 ;Quotient in R6
	BCS LO
	ADDCS R2, R1, R2
	STR R2, [R0], #4				 
	STR R6, [R0], #4				 
UP	B UP
	END