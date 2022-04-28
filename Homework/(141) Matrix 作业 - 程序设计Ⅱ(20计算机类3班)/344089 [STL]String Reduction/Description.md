# [STL]String Reduction

## Description
Lisa loves playing string reduction games: 
Given three strings s1, s2 and s3, one needs to replace all substring s2 in the string s1 with s3 repeatedly, until no s3 in found in the resulting string.

## Input
The first line is an integer t, indicating the number of test cases.
Then follow t lines. The i-th line contains three strings s1, s2 and s3. Each string consisting of only lowercase letters, with no spaces between letters. Each string will contain no more than 300 letters.

## Output
For each test case, print the final string in a single line.
## Sample Input
3
abc abc a
abcbcxabc abc a
abc ab a

## Sample Output
a
axa
ac
