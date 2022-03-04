#include <stdio.h>
#include <stdlib.h>

int main()
{

    unsigned int pack_unpack,coded_number,H,T,S;
    printf("Write 0 to pack, 1 to unpack\n");
    scanf("%u", &pack_unpack);
    if ( pack_unpack != 0 && pack_unpack != 1)
        {
        printf("Invalid input");
        return 0;
        }
    else if (!pack_unpack)
        {
        coded_number = 0;
        printf("Write H,T,S\n");
        scanf("%u%u%u",&H,&T,&S);
        coded_number = coded_number | (H << 14);
        coded_number = coded_number | (T << 5);
        coded_number = coded_number | (S);
        printf("%4x",coded_number);
        return 0;
        }
    else
        {
        printf("Write coded number\n");
        scanf("%x",&coded_number);
        H = (coded_number >> 14);
        T = (coded_number & 16352) >> 5;
        S = (coded_number & 31);
        printf("%u %u %u",H,T,S);
        return 0;
        }

}
