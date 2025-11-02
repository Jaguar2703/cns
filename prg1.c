#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesar_encrypt(const char *plaintext, char *ciphertext, int shift) {
    size_t n = strlen(plaintext);
    for (size_t i = 0; i < n; ++i) {
        char c = plaintext[i];
        if (isupper((unsigned char)c)) {
            ciphertext[i] = (char)((((c - 'A') + shift) % 26 + 26) % 26 + 'A');
        } else if (islower((unsigned char)c)) {
            ciphertext[i] = (char)((((c - 'a') + shift) % 26 + 26) % 26 + 'a');
        } else {
            ciphertext[i] = c;
        }
    }
    ciphertext[n] = '\0';
}

void caesar_decrypt(const char *ciphertext, char *plaintext, int shift) {
    caesar_encrypt(ciphertext, plaintext, -shift);
}

int main(void) {
    const char sample[] = "hello how are u";
    int key = 3;

    char encrypted[256];
    char decrypted[256];
    char wrapped[256];

    printf("Plaintext:  \"%s\"\n", sample);
    printf("Key (shift): %d\n", key);

    caesar_encrypt(sample, encrypted, key);
    printf("Encrypted:  \"%s\"\n", encrypted);

    caesar_decrypt(encrypted, decrypted, key);
    printf("Decrypted:  \"%s\"\n", decrypted);

    caesar_encrypt(sample, wrapped, key + 26);
    printf("\n(Shift +26) Encrypted with key+26: \"%s\"\n", wrapped);

    return 0;
}
