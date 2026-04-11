#include <stdio.h>

#define MAX 256

extern int left[2*MAX];
extern int right[2*MAX];

char code[2*MAX][MAX];

void generate(int node,char temp[],int depth)
{
    if(left[node]==-1 && right[node]==-1)
    {
        temp[depth]='\0';

        int i=0;
        while(temp[i])
        {
            code[node][i]=temp[i];
            i++;
        }

        code[node][i]='\0';
        return;
    }

    if(left[node]!=-1)
    {
        temp[depth]='0';
        generate(left[node],temp,depth+1);
    }

    if(right[node]!=-1)
    {
        temp[depth]='1';
        generate(right[node],temp,depth+1);
    }
}

void compressFile(FILE *in,FILE *out)
{
    int c;
    unsigned char buffer=0;
    int bits=0;

    while((c=fgetc(in))!=EOF)
    {
        char *str=code[c];

        for(int i=0;str[i];i++)
        {
            buffer <<=1;

            if(str[i]=='1')
                buffer |=1;

            bits++;

            if(bits==8)
            {
                fputc(buffer,out);
                buffer=0;
                bits=0;
            }
        }
    }

    if(bits>0)
    {
        buffer <<= (8-bits);
        fputc(buffer,out);
    }
}