#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define DBG 0

using namespace std;

int N;
vector<string>seq,tar;
void ans(){
    N=seq.size();
    int rank[200],m=-1,cur;
    map<string,int>mp;
    rep(i,N)mp[tar[i]]=i;
    rep(i,N){
        rank[i]=mp[seq[i]];
        if(DBG)printf("%s: %d\n",seq[i].c_str(), rank[i]);
    }
    cur=rank[0];
    REP(i,1,N){
        if(cur>rank[i])m=max(rank[i],m);
        cur=max(cur,rank[i]);
    }
    if(DBG)printf("m: %d %s\n",m,tar[m].c_str());
    for(int i=m;i>=0;i--)printf("%s\n",tar[i].c_str());
    printf("\n");
}
int main(){
    int a,b;
    char nds[100];
    string s;
    cin>>a;
    rep(i,a){
        tar.clear(),seq.clear();
        scanf("%d ",&b);
        rep(i,b){
            fgets(nds,100,stdin);
            if(nds[strlen(nds)-1]=='\n')nds[strlen(nds)-1]='\0';
            seq.push_back(nds);
        }
        rep(i,b){
            fgets(nds,100,stdin);
            if(nds[strlen(nds)-1]=='\n')nds[strlen(nds)-1]='\0';
            if(DBG)printf("b: %s\n",nds);
            tar.push_back(nds);
        }
        ans();
    }
}