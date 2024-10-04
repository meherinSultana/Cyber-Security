#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


void encr(const char* plaintext, const char* key, char* ciphertext);

int main()
{
    char key[100];
    char plaintext[100];
    char ciphertext[100];

    printf("Enter Plaintext: ");

    fgets(plaintext, sizeof(plaintext), stdin);
    if (strlen(plaintext)> 0 && plaintext[strlen(plaintext) - 1] == '\n')
    {
        plaintext[strlen(plaintext) - 1] = '\0';
    }
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    if (strlen(key) > 0 && key[strlen(key) - 1] == '\n')
    {
        key[strlen(key) - 1] = '\0';
    }
    encr(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    return 0;
}

void encr(const char* plaintext, const char* key, char* ciphertext)
{
    int i, j;
    int keyLength = strlen(key);
    for (i = 0, j = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char shift = isupper(key[j]) ? 'A' : 'a';
            ciphertext[i] = ((plaintext[i] + key[j] - 2 * shift) % 26) + shift;
            j = (j + 1) % keyLength;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}
