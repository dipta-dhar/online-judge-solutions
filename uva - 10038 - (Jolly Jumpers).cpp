#include<cstdio>
#include<cstring>

int n, a[3001], dif, N;
bool v[3001], flag;

int abs(int a, int b) {
    if (a>b)  return a-b;
    return b-a;
}

int main()
{
    while(scanf("%d", &n) == 1) {
        flag = true;
        memset(v, false, sizeof(bool)*n);
        for(int i=0; i<n; i++)  scanf("%d", &a[i]);

        N = n-1;
        for(int i=0; i<N; i++) {
            dif = abs(a[i], a[i+1]);

            if (dif==0 || dif>N || v[dif]==true) {
                flag = false;
                break;
            }
            v[dif] = true;
        }

        flag==true ? printf("Jolly\n") : printf("Not jolly\n");
    }

    return 0;
}
