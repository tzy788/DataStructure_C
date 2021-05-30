/*
 * StaticLinkList.c
 *
 *  Created on: 2021��5��29��
 *      Author: HP
 */

#include<stdio.h>
#include<stdlib.h>

#define maxsize 12  //һ��Ƚϴ󣬷���ʹ�õ�ʱ��ͣ�Ĳ������ݣ��ܴ�������ݸ���Ϊmaxsize-2

//�����һ�������һ��������Ԫ�أ���������data
//����δ��ʹ�õ�����Ԫ��Ϊ��������
//�����һ��Ԫ�ص�cur��ű�������ĵ�һ�������±�
//�������һ��Ԫ�ص�cur��ŵ�һ������ֵԪ�ص��±꣬�൱��ͷ���
typedef struct StaticLinkList{
	int data;
	int cur;//�α�
}staticlinklist[maxsize];



//��ʼ������
int InitialStatLinkList(staticlinklist p){

	p[maxsize-1].cur=0; //���������һ��curָ��0
	p[0].cur=1;//��һ��curָ��1���²�������ݻ�ŵ�p[1]��
	for(int i=0;i<maxsize-1;i++){//p[1]��p[maxsize-2]��data��cur����Ϊ��
		p[i].cur=i+1;

	}
	return 1;
}

//�����ĳ���
int LengthofStaticLinkList(staticlinklist p){
	if(p[maxsize-1].cur==0){
		printf("�ձ�\n");
		return 0;
	}
	int length=0;
	int i;
	i=p[maxsize-1].cur;//��һ�������ݵ��±�
	while(i){
		i=p[i].cur;//���һ�������ݵĽ���cur����0
		length++;
	}

	return length;
}

//�������з���ռ䣬�൱��malloc,���ر�������ĵ�һ���ռ���±�
int StaLinkListMalloc(staticlinklist p){
	int i=p[0].cur;
	if(p[0].cur!=maxsize-1){
		p[0].cur=p[i].cur;
	}
	else{
		printf("�ռ����ʧ��\n");
		return -1;
	}
	return i;
}

//��ɾ���Ľڵ���뱸������ĵ�һ��,posΪҪfree��λ��,��pos��λ�ñ�ɱ��������ͷ���
void StaLinkListFree(staticlinklist p,int pos){
	p[pos].cur=p[0].cur;
	p[0].cur=pos;

}

//����Ԫ��,num�ǲ����ֵ��pos�ǲ����λ��
int InsertElemInStaLinkList(staticlinklist p,int num,int pos){
	//�����ͷ
	if(pos==1){
		int k=StaLinkListMalloc(p);//�·���λ���±�
		p[k].data=num;
		p[maxsize-1].cur=k;
		p[k].cur=0;
		return 1;

	}
	//�жϱ���
	if(p[0].cur==maxsize-1){
		printf("����������ʧ��\n");
		return 0;
	}
	//�жϲ���λ���Ƿ�Ϸ�
	if(pos<1||pos>LengthofStaticLinkList(p)+1){
		printf("����λ�÷Ƿ�\n");
		return 0;
	}

	int i=StaLinkListMalloc(p);//���������һ�����±�
	if(i!=-1){//�ռ����ɹ�
		p[i].data=num;
		int temp=p[maxsize-1].cur;//��һ�������ݵ��±�
		for(int j=1;j<pos-1;j++){//�ҵ�����λ��ǰһ�����
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

//����
void DisplayStatLinkList(staticlinklist p){
	int i=p[maxsize-1].cur;
	while(i){
		printf("%d ",p[i].data);
		i=p[i].cur;
	}
	printf("\n");
}

//ɾ��Ԫ��
int DeleteElemFromStatLinkList(staticlinklist p,int pos){
	//�ж�ɾ��λ���Ƿ�Ƿ�
	if(pos<1||pos>LengthofStaticLinkList(p)){
		printf("����λ�÷Ƿ�\n");
		return 0;
	}
	//ɾ����ͷ
	if(pos==1){
		int temp=p[maxsize-1].cur;
		p[maxsize-1].cur=p[(p[maxsize-1].cur)].cur;
		StaLinkListFree(p,temp);
		return 1;
	}
	int temp=p[maxsize-1].cur;//��һ�������ݵ��±�
	for(int j=1;j<pos-1;j++){//�ҵ�ɾ��λ��ǰһ�����
		temp=p[temp].cur;
	}
	//ɾ��������λ�õ�Ԫ��
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
