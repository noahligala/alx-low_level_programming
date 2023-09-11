3.1 Object-like Macros
An object-like macro is a simple identifier which will be replaced by a code fragment. It is called object-like because it looks like a data object in code that uses it. They are most commonly used to give symbolic names to numeric constants.

You create macros with the ‘#define’ directive. ‘#define’ is followed by the name of the macro and then the token sequence it should be an abbreviation for, which is variously referred to as the macro's body, expansion or replacement list. For example,

     #define BUFFER_SIZE 1024
defines a macro named BUFFER_SIZE as an abbreviation for the token 1024. If somewhere after this ‘#define’ directive there comes a C statement of the form

     foo = (char *) malloc (BUFFER_SIZE);
then the C preprocessor will recognize and expand the macro BUFFER_SIZE. The C compiler will see the same tokens as it would if you had written

     foo = (char *) malloc (1024);
By convention, macro names are written in uppercase. Programs are easier to read when it is possible to tell at a glance which names are macros.

The macro's body ends at the end of the ‘#define’ line. You may continue the definition onto multiple lines, if necessary, using backslash-newline. When the macro is expanded, however, it will all come out on one line. For example,

     #define NUMBERS 1, \
                     2, \
                     3
     int x[] = { NUMBERS };
          ==> int x[] = { 1, 2, 3 };
The most common visible consequence of this is surprising line numbers in error messages.

There is no restriction on what can go in a macro body provided it decomposes into valid preprocessing tokens. Parentheses need not balance, and the body need not resemble valid C code. (If it does not, you may get error messages from the C compiler when you use the macro.)

The C preprocessor scans your program sequentially. Macro definitions take effect at the place you write them. Therefore, the following input to the C preprocessor

     foo = X;
     #define X 4
     bar = X;
produces

     foo = X;
     bar = 4;
When the preprocessor expands a macro name, the macro's expansion replaces the macro invocation, then the expansion is examined for more macros to expand. For example,

     #define TABLESIZE BUFSIZE
     #define BUFSIZE 1024
     TABLESIZE
          ==> BUFSIZE
          ==> 1024
TABLESIZE is expanded first to produce BUFSIZE, then that macro is expanded to produce the final result, 1024.

Notice that BUFSIZE was not defined when TABLESIZE was defined. The ‘#define’ for TABLESIZE uses exactly the expansion you specify—in this case, BUFSIZE—and does not check to see whether it too contains macro names. Only when you use TABLESIZE is the result of its expansion scanned for more macro names.

This makes a difference if you change the definition of BUFSIZE at some point in the source file. TABLESIZE, defined as shown, will always expand using the definition of BUFSIZE that is currently in effect:

     #define BUFSIZE 1020
     #define TABLESIZE BUFSIZE
     #undef BUFSIZE
     #define BUFSIZE 37
Now TABLESIZE expands (in two stages) to 37.

If the expansion of a macro contains its own name, either directly or via intermediate macros, it is not expanded again when the expansion is examined for more macros. This prevents infinite recursion. See Self-Referential Macros, for the precise details.


3.3 Macro Arguments
Function-like macros can take arguments, just like true functions. To define a macro that uses arguments, you insert parameters between the pair of parentheses in the macro definition that make the macro function-like. The parameters must be valid C identifiers, separated by commas and optionally whitespace.

To invoke a macro that takes arguments, you write the name of the macro followed by a list of actual arguments in parentheses, separated by commas. The invocation of the macro need not be restricted to a single logical line—it can cross as many lines in the source file as you wish. The number of arguments you give must match the number of parameters in the macro definition. When the macro is expanded, each use of a parameter in its body is replaced by the tokens of the corresponding argument. (You need not use all of the parameters in the macro body.)

As an example, here is a macro that computes the minimum of two numeric values, as it is defined in many C programs, and some uses.

     #define min(X, Y)  ((X) < (Y) ? (X) : (Y))
       x = min(a, b);          ==>  x = ((a) < (b) ? (a) : (b));
       y = min(1, 2);          ==>  y = ((1) < (2) ? (1) : (2));
       z = min(a + 28, *p);    ==>  z = ((a + 28) < (*p) ? (a + 28) : (*p));
(In this small example you can already see several of the dangers of macro arguments. See Macro Pitfalls, for detailed explanations.)

