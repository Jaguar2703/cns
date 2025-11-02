#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void keyMatrix(char *key, char m[SIZE][SIZE]) {
    int used[26] = {0}, k = 0;
    used['J' - 'A'] = 1;
    for (int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if (c<'A'||c>'Z') continue;
        if (c=='J') c='I';
        if (!used[c-'A']) m[k/SIZE][k%SIZE]=c, used[c-'A']=1, k++;
    }
    for (char c='A'; c<='Z'; c++)
        if (!used[c-'A']) m[k/SIZE][k%SIZE]=c, k++;
}

void findPos(char m[SIZE][SIZE], char c, int *r, int *c1) {
    if (c=='J') c='I';
    for (int i=0;i<SIZE;i++)
        for (int j=0;j<SIZE;j++)
            if (m[i][j]==c){*r=i;*c1=j;return;}
}

void formatText(char *t) {
    int k=0; char res[256];
    for(int i=0;t[i];i++){
        char c=toupper(t[i]);
        if(c<'A'||c>'Z')continue;
        if(c=='J')c='I';
        res[k++]=c;
        if(i+1<strlen(t)&&c==toupper(t[i+1]))res[k++]='X';
    }
    if(k%2)res[k++]='X';
    res[k]='\0';
    strcpy(t,res);
}

void encrypt(char *p, char m[SIZE][SIZE], char *out, int dec) {
    for (int i=0;i<strlen(p);i+=2){
        int r1,c1,r2,c2;
        findPos(m,p[i],&r1,&c1);
        findPos(m,p[i+1],&r2,&c2);
        if(r1==r2){
            out[i]=m[r1][(c1+dec+SIZE)%SIZE];
            out[i+1]=m[r2][(c2+dec+SIZE)%SIZE];
        }else if(c1==c2){
            out[i]=m[(r1+dec+SIZE)%SIZE][c1];
            out[i+1]=m[(r2+dec+SIZE)%SIZE][c2];
        }else{
            out[i]=m[r1][c2];
            out[i+1]=m[r2][c1];
        }
    }
    out[strlen(p)]='\0';
}

int main(){
    char key[100], text[256], m[SIZE][SIZE], enc[256], dec[256];
    printf("Enter key: "); fgets(key,100,stdin); key[strcspn(key,"\n")]=0;
    printf("Enter message: "); fgets(text,256,stdin); text[strcspn(text,"\n")]=0;

    keyMatrix(key,m);
    formatText(text);
    encrypt(text,m,enc,1);
    encrypt(enc,m,dec,-1);

    printf("\nKey Matrix:\n");
    for(int i=0;i<SIZE;i++){for(int j=0;j<SIZE;j++)printf("%c ",m[i][j]);printf("\n");}
    printf("\nFormatted: %s\nEncrypted: %s\nDecrypted: %s\n",text,enc,dec);
}
