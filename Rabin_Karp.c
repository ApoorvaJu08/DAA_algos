// for base 10
#include <stdio.h>
#include <math.h>
#define d 10
int search(int T[], int P[], int n, int m, int q)
{
    int h, i;
    int a = pow(d, (m-1));
    h = (a % q); 
    int p = 0;
    int t = 0;
    for(i = 1; i <= m; i++)
    {
        p = (((d*p) + P[i]) % q);
        t = (((d*t) + T[i]) % q);
    }
    // for(int s = 0; s <= (n-m); s++)
    // {
    //     if(p == t)
    //     {
    //         for(int j = 1; j <= m; j++)
    //         {
    //             if(P[j] == T[s+j])
    //             {
    //                 printf("Pattern match at shift %d", s);
    //             }
    //         }   
    //     }
    //     if(s < (n-m))
    //     {
    //         t = ((d * (t - (T[s+1] * h))) + T[s+m+1] % q);
    //         if(t < 0)
    //             t = (t + q);
    //     }
    // }
}

int main()
{
    int T[] = {2, 3, 5, 9, 0, 2, 3, 1, 4, 1, 5, 2, 6, 7, 3, 9, 9, 2, 1};
    int P[] = {3, 1, 4, 1, 5};
    int n = sizeof(T)/sizeof(T[0]);
    int m = sizeof(P)/sizeof(P[0]);
    int q = 13;
    search(T, P, n, m, q);
    return 0;
}