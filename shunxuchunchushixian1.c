/*
 * shunxuchunchushixian1.c
 *
 *  Created on: 2021��5��19��
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct Table{
	int *head;
	int length;
	int size;
}table;

table InitialTable(){
	table t;
	t.head=(int *)malloc(SIZE*sizeof(int));
	if(!t.head){
		printf("�����ڴ�ʧ�ܡ�\n");
		exit(0);
	}
	t.length=0;
	t.size=SIZE;
	return t;
}

void DisplayTable(table t){
	int i;
	for(i=0;i<t.length;i++){
		printf("%d",t.head[i]);
		printf("  ");
	}
	printf("\n");
}

table addTable(table t,int x,int add){//xΪ�����Ԫ�أ�addΪ�����λ��
	//�жϲ���λ�õĺϷ���
	if(add>t.length+1||add<1){
		printf("�����λ�ò��Ϸ���\n");
		return t;
	}
	//�жϱ�����û
	if(t.length==t.size){
		printf("������,����Ϊ�����·���ռ䡣\n");
		t.head=(int *)realloc(t.head,(t.size+1)*sizeof(int));
		if(!t.head){
			printf("����ռ�ʧ�ܣ�\n");
			return t;
		}
		t.size+=1;
	}
	//��ʼ���룬�����һ������Ųһ����Ȼ�����������ơ�
	for(int i=t.length-1;i>=add-1;i--){
		t.head[i+1]=t.head[i];

	}
	t.length++;
	t.head[add-1]=x;
	return t;
}

table deleteTable(table t, int delete){//deleteΪ��Ҫɾ����Ԫ�ص�λ��
	if(delete>t.length || delete<1){
		printf("ɾ����λ������\n");
		return t;
	}

	for(int i=delete;i<t.length;i++){
		t.head[i-1]=t.head[i];
		}
	t.length--;
	return t;
}

table changeTable(table t, int x,int newx ){//��newx���x
	int temp=find(t,x);
	if(temp==-1){
		printf("δ�ҵ���Ԫ��\n");
	}
	else{
		t.head[temp-1]=newx;
	}
	return t;
}

int find(table t, int x){//����x
	for(int i=0;i<t.length;i++){
		if(t.head[i]==x){
			return i+1;
		}

	}
	return -1;
}

//int main(){
//	table t;
//	t=InitialTable();
//	for(int i=1;i<=SIZE;i++){
//		t.head[i-1]=i;
//		t.length++;
//	}
//	DisplayTable(t);
//	t=addTable(t,10,2);
//	DisplayTable(t);
//	t=deleteTable(t,4);
//	DisplayTable(t);
//	t=changeTable(t,5,45);
//	DisplayTable(t);
//	return 0;
//}
