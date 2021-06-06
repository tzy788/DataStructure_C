/*
 * KMP_example.c
 *
 *  Created on: 2021Äê6ÔÂ5ÈÕ
 *      Author: HP
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 40

void get_Next(char t[],int *next){
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

int index_KMPEX(char s[],char t[]){
	int i=1;
	int j=1;
	int *next[strlen(t)];
	get_Next(t,next);
	while(i<=s[0]&&j<=t[0]){
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
	return 0;
}
