#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

#define MAXVALUE 65000

bool isPrime[MAXVALUE];

void Sieve(){
    memset(isPrime,true, sizeof(bool)*MAXVALUE);

    for(int i=2;i*i<MAXVALUE;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAXVALUE;j+=i){
                isPrime[j]=false;
            }
        }
    }
}
int powMod(long long base, int exp, int mod) {
    long long result = 1;
    while(exp > 0) {
        if(exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool IsCarmichael(int n){
    if(isPrime[n])
        return false;
    for(int i=2;i<n;i++){
        if(powMod(i,n,n)!=i){
            return false;
        }

    }
    return true;
}

int main(){
    Sieve();

    int number;
    cin>>number;
    while(number!=0){
        if(IsCarmichael(number))
            cout<<"The number "<<number<<" is a Carmichael number."<<endl;
        else
            cout<<number<<" is normal."<<endl;
        cin>>number;
    }
}