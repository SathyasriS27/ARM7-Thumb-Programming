	AREA SBCS, CODE, READONLY
	ENTRY
	LDR R4, =0x00000000
	LDR R5, =0x00000000
	LDR R7, =0x00000005
	LDR R9, =0x00000000
	LDR R0, =0x40000000
	LDR R1, =0x40000018
	LDR R6, =0x40000038

LO 	LDR R2, [R0], #04
	LDR R3, [R1], #04
	UMLAL R5, R4, R2, R3
	SUBS R9, R9, #01
	BNE LO

	STR R4, [R6], #04
	STR R5, [R6]
UP 	B UP
	END