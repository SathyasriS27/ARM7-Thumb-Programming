	AREA SBCS, CODE, READONLY
	ENTRY
	LDR R0,=0X40000000				 ;Divisor
	LDR R1, [R0], #04				 ;Dividend
	LDR R2, [R0], #04				 ;Remainder
	MOV R6, #00						 
LO	SUBS R2, R2, R1					 ;R2 - R1 = 0
	ADDCS R6, R6, #1				 
	BCS LO
	ADD R2, R2, R1
	STR R2, [R0], #4				 
	STR R6, [R0], #4				 
UP	B UP
	END