	AREA SBSC, CODE, READONLY
ENTRY
    MOV R0,#0X00000100  ; 256 (First number MSB)
    MOV R1,#0X00000120	; 288 (Second number MSB)
    MOV R2,#0X00000009	; 9	  (First number LSB)
    MOV R3,#0X0000000C	; 12  (Second number LSB)
    ADDS R5,R0,R1	; 544  (R0 + R1)
    ADC R4,R2,R3	; 21   (R2 + R3)
UP B UP
    END