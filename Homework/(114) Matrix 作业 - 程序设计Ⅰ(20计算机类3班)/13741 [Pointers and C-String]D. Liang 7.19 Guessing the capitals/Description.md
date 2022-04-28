# [Pointers and C-String]D. Liang 7.19 Guessing the capitals

## Description

There are 49 states and the corresponding capitals of USA: 
```
State, Capital
Alabama, Montgomery
Alaska, Juneau
Arizona, Phoenix
Arkansas, Little Rock
California, Sacramento
Colorado, Denver
Connecticut, Hartford
Delaware, Dover
Florida, Tallahassee
Georgia, Atlanta
Hawaii, Honolulu
Idaho, Boise
Illinois, Springfield
Maryland, Annapolis
Minnesota, Saint Paul
Iowa, Des Moines
Maine, Augusta
Kentucky, Frankfort
Indiana, Indianapolis
Kansas, Topeka
Louisiana, Baton Rouge
Oregon, Salem
Oklahoma, Oklahoma City
Ohio, Columbus
North Dakota, Bismark
New York, Albany
New Mexico, Santa Fe
New Jersey, Trenton
New Hampshire, Concord
Nevada, Carson City
Nebraska, Lincoln
Montana, Helena
Missouri, Jefferson City
Mississippi, Jackson
Massachusettes, Boston
Michigan, Lansing
Pennslyvania, Harrisburg
Rhode Island, Providence
South Carolina, Columbia
South Dakota, Pierre
Tennessee, Nashville
Texas, Austin
Utah, Salt Lake City
Vermont, Montpelier
Virginia, Richmond
Washington, Olympia
West Virginia, Charleston
Wisconsin, Madison
Wyoming, Cheyenne
```
Write a program that read in state name and guess for its capital. Upon receiving each input pair, the program reports whether the answer is correct.


## Input

The first line is an integer n (0<n<100), then followed 2 * n lines 
with a string in each line.
Each odd line i contains a string STATE which is a name of a state, and line i+1 contains a string CAPITAL which is a guess for State. 
Output
For each input line, you should judge whether CAPITAL is the capital of STATE.
If the answer is "yes", output "Your answer is correct."
If the answer is "no", output the correct answer, "The capital of #state is #capital." Fill in #state with STATE and #capital with the correct capital of STATE.

## Sample Input
```
2
Alabama
Phoenix
Alaska
Juneau
```
## Sample Output
```
The capital of Alabama is Montgomery
Your anwswer is correct
```