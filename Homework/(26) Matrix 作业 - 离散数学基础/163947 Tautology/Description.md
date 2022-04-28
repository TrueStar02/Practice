# Tautology

### Description
 Check if a proposition in postfix form is a tautology, for example, ```pp~+``` (that is, ```p \/ ~p```) is a tautology, while ```qq~*r+``` (```q/\~q)\/r```) is not.

### Input
 The first line is an integer N(<=1000).

Then there are N lines of propositional formulas with postfix form, where
+  ```'~' ```represents negation
+ ```'*'``` represents  conjunction and
+  ```'+'``` represents disjunction
+ Propositional variables are lower case letters.
+  You may assume there are no other characters in the formulas. 

### Output
 For each formula, output the formula, then a colon ':' and "Yes" or "No" on one line depending on if the formula is a tautology.

### Sample Input
```
4
p
pq~p~**~
pq+
p~p+
```
### Sample Output
```
p:No
pq~p~**~:Yes
pq+:No
p~p+:Yes
```