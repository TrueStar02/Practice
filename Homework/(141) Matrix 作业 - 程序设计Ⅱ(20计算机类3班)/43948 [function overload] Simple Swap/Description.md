# [function overload] Simple Swap

## Before
### Overloading
C++ allows specification of more than one function of the same name in the same scope. These are called overloaded functions and are described in detail in Overloading. Overloaded functions enable programmers to supply different semantics for a function, depending on the types and number of arguments.

For example, a print function that takes a `string (or char *)` argument performs very different tasks than one that takes an argument of type `double`. Overloading permits uniform naming and prevents programmers from having to invent names such as print_sz or print_d. The following table shows what parts of a function declaration C++ uses to differentiate between groups of functions with the same name in the same scope.

| Function Declaration Element | Used for Overloading? |
|---|---|
| Function return type | No |
| Number of arguments | Yes |
| Type of arguments | Yes |
| Presence or absence of ellipsis | Yes |
| Use of typedef names | No |
| Unspecified array bounds | No |
| const or volatile | Yes |

**This table is helpful!**
#### Argument Matching
Overloaded functions are selected for the best match of function declarations in the current scope to the arguments supplied in the function call. If a suitable function is found, that function is called. "Suitable" in this context means one of the following:
- An exact match was found.
- A trivial conversion was performed.
- An integral promotion was performed.
- A standard conversion to the desired argument type exists.
- A user-defined conversion (either conversion operator or constructor) to the desired argument type exists.
- Arguments represented by an ellipsis were found.

### Reference
C++ references allow you to create a `second name` for the a variable that `you can use to read or modify the original data stored in that variable`. While this may not sound appealing at first, what this means is that `when you declare a reference and assign it a variable, it will allow you to treat the reference exactly as though it were the original variable` for the purpose of accessing and modifying the value of the original variable--even if the second name (the reference) is located within a different scope. This means, for instance, that if you make `your function arguments references, and you will effectively have a way to change the original data passed into the function`. This is quite `different from how C++ normally works, where you have arguments to a function copied into new variables`. It also allows you to dramatically reduce the amount of copying that takes place behind the scenes.
## Now
After reading, there is a simple job for you. 
Write functions for swaping.
### Swap Types : 
- int
- float
- double
- string

