#include <stdio.h>

#define MAX 256

extern int freq[2*MAX];
int left[2*MAX], right[2*MAX];

int buildTree()
{
    int nodes[MAX];
    int n=0;

    for(int i=0;i<MAX;i++)
        if(freq[i]>0)
            nodes[n++]=i;

    int next=MAX;

    while(n>1)
    {
        int m1=0,m2=1;

        if(freq[nodes[m2]] < freq[nodes[m1]])
        {
            int t=m1;
            m1=m2;
            m2=t;
        }

        for(int i=2;i<n;i++)
        {
            if(freq[nodes[i]] < freq[nodes[m1]])
            {
                m2=m1;
                m1=i;
            }
            else if(freq[nodes[i]] < freq[nodes[m2]])
            {
                m2=i;
            }
        }

        int newNode=next++;

        freq[newNode]=freq[nodes[m1]]+freq[nodes[m2]];

        left[newNode]=nodes[m1];
        right[newNode]=nodes[m2];

        nodes[m1]=newNode;
        nodes[m2]=nodes[n-1];

        n--;
    }

    return nodes[0];
}