
void delete(int i,list *ptrl)
{
    int j;
    if(i<1||i>ptrl->last+1)
    {
        printf("������%d��Ԫ��\n",i);
    }
    for(j=i;j<=ptrl->last;j++)
    {
        ptrl->data[j-1]=ptrl->data[j];
    }
    ptrl->last--;
}
