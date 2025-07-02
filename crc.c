#include <stdio.h>
#include <string.h>
#define N strlen(poly)
char data[28];
char check[28];
char poly[10];
int data_len, i, j;

void crc()
{
    for (i = 0; i < N; i++)
        check[i] = data[i];
    do
    {
        if (check[0] == '1')
            xor();
        for (j = 0; j < N - 1; j++)
            check[j] = check[j + 1];
        check[j] = data[i++];
    } while (i <= data_len + N - 1);
}

void xor () {
    for (j = 1; j < N; j++)
        check[j] = ((check[j] == poly[j]) ? '0' : '1');
}

    void recieved()
{
    printf("\nEnter the reciever data: ");
    scanf("%s", data);
    printf("\nData received: %s", data);
    crc();
    for (i = 0; (i < N - 1) && (check[i] != '1'); i++)
        ;
    if (i < N - 1)
        printf("\nError present\n");
    else
        printf("\nNo error present\n");
}

int main()
{
    printf("\n Enter data to be transmitted: ");
    scanf("%s", data);
    printf("\n Enter the polynomial R-bit: ");
    scanf("%s", poly);
    data_len = strlen(data);
    for (i = data_len; i < data_len + N - 1; i++)
        data[i] = '0';
    printf("\n Data loaded with n-1 zeros: %s", data);
    crc();
    printf("\n Check value is: %s", check);
    for (i = data_len; i < data_len + N - 1; i++)
        data[i] = check[i - data_len];
    printf("\n Final data to be sent : %s", data);
    recieved();
    return 0;
}