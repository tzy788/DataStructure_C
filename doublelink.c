/*
 * doublelink.c
 *
 *  Created on: 2021年5月25日
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

#define number 7
int linklength=number;

typedef struct Doublelink{
	int elem;
	struct Doublelink *pre;
	struct Doublelink *next;

}doublelink;

doublelink *initialdoubleLink(){
	int position=2;//从第二个开始创建
	if(number<1)
		return NULL;
	doublelink *p=(doublelink *)malloc(sizeof(doublelink));
	p->pre=NULL;
	p->next=NULL;
	p->elem=1;
	doublelink *temp=p;
	for(int i=position;i<=number;i++){
		doublelink *a=(doublelink *)malloc(sizeof(doublelink));
		a->next=NULL;
		a->pre=NULL;
		a->elem=i;
		a->pre=temp;
		temp->next=a;
		temp=a;
	}


	return p;
}

void DisplayDoubleLink(doublelink *p){
	doublelink *temp=p;
	while(temp){
		if(temp->pre!=NULL)
			printf("<-");
		printf("%d",temp->elem);
		if(temp->next!=NULL)
			printf("->");

		temp=temp->next;
	}
	printf("\n");

}

doublelink *InsertElemInDoubleLink(doublelink *p,int elem,int position){
	if(position<1 || position>linklength+1){
		printf("插入%d位置错误\n",position);
		return p;
	}
	doublelink *temp=(doublelink *)malloc(sizeof(doublelink));
	temp->elem=elem;
	temp->pre=NULL;
	temp->next=NULL;
	doublelink *temp1=p;
	//插入表头
	if(position==1){
		temp->next=temp1;
		temp1->pre=temp;
		p=temp;//头结点地址转给p
		linklength++;
		return p;
	}

	for(int i=1;i<position-1;i++){//到达插入位置前一个节点。为什么不定位到插入的位置？因为插入不了在链表结尾
		temp1=temp1->next;
	}
	//插入表尾
	if(temp1->next==NULL){
		temp1->next=temp;
		temp->pre=temp1;
		linklength++;
		return p;
	}
	temp->pre=temp1;//新节点的pre指向前一个节点
	temp->next=temp1->next;//新节点的next指向当前位置
	temp1->next->pre=temp;
	temp1->next=temp;//插入位置前一个节点的next指向新节点

	linklength++;
	return p;
}

doublelink *DeleteElemFromDoublelink(doublelink *p,int position){
	if(position<1 || position>linklength+1){
		printf("位置%d不存在\n",position);
		return p;
	}
	doublelink *temp=p;
	if(position==1){//删除表头
		p=temp->next;
		temp->next->pre=NULL;
		linklength--;
		free(temp);
		return p;
	}
	for(int i=1;i<position-1;i++){//定位到删除位置前一个节点
		temp=temp->next;
	}
	//删除表尾
	if(temp->next->next==NULL){
		temp->next=NULL;
		free(temp->next);
		linklength--;
		return p;
	}
	//删除除表头表尾以外的位置
	//printf("%d\n",temp->next->elem);
	doublelink *temp1=temp->next;//暂存删除节点
	temp->next=(temp->next)->next;//删除位置前一个节点的next接到删除位置后一个节点
	((temp->next)->next)->pre=temp;//删除位置后一个节点的pre接到删除位置前一个节点

	linklength--;
	free(temp1);
	return p;
}

//int main(void){
//	doublelink *t=initialdoubleLink();
//	DisplayDoubleLink(t);
//	//printf("linklength=%d\n",linklength);
//	t=InsertElemInDoubleLink(t,89,4);
//	DisplayDoubleLink(t);
//	t=InsertElemInDoubleLink(t,75,1);
//	DisplayDoubleLink(t);
//	//printf("linklength=%d\n",linklength);
//	t=InsertElemInDoubleLink(t,35,linklength+1);
//	DisplayDoubleLink(t);
//	//printf("linklength=%d\n",linklength);
//	t=InsertElemInDoubleLink(t,46,0);
//	//printf("linklength=%d\n",linklength);
//	t=InsertElemInDoubleLink(t,758,linklength+2);
//	t=DeleteElemFromDoublelink(t,7);
//	DisplayDoubleLink(t);
//	return 0;
//}
