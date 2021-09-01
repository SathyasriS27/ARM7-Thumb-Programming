	AREA CONV, CODE, READONLY
	ENTRY

	MOV R0, =0x40000000	; Used to enter the value of N
	MOV R2, =0x40000100	; Starting index of h(n)
	MOV R3, =0x41000000	; Starting index of h(-n) [Irrelevant to display]
	MOV R8, R3
	MOV R10, =0x40000500; Starting index of outputs

	SUB R4, [R0], #1	; Storing (N - 1) in R4
	MOV R5, #4			; Storing integer 4 in R5
	MUL R5, R5, R4		; Storing [4 * (N - 1)] in R5
	ADD R5, R5, R2		; Storing last index of h(n) in R5

	LDR R6, [R0]		; Buffer Count in R6
	LDR R7, #0			; Temp Register for intermediate addition


INVERTING

	LDR R1, [R0], #4	; Storing address stored in R0
						; and incrementing address by 4

	SUB R1, R1, #1		; Decrementing count by 1
	STR R8, [R5]		; Storing value in R5 at address in R3
	ADD R8, R8, #4		; Incrementing address at R3
	SUB R5, R5, #4		; Decrementing towards h(-n)

	CMP R5, R2			; Comparing current address (R5) to base address of h(n)

	BGE INVERTING		; If more h(n) is left, repeat
	BLE OVERLAP

	
OVERLAP
	

