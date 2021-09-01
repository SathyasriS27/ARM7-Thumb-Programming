	AREA SBCS, CODE, READONLY

	ENTRY
    LDR R0,=0X40000000 
    LDR R10,=0X40000050
	LDR R4, #32

    LDR R5, [R0], #04         ; N (no. of numbers)
    LDR R2, [R0], #04         
    SUB R5, R5, #01			  ; counter

OUTER
	
START
    MOVS R3, R2, LSL #01
    BCC FINE
    BCS BREAK
    SUBS  R4, R4, #01
    BNE START

FINE 
	ADDS R0, R0, #01
    CMP R3, #00
    BNE START
    BEQ UP

BREAK   
	STR R0, [R10], #04

UP  B UP
    END