	AREA SBSC, CODE, READONLY
	ENTRY
	LDR R0, =0X40000000
	LDR R4, [R0], #4   ; total count (N)
	LDR R1, [R0], #4   ; first number

LO	LDR R2, [R0], #4   ; second number
	CMP R1, R2
	BGE DN			   
	MOV R1, R2		   ; larger number in R1
	SUBS R4, R4, #1
	BNE LO

DN	SUBS R4, R4, #1
	BNE LO
	STR R1, [R0], #4
UP	B UP
	END	