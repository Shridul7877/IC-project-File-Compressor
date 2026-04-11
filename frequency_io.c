#include <stdio.h>

#define MAX 256

int freq[2*MAX];

FILE* openInput()
{
    FILE *in=fopen("input.txt","rb");

    if(!in)
        printf("Error opening input.txt\n");

    return in;
}

FILE* openOutput()
{
    FILE *out=fopen("compressed.bin","wb");

    if(!out)
        printf("Error creating compressed.bin\n");

    return out;
}

void countFrequency(FILE *in)
{
    int c;

    for(int i=0;i<2*MAX;i++)
        freq[i]=0;

    while((c=fgetc(in))!=EOF)
        freq[c]++;
}

void writeFrequency(FILE *out)
{
    fwrite(freq,sizeof(int),MAX,out);
}