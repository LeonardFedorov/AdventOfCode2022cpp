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

END	