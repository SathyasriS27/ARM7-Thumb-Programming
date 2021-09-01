	AREA CONV, CODE, READONLY
	ENTRY

	LDR R0, =0X40000000
	LDR R1, =0X40000050					; Base address for h(n)
	LDR R2, =0X40002000					; Base address for h(-n)
	LDR R9, =0X40002500					; Base address for output
	LDR R6, [R0] 						; Contents of 0x40000000 in R6


; Loop to invert h(n) to h(-n):

LOOP
	SUB R6, R6, #1						; Decrement counter (R6)  
	SUB R2, R2, #4						; Decrement R2
	LDR R3, [R1], #4					; Store contents of address at R3 and increment R1
	STR R3, [R2]						; Store contents of R3 in R2
	CMP R6, #0							; Comparing counter with 0
	BNE LOOP


; h(-n) created, base address stored in R2

	MOV R1, R2							; Moving base address of h(-n) to R1
	LDR R6, [R0], #4					; Restoring counter in R6
	MOV R7, #0x00						; Initializing counter to 0

OUTER
	MOV R11, #0X00
	LDR R5, =0X40000050					; Base address for h(n)
	LDR R0, =0X40000000
	ADD R7, R7, #1						; Incrementing counter by 1
	MOV R10, #4
	MUL R4, R7, R10
	ADD R0, R0, R4						; Highest index of x(n) in overlap, stored in R0
	MOV R8, R7							; Copying counter from R7 to R8
	B INNER

INNER
	SUB R8, R8, #1						; Decrement sub-counter
	LDR R2, [R5]
	LDR R12, [R0]
	MUL R10, R2, R12					; Multiply contents of R5 and R0, store in R10
	ADD R11, R11, R10					; Adding R10 to R11 after each multiplication (Summation)
	ADD R5, R5, #4
	SUB R0, R0, #4						; Decrementing register addresses
	CMP R8, #0
	BNE INNER
	BEQ WRITEOP							; Once inner loop finishes, add output to address
	
WRITEOP
	STR R11, [R9]						; Storing the output
	ADD R9, R9, #4						; Incrementing address in R9 by 4	 
	LDR R12, =0X40000000				; Retrieving N from 0x40000000
	LDR R12, [R12]
	CMP R7, R12
	BNE OUTER


; h(n) completely overlaps x(n), now it shifts away

	SUB R12, R12, #1					; Counter at N - 1
	LDR R4, =0X40000004

SECONDHALF	
	MOV R0, R4 							; 0x40000004 in R0
	MOV R3, R1							; Copying starting address of h(-n) to R3
	MOV R11, #0X00						; Initializing output to 0
	MOV R8, R12							; Copying counter at N - 1
	LDR R10, [R1]						; Storing h(-n) in R10	
	; MOV R6, R0							; Storing address pointing to last element of x(n) in R6
	B SECONDIN

SECONDIN
	LDR R7, [R0, #4]!					; R7 stores the value of x(n), R0 updated
	LDR R2, [R3]
	MUL R5, R7, R2						; Multiply contents of R7 and R2
	ADD R11, R11, R5					; Updating R11 (Summation) 
	SUB R8, R8, #1						; Decrement counter
	ADD R3, R3, #4						; Increment h(-n) address at R13
	CMP R8, #0
	BNE SECONDIN
	BEQ WRITESEC

WRITESEC
	STR R11, [R9]						; Output in address at R9
	ADD R9, R9, #4						; Incrementing address in R9 by 4  
	SUB R12, R12, #1
	; ADD R1, R1, #4
	ADD R4, R4, #4
	CMP R12, #0
	BNE SECONDHALF
   	
UP	B UP
	END 