#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_DIGITS 256

int length(char *);
void swap(char *, int);
void multiplication(char *, char *, int, int);

int main()
{
    char str1[NUMBER_OF_DIGITS];
    char str2[NUMBER_OF_DIGITS];
    int len1=0;
    int len2=0;

    printf("Insert 1st value: ");
    scanf("%s", str1);
    len1 = length(str1);
    printf("%u\n", length(str1));

    printf("Insert 2nd value: ");
    scanf("%s", str2);
    len2 = length(str2);
    printf("%u\n", length(str2));

    swap(str1, len1);
    printf("%s\n", str1);

    swap(str2, len2);
    printf("%s\n", str2);

    multiplication(str1, str2, len1, len2);

    return 0;
}

void swap(char * ptr, int len)
{
    char * dynamic = (char *) malloc(len);
    int i = 0;
    
    for(i=0;i<len;i++)
    {
        dynamic[i] = ptr[len-i-1];
    }

    for(i=0;i<len;i++)
    {
        ptr[i] = dynamic[i];
    }

    free(dynamic);
}


int length(char * ptr)
{   

    //ponieważ '\0' to znak końca stringu 
    unsigned int i = 0;
    while(ptr[i] != '\0')
    {
        i++;
    }

    return i;
}

void multiplication(char * str1, char *str2, int len1, int len2)
{
    int * result =  calloc(len1+len2+1,sizeof(int));
    int * val1 =  calloc(len1,sizeof(int)); //dłuższa
    int * val2 =  calloc(len2,sizeof(int)); //krótsza

    int new = 0;
    int i = 0;
    int temp = 0;

    int zera_x = 0;
    int zera_y = 0;

    int bigger;
    int smaller;


    for(i = 0; i<len2+len1;i++)
    {
        result[i] = 0;
    }

    
    for(i = 0; i<len1;i++)
    {
        val1[i] = (((int)str1[i]) - 48);
        printf("xxx %d",val1[i]);
    }
    printf("\n");
    for(i = 0; i<len2;i++)
    {
        val2[i] = (((int)str2[i]) - 48);
        printf("xxx %d",val2[i]);
    }
    printf("\n");
 

    if(len1 >= len2)
    {
        bigger = len1;
        smaller = len2;
    }
    else
    {
        bigger = len2;
        smaller = len1; 
    }



    //wieksza najpier potem mniejsza liczba
    for(zera_y=0;zera_y<smaller;zera_y++)
    {
        for(zera_x=0; zera_x < bigger; zera_x++)
        {
            temp = val1[zera_x] * val2[zera_y];
            printf("temp = %d \n",temp);

            //teraz sobie dodaje odpowiednio do komórek co i jak w senie mnożenie np 9*9 to 81
            for(i=0;i<2;i++)
            {
                new = temp % 10 + result[zera_x + zera_y + i];
                printf("new = %d \n",new);
                temp = temp / 10;
                printf("temp1 = %d \n",temp);
                result[zera_x + zera_y + i] = new;
                printf("result = %d \n",result[zera_x + zera_y + i]);
            }

            printf("result after = ");
            for(i=0;i<len1+len2;i++)
            {
                if(result[i] >= 10)
                {   
                    result[i+1] = (result[i] / 10) + result[i+1];
                    result[i] = result[i] % 10;
                    
                }
                printf("%d",result[len1+len2-1-i]);
            }

            printf("\n");
            
        }

        printf("\n------\n"); 
    } 

    for(i = len2+len1; i>=0;i--)
    {
        printf("%d",result[i]);
    }
    printf("\n------\n"); 
    free((int *)result);
    free((int *)val1);
    free((int *)val2);
}