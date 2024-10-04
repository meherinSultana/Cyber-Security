#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encr(const char* plaintext, const char* key, char* ciphertext);
void createPermutationIndices(const char* key, int* in, int length);

int main()
{
    char key[100];
    char plaintext[100];
    char ciphertext[100];

    printf("Enter Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    if (strlen(plaintext)> 0 && plaintext[strlen(plaintext) - 1] == '\n')
    {
        plaintext[strlen(plaintext)- 1] = '\0';
    }
    printf("Enter the key:");
    fgets(key, sizeof(key), stdin);

    if (strlen(key)>0 && key[strlen(key) -1] == '\n')
    {
        key[strlen(key) - 1] = '\0';
    }
    encr(plaintext, key, ciphertext);
    printf("Cipher Text: %s\n", ciphertext);
    return 0;
}

void encr(const char* plaintext, const char* key, char* ciphertext)
{
    int i, row, col;
    int index = 0;
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);

    int numRows = (textLength + keyLength - 1) / keyLength;

    int in[keyLength];


    createPermutationIndices(key, in, keyLength);


    for(i =0; i < textLength; i++)
    {
        ciphertext[i] = 'X';


    }
    ciphertext[textLength] = '\0';
     createPermutationIndices(key, in, keyLength);

    for(row =0; row < numRows; row++)
    {
        for(col= 0; col < keyLength; col++)
        {
            int position = row + in[col] * numRows;
            if (position < textLength)
            {
                ciphertext[index++] = plaintext[position];
            }

        }

    }
}

void createPermutationIndices(const char* key, int* in, int length)
{
    for (int i = 0; i < length; i++)
    {
        in[i] = i;
    }

    for (int i =0; i < length-1; i++)
    {
        for (int j= i+1; j < length; j++)
        {
            if(key[in[i]] > key[in[j]])
            {
                int te = in[i];
                in[i]= in[j];
                in[j]= te;

            }

        }
    }
}
