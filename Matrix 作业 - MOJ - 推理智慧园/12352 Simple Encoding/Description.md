# Simple Encoding

# Description

Encode the input text that consists of "a" - "z", "A" - "Z" and " " into a series of numbers according to the following rules:

```
" " -> 000
"a" -> 001
"b" -> 002
"c" -> 003
...
"y" -> 025
"z" -> 026

"A" -> 101
"B" -> 102
"C" -> 103
...
"Y" -> 125
"Z" -> 126

```

# Input

The input consists of one line ending with "\n" and represents the message to encode.

# Output
Output the encoded series ending with "\n".

# Sample Input

```
Hello Matrix

```

# Sample Output

```
108005012012015000113001020018009024

```