Leading and trailing whitespace in each argument is dropped, and all whitespace between the tokens of an argument is reduced to a single space. Parentheses within each argument must balance; a comma within such parentheses does not end the argument. However, there is no requirement for square brackets or braces to balance, and they do not prevent a comma from separating arguments. Thus,

     macro (array[x = y, x + 1])
passes two arguments to macro: array[x = y and x + 1]. If you want to supply array[x = y, x + 1] as an argument, you can write it as array[(x = y, x + 1)], which is equivalent C code.

All arguments to a macro are completely macro-expanded before they are substituted into the macro body. After substitution, the complete text is scanned again for macros to expand, including the arguments. This rule may seem strange, but it is carefully designed so you need not worry about whether any function call is actually a macro invocation. You can run into trouble if you try to be too clever, though. See Argument Prescan, for detailed discussion.

For example, min (min (a, b), c) is first expanded to

       min (((a) < (b) ? (a) : (b)), (c))
and then to

     ((((a) < (b) ? (a) : (b))) < (c)
      ? (((a) < (b) ? (a) : (b)))
      : (c))
(Line breaks shown here for clarity would not actually be generated.)

You can leave macro arguments empty; this is not an error to the preprocessor (but many macros will then expand to invalid code). You cannot leave out arguments entirely; if a macro takes two arguments, there must be exactly one comma at the top level of its argument list. Here are some silly examples using min:

     min(, b)        ==> ((   ) < (b) ? (   ) : (b))
     min(a, )        ==> ((a  ) < ( ) ? (a  ) : ( ))
     min(,)          ==> ((   ) < ( ) ? (   ) : ( ))
     min((,),)       ==> (((,)) < ( ) ? ((,)) : ( ))
     
     min()      error--> macro "min" requires 2 arguments, but only 1 given
     min(,,)    error--> macro "min" passed 3 arguments, but takes just 2
Whitespace is not a preprocessing token, so if a macro foo takes one argument, foo () and foo ( ) both supply it an empty argument. Previous GNU preprocessor implementations and documentation were incorrect on this point, insisting that a function-like macro that takes a single argument be passed a space if an empty argument was required.

Macro parameters appearing inside string literals are not replaced by their corresponding actual arguments.

     #define foo(x) x, "x"
     foo(bar)        ==> bar, "x"

     The C preprocessor modifies a source code file before handing it over to the compiler. You're most likely used to using the preprocessor to include files directly into other files, or #define constants, but the preprocessor can also be used to create "inlined" code using macros expanded at compile time and to prevent code from being compiled twice.


AD



