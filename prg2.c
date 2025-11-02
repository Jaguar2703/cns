#include <stdio.h>
#include <string.h>
#include <ctype.h>

void monoalphabetic_encrypt(const char *plaintext, char *ciphertext, const char *key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        if (isupper((unsigned char)c))
            ciphertext[i] = key[c - 'A'];
        else if (islower((unsigned char)c))
            ciphertext[i] = tolower(key[c - 'a']);
        else
            ciphertext[i] = c;
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void monoalphabetic_decrypt(const char *ciphertext, char *plaintext, const char *key) {
    char reverse_key[26];
    for (int i = 0; i < 26; i++)
        reverse_key[key[i] - 'A'] = 'A' + i;

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        if (isupper((unsigned char)c))
            plaintext[i] = reverse_key[c - 'A'];
        else if (islower((unsigned char)c))
            plaintext[i] = tolower(reverse_key[toupper(c) - 'A']);
        else
            plaintext[i] = c;
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    const char plaintext[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    const char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    char ciphertext[256];
    char decrypted[256];

    printf("Plaintext:  %s\n", plaintext);
    printf("Key:        %s\n", key);

    monoalphabetic_encrypt(plaintext, ciphertext, key);
    printf("Encrypted:  %s\n", ciphertext);

    monoalphabetic_decrypt(ciphertext, decrypted, key);
    printf("Decrypted:  %s\n", decrypted);

    return 0;
}
