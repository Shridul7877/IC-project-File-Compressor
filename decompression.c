#include <stdio.h>
#include <stdlib.h>

#define MAX 256

typedef struct Node
{
    int ch;
    int freq;
    struct Node *left,*right;
} Node;

Node* create(int,int);
Node* build(Node*[],int);
void decodeFile(FILE*,FILE*,Node*,int[]);

int main()
{
    FILE *in=fopen("compressed.bin","rb");
    FILE *out=fopen("output.txt","w");

    if(!in || !out)
    {
        printf("File error\n");
        return 0;
    }

    int freq[MAX];

    fread(freq,sizeof(int),MAX,in);

    Node* arr[MAX];
    int n=0;

    for(int i=0;i<MAX;i++)
        if(freq[i]>0)
            arr[n++]=create(i,freq[i]);

    Node* root=build(arr,n);

    decodeFile(in,out,root,freq);

    fclose(in);
    fclose(out);

    printf("Decompression complete → output.txt\n");

    return 0;
}