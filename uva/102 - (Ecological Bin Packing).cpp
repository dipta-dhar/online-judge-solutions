/*
102 - Ecological Bin Packing
authors: dipta1010
RunTime:
*/

#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;

int bottles[12];

int count_movement(int a, int b, int c) {
    int m = 0;
    for (int i=0; i<9; i++) {
        if (i!=a && i!=b && i!=c)
            m += bottles[i];
    }

    return m;
}

int main()
{
    while (scanf ("%d", &bottles[0]) == 1) {

        for (int i=1; i<9; i++ )
            scanf("%d", &bottles[i]);

        char output_str[6];
        int movements[6];
        int min_movement = INT_MAX;
        char combinations[6][5] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

        movements[0] = count_movement (0, 5, 7); // BCG
        movements[1] = count_movement (0, 4, 8); // BGC
        movements[2] = count_movement (2, 3, 7); // CBG
        movements[3] = count_movement (2, 4, 6); // CGB
        movements[4] = count_movement (1, 3, 8); // GBC
        movements[5] = count_movement (1, 5, 6); // GCB

        for (int i=0; i<6; i++) {
            if (movements[i] < min_movement ) {
                min_movement = movements[i];
                strcpy (output_str, combinations[i]);
            }
        }

        printf ("%s %d\n", output_str, min_movement);
    }

    return 0;
}
