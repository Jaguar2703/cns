#include <stdio.h>
#include <math.h>

long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();

int main() {
    printf("Enter first prime number: ");
    scanf("%ld", &p);
    if (!prime(p)) {
        printf("First number is not prime.\n");
        return 0;
    }

    printf("Enter second prime number: ");
    scanf("%ld", &q);
    if (!prime(q) || p == q) {
        printf("Second number is not prime or same as first.\n");
        return 0;
    }

    printf("Enter message to encrypt: ");
    scanf(" %[^\n]", msg);

    n = p * q;
    t = (p - 1) * (q - 1);
    ce();

    printf("\nPossible values of e and d are:\n");
    for (i = 0; i < j - 1; i++)
        printf("%ld\t%ld\n", e[i], d[i]);

    encrypt();
    decrypt();

    return 0;
}

int prime(long int pr) {
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
        if (pr % i == 0)
            return 0;
    return 1;
}

void ce() {
    int k;
    k = 0;
    for (i = 2; i < t; i++) {
        if (t % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q) {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0) {
                d[k] = flag;
                k++;
            }
        }
        if (k == 99)
            break;
    }
    j = k;
}

long int cd(long int x) {
    long int k = 1;
    while (1) {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

void encrypt() {
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = 0;
    while (msg[i] != '\0') {
        m[i] = msg[i];
        i++;
        len++;
    }

    printf("\nEncrypted message:\n");
    for (i = 0; i < len; i++) {
        pt = m[i] - 96;
        k = 1;
        for (j = 0; j < key; j++)
            k = (k * pt) % n;
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        printf("%c", en[i]);
    }
    en[i] = -1;
}

void decrypt() {
    long int pt, ct, key = d[0], k;
    i = 0;
    printf("\n\nDecrypted message:\n");
    while (en[i] != -1) {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
            k = (k * ct) % n;
        pt = k + 96;
        printf("%c", pt);
        i++;
    }
    printf("\n");
}
