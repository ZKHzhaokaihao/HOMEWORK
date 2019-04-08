#include<stdio.h>
#define maxlen 100
struct node{
   int data[maxlen];
   int top;
}s;

int n;

void initstack()
{
    s.top=-1;
}

void push(int q)
{
    s.top++;
    s.data[s.top]=q;
}

int pop()
{
    int t;
    t=s.data[s.top];
    s.top--;
    return t;
}

int ifempty()
{
    if(s.top==-1)
        return 1;
    else
        return 0;
}

void process(int pos,int path[],int curp)
{
    int m,i;
    if(pos<n)
    {
        push(pos+1);
        process(pos+1,path,curp);
        pop();
    }
    if(!ifempty())
    {
        m=pop();
        path[curp]=m;
        curp++;
        process(pos,path,curp);
        push(m);
    }
    if(pos==n&&ifempty())
    {
        for(i=0;i<curp;i++)
            printf("%2d",path[i]);
        printf("\n");
    }
}

void main()
{
    int path[maxlen];
    printf("请输入车厢数:");
    scanf("%d",&n);
    initstack();
    push(1);
    printf("所有输出序列:\n");
    process(1,path,0);
}
