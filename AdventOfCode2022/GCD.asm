.DATA


.CODE	

;Finds GCD of two non-negative numbers, loaded to RCX and RDX by default
GCD1 PROC

	;Begin setup by ascertaining which number is larger and placing the larger in R8
	CMP RCX, RDX

	JGE	 RCXLarger

		MOV R8, RDX
		MOV R9, RCX

		JMP EndSetup

	RCXLarger:

		MOV R8, RCX
		MOV R9, RDX

	EndSetup:

	;Check if the lower number is 0, if so then finish
	CMP R9, 0

	JE Finalise

	;Divide R8 by R9

	XOR RDX, RDX
	MOV RAX, R8

	DIV R9

	;Since the remainder is strictly less than the value in R9, make the remainder the new lower value
	MOV R8, R9
	MOV R9, RDX

	JMP EndSetup

	Finalise:
	MOV RAX, R8
	RET

GCD1 ENDP

;Finds GCD of two non-negative numbers, loaded to RCX and RDX by default
;Uses binary GCD algorithm
GCD2 PROC

	MOV R8, RCX
	MOV R9, RDX

	;Count the trailing zeroes and then remove them
	tzcnt RCX, r8
	SHR R8, CL
	MOV R10, RCX

	tzcnt RCX, r9
	SHR R9, CL

	;Store the lower of the two in R10
	CMP R10, RCX
	JLE	EndSetup
		MOV R10, RCX
	EndSetup:

		;Check that R8 contains the greater of the two number
		CMP R8, R9
		JGE SkipSwap
			XCHG R8, R9
		SkipSwap:

		;Subtract the lower number from the higher number and then remove excess multiples of 2
		SUB R8, R9

		;If R8 is now zero then we are done
		CMP R8, 0
		JE Finalise

		;Otherwise, strip excess 0s from R8
		tzcnt RCX, R8
		SHR R8, CL

	JMP EndSetup

	Finalise:
	MOV RAX, R9
	MOV RCX, R10
	SHL RAX, CL

	RET

GCD2 ENDP

END	