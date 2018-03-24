/*
100 - The 3n+1 problem
authors: dipta1010
RunTime: 0.000s (best time)
*/

#include<cstdio>
#include<algorithm>
#define lli long long int
using namespace std;

lli a,b, x,y, n, cnt, mcnt;

int main() {
    while(scanf("%lld %lld", &a,&b) == 2) {
        x = min(a, b);
        y = max(a, b);
        
        mcnt = 0;  // max counter
        for(int i=x; i<=y; i++) {
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
