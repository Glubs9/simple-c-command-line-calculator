# simple-c-command-line-calculator
a simple c command line calculator made for fun! 

# installation
linux only unless you want to manually compile my files.            
to install just download everything and run make.           
to run just run ./main .

# requirements
gcc             

# usage
just enter in a maths equation with only four functions, +-\*\/ , and also brackets if you want. 

# file structure
if you want to contribute or fork this, feel free to do so!         
the files purposes are as follows       
main.c: the main running code that takes input and runs the algorithm over it.          
lex.h: lexer (splits the input into tokens/splits the input into numbers and operators)            
parse.h: converts tokens into reverse polish notation.          
rpn.h: runs a reverse polish notation input.                   
