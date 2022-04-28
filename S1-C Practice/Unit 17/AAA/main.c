#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"tree.h"
#define MAXI 50
int main() {
    BN* root=NULL;
    BN* que[MAXI];    /*used for free*/
    int head = 0;   /*head of que*/
    int tail = 1;   /*tail of que*/
    buildTree(&root);
    outputTree(root);
  
}
