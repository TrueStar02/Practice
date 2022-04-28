# [Loops]D. Liang 4..1 Repeating subtractions

### Description
Repeating additions ``AdditionTutorLoop.c``, generates 4 addition questions using the operands readed from the input, the answer is also readed from the input. Finally the correct count is also displayed. Revise the program to generate 4 subtraction questions, note that the subtrahend(被减数) should no less than the minuend（减数）.

```
/* AdditionTutorLoop.c */
#include <stdio.h>
int main()
{
    int correctCount = 0; // Count the number of correct answers
    int count = 0; // Count the number of questions
    int number1, number2, answer;
    while (count < 4) {
        scanf("%d %d", &number1, &number2);
        printf("What is %d + %d? ", number1, number2);
        scanf("%d", &answer);
        if (number1 + number2 == answer) {
            printf("You are correct!\n");
            correctCount++;
        } else {
            printf("Your answer is wrong.\n");
            printf("%d + %d should be %d\n", number1, number2, (number1 + number2));
        }
        count++;
    }
    printf("Correct count is %d\n", correctCount);
    return 0;
}
```
### Input
Including 4 lines. <br />
There are 3 numbers perline. The first two integers are operands for subtraction question, and the third is the answer for the question.
### Output
The result like the sample output.
### Sample Input
```
3 2 5
0 4 4
3 7 4
9 3 4
```
### Sample Output
```
What is 3 - 2? Your answer is wrong.
3 - 2 should be 1
What is 4 - 0? You are correct!
What is 7 - 3? You are correct!
What is 9 - 3? Your answer is wrong.
9 - 3 should be 6
Correct count is 2

```