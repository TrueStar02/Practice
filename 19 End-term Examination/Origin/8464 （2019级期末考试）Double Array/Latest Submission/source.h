#include<stdlib.h>
int num_rows=0;
double** make_list(double data[], int sizes[]){
	double** lists;
	double** ptr;
	
    int i, j, k;
	while(sizes[num_rows]){
		num_rows++;
	}
	lists=(double**)malloc(sizeof(double*)*num_rows);
	k=0;
	for(i=0;i<num_rows;i++){
		lists[i]=(double*)malloc(sizeof(double)*sizes[i]);
		for(j=0;j<sizes[i];j++){
			lists[i][j]=data[k];
			k++;
		}
	}
    lists[i]=(double*)malloc(sizeof(double));
    ptr=&lists[num_rows];
    *ptr=NULL;
    return lists;
}
void free_lists(double** lists){
	int i;
	for(i=0;i<=num_rows;i++){
		free(lists[i]);
	}
	free(lists);
}