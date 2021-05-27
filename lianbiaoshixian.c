/*
 * lianbiaoshixian.c
 *
 *  Created on: 2021年5月24日
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

/*其中每个结点的数据空间一般会包含一个数据结构（用于存放各种类型的数据）以及一个指针，
 * 该指针一般称为next，用来指向下一个结点的位置。由于下一个结点也是链表类型，
 * 所以next的指针也要定义为链表类型。
*/

typedef struct Link{
	char elem;  //数据域
	struct Link  *next;  //指针域，指向后继元素
}link;  //link为节点名，每个节点都是一个link结构体

//创建带有头结点的链表
link *initialLink(){
	link *p=(link *)malloc(sizeof(link));//创建头结点
	link *temp=p;			//暂存变量
	for(int i=1;i<6;i++){
		link *a=(link *)malloc(sizeof(link)); //新节点a
		temp->next=a;       //前一个节点的指针域指向新的节点地址
		a->elem=i;			//给新节点a的数据域赋值
		a->next=NULL;		//默认新节点为最后一个，所以没有向后的指针
		temp=a;		//将新节点暂存在temp中，方便下次将指针域指向下一个节点

	}
	return p;
}


void DisplayLink(link *p){
	link *temp=p;
	while(temp->next){
		temp=temp->next;
		printf("%d  ",temp->elem);
	}
	printf("\n");
}

//elem为插入的元素，position为插入的位置
link *insertElem(link *p,int elem,int position){
	link *temp=(link *)malloc(sizeof(link));
	temp=p;
	for(int i=1;i<position;i++){//插入位置前一个节点
		temp=temp->next;
		if(temp==NULL){
			printf("插入位置错误\n");
			return p;
		}
	}
	link *newnode=(link *)malloc(sizeof(link)); //创建新节点
	newnode->elem=elem;
	newnode->next=temp->next;			//新节点指向插入位置的后一个节点
	temp->next=newnode;					//插入位置前一个节点的next指向新节点
	return p;
}

link *deleteElem(link *p,int position){//position为删掉对应位置的值
	link *temp=(link *)malloc(sizeof(link));
	temp=p;
	for(int i=1;i<position;i++){//删除位置前一个节点
		temp=temp->next;
		if(temp->next==NULL){
			printf("删除位置错误\n");
			return p;
		}
	}
	link *temp1=temp->next;
	temp->next=(temp->next)->next;
	free(temp1);
	return p;

}

int FindElem(link *p,int x){
	int position=1;
	link *temp=p;
	while(temp->next){
		temp=temp->next;
		if(temp->elem==x){//找到了
			return position;
		}
		else{
			position++;
		}

	}
	return -1;
}

link *changeElem(link *p,int newnum,int position){//newnum为新值，position为更改的地方
	link *temp=p;
	for(int i=1;i<=position;i++){
		temp=temp->next;
		}
	temp->elem=newnum;

	return p;
}


//
//int main(void){
//	link *t=initialLink();
//	DisplayLink(t);
//	t=insertElem(t,45,1);
//	DisplayLink(t);
//	t=insertElem(t,36,7);
//	DisplayLink(t);
//	t=insertElem(t,45,10);
//	t=deleteElem(t,4);
//	DisplayLink(t);
//	printf("5 在链表的第%d个\n",FindElem(t,5));
//	t=changeElem(t,98,3);
//	DisplayLink(t);
//	return 0;
//}
