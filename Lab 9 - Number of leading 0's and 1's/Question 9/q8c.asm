	AREA OEN, CODE,READONLY
	ENTRY
      LDR R0,=0X40000000
      LDR R6,[R0],#04
      LDR R1,[R0],#04
      LDR R2,=0X00000000
      LDR R3,=0X00000000
      LDR R7,=0X40000040
      SUB R6,R6,#01

XS
      LDR R4,=0x00000020

XQ    MOVS R1,R1,LSR #1   ; Logical right shift of number
      ADDCS R2,R2,#1      ; R3 holds number of ones
      ADDCC R3,R3,#1      ; R4 holds number of zeros
      SUB R4,R4,#1        ; decrementing counter value
      CMP R4,#00
      BNE XQ

      STR R2, [R7], #04
      STR R3, [R7], #04

      SUBS R6,R6,#01
      LDR R1,[R0],#04
      BCS XS

UP B UP

      END