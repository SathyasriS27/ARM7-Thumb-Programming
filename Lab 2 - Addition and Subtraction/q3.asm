	AREA SBCS, CODE,READONLY
ENTRY
    MOV R0,#0X00000120  ; 288
    MOV R1,#0X00000100	; 256
	SUBS R2,R1,R0		 
UP B UP
    END