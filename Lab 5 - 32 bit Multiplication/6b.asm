	AREA SBCS, CODE, READONLY
	ENTRY
	LDR R0, =0x40000000	 
	LDR R5, =0x40000030
	LDR R1, [R0], #04
	LDR R2, [R0], #04
	UMULL R4, R3, R1, R2
	STR R4, [R5], #04
	STR R3, [R5]
UP B UP
	END