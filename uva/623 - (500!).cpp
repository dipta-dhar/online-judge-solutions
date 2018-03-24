/*
623 - 500!
algType: BigInteger
RunTime: 0.000
authors: dipta1010
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAX 3000

int num;
char fact[1001][MAX], tem[10];

void intTOchar(int curr) {
    int in = 0;
    while (curr != 0) {
        tem[in++] = (curr%10) + '0';
        curr /= 10;
    }
    tem[in] = '\0';
    strrev(tem);
}

void multiply(char* a, char* b, char* res) {
	int lenA = strlen(a);
	int lenB = strlen(b);
	int i,j, c[lenA+lenB];

	memset(c, 0, sizeof(int)*(lenA+lenB));
	for (i = lenA - 1; i >= 0; i--)
		for (j = lenB - 1; j >= 0; j--)
			c[i + j + 1] += (b[j] - '0') * (a[i] - '0');

	for (i = lenA + lenB - 1; i >= 0; i--) {
		if (c[i] >= 10) {
			c[i - 1] += c[i] / 10;
			c[i] %= 10;
		}
	}

	i = 0;
	while (c[i] == 0)
		i++;

	j = 0;
	while (i < lenA + lenB) {
		res[j] = c[i] + '0';
		i++; j++;
	}

	res[j] = '\0';
}

void solve() {
    strcpy(fact[0], "1");
    strcpy(fact[1], "1");

    for(int i=2; i<1001; i++) {
        intTOchar(i);
        multiply(fact[i-1], tem, fact[i]);
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    solve();
    while(scanf("%d", &num) == 1) {
       printf("%d!\n%s\n", num, fact[num]);
    }

    return 0;
}
