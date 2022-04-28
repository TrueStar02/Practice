#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
	int n = 0, op = 0, op_number = 0;
	scanf("%d", &n);
	struct queue q;
	initialize(&q);
	while(n--){
		scanf("%d", &op);
		switch(op){
			case 1:{
				int res = pop(&q);
				if(res == -1){
					printf("Pop failed!\n");
				}
				else{
					printf("Pop %d successfully!\n", res);
				}
				break;
			}
				
			case 2:{
				scanf("%d", &op_number);
				int res = push(&q, op_number);
				if(res == -1){
					printf("Push failed!\n");
				}
				else{
					printf("Push %d successfully!\n", res);
				}
				break;
			}
				
			case 3:{
				printf("Size of queue is %d\n", get_size(&q));
				break;
			}
				
			case 4:{
				int res = get_front(&q);
				if(res == -1){
					printf("Queue is empty!\n");
				}
				else{
					printf("Front element of queue is %d\n", res);
				}
				break;
			}
				
			case 5:{
				int res = empty(&q);
				if(res){
					printf("Queue is empty!\n");
				}
				else{
					printf("Queue is not empty!\n");
				}
				break;
			}	
			default:
				printf("Curr queue is: ");
				list(&q);
		}
	}
	list(&q);
	free(q.elements);
	return 0;
}