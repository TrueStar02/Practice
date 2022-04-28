#include<stdio.h>
int main(void)
{unsigned int un=3000000000;
 short small=200;
 long big=100000;
 long long extraordinary=123456789012345;
 printf("unsigned number is %u but not %d\n",un,un);
 printf("small number is %hd and %d\n",small,small);
 printf("big number is %ld but not %hd\n",big,big);
 printf("extraordinary nunber is %lld but not %d or %hd\n",extraordinary,extraordinary,extraordinary);
 return 0;
}
