/*
 * lianbiaoshixian.c
 *
 *  Created on: 2021��5��24��
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

/*����ÿ���������ݿռ�һ������һ�����ݽṹ�����ڴ�Ÿ������͵����ݣ��Լ�һ��ָ�룬
 * ��ָ��һ���Ϊnext������ָ����һ������λ�á�������һ�����Ҳ���������ͣ�
 * ����next��ָ��ҲҪ����Ϊ�������͡�
*/

typedef struct Link{
	char elem;  //������
	struct Link  *next;  //ָ����ָ����Ԫ��
}link;  //linkΪ�ڵ�����ÿ���ڵ㶼��һ��link�ṹ��

//��������ͷ��������
link *initialLink(){
	link *p=(link *)malloc(sizeof(link));//����ͷ���
	link *temp=p;			//�ݴ����
	for(int i=1;i<6;i++){
		link *a=(link *)malloc(sizeof(link)); //�½ڵ�a
		temp->next=a;       //ǰһ���ڵ��ָ����ָ���µĽڵ��ַ
		a->elem=i;			//���½ڵ�a��������ֵ
		a->next=NULL;		//Ĭ���½ڵ�Ϊ���һ��������û������ָ��
		temp=a;		//���½ڵ��ݴ���temp�У������´ν�ָ����ָ����һ���ڵ�

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

//elemΪ�����Ԫ�أ�positionΪ�����λ��
link *insertElem(link *p,int elem,int position){
	link *temp=(link *)malloc(sizeof(link));
	temp=p;
	for(int i=1;i<position;i++){//����λ��ǰһ���ڵ�
		temp=temp->next;
		if(temp==NULL){
			printf("����λ�ô���\n");
			return p;
		}
	}
	link *newnode=(link *)malloc(sizeof(link)); //�����½ڵ�
	newnode->elem=elem;
	newnode->next=temp->next;			//�½ڵ�ָ�����λ�õĺ�һ���ڵ�
	temp->next=newnode;					//����λ��ǰһ���ڵ��nextָ���½ڵ�
	return p;
}

link *deleteElem(link *p,int position){//positionΪɾ����Ӧλ�õ�ֵ
	link *temp=(link *)malloc(sizeof(link));
	temp=p;
	for(int i=1;i<position;i++){//ɾ��λ��ǰһ���ڵ�
		temp=temp->next;
		if(temp->next==NULL){
			printf("ɾ��λ�ô���\n");
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
		if(temp->elem==x){//�ҵ���
			return position;
		}
		else{
			position++;
		}

	}
	return -1;
}

link *changeElem(link *p,int newnum,int position){//newnumΪ��ֵ��positionΪ���ĵĵط�
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
//	printf("5 ������ĵ�%d��\n",FindElem(t,5));
//	t=changeElem(t,98,3);
//	DisplayLink(t);
//	return 0;
//}
