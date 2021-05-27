/*
 * doublelink.c
 *
 *  Created on: 2021��5��25��
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
	int position=2;//�ӵڶ�����ʼ����
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
		printf("����%dλ�ô���\n",position);
		return p;
	}
	doublelink *temp=(doublelink *)malloc(sizeof(doublelink));
	temp->elem=elem;
	temp->pre=NULL;
	temp->next=NULL;
	doublelink *temp1=p;
	//�����ͷ
	if(position==1){
		temp->next=temp1;
		temp1->pre=temp;
		p=temp;//ͷ����ַת��p
		linklength++;
		return p;
	}

	for(int i=1;i<position-1;i++){//�������λ��ǰһ���ڵ㡣Ϊʲô����λ�������λ�ã���Ϊ���벻���������β
		temp1=temp1->next;
	}
	//�����β
	if(temp1->next==NULL){
		temp1->next=temp;
		temp->pre=temp1;
		linklength++;
		return p;
	}
	temp->pre=temp1;//�½ڵ��preָ��ǰһ���ڵ�
	temp->next=temp1->next;//�½ڵ��nextָ��ǰλ��
	temp1->next->pre=temp;
	temp1->next=temp;//����λ��ǰһ���ڵ��nextָ���½ڵ�

	linklength++;
	return p;
}

doublelink *DeleteElemFromDoublelink(doublelink *p,int position){
	if(position<1 || position>linklength+1){
		printf("λ��%d������\n",position);
		return p;
	}
	doublelink *temp=p;
	if(position==1){//ɾ����ͷ
		p=temp->next;
		temp->next->pre=NULL;
		linklength--;
		free(temp);
		return p;
	}
	for(int i=1;i<position-1;i++){//��λ��ɾ��λ��ǰһ���ڵ�
		temp=temp->next;
	}
	//ɾ����β
	if(temp->next->next==NULL){
		temp->next=NULL;
		free(temp->next);
		linklength--;
		return p;
	}
	//ɾ������ͷ��β�����λ��
	//printf("%d\n",temp->next->elem);
	doublelink *temp1=temp->next;//�ݴ�ɾ���ڵ�
	temp->next=(temp->next)->next;//ɾ��λ��ǰһ���ڵ��next�ӵ�ɾ��λ�ú�һ���ڵ�
	((temp->next)->next)->pre=temp;//ɾ��λ�ú�һ���ڵ��pre�ӵ�ɾ��λ��ǰһ���ڵ�

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
