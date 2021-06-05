/*
 * KMP.c
 *
 *  Created on: 2021��6��5��
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 40


int getNext(char t[], int *next){
	int i,j;
	j=0;
	next[0]=0;
	for(i=1;i<strlen(t);i++){
		while(j>0 && t[i]!=t[j]){
			j=next[j-1];
		}
		if(t[i]==t[j]){
			j++;
		}
		next[i]=j;
	}
	return 0;
}

//tΪ�ı�����sΪģʽ��
int index_KMP(char t[],char s[]){
	int i,j;
	i=j=0;
	int tlength=strlen(t);
	int slength=strlen(s);
	int next[slength];
	getNext(s,next);
	while(i<tlength && j<slength){//����bug�����統t=abxbabcqqqabcabc��s=xbʱ������1.
		if(j==0 || t[i]==s[j]){//��Ϊ����д���޷��жϳ���һ��Ԫ���⣬��������Ԫ�ض���ƥ���ϵ�����µ�λ��
			i++;
			j++;
		}
		else{
			j=next[j-1];
		}
	}
	if(j>=slength){
		return i-slength+1;
	}
	return -1;
}



int main(void){
	char t[maxsize]="abxaxbcqqqabcabc";//�ı���
	char s[]="xbc";//ģʽ��
	int next[strlen(s)];
	printf("�ı���t=%s\n",t);
	printf("ģʽ��s=%s\n",s);
	getNext(s,next);
	printf("next=");
	for(int i=0;i<strlen(s);i++){
		printf("%d",next[i]);
	}
	printf("\n");
	int pos=index_KMP(t,s);
	printf("s����t�ĵ�%d����ʼƥ��ɹ�\n",pos);
	return 0;
}

