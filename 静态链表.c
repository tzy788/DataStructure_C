/*
 * StaticLinkList.c
 *
 *  Created on: 2021年5月29日
 *      Author: HP
 */

#include<stdio.h>
#include<stdlib.h>

#define maxsize 12  //一般比较大，方便使用的时候不停的插入数据，能存入的数据个数为maxsize-2

//数组第一个和最后一个做特殊元素，不存数据data
//定义未被使用的数组元素为备用链表
//数组第一个元素的cur存放备用链表的第一个结点的下标
//数组最后一个元素的cur存放第一个有数值元素的下标，相当于头结点
typedef struct StaticLinkList{
	int data;
	int cur;//游标
}staticlinklist[maxsize];



//初始化链表
int InitialStatLinkList(staticlinklist p){

	p[maxsize-1].cur=0; //空链表，最后一个cur指向0
	p[0].cur=1;//第一个cur指向1，新插入的数据会放到p[1]中
	for(int i=0;i<maxsize-1;i++){//p[1]到p[maxsize-2]的data和cur都置为空
		p[i].cur=i+1;

	}
	return 1;
}

//计算表的长度
int LengthofStaticLinkList(staticlinklist p){
	if(p[maxsize-1].cur==0){
		printf("空表\n");
		return 0;
	}
	int length=0;
	int i;
	i=p[maxsize-1].cur;//第一个有数据的下标
	while(i){
		i=p[i].cur;//最后一个有数据的结点的cur等于0
		length++;
	}

	return length;
}

//在数组中分配空间，相当于malloc,返回备用链表的第一个空间的下标
int StaLinkListMalloc(staticlinklist p){
	int i=p[0].cur;
	if(p[0].cur!=maxsize-1){
		p[0].cur=p[i].cur;
	}
	else{
		printf("空间分配失败\n");
		return -1;
	}
	return i;
}

//将删除的节点加入备用链表的第一个,pos为要free的位置,将pos的位置变成备用链表的头结点
void StaLinkListFree(staticlinklist p,int pos){
	p[pos].cur=p[0].cur;
	p[0].cur=pos;

}

//插入元素,num是插入的值，pos是插入的位置
int InsertElemInStaLinkList(staticlinklist p,int num,int pos){
	//插入表头
	if(pos==1){
		int k=StaLinkListMalloc(p);//新分配位置下标
		p[k].data=num;
		p[maxsize-1].cur=k;
		p[k].cur=0;
		return 1;

	}
	//判断表满
	if(p[0].cur==maxsize-1){
		printf("表满，插入失败\n");
		return 0;
	}
	//判断插入位置是否合法
	if(pos<1||pos>LengthofStaticLinkList(p)+1){
		printf("插入位置非法\n");
		return 0;
	}

	int i=StaLinkListMalloc(p);//备用链表第一个的下标
	if(i!=-1){//空间分配成功
		p[i].data=num;
		int temp=p[maxsize-1].cur;//第一个有数据的下标
		for(int j=1;j<pos-1;j++){//找到插入位的前一个结点
			temp=p[temp].cur;
		}
		p[i].cur=p[temp].cur;
		p[temp].cur=i;
		return 1;
	}
	else{
		return 0;
	}
}

//遍历
void DisplayStatLinkList(staticlinklist p){
	int i=p[maxsize-1].cur;
	while(i){
		printf("%d ",p[i].data);
		i=p[i].cur;
	}
	printf("\n");
}

//删除元素
int DeleteElemFromStatLinkList(staticlinklist p,int pos){
	//判断删除位置是否非法
	if(pos<1||pos>LengthofStaticLinkList(p)){
		printf("插入位置非法\n");
		return 0;
	}
	//删除表头
	if(pos==1){
		int temp=p[maxsize-1].cur;
		p[maxsize-1].cur=p[(p[maxsize-1].cur)].cur;
		StaLinkListFree(p,temp);
		return 1;
	}
	int temp=p[maxsize-1].cur;//第一个有数据的下标
	for(int j=1;j<pos-1;j++){//找到删除位的前一个结点
		temp=p[temp].cur;
	}
	//删除表其他位置的元素
	int temp1=p[temp].cur;
	p[temp].cur=p[p[temp].cur].cur;
	StaLinkListFree(p,temp1);
	return 1;
}

int main(void){
	staticlinklist t;
	int status=0;
	status=InitialStatLinkList(t);
	for(int i=1;i<9;i++){
		status=InsertElemInStaLinkList(t,i,i);
		t[LengthofStaticLinkList(t)].cur=0;
	}
	DisplayStatLinkList(t);
	status=InsertElemInStaLinkList(t,45,3);
	status=InsertElemInStaLinkList(t,75,7);
	DisplayStatLinkList(t);
	status=DeleteElemFromStatLinkList(t,2);
	status=DeleteElemFromStatLinkList(t,1);
	status=InsertElemInStaLinkList(t,785,6);
	DisplayStatLinkList(t);
	return 0;
}
