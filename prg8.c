#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    unsigned char key[16] = "0123456789abcdef";
    unsigned char in[] = "welcome to ISE";
    unsigned char enc_out[128], dec_out[128];

    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_encrypt(in, enc_out, &enc_key);

    AES_set_decrypt_key(key, 128, &dec_key);
    AES_decrypt(enc_out, dec_out, &dec_key);
    dec_out[15] = '\0';

    printf("Original: %s\n", in);
    printf("Encrypted: ");
    for (int i = 0; i < 16; i++) printf("%02x", enc_out[i]);
    printf("\nDecrypted: %s\n", dec_out);
    return 0;
}
