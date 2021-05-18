#include<bits/stdc++.h>

using namespace std;

/// Typedef
typedef long long ll;

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)

#define pf1(a) printf("%lld\n",a)
#define pf2(a,b) printf("%lld %lld\n",a,b)

#define mx 10000007
#define mod 100000007
#define PI acos(-1.0)


int dr[] = {-2,-2,-1,-1,1,1,2,2};
int dc[] = {-1,1,-2,2,-2,2,-1,1};


ll checkprime[mx];
vector<ll>prime;

void sieve() {

    ll n,i,j;

    for(i=4; i<mx; i+=2) checkprime[i] = 1;
    for(i=3; i*i<=mx; i+=2){
        if(checkprime[i]==0){
            for(j=i*i; j<mx; j+=(i+i)) checkprime[j] = 1; }
    }
    for(i=3; i<mx; i++) if(!checkprime[i]) prime.push_back(i);
}


ll checkPrimeNum(ll extra) {

    if(extra<=1)return 0;

    for(ll i = 2; i * i <= extra; i++){
        if(extra % i==0)return 0;
    }
    return extra;
}

int main()
{
    ll tc, t = 1;

    sieve();

    ll num;

    //freopen("/opt/Coding/clion code/output.txt", "w", stdout);

    while (cin >> num){

        if(num < 8){
            cout << "Impossible." << endl;
            continue;
        }
        if(num % 2 == 0){
            cout << "2 2 ";
            num -= 4;
        }
        else{

            cout << "2 3 ";
            num -= 5;
        }

        if(num == 4){
            cout << "2 2" << endl;
            continue;
        }

        ll extra = 0;

        for(ll i = 0; i < num; i++){

            extra = num - prime[i];
            
            if(prime[i] + checkPrimeNum(extra) == num){
                cout << prime[i] << " " << extra << endl;
                break;
            }
        }

    }

}