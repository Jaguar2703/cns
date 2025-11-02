#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 3  // Key matrix size (3x3)

int charToNum(char c) {
    return toupper(c) - 'A';
}

char numToChar(int n) {
    return (n % 26) + 'A';
}

void hillEncrypt(int key[SIZE][SIZE], int message[], int cipher[]) {
    for (int i = 0; i < SIZE; i++) {
        cipher[i] = 0;
        for (int j = 0; j < SIZE; j++)
            cipher[i] += key[i][j] * message[j];
        cipher[i] %= 26;
    }
}

int main() {
    int key[SIZE][SIZE];
    char text[100], cipherText[100];
    int message[SIZE], cipher[SIZE];

    printf("Enter 3x3 key matrix (only integers):\n");
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &key[i][j]);

    printf("Enter plaintext (A–Z letters only): ");
    scanf("%s", text);

    int len = strlen(text);
    for (int i = 0; i < len; i++)
        text[i] = toupper(text[i]);
    while (len % SIZE != 0)
        text[len++] = 'X';
    text[len] = '\0';

    printf("\nPlaintext: %s\n", text);

    int k = 0;
    for (int i = 0; i < len; i += SIZE) {
        for (int j = 0; j < SIZE; j++)
            message[j] = charToNum(text[i + j]);

        hillEncrypt(key, message, cipher);

        for (int j = 0; j < SIZE; j++)
            cipherText[k++] = numToChar(cipher[j]);
    }
    cipherText[k] = '\0';

    printf("Ciphertext: %s\n", cipherText);

    return 0;
}
