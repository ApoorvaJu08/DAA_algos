#include <stdio.h>
int main()
{
    int i, a, b, n;
    float M, temp, x[i],  w[20], profit = 0, v[20], s[20];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &M);
    for(i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter the value of item%d: ", i);
        scanf("%f", &v[i]);
        printf("Enter the weight of item%d: ", i);
        scanf("%f", &w[i]);
    }

    for(i = 0; i < n; i++)
    {
        s[i] = v[i]/w[i];
    }

    for(a = 0; a < n; a++)
    {
        for(b = (a + 1); b < n; b++)
        {
            if(s[a] < s[b])
            {
                temp = s[b];
                s[b] = s[a];
                s[a] = temp;
                temp = w[b];
                w[b] = w[a];
                w[a] = temp;
                temp = v[b];
                v[b] = v[a];
                v[a] = temp;
            }
        }
    }

    // for(i = 0; i < n; i++)
    // {
    //     printf("%f\t", s[i]);
    //     printf("\n%f\t\n", v[i]);
    //     printf("\n%f\t", w[i]);
    // }

    for(i = 0; i < n; i++)
    {
        if(w[i] <= M)
        {
            x[i] = 1.0; 
            M = M - w[i];
            // printf("%f\n", M);
        }
        else
        {
            break;
        }
        
    }

    if(i <= n)
    {
        x[i] = M/w[i];
        // printf("%f\n", x[i]);
    }

    for(i = 0; i < n; i++)
    {
        profit = profit + (x[i]*v[i]);
        printf("%f\t", x[i]);
    }
    printf("\n%f\n", profit);
    return 0;
}