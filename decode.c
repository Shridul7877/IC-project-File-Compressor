#include <stdio.h>

#define MAX 256

typedef struct Node
{
    int ch;
    int freq;
    struct Node *left,*right;
} Node;

void decodeFile(FILE *in, FILE *out, Node *root, int freq[])
{
    int total=0;

    for(int i=0;i<MAX;i++)
        total+=freq[i];

    Node *current=root;
    unsigned char byte;

    while(total>0 && fread(&byte,1,1,in))
    {
        for(int i=7;i>=0;i--)
        {
            int bit=(byte>>i)&1;

            if(bit==0)
                current=current->left;
            else
                current=current->right;

            if(current->left==NULL && current->right==NULL)
            {
                fputc(current->ch,out);
                current=root;
                total--;

                if(total==0)
                    break;
            }
        }
    }
}