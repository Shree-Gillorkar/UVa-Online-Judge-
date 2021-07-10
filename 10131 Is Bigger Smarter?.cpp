/*
Algorithm - 
Add the number attribute i to the elephant to avoid losing after sorting
Reverse the array of elephants (W is big in front; if W is the same, S is small in front)
Reverse the longest subsequence of dp for a good array of sort, record the precursor
Output path (because it is reversed dp, so the output path does not need to stack, continue to output the precursor)

Time Complexity - O(n^2)


*/

#include <cstdio>
#include <algorithm>

using namespace std;

struct E{
    int ind,W,S;
    
    E(){
    }
    
    E(int _ind, int _W, int _S){
        ind=_ind;
        W=_W;
        S=_S;
    }
    
    bool operator < (E X) const{
        if(W!=X.W) return W<X.W;
        return S>X.S;
    }
};

int main(){
    int n=0,W,S;
    E a[1000];
    
    while(scanf("%d %d",&W,&S)==2) a[n]=E(++n,W,S);
    sort(a,a+n);
    
    int dp[n],next[n],ans=0,start;
    
    for(int i=n-1;i>=0;i--){
        dp[i]=1;
        next[i]=-1;
        
        for(int j=i+1;j<n;j++){
            if(a[i].W<a[j].W && a[i].S>a[j].S && 1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
                next[i]=j;
            }
        }
        
        if(dp[i]>ans){
            ans=dp[i];
            start=i;
        }
    }
    
    printf("%d\n",ans);
    for(int i=start;i!=-1;i=next[i]) printf("%d\n",a[i].ind);
    
    return 0;
}
