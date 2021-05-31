/*
 * shunxuchunchushixian1.c
 *
 *  Created on: 2021年5月19日
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
		printf("申请内存失败。\n");
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

table addTable(table t,int x,int add){//x为插入的元素，add为插入的位置
	//判断插入位置的合法性
	if(add>t.length+1||add<1){
		printf("插入的位置不合法。\n");
		return t;
	}
	//判断表满了没
	if(t.length==t.size){
		printf("表已满,正在为您重新分配空间。\n");
		t.head=(int *)realloc(t.head,(t.size+1)*sizeof(int));
		if(!t.head){
			printf("分配空间失败！\n");
			return t;
		}
		t.size+=1;
	}
	//开始插入，将最后一个往后挪一个，然后依次往后移。
	for(int i=t.length-1;i>=add-1;i--){
		t.head[i+1]=t.head[i];

	}
	t.length++;
	t.head[add-1]=x;
	return t;
}

table deleteTable(table t, int delete){//delete为想要删除的元素的位置
	if(delete>t.length || delete<1){
		printf("删除的位置有误\n");
		return t;
	}

	for(int i=delete;i<t.length;i++){
		t.head[i-1]=t.head[i];
		}
	t.length--;
	return t;
}

table changeTable(table t, int x,int newx ){//用newx替代x
	int temp=find(t,x);
	if(temp==-1){
		printf("未找到该元素\n");
	}
	else{
		t.head[temp-1]=newx;
	}
	return t;
}

int find(table t, int x){//查找x
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
