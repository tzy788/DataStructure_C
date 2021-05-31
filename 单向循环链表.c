/*
 * singlecirclelink.c
 *
 *  Created on: 2021年5月25日
 *      Author: HP
 */

#include<stdio.h>
#include<stdlib.h>

#define number 7
#define position 1
int length=number;

typedef struct Singlecirlink{
	int elem;
	struct Singlecirlink *next;
}singlecirlink;

singlecirlink *InitialCirLink(){
	singlecirlink *p=(singlecirlink *)malloc(sizeof(singlecirlink));
	p->elem=-456;
	p->next=NULL;
	singlecirlink *temp=p;
	for(int i=1;i<=number;i++){
		singlecirlink *a=(singlecirlink *)malloc(sizeof(singlecirlink));
		temp->next=a;
		a->elem=i;
		a->next=NULL;
		temp=a;
	}
	temp->next=p;
	//free(p);
	return p;
}

void DisplayCirLink(singlecirlink *p){
	singlecirlink *temp=p;
	for(int i=1;i<20;i++){
		temp=temp->next;
		if(temp->elem==-456){
			i--;
			continue;
		}
		printf("%d ",temp->elem);
	}
	printf("\n");
}

singlecirlink *InsertCirLinkElem(singlecirlink *p,int elem,int inpos){
	singlecirlink *temp1=p;

	if(inpos<1 || inpos>length+1){
		printf("插入位置错误\n");
		return p;
	}
	singlecirlink *temp=(singlecirlink *)malloc(sizeof(singlecirlink));
	temp->elem=elem;
	//插入表头
	if(inpos==1){
		temp->next=temp1->next;
		temp1->next=temp;
		length++;
		return p;
	}
	for(int i=1;i<inpos;i++){//插入位置的前一个节点
		temp1=temp1->next;
	}
	//插入表尾
	if(temp1->next->elem==-456){
		temp->next=p;
		temp1->next=temp;
		length++;
		return p;
	}
	//插入除表头和表尾的位置
	temp->next=temp1->next;
	temp1->next=temp;
	length++;
	return p;
}

singlecirlink *DeleteCirLinkElem(singlecirlink *p,int outpos){
	if(outpos<1 || outpos>length){
		printf("删除位置不存在。\n");
		return p;
	}
	singlecirlink *temp=p;
	for(int i=1;i<outpos;i++){
		temp=temp->next;
	}
	singlecirlink *temp1=temp->next;
	temp->next=temp->next->next;
	free(temp1);

	return p;
}

//int main(void){
//	singlecirlink *t=InitialCirLink();
//	DisplayCirLink(t);
//	InsertCirLinkElem(t,45,1);
//	DisplayCirLink(t);
//	InsertCirLinkElem(t,89,length+1);
//	DisplayCirLink(t);
//	InsertCirLinkElem(t,76,4);
//	DisplayCirLink(t);
//	t=DeleteCirLinkElem(t,length);
//	DisplayCirLink(t);
//	return 0;
//}