There are essentially three uses of the preprocessor--directives, constants, and macros. Directives are commands that tell the preprocessor to skip part of a file, include another file, or define a constant or macro. Directives always begin with a sharp sign (#) and for readability should be placed flush to the left of the page. All other uses of the preprocessor involve processing #define'd constants or macros. Typically, constants and macros are written in ALL CAPS to indicate they are special (as we will see).
Header Files
The #include directive tells the preprocessor to grab the text of a file and place it directly into the current file. Typically, such statements are placed at the top of a program--hence the name "header file" for files thus included.
Constants
If we write
1
#define [identifier name] [value]
whenever [identifier name] shows up in the file, it will be replaced by [value].

If you are defining a constant in terms of a mathematical expression, it is wise to surround the entire value in parentheses:
1
#define PI_PLUS_ONE (3.14 + 1)
By doing so, you avoid the possibility that an order of operations issue will destroy the meaning of your constant:
1
x = PI_PLUS_ONE * 5;
Without parentheses, the above would be converted to
1
x = 3.14 + 1 * 5;
which would result in 1 * 5 being evaluated before the addition, not after. Oops!

It is also possible to write simply
1
#define [identifier name]
which defines [identifier name] without giving it a value. This can be useful in conjunction with another set of directives that allow conditional compilation.
Conditional Compilation
There are a whole set of options that can be used to determine whether the preprocessor will remove lines of code before handing the file to the compiler. They include #if, #elif, #else, #ifdef, and #ifndef. An #if or #if/#elif/#else block or a #ifdef or #ifndef block must be terminated with a closing #endif.

The #if directive takes a numerical argument that evaluates to true if it's non-zero. If its argument is false, then code until the closing #else, #elif, of #endif will be excluded.
Commenting out Code
Conditional compilation is a particularly useful way to comment out a block of code that contains multi-line comments (which cannot be nested).
1
2
3
4
5
6
7
8
#if 0
/* comment ...
*/
 
// code
 
/* comment */
#endif
Include Guards
Another common problem is that a header file is required in multiple other header files that are later included into a source code file, with the result often being that variables, structs, classes or functions appear to be defined multiple times (once for each time the header file is included). This can result in a lot of compile-time headaches. Fortunately, the preprocessor provides an easy technique for ensuring that any given file is included once and only once.

By using the #ifndef directive, you can include a block of text only if a particular expression is undefined; then, within the header file, you can define the expression. This ensures that the code in the #ifndef is included only the first time the file is loaded.
1
2
3
4
5
6
#ifndef _FILE_NAME_H_
#define _FILE_NAME_H_
 
/* code */
 
#endif // #ifndef _FILE_NAME_H_
Notice that it's not necessary to actually give a value to the expression _FILE_NAME_H_. It's sufficient to include the line "#define _FILE_NAME_H_" to make it "defined". (Note that there is an n in #ifndef--it stands for "if not defined").

A similar tactic can be used for defining specific constants, such as NULL:
1
2
3
#ifndef NULL
#define NULL (void *)0
#endif // #ifndef NULL
Notice that it's useful to comment which conditional statement a particular #endif terminates. This is particularly true because preprocessor directives are rarely indented, so it can be hard to follow the flow of execution.

On many compilers, the #pragma once directive can be used intead of include guards.
Macros
The other major use of the preprocessor is to define macros. The advantage of a macro is that it can be type-neutral (this can also be a disadvantage, of course), and it's inlined directly into the code, so there isn't any function call overhead. (Note that in C++, it's possible to get around both of these issues with templated functions and the inline keyword.)

A macro definition is usually of the following form:
1
#define MACRO_NAME(arg1, arg2, ...) [code to expand to]
For instance, a simple increment macro might look like this:
1
#define INCREMENT(x) x++
They look a lot like function calls, but they're not so simple. There are actually a couple of tricky points when it comes to working with macros. First, remember that the exact text of the macro argument is "pasted in" to the macro. For instance, if you wrote something like this:
1
#define MULT(x, y) x * y
and then wrote
1
int z = MULT(3 + 2, 4 + 2);
what value do you expect z to end up with? The obvious answer, 30, is wrong! That's because what happens when the macro MULT expands is that it looks like this:
1
int z = 3 + 2 * 4 + 2;    // 2 * 4 will be evaluated first!
So z would end up with the value 13! This is almost certainly not what you want to happen. The way to avoid it is to force the arguments themselves to be evaluated before the rest of the macro body. You can do this by surrounding them by parentheses in the macro definition:
1
2
#define MULT(x, y) (x) * (y)
// now MULT(3 + 2, 4 + 2) will expand to (3 + 2) * (4 + 2)
But this isn't the only gotcha! It is also generally a good idea to surround the macro's code in parentheses if you expect it to return a value. Otherwise, you can get similar problems as when you define a constant. For instance, the following macro, which adds 5 to a given argument, has problems when embedded within a larger statement:
1
2
3
4
5
#define ADD_FIVE(a) (a) + 5
 
int x = ADD_FIVE(3) * 3;
// this expands to (3) + 5 * 3, so 5 * 3 is evaluated first
// Now x is 18, not 24!
To fix this, you generally want to surround the whole macro body with parentheses to prevent the surrounding context from affecting the macro body.
1
2
3
#define ADD_FIVE(a) ((a) + 5)
 
int x = ADD_FIVE(3) * 3;
On the other hand, if you have a multiline macro that you are using for its side effects, rather than to compute a value, you probably want to wrap it within curly braces so you don't have problems when using it following an if statement.
1
2
3
4
5
6
7
8
9
10
11
12
// We use a trick involving exclusive-or to swap two variables
#define SWAP(a, b)  a ^= b; b ^= a; a ^= b; 
 
int x = 10;
int y = 5;
 
// works OK
SWAP(x, y);
 
// What happens now?
if(x < 0)
    SWAP(x, y);
When SWAP is expanded in the second example, only the first statement, a ^= b, is governed by the conditional; the other two statements will always execute. What we really meant was that all of the statements should be grouped together, which we can enforce using curly braces:
1
#define SWAP(a, b)  {a ^= b; b ^= a; a ^= b;} 
Now, there is still a bit more to our story! What if you write code like so:
1
2
3
4
5
6
7
8
9
10
11
#define SWAP(a, b)  { a ^= b; b ^= a; a ^= b; }
 
int x = 10;
int y = 5;
int z = 4;
 
// What happens now?
if(x < 0)
    SWAP(x, y);
else
    SWAP(x, z); 
Then it will not compile because semicolon after the closing curly brace will break the flow between if and else. The solution? Use a do-while loop:
1
2
3
4
5
6
7
8
9
10
11
#define SWAP(a, b)  do { a ^= b; b ^= a; a ^= b; } while ( 0 )
 
int x = 10;
int y = 5;
int z = 4;
 
// What happens now?
if(x < 0)
    SWAP(x, y);
else
    SWAP(x, z); 
Now the semi-colon doesn't break anything because it is part of the expression. (By the way, note that we didn't surround the arguments in parentheses because we don't expect anyone to pass an expression into swap!)
More Gotchas
By now, you've probably realized why people don't really like using macros. They're dangerous, they're picky, and they're just not that safe. Perhaps the most irritating problem with macros is that you don't want to pass arguments with "side effects" to macros. By side effects, I mean any expression that does something besides evaluate to a value. For instance, ++x evaluates to x+1, but it also increments x. This increment operation is a side effect.

The problem with side effects is that macros don't evaluate their arguments; they just paste them into the macro text when performing the substitution. So something like
1
2
3
#define MAX(a, b) ((a) < (b) ? (b) : (a))
int x = 5, y = 10;
int z = MAX(x++, y++);
will end up looking like this:
1
int z = (x++ < y++ ? y++ : x++)
The problem here is that y++ ends up being evaluated twice! The nasty consequence is that after this expression, y will have a value of 12 rather than the expected 11. This can be a real pain to debug!
Multiline macros
Until now, we've seen only short, one line macros (possibly taking advantage of the semicolon to put multiple statements on one line.) It turns out that by using a the "\" to indicate a line continuation, we can write our macros across multiple lines to make them a bit more readable.

For instance, we could rewrite swap as
1
2
3
4
5
#define SWAP(a, b)  {                   \
                        a ^= b;         \
                        b ^= a;         \ 
                        a ^= b;         \
                    } 
Notice that you do not need a slash at the end of the last line! The slash tells the preprocessor that the macro continues to the next line, not that the line is a continuation from a previous line.

Aside from readability, writing multi-line macros may make it more obvious that you need to use curly braces to surround the body because it's more clear that multiple effects are happening at once.
Advanced Macro Tricks
In addition to simple substitution, the preprocessor can also perform a bit of extra work on macro arguments, such as turning them into strings or pasting them together.
Pasting Tokens
Each argument passed to a macro is a token, and sometimes it might be expedient to paste arguments together to form a new token. This could come in handy if you have a complicated structure and you'd like to debug your program by printing out different fields. Instead of writing out the whole structure each time, you might use a macro to pass in the field of the structure to print.

To paste tokens in a macro, use ## between the two things to paste together.

For instance
1
#define BUILD_FIELD(name) my_struct.inner_struct.union_a.field_##name
Now, when used with a particular field name, it will expand to something like
1
my_struct.inner_struct.union_a.field_field1
The tokens are literally pasted together.
String-izing Tokens
Another potentially useful macro option is to turn a token into a string containing the literal text of the token. This might be useful for printing out the token. The syntax is simple--simply prefix the token with a pound sign (#).
1
#define PRINT_TOKEN(token) printf(#token " is %d", token)
For instance, PRINT_TOKEN(foo) would expand to
1
printf("<foo>" " is %d" <foo>)
(Note that in C, string literals next to each other are concatenated, so something like "token" " is " " this " will effectively become "token is this". This can be useful for formatting printf statements.)

For instance, you might use it to print the value of an expression as well as the expression itself (for debugging purposes).
1
PRINT_TOKEN(x + y);
Avoiding Macros in C++
In C++, you should generally avoid macros when possible. You won't be able to avoid them entirely if you need the ability to paste tokens together, but with templated classes and type inference for templated functions, you shouldn't need to use macros to create type-neutral code. Inline functions should also get rid of the need for macros for efficiency reasons. (Though you aren't guaranteed that the compiler will inline your code.)

Moreover, you should use const to declare typed constants rather than #define to create untyped (and therefore less safe) constants. Const should work in pretty much all contexts where you would want to use a #define, including declaring static sized arrays or as template parameters.
