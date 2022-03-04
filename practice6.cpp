#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    unsigned N,min_non_minus;
    repeat_number_of_elements_input:
    scanf("%u",&N);               // NUMBER OF ARRAY ELEMENTS INPUT
    if ( N < 5 || N > 20)                         // NUMBER OF ELEMENTS FILTER
    	{
    	printf("Wrong input,try again\n");
        goto repeat_number_of_elements_input;
		}
    int Arr[N];

    for(unsigned i = 0;i<N;i++) // INPUT + INPUT FILTER
        {
        repeat_in_case_of_wrong_input:
        printf("\n Arr[%d]=", i);
        scanf("%d",Arr+i);
        if ( *(Arr+i) > 100 ||  *(Arr+i) < -100 )
            {
            printf("Wrong input,try again\n");
            goto repeat_in_case_of_wrong_input;
            }
        }

    min_non_minus = Arr[0];
    printf("Input_Array = ");
    for (unsigned i = 0; i<N; i++)
        {
        printf("%d ",*(Arr+i));
        if ( *(Arr+i) < min_non_minus && *(Arr+i) >= 0) {min_non_minus = *(Arr+i);} // PRINT ARRAY + MINIMAL NON MINUS ELEMENT SEARCH
        }

    for (unsigned i = 0; i<N;i++) {if ( *(Arr+i) < 0) {*(Arr+i) = min_non_minus;}} // CHANGING MINUS ELEMRNT TO MIN NON MINUS ELEMENT

    printf("\n");
    printf("Result_Array = ");
    for (unsigned i = 0; i<N; i++){printf("%d ",*(Arr+i));} // PRINT RESULT
}