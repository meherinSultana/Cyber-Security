#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void generateKey(char key[ALPHABET_SIZE]);
void encrypt(const char *plaintext, const char key[ALPHABET_SIZE], char *ciphertext);

int main()
{
    char key[ALPHABET_SIZE];
    char plaintext[100];
    char ciphertext[100];
    generateKey(key);
    printf("Enter Plaintext: ");

    fgets(plaintext, sizeof(plaintext), stdin);
    if (strlen(plaintext)> 0 && plaintext[strlen(plaintext) - 1] == '\n')
    {
        plaintext[strlen(plaintext) - 1] = '\0';
    }
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    return 0;
}

void generateKey(char key[ALPHABET_SIZE])
{
    char alphabet[ALPHABET_SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, j, temp;
    for (i = ALPHABET_SIZE - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        srand( time(0));
        temp = alphabet[i];
        alphabet[i] = alphabet[j];
        alphabet[j] = temp;
    }

    strcpy(key, alphabet);
}

void encrypt(const char* plaintext, const char key[ALPHABET_SIZE], char* ciphertext)
{
    int i;
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char originalChar = toupper(plaintext[i]);
            int index = originalChar - 'A';
            char encryptedChar = (plaintext[i]) ? key[index] : tolower(key[index]);
            ciphertext[i] = encryptedChar;
        }
        else
        {
            ciphertext[i] = 'X';
        }
    }
    ciphertext[i] = '\0';
}
