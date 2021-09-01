	AREA SBCS, CODE, READONLY
ENTRY
    MOV R0,#0X000000C0	; 192  (First number MSB)
    MOV R1,#0X00000090	; 144  (Second number MSB)
    MOV R2,#0X0000000A	; 10   (First number LSB)
    MOV R3,#0X00000010	; 16   (Second number LSB)
    SUBS R5,R0,R1 ; 48
    SBC R4,R2,R3  ; -6 (2's complement)
UP B UP
    END