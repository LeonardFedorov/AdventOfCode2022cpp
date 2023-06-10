.DATA	

	;Offset to convert digit chars into the represented number
	charOffset EQU 30h

.CODE	

;RCX will be loaded with the number of digits to read
;RDX will be loaded with a pointer from which to start reading
;This function does not validate that the digit stream is actually a number, if it isn't then a nonsense result will be returned
parseUInt PROC

	; Store 10 so we can multiply by it
	MOV R11, 10d

	; Clear the register to hold the current digit value
	XOR R9, R9

	; Move the pointer to RSI so it can be used with the byte load instruction
	MOV RSI, RDX

	ProcessChar:
			
		; Check if we're at end of the read, in this case end as well
		CMP RCX, 0
		JE Ending

		;Clear rax and load the char
		XOR RAX, RAX
		LODSB
		DEC RCX

		SUB AL, charOffset ; change the char value to its number value
		MOV R10, RAX ; move the converted har out of the way so we can use RAX for multiplication

		MOV RAX, R9
		MUL R11
		MOV R9, RAX

		ADD R9, R10 ; add this digit to the value in R9
			
		JMP ProcessChar

	Ending:

		; Whem finished, write the final result to RAX 
		MOV RAX, R9	
	
	RET
parseUInt ENDP


;RCX and RDX are loaded with the two numbers to find the GCD of
;No assumption is made about which is larger
;The numbers will be read as unsigned 64 bit integers
GCD PROC

	;Start by loading the larger number in R8 and the smaller into R9
	CMP RCX, RDX	
	JG	RCXLarger

	MOV R8, RDX
	MOV R9, RCX
	JMP EndOfSetup

	RCXLarger:
	MOV R8, RCX
	MOV R9, RDX

	EndOfSetup:

	;Remove the commond dividers of two
	tzcnt RAX, R8
	tzcnt RDX, R9



	EndOfDivision:


	;First test, is R9 0? If so, R8 is the GCD and we can exit
	CMP R9, 0
	
	JG Continue

	MOV RAX, R8
	RET	

	Continue:

	;Are both numbers even?



GCD ENDP




END