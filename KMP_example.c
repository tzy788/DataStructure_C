/*
 * KMP_example.c
 *
 *  Created on: 2021��6��5��
 *      Author: HP
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 40
int flag,flag1;

void get_Next(char t[],int *next){//ԭʼ��next������㷨
	int i,j;
	i=1;
	j=0;
	next[1]=0;
	next[0]=t[0];
	while(i<t[0]){
		if(j==0||t[i]==t[j]){
			i++;
			j++;
			next[i]=j;
		}
		else{
			j=next[j];
		}

	}
}

void get_Nextval(char t[],int *nextval){//�Ľ������next����ķ��������ڱ��ȡ��Ϊnextval
	int i,j;
	i=1;
	j=0;
	nextval[1]=0;
	nextval[0]=t[0];
	while(i<t[0]){
		if(j==0||t[i]==t[j]){
			i++;
			j++;
			if(t[i]==t[j]){
				nextval[i]=nextval[j];
			}
			else{
				nextval[i]=j;
			}
		}
		else{
			j=nextval[j];
		}

	}
}

int index_KMPEX(char s[],char t[]){
	flag=0;
	int i=1;
	int j=1;
	int *next[strlen(t)];
	get_Next(t,next);
	while(i<=s[0]&&j<=t[0]){
		flag++;
		if(j==0||s[i]==t[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>t[0])
		return i-t[0];
	else
		return 0;
}

int index_KMPEX_Nextval(char s[],char t[]){
	flag1=0;
	int i=1;
	int j=1;
	int *next[strlen(t)];
	get_Nextval(t,next);//ֻ��Ҫ����һ������
	while(i<=s[0]&&j<=t[0]){
		flag1++;
		if(j==0||s[i]==t[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>t[0])
		return i-t[0];
	else
		return 0;
}

int main(void){
	char *t="xb";
	char *txt="abcaboabcmbxbaacabxabcabx";
	char s[maxsize];
	char S[maxsize];
	int status=StrAssign(s,t);
	status=StrAssign(S,txt);
	int next[strlen(s)];
	get_Next(s,next);
	printf("S=");
	DisplayStr(S);
	printf("s=");
	DisplayStr(s);
	printf("next=");
	for(int i=1;i<=next[0];i++){
		printf("%d",next[i]);
	}
	printf("\n");
	int pos=index_KMPEX(S,s);
	printf("pos=%d\n",pos);


	printf("�Ľ����nextval�����ã�\n");
	char *txt1="aaaabcdaaaaaxe";
	char *pattern_txt1="aaaaax";
	char txt1_[maxsize];
	char pattern_txt1_[maxsize];
	status=StrAssign(txt1_,txt1);
	status=StrAssign(pattern_txt1_,pattern_txt1);
	printf("txt1_=");
	DisplayStr(txt1_);
	printf("pattern_txt1_=");
	DisplayStr(pattern_txt1_);
	int next1[strlen(pattern_txt1_)];
	int nextval[strlen(pattern_txt1_)];
	get_Next(pattern_txt1_,next1);
	get_Nextval(pattern_txt1_,nextval);
	printf("next=");
	for(int i=1;i<=next1[0];i++){
		printf("%d",next1[i]);
	}
	printf("\n");
	printf("nextval=");
	for(int i=1;i<=nextval[0];i++){
		printf("%d",nextval[i]);
	}
	printf("\n");
	pos=index_KMPEX(txt1_,pattern_txt1_);
	int pos1=index_KMPEX_Nextval(txt1_,pattern_txt1_);
	printf("�Ľ�ǰpos=%d�Σ��Ľ���pos1=%d�Ρ�\n",pos,pos1);
	printf("�Ľ�ǰ��Ҫѭ��ƥ��%d�Σ��Ľ�����Ҫѭ��ƥ��%d�Ρ�\n",flag,flag1);

	return 0;
}
