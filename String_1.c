#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxsize 40

//����һ����ֵ�����ַ�������chars�Ĵ�T
int StrAssign(char T[],char *chars){
	T[0]=strlen(chars);
	int i;
	for(i=1;i<=T[0];i++){
		T[i]=*(chars+i-1);//ע�⡰*�������ȼ�������Ҫ������
	}
	return 1;
}

//��S���ڣ��ɴ�S���Ƶô�T
int StrCopy(char T[],char S[]){
	int i;
	for(i=0;i<=S[0];i++){
		T[i]=S[i];
	}
	return 1;
}

//��S���ڣ��������
int ClearString(char S[]){
	S[0]=0;
	return 1;	
}

//��Ϊ�գ�����1�����򷵻�0
int StringEmpty(char S[]){
	if(S[0]==0)
		return 1;
	else
		return 0;
}

//���ش�S��Ԫ�ظ���
int StrLength(char s[]){
	return s[0];
}

//S>T������ֵ>0;S=T������0��S<T������ֵ<0;
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

//��t������s1��s2���Ӷ��ɵ��´�
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

//��s���ڣ�1<=POS<=StrLength(s),��0<=len<=StrLength(s)-pos+1,��sub���ش�s�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
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

//��s��t���ڣ�t�Ƿǿմ���1<=pos<=StrLength(s)��
//������s�д��ںʹ�tֵ��ͬ���Ӵ����򷵻���������s�е�pos���ַ�֮���һ�γ��ֵ�λ�ã����򷵻�0
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

//����������ʾ
void DisplayStr(char s[]){
	int i;
	for(i=1;i<=s[0];i++){
		printf("%c",s[i]);
	}
	printf("\n");
}


//��s��t���ڣ�1<=pos<=StrLength(s)+1,�ڴ�s�ĵ�pos���ַ�֮ǰ���봮T
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

//��s���ڣ�1<=pos<=SreLength(s)-len+1���Ӵ�s��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
int StrDelete(char s[],int pos,int len){
	if(pos<1 || pos+len>s[0] ){
		return 0;
	}
	int numlast=s[0]-(pos+len-1);//pos��ɾ��Len���Ⱥ�ʣ�µ�Ԫ������
	for(int i=1;i<=numlast;i++){
		s[pos]=s[pos+len];
		pos++;
	}
	s[0]=s[0]-len;
	return 1;
}

//��s��t��v���ڣ�t�Ƿǿմ�����v�滻����s�г��ֵ�������t��ȵĲ��ص����Ӵ�
int Replace(char s[],char t[],char v[]){
	int pos=0;
	int status,star;
	star=pos;
	for(int i=0;star<s[0];i++){
		pos=Index(s,t,star);
		if(pos!=0){
		//printf("%d\n",pos);
		star=star+pos;//������һ���ظ����ֵ�λ��
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


