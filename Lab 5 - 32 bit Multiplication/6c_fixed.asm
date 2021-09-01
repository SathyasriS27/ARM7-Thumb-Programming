	AREA SBCS, CODE, READONLY
	ENTRY
    LDR R0,=0X40000000 ;Base Address
    LDR R4,=0X00000000 ;ACC1
    LDR R5,=0X00000000 ;ACC2
    LDR R6,=0X5 ;Iteration count (5 nos.)
    LDR R7,=0X40000040 ;Base Address (RES)

LO  LDR R1,[R0],#04
    LDR R2,[R0],#04
    UMLAL R5, R4, R1, R2
    SUBS R6,R6,#1
    BNE LO

    STR R4, [R7], #04
    STR R5, [R7]
UP B UP
    END