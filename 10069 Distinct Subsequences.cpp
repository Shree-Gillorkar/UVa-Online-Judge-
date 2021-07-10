#include<cstdio>
#include<string.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
void add(char str1[],char str2[],char res[]){
    int len1=strlen(str1);
    int len2=strlen(str2);
    int reslen=MAX(len1,len2)+1;
    int i,j,k,carry,tmp;
    for(int i=0;i<reslen;i++)   res[i]='0';
    res[reslen]='\0';
    for(i=len1-1,j=len2-1,k=reslen-1,carry=tmp=0;i>=0||j>=0;k--){
        tmp=0;
        if(i>=0)    tmp+=str1[i--]-'0';
        if(j>=0)    tmp+=str2[j--]-'0';
        tmp+=carry;
        if(tmp>=10)
            carry=1,tmp-=10;
        else
            carry=0;
        res[k]=tmp+'0';
    }
    res[0]='0'+carry;
    if(res[0]=='0')
        for(int i=0;i<reslen;i++)
            res[i]=res[i+1];
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char S[10001],T[101];
        char DP[101][10000];
        scanf("%s%s",S,T);
        int len=strlen(T);
        for(int i=1;i<=100;i++)
            DP[i][0]='0',DP[i][1]='\0';
        DP[0][0]='1',DP[0][1]='\0';
        for(int i=0;S[i]!='\0';i++){
            for(int j=len-1;j>=0;j--){
                if(S[i]==T[j]){
                    char res[10000];
                    add(DP[j+1],DP[j],res);
                    strcpy(DP[j+1],res);
                }
            }
        }
        printf("%s\n",DP[len]);
    }
}
