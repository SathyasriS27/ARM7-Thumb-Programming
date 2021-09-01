	AREA SBCS, CODE, READONLY

     ENTRY
     MOV R0, #0X00                ; Storing leading 0's
     LDR R1, =0X40001000          ; Starting address of the user permitted memory
     MOV R3, #32
     LDR R2, [R1], #04            ; Loading first data into R2

LOOP
     MOVS R2, R2, LSL #01         ; Left shift and set flag bits
     ADDCC R0, R0, #01
     BCS ENDIF
     SUBS R3, R3, #01
     BNE LOOP

ENDIF
	 STR R0, [R1]

UP   B UP
     END