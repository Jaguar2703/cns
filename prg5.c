#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateKey(const char *key, char *newKey, int textLen) {
    int keyLen = strlen(key);
    for (int i = 0; i < textLen; i++)
        newKey[i] = tolower(key[i % keyLen]);
    newKey[textLen] = '\0';
}


void encrypt(const char *plaintext, const char *key, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char p = tolower(plaintext[i]);
        if (p >= 'a' && p <= 'z') {
            ciphertext[i] = ((p - 'a') + (tolower(key[i]) - 'a')) % 26 + 'a';
        } else {
            ciphertext[i] = p;
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}


void decrypt(const char *ciphertext, const char *key, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = tolower(ciphertext[i]);
        if (c >= 'a' && c <= 'z') {
            plaintext[i] = ((c - 'a') - (tolower(key[i]) - 'a') + 26) % 26 + 'a';
        } else {
            plaintext[i] = c;
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char plaintext[] = "wearediscoveredsaveyourself";
    char key[] = "deceptive";
    char newKey[256], ciphertext[256], decrypted[256];

    generateKey(key, newKey, strlen(plaintext));

    encrypt(plaintext, newKey, ciphertext);
    decrypt(ciphertext, newKey, decrypted);

    printf("Plaintext : %s\n", plaintext);
    printf("Key       : %s\n", key);
    printf("Generated Key: %s\n", newKey);
    printf("Encrypted : %s\n", ciphertext);
    printf("Decrypted : %s\n", decrypted);

    return 0;
}
