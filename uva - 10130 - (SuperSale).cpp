/*
10130 - SuperSale
algType: KnapSack
RunTime:
authors: dipta1010
*/

#include<cstdio>
#define max(a,b) ((a)>(b) ? (a):(b))
using namespace std;

int TC, N,G,MW, i,Ans;
int weight[1001], price[1001], K[1005][35];

int knapSack(int MW, int weight[], int price[], int N) {
    int i, w;

   for (i=0; i<=N; i++) {
        for (w=0; w<=MW; w++) {
            if (i==0 || w==0)           K[i][w] = 0;
            else if (weight[i-1] <= w)  K[i][w] = max(price[i-1]+K[i-1][w-weight[i-1]], K[i-1][w]);
            else                        K[i][w] = K[i-1][w];
        }
    }

   return K[N][MW];
}

int main() {
    // Enter Test case
    scanf("%d", &TC);

    while(TC--) {
        scanf("%d", &N);
        for(i=0; i<N; i++) {
            scanf("%d %d", &price[i], &weight[i]);
        }
        Ans = 0;
        scanf("%d", &G);
        for(i=0; i<G; i++) {
            scanf("%d", &MW);
            Ans += knapSack(MW, weight, price, N);
        }
        printf("%d\n", Ans);
    }

    return 0;
}
