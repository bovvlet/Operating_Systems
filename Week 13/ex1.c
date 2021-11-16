#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int r = 3, p = 5;
    int flag = 0;
    int rNum[r];
    int col[p][r];
    int row[p][r];
    int r_avalable[r];

    FILE* input_file = fopen("input_ok.txt", "r");
    FILE* output = fopen("ex1_output.txt", "w");

    int cur;
    int n = 1;
    int a = 0;
    int r_unused[p];

    for( int i = 0; i < p; i ++ )
        r_unused[i] = 0;

    for( int i = 0; i < r; i ++ )
        fscanf(input_file, "%d", &rNum[i]);

    for( int i = 0; i < r; i ++ )
        fscanf(input_file, "%d", &r_avalable[i]);

    for( int i = 0; i < p; i ++ )
        for( int j = 0; j < r; j ++ )
            fscanf(input_file, "%d", &col[i][j]);

    for( int i = 0; i < p; i ++ )
        for( int j = 0; j < r; j ++ )
            fscanf(input_file, "%d", &row[i][j]);

    while(n == 1)
    {
        n = 0;
        for( int i = 0; i < p; i ++ )
        {
            a = 0;
            for(int j = 0; j < r; j++ )
                if(row[i][j] <= r_avalable[j])
                    a += 1;

            if(a == r && r_unused[i] == 0){
                for(int pg = 0; pg < r; pg++)
                    r_avalable[pg] += col[i][pg];
                n = 1;
                r_unused[i] = 1;
            }
        }
    }

    int hgh = 1;
    for( int i = 0; i < p; i ++ )
    {
        if(r_unused[i] == 0)
        {
            hgh = 0;
            fprintf(output, "There has occured r_avalable deadlock in pess %d \n", i);
        }
    }
    if(hgh == 1)
        fprintf(output, "No deadlock detected\n");
    return 0;
}
