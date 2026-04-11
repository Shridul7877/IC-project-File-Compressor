#include <stdlib.h>

typedef struct Node
{
    int ch;
    int freq;
    struct Node *left,*right;
} Node;

Node* create(int ch,int freq)
{
    Node* n=(Node*)malloc(sizeof(Node));

    n->ch=ch;
    n->freq=freq;
    n->left=NULL;
    n->right=NULL;

    return n;
}