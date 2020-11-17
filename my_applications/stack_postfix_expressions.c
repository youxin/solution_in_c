/* postfix expressions, calculation
6 5 2 3 + 8 * + 3 + * 
When a number is seen, 
	it is pushed onto the stack; 
when an operator is seen,
	the operator is applied to the two numbers (symbols) that are popped from the stack and 
	the result is pushed onto the stack.
*/








/*Infix to Postfix Conversion
Infix a + b * c + ( d * e + f ) * g
postfix b c * + d e * f + g * +

When an operand is read
	it is immediately placed onto the output
When operators read
	place onto the stack
When left parentheses 
	place onto the stack
If we see operator + * (  
	pop entries from the stack, those with higher or equeal priority. note: ( priority is highest
	push the operator onto the stack
If we see a right parenthesis
	pop the stack, writing symbols until we encounter a (corresponding) left parenthesis, which is popped but not output.
if we read the end of input, 
	we pop the stack until it is empty, writing symbols onto the output

*/