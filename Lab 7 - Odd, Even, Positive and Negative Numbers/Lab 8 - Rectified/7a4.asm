	AREA SBCS, CODE, READONLY
	ENTRY
	LDR R0,=0X40000000				 ;Divisor
	LDR R1, [R0], #04				 ;Dividend
	LDR R2, [R0], #04				 ;Remainder
	MOV R6,#0xFFFFFFFF						 
UP	B UP
	END