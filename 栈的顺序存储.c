/*
 * Sqstack.c
 *
 *  Created on: 2021年5月31日
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

#define maxsize 12

//top应小于maxsize;当栈为空，top=-1
typedef struct SQstack{
	int data[maxsize];
	int top;		//栈顶指针
}sqstack;

int initialSQstack(sqstack *p){
	p->top=-1;
	return 1;
}


int SQstackPush(sqstack *p, int num){
	//判断栈满没满
	if(p->top==maxsize-1){
		printf("栈满\n");
		return 0;
	}
	p->top++;
	p->data[p->top]=num;
	return 1;
}

int SQstackPop(sqstack *p){
	//判断栈是否为空
	if(p->top==-1){
		printf("栈空\n");
		return 0;
	}
	p->top--;
	return 1;
}

void DisplaySQstack(sqstack p){
	for(int i=p.top;i>-1;i--){
		printf("%d ",p.data[i]);
	}
	printf("\n");
}


int main(void){
	sqstack t;
	int status;
	status=initialSQstack(&t);
	status=SQstackPush(&t,5);
	status=SQstackPush(&t,78);
	status=SQstackPush(&t,30);
	status=SQstackPush(&t,64);
	DisplaySQstack(t);
	status=SQstackPop(&t);
	status=SQstackPop(&t);
	DisplaySQstack(t);
	return 0;
}


