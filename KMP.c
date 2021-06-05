/*
 * KMP.c
 *
 *  Created on: 2021年6月5日
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

//t为文本串，s为模式串
int index_KMP(char t[],char s[]){
	int i,j;
	i=j=0;
	int tlength=strlen(t);
	int slength=strlen(s);
	int next[slength];
	getNext(s,next);
	while(i<tlength && j<slength){//存在bug，例如当t=abxbabcqqqabcabc，s=xb时，返回1.
		if(j==0 || t[i]==s[j]){//因为这种写法无法判断除第一个元素外，其他后续元素都能匹配上的情况下的位置
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
	char t[maxsize]="abxaxbcqqqabcabc";//文本串
	char s[]="xbc";//模式串
	int next[strlen(s)];
	printf("文本串t=%s\n",t);
	printf("模式串s=%s\n",s);
	getNext(s,next);
	printf("next=");
	for(int i=0;i<strlen(s);i++){
		printf("%d",next[i]);
	}
	printf("\n");
	int pos=index_KMP(t,s);
	printf("s串从t的第%d个开始匹配成功\n",pos);
	return 0;
}

