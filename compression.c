#include <stdio.h>

#define MAX 256

extern int freq[2*MAX];
extern int left[2*MAX];
extern int right[2*MAX];

FILE* openInput();
FILE* openOutput();
void countFrequency(FILE*);
void writeFrequency(FILE*);
int buildTree();
void generate(int,char[],int);
void compressFile(FILE*,FILE*);

int main()
{
    FILE *in=openInput();
    FILE *out=openOutput();

    if(!in || !out)
        return 0;

    countFrequency(in);
    writeFrequency(out);

    for(int i=0;i<512;i++)
    {
        left[i]=-1;
        right[i]=-1;
    }

    int root=buildTree();

    char temp[256];
    generate(root,temp,0);

    rewind(in);

    compressFile(in,out);

    fclose(in);
    fclose(out);

    printf("Compression complete → compressed.bin\n");

    return 0;
}