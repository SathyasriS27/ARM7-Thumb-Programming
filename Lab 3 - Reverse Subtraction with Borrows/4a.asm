	AREA SBSC, CODE, READONLY
	ENTRY
    MOV R0,#0X00000100	; 256
    MOV R1,#0X00000120	; 288
	RSB R2,R0,R1
    END