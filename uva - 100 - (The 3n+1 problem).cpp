#include<cstdio>
#include<algorithm>
#define lli long long int
using namespace std;

lli a,b,n, cnt, mcnt;

void init() {
    if (a>b) { n=a; a=b; b=n;  }
}

int main() {
    while(scanf("%lld %lld", &a,&b) == 2) {
        init();
        mcnt = 0;  // max counter
        for(int i=a; i<=b; i++) {
            cnt = 0; // counter
            n = i;
            while(n != 1) {
                cnt++;

                if (n%2)    n = 3*n+1;
                else        n = n/2;
            }
            mcnt = max(mcnt, cnt);
        }

        printf("%lld %lld %lld\n",a,b,mcnt+1);
    }

    return 0;
}

