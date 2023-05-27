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

END