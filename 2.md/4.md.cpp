#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main() {
	char *str;
	char flag;
	str=(char *)malloc(sizeof(char));
	scanf("%s",str);
	int len,i=0,j=0,k=0,l=0,lena=0,lenb=0;
	int counta=0,countb=0;
	len=strlen(str);
	char a[len],b[len];
 
	for(i=0; i<len; i++) 
    {
		if((*str=='/')||(*str=='%')||(*str=='.')) 
        { 
			flag=*str;
			str++;
			break;
		} else if(*str>='0'&&*str<='9') {
			if(*str=='0') counta++;
			a[i]=*str;
			str++;
		} else {
			printf("输入违法");
			return 0;
		}
	}
	lena=i;
	if(i<(len-1)) { 
		for(j=0; j<(len-i-1); j++) { 
			if(*str=='0') countb++; 
			b[j]=*str;
			str++;
		}
	}
	lenb=j;//b中元素个数
	if(lena>0) {
		if(counta==lena) {
			printf("0");
		} else {
			i=lena-1;
			while(a[i]=='0') {
				i--;
			}
			for(k=i; k>=0; k--) {
				printf("%c",a[k]);
			}
		}
	}
	printf("%c",flag);//输出特殊字符
	if(lenb>0) {
		if(countb==lenb) {
			printf("0");
		} else {
			j=0;
			while(b[j]=='0') {
				j++;
			}
			l=lenb-1;
			while(b[l]=='0'){
				l--;
			}
			for(k=l; k>=j; k--) {
				printf("%c",b[k]);
			}
		}
	}
 
	return 0;
}