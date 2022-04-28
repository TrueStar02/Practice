# [Pointers and C-String]D. Liang 7.10 Occurrences of each digit in a string

#Description
Write a function that counts the occurrences of each digit in a string using the following header:

```c
int * count(const char * const s);
```
The function counts how many times a digits appears in the string. The return value is an array of ten elements, each of which holds the count for a digit. For example, after executing ``int counts[] = count("12203AB3")``, ``counts[0]`` is 1, ``counts[1]`` is 1, ``counts[2]`` is 2, ``counts[3]`` is 2.

#Hint
Don't submit the main() function.
