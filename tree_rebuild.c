#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int ch;
    int freq;
    struct Node *left,*right;
} Node;

Node* create(int,int);

Node* build(Node* arr[],int n)
{
    while(n>1)
    {
        int m1=0,m2=1;

        if(arr[m2]->freq < arr[m1]->freq)
        {
            int t=m1;
            m1=m2;
            m2=t;
        }

        for(int i=2;i<n;i++)
        {
            if(arr[i]->freq < arr[m1]->freq)
            {
                m2=m1;
                m1=i;
            }
            else if(arr[i]->freq < arr[m2]->freq)
            {
                m2=i;
            }
        }

        Node* p=create(-1,arr[m1]->freq+arr[m2]->freq);

        p->left=arr[m1];
        p->right=arr[m2];

        arr[m1]=p;
        arr[m2]=arr[n-1];

        n--;
    }

    return arr[0];
}