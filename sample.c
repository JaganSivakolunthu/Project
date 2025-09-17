#include<stdio.h>
#include<stdlib.h>
typedef struct dt{
    int b_id;
    char b_nm[50];
    char b_ar[50];
    int b_cp;
    char b_st[25];
    struct dt *nxt;
} LD;
void add_book(LD **);
void print(LD **);
int main()
{
    char opt;
    LD *hptr = NULL;
    do{
        add_book(&hptr);
        puts("Want to add one more data...(y/n)");
        scanf(" %c",&opt);
    }while(opt == 'y');
    print(&hptr);
}
void add_book(LD **ptr)
{
    //LD *p = *ptr;
    LD *p = (LD *)malloc(sizeof(LD));
    puts("Enter thebook data...");
    scanf("%d%s%s%d%s",&p->b_id,p->b_nm,p->b_ar,&p->b_cp,p->b_st);
    p->nxt = NULL;
    if(*ptr == NULL)    *ptr = p;
    else{
        LD *last = *ptr;
        while(last->nxt)    last = last->nxt;
        last->nxt = p;
    }
}
void print(LD **ptr)
{
    LD *p = *ptr;
    puts("Displaying the data...,");
    while(p)
    {
        printf("%d %s %s %d %s \n",p->b_id,p->b_nm,p->b_ar,p->b_cp,p->b_st);
        p = p->nxt;
    }
}
