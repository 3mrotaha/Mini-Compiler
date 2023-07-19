# Simple-Compiler-With-Lex-Yacc

## Overview

This project is a simple compiler that takes input in a language called `Wordlang` and generates `intermediate code` in C. The compiler has three main phases in its front end: **lexical analysis, syntax analysis, and semantic analysis.**

During `lexical analysis`, the **input is broken down into tokens**, which are then used to build a `symbol table`. The symbol table **keeps track of all the variables and their types**, as well as any functions or procedures defined in the program.

In the `syntax analysis phase`, the tokens are used to build an `abstract syntax tree (AST)`. The AST represents the structure of the program and is used to **check that the program is syntactically correct.**

Finally, in the `semantic analysis phase`, the AST is used to **check that the program is semantically correct**. This includes **checking that variables are declared before they are used, that types are compatible**, and that functions and procedures are called correctly.

Once the front end has completed these phases, the intermediate code generator takes the AST and generates C code that performs the same operations as the original wordlang program.  


## How to use
1. Install lex and yacc
2. Run `make` to compile
3. Run `./compiler <input_file> <output_file.c>` to compile the input file to the output file
4. Run `gcc -o <output_file.exe> <output_file.c>` to generate the executable file
5. Run `./<output_file.exe>` to run the executable file

## Syntax of wordlang
# Data types
- `int`: 32-bit signed integer
- `char`: 8-bit signed integer
- `word`: a string of characters without spaces terminated by a null character `'\0'`
- `sentence`: a string of characters with spaces terminated by a new line character `'\n'`

# Variable declaration
- `<type> <variable_name>;`
- `<type> <variable_name> = <value>;`
- `<type> <variable_name> = <value>, <variable_name> = <value>, ...;`
- `<type> <variable_name> = <value>, <variable_name>, ...;`

# Variable assignment
- `<variable_name> = <value>;`
- `<variable_name> = <expression>;`

# Operators
| Operator | Description | Precedence | Associativity |
|----------|-------------|------------|---------------|
| '(' ')' | Parentheses, it's used to change the order of evaluation of an expression | 1 | Left to right |
| ':'| Index Operator, it's used to access a word in a sentence or a character in a word, result level is reduced by one level | 2 | Left to right |
| '#'| Concatenation Operator, it's used to concatenate words, sentences, characters or a combination of them, result is in the Higher level | 3 | Left to right |
| '+' | Addition Operator, it's used to add two numbers | 3 | Left to right |
| '-' | Subtraction or Remove Operator, it's used to subtract two numbers or remove a the first occurrence of a word from a sentence, a character from a word, a sentence from a sentence or a word from a word, result is in the left value's level | 3 | Left to right |
| '=' | Assignment Operator, it's used to assign a value to a variable | 4 | Right to left |
| '==' | Equality Operator, it's used to check if two values are equal | 5 | Left to right |
| '!=' | Inequality Operator, it's used to check if two values are not equal | 5 | Left to right |
| '>' | Greater Than Operator, it's used to check if the first value is greater than the second value | 5 | Left to right |
| '<' | Less Than Operator, it's used to check if the first value is less than the second value | 5 | Left to right |
| '>=' | Greater Than or Equal Operator, it's used to check if the first value is greater than or equal to the second value | 5 | Left to right |
| '<=' | Less Than or Equal Operator, it's used to check if the first value is less than or equal to the second value | 5 | Left to right |

# Control flow
| <div style="width:500px">Statement</div>|  <div style="width:100px">Description</div> |
|---------------------------------|-------------|
| `if (<condition>) <statement> \| {<statement_list>}` | If statement, if the condition is true, the statement or the statement list will be executed |
| `if (<condition>) <statement> \| {<statement_list>}` <br> `else <statement> \| {<statement_list>}` | If-else statement, if the condition is true, the first statement or the first statement list will be executed, otherwise the second statement or the second statement list will be executed |
| `while (<condition>)` <br> `<statement> \| {<statement_list>}` | While statement, while the condition is true, the statement or the statement list will be executed |
| `loop(<number> \| <integer_var> \| <integer_expression>)` <br> `<statement> \| {<statement_list>}` | Loop statement, the statement or the statement list will be executed the number of times specified by the number, integer variable or integer expression |

# Input and Output
| Statement | Description |
|-----------|-------------|
| `output <value> \| <expression>;` | Output statement, it's used to print a value or the result of an expression to the console |
| `input <sentence_constant> IDENTIFIER;` | Input statement, it's used to read a sentence from the console and store it in the variable |

# Example Code

## Example 1
```
word w1;
sentence s1 = ^^, adverb = ^^;
loop(3)
    adverb = adverb # "very";
w1 = "interesting";
s1 = ^Compilers are a^ # adverb # w1;
output s1 # "topic";
```
### Example 1 Output
```
Compilers are very very very interesting topic
```

## Example 2
```
word object = "", article = "";
char notVowel;
input ^What are you holding?^ object;
notVowel = object : 0;
notVowel = (((((notVowel - 'a') - 'e') - 'i') - 'o') - 'u');
s1 = ^You are holding^;
if(notVowel)
    article = "a";
else
    article = "an";
s1 = (s1 # article) # object;
output s1;
```
### Example 2 output
```
What are you holding?
apple
You are holding an apple
```