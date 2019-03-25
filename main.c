#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int data;
    int order;
    struct LNode*next;
}LNode;
int main()
{
    struct LNode *pa,*pb,*head;
    head=(struct LNode*)malloc(sizeof(LNode));
    pa=head;
    int i,m,n;
    printf("输入人数n和上限m\n");
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        int k=0;
        printf("请依次输入每个人的密码\n");
        scanf("%d",&k);
        pa->next=(struct LNode*)malloc(sizeof(LNode));
        pa=pa->next;
        pa->data=k;
        pa->order=i;
    }
    pa->next=head->next;
    pa=head->next;
    free(head);
    while(pa->next!=pa)
    {
        for(i=1;i<m;i++)
        {
            pb=pa;
            pa=pa->next;
        }
        printf("%d->",pa->order);
        m=pa->data;
        pb->next=pa->next;
        free(pa);
        pa=pb->next;
    }
    printf("%d\n",pa->order);
}
