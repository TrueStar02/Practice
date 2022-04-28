#include <stdio.h>
#include "1088.h"

int list1[105];
double list2[105];

int main()
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &list1[i]);
	printf("%d\n", average_int(list1, n));

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lf", &list2[i]);
	printf("%lf\n", average_double(list2, n));

    return 0;
}
