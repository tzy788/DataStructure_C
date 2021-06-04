#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxsize 40

//生成一个其值等于字符串常量chars的串T
int StrAssign(char T[],char *chars){
	T[0]=strlen(chars);
	int i;
	for(i=1;i<=T[0];i++){
		T[i]=*(chars+i-1);//注意“*”的优先级，所以要用括号
	}
	return 1;
}

//串S存在，由串S复制得串T
int StrCopy(char T[],char S[]){
	int i;
	for(i=0;i<=S[0];i++){
		T[i]=S[i];
	}
	return 1;
}

//串S存在，将串清空
int ClearString(char S[]){
	S[0]=0;
	return 1;	
}

//串为空，返回1，否则返回0
int StringEmpty(char S[]){
	if(S[0]==0)
		return 1;
	else
		return 0;
}

//返回串S的元素个数
int StrLength(char s[]){
	return s[0];
}

//S>T，返回值>0;S=T，返回0；S<T，返回值<0;
int StrCompare(char s[],char t[]){
	int i,res;
	for(i=1;i<=s[0]&&i<=t[0];i++){
		if(s[i]==t[i])
			res=0;
		else
			return s[i]-t[i];
	}
	return res;
}

//用t返回由s1和s2连接而成的新串
int Concat(char t[],char s1[],char s2[]){
	if(s1[0]+s2[0]>maxsize)
		return 0;
	t[0]=s1[0]+s2[0];
	int i,j;
	j=1;
	for(i=1;i<=s1[0];i++){
		t[j]=s1[i];
		j++;
	}
	for(i=1;i<=t[0];i++){
		t[j]=s2[i];
		j++;
	}
	return 1;
}

//串s存在，1<=POS<=StrLength(s),且0<=len<=StrLength(s)-pos+1,用sub返回串s的第pos个字符起长度为len的子串
int SubString(char sub[],char s[],int pos,int len){
	if((pos<1 && pos>StrLength(s)) || (len<0 && len>StrLength(s)-pos+1))
		return 0;
	int i;
	sub[0]=len;
	for(i=1;i<=len;i++){
		sub[i]=s[pos];
		pos++;
	}
	return 1;
}

//串s和t存在，t是非空串，1<=pos<=StrLength(s)。
//若主串s中存在和串t值相同的子串，则返回它在主串s中第pos个字符之后第一次出现的位置，否则返回0
int Index(char s[],char t[],int pos){
	if(pos+t[0]>s[0])
		return 0;
	int i,j,temp,res;
	res=0;
	i=pos;
	for(i=i+1;i<=s[0];i++){//the length of s
		res++;
		temp=i;
		for(j=1;j<=t[0];j++){//the length of t
			if(s[temp]==t[j]){
				temp++;
				continue;
			}
			else{
				break;
			}
		}
		if(j>t[0]){
			return res;
		}
		else{
			continue;
		}
		
	}
	return 0;
}

//遍历串并显示
void DisplayStr(char s[]){
	int i;
	for(i=1;i<=s[0];i++){
		printf("%c",s[i]);
	}
	printf("\n");
}


//串s、t存在，1<=pos<=StrLength(s)+1,在串s的第pos个字符之前插入串T
int StrInsert(char s[],int pos,char t[]){
	if(pos<1 || pos>StrLength(s)+1)
		return 0;
	int slength=s[0];
	int tlength=t[0];
	if((slength+tlength)>maxsize-1)
		return 0;
	for(int i=slength;i>=pos;i--){
		s[(i+tlength)]=s[i];
	}
	for(int j=1;j<=tlength;j++){
		s[pos]=t[j];
		pos++;
	}
	s[0]=slength+tlength;
	return 1;
}

//串s存在，1<=pos<=SreLength(s)-len+1，从串s中删除第pos个字符起长度为len的子串
int StrDelete(char s[],int pos,int len){
	if(pos<1 || pos+len>s[0] ){
		return 0;
	}
	int numlast=s[0]-(pos+len-1);//pos后删掉Len长度后剩下的元素数量
	for(int i=1;i<=numlast;i++){
		s[pos]=s[pos+len];
		pos++;
	}
	s[0]=s[0]-len;
	return 1;
}

//串s、t和v存在，t是非空串，用v替换主串s中出现的所有与t相等的不重叠的子串
int Replace(char s[],char t[],char v[]){
	int pos=0;
	int status,star;
	star=pos;
	for(int i=0;star<s[0];i++){
		pos=Index(s,t,star);
		if(pos!=0){
		//printf("%d\n",pos);
		star=star+pos;//更新下一个重复出现的位置
		status=StrDelete(s,star,t[0]);
		status=StrInsert(s,star,v);
		}
		else{
			return 0;
		}
	}
	return 1;
}
int main(void){
	char *t="adjj";
	char *ti="adjoi";
	char *sub="adj";
	char *replace="mzcjh";
	char s1[maxsize],s[maxsize],s2[maxsize],s3[maxsize],s4[maxsize],s5[maxsize];
	int status;
	printf("char *t=%s\n",t);
	status=StrAssign(s,t);
	printf("strassign(s,t),s=");
	DisplayStr(s);
	status=StrCopy(s1,s);
	status=ClearString(s);
	printf("after clearstring s,s[0]=%d\n",s[0]);
	status=StrAssign(s,ti);
	status=StrCompare(s,s1);
	printf("s-s1=%d\n",status);
	status=Concat(s2,s,s1);
	printf("concat(s2,s,s1),s2=");
	DisplayStr(s2);
	status=SubString(s3,s2,2,3);
	printf("substring(s3,s2,2,3),s3=");
	DisplayStr(s3);
	status=StrAssign(s4,sub);
	printf("s4=");
	DisplayStr(s4);
	int pos=0;
	int index=Index(s2,s4,pos);
	printf("index(s2,s4,%d),s2[2]=%c,the first position \"%s\" show in s2(after postionsion %d)is %d\n",pos,s2[2],sub,pos,index);
	status=StrInsert(s2,3,s);
	printf("after StrInsert(s2,3,s),s2=");
	DisplayStr(s2);
	status=StrDelete(s2,4,4);
	printf("after StrDelete(s2,4,4),s2=");
	DisplayStr(s2);
	status=StrInsert(s2,3,s4);
	status=StrInsert(s2,6,s4);
	printf("s2=");
	DisplayStr(s2);
	status=StrAssign(s5,replace);
	printf("s5=");
	DisplayStr(s5);
	status=Replace(s2,s4,s5);
	printf("s2=");
	DisplayStr(s2);
	return 0;
}


