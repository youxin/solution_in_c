/*
Make an empty stack
Read characters until end of file
	IF the character is an open anything
		push it onto the stack
	ENDIF
	IF it is a close anything, 
		IF the stack is empty 
			report an error. 
		ELSE, 
			pop the stack. 
			IF the symbol popped is not thecorresponding opening symbol, 
				report an error. 
			ENDIF
		ENDIF
	ENDIF
At end of file, if the stack is not empty report an error.
*/