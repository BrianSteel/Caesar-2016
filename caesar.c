#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PLAIN_TEX_LEN 80

int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: ./caeser [integer]\n");
        return 1;
    }

    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Give me a positive integer. \n");
        return 2;
    }
    char plaintext[MAX_PLAIN_TEX_LEN];
    printf("Enter plain text:`");
    scanf("%[^\n]%*c", plaintext);
    printf("ciphertext: ");
    if (strlen(plaintext) > 0 && strlen(plaintext) <= 80)
    {
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (islower(plaintext[i]))
            {
                printf("%c", (plaintext[i] - 'a' + key) % 26 + 'a');
            }
            else if (isupper(plaintext[i]))
            {
                printf("%c", (plaintext[i] - 'A' + key) % 26 + 'A');
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
    }
    printf("\n");
    return 0;
}