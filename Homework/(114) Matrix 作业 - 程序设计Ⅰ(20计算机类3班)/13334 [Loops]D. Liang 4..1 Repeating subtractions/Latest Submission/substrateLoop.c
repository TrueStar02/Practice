#include <stdio.h>
int main()
{
    int correctCount = 0; 
    int count = 0; 
    int number1, number2, answer;
    int x;
    while (count < 4) {
        scanf("%d %d", &number1, &number2);
        if(number1<number2)
        {x=number1;
         number1=number2;
         number2=x;
        }
        printf("What is %d - %d? ", number1, number2);
        
        scanf("%d", &answer);
        if (number1 - number2 == answer) {
            printf("You are correct!\n");
            correctCount++;
        } else {
            printf("Your answer is wrong.\n");
            printf("%d - %d should be %d\n", number1, number2, (number1 - number2));
        }
        count++;
    }
    printf("Correct count is %d\n", correctCount);
    return 0;
}