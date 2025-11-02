#include <stdio.h>
#include <math.h>

long long int power(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    for (long long int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

int main() {
    long long int p, g, a, b;
    long long int A, B;
    long long int secretA, secretB;

    printf("Enter a prime number (p): ");
    scanf("%lld", &p);
    printf("Enter a primitive root of %lld (g): ", p);
    scanf("%lld", &g);
    printf("Enter private key for Client (a): ");
    scanf("%lld", &a);
    printf("Enter private key for Server (b): ");
    scanf("%lld", &b);

    A = power(g, a, p);
    B = power(g, b, p);

    printf("\nClient sends public key A = %lld to Server", A);
    printf("\nServer sends public key B = %lld to Client", B);

    secretA = power(B, a, p);
    secretB = power(A, b, p);

    printf("\n\nShared secret key computed by Client: %lld", secretA);
    printf("\nShared secret key computed by Server: %lld", secretB);

    if (secretA == secretB)
        printf("\n\nSecure channel established successfully!");
    else
        printf("\n\nKey mismatch! Secure channel setup failed.");

    printf("\n");
    return 0;
}
