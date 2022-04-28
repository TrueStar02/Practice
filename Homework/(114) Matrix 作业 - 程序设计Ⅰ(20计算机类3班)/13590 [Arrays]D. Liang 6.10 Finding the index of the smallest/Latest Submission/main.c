#include <stdio.h>
#include "1090.h"

int list[105];

int main()
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &list[i]);
	printf("%d\n", smallestElementIndex(list, n));

  return 0;
}
