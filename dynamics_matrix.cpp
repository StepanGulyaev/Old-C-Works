#include <stdio.h>
#include <stdlib.h>

int main()
    {
    size_t n;
    scanf("%lu",&n);
    int sum = 0;

    int** table = (int**)malloc(n*sizeof(int*));
    int* rows = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
        {
        
        *(table+i) = (int*)malloc(*rows);
        printf("%d   \n",i);
        rows = *(table+i);
        for (int j = 0; j < n; j++)
            {
            printf("A[%d][%d] = ",i,j);
            scanf("%d",rows+j);
            }
        }

    for (int i = 0; i < n; i++)
        {
        rows = *(table+i);
        for (int j = 0; j < n; j++){printf("%d  ",*(rows+j));}
        printf("\n");
        }

    int border = n-1;

    for (int i = 0; i < n; i++)
        {
        int j = 0;
        rows = *(table+i);
        while (j < border)
            {
            sum = sum + *(rows+j);
            j++;
            }
        border--;
        }
    printf("\n");
    printf("%d\n",sum);

    for(int i = 0; i < n; i++)
        {
        free(table+i);
        }
    free(rows);
    free(table);
    }


