#include <stdio.h>
#include <string.h>
int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];
void print(int i, int j);
void lcs();

// void print(int i, int j)
// {
//     if(i == 0 || j == 0)
//         return;
//     if(b[i][j] == 'd')
//     {
//         print(i-1, j-1);
//         printf("%c", x[i-1]);
//     }
//     else if(b[i][j] == 't')
//         print(i-1, j);
//     else if(b[i][j] == 'l')
//         print(i, j-1);
// }

void lcs()
{
    m = strlen(x);
    n = strlen(y);
    for(i = 1; i <= m; i++)
        c[i][0] = 0;
    for(j = 0; j < n; j++)
        c[0][j] = 0;
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = (c[i-1][j-1] + 1);
                b[i][j] = 'd';
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 't';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 'l';
            }
            
        }
    }
    printf("%d", c[m][n]);

    int index = c[m][n];
    char lcs[index+1]; 
    lcs[index] = '\0'; // Set the terminating character 
  
    // Start from the right-most-bottom-most corner and 
    // one by one store characters in lcs[] 
    int i = m, j = n; 
    while (i > 0 && j > 0) 
    { 
        // If current character in X[] and Y are same, then 
        // current character is part of LCS 
        if (x[i-1] == y[j-1]) 
        { 
            lcs[index-1] = x[i-1]; // Put current character in result 
            i--; j--; index--;     // reduce values of i, j and index 
        } 
    
        // If not same, then find the larger of two and 
        // go in the direction of larger value 
        else if (c[i-1][j] > c[i][j-1]) 
            i--; 
        else
            j--; 
    } 
    
    // Print the lcs 
    printf("%s",lcs); 

}

int main()
{
    printf("Enter first sequence:");
    scanf("%s", x);
    printf("Enter second sequence: ");
    scanf("%s", y);
    lcs();
    // print(m, n);
    return 0;
}