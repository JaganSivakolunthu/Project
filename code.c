#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
char d_arr[20];
char i_arr[20];
typedef struct dt{
    int b_id;		
    char b_nm[50];	
    char b_ar[50];	
    int b_cp;		
    struct dt *nxt;
} LD;
typedef struct issue{
	int bk_id;		
	int usr_id;		
	char usr_nm[40];
	char iss_dt[30];
	char due_dt[30];
	struct issue *nxt;
} ISS;
void add(LD **);
void add_book(LD **);
void print(LD **);
void add_iss(LD *, ISS **, struct tm *);
void iss_print(ISS **);
void update_book_details(LD **);
void up_b_id(LD **);
void up_b_nm(LD **);
void search_book(LD **);
void srch_b_id(LD **);
void srch_b_nm(LD **);
void srch_b_ar(LD **);
void search_menu_dp();
void remove_menu_dp();
void update_menu_dp();
void choice_menu_dp();
char* due_date(struct tm *);
char* issue_date(struct tm *);
int main()
{
    int opt;
    struct tm *a;
    time_t present = time(NULL);
    a = localtime(&present);
    LD *hptr = NULL;
    ISS *hp = NULL;
    while(1){
    choice_menu_dp();
    scanf("%d",&opt);
    switch(opt)
    {
	    case 1:	add(&hptr);	break;
	    case 2:	update_book_details(&hptr);	break;
	    //case 3:	
	    case 4:	search_book(&hptr);	break;
	    case 5:	print(&hptr);	break;
	    case 6:	add_iss(hptr,&hp,a);	break;
	    //case 7:
	    case 8:	iss_print(&hp);	break;
	    //case 9:
            //case 10:
	    default: puts("Invalid Choice!!!");
    }
    }
}
void add(LD **hp)
{
    char opt;
    do{
        add_book(hp);
        puts("Want to add one more data...(y/n)");
        scanf(" %c",&opt);
    }while(opt == 'y');
}
void add_book(LD **ptr)
{
    
    LD *p = (LD *)malloc(sizeof(LD));
    puts("Enter the book data(_id,_name,_arthor,_copies,_status)...");
    scanf("%d%s%s%d",&p->b_id,p->b_nm,p->b_ar,&p->b_cp);
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
        printf("%d %s %s %d \n",p->b_id,p->b_nm,p->b_ar,p->b_cp);
        p = p->nxt;
    }
}
void add_iss(LD *p,ISS **ptr, struct tm *a)
{
	LD *pt = p;
	ISS *temp = (ISS *)malloc(sizeof(ISS));
	puts("Enter the data for issuinng the book(bk_id,ur_id,ur_nm,iss_dt,due_dt)......");
	scanf("%d%d%s",&temp->bk_id,&temp->usr_id,temp->usr_nm);
	strcpy(temp->iss_dt,issue_date(a));	
	strcpy(temp->due_dt,due_date(a));
	while(p)
	{
		if((temp->bk_id)==(p->b_id)){
		   	p->b_cp = p->b_cp - 1;
		   	printf("Remaining Copies is %d\n",p->b_cp);
		    break;
		}
		p = p->nxt;
	}
	p=pt;
	temp->nxt = NULL;
	if(*ptr == NULL)	*ptr = temp;
	else{
		ISS *last = *ptr;
		while(last->nxt)	last = last->nxt;
		last->nxt = temp;
	}
}
void iss_print(ISS **ptr)
{
	ISS *p = *ptr;
	puts("Displaying the Issued book list...");
	while(p){
		printf("%d %d %s %s %s\n",p->bk_id,p->usr_id,p->usr_nm,p->iss_dt,p->due_dt);
		p=p->nxt;
	}
}
char* due_date(struct tm *a)
{
        a->tm_mday+=7;
        mktime(a);
        sprintf(d_arr,"%d-%d-%d",a->tm_mday,a->tm_mon+1,a->tm_year+1900);
	return d_arr;
}
char* issue_date(struct tm *a)
{
        puts("THE TIME IS....");
        sprintf(i_arr,"%d-%d-%d",a->tm_mday,a->tm_mon+1,a->tm_year+1900);
	return i_arr;
}
void update_book_details(LD **ptr)
{
	int opt;
	update_menu_dp();
	scanf("%d",&opt);
	switch(opt)
	{
		case 1: up_b_id(ptr);	break;
		case 2: up_b_nm(ptr);	break;
		//case 3: 
		default : puts("Invalid Choice");	
	}
}
void up_b_id(LD **ptr)
{
	LD *p = *ptr;
	int id ;
	puts("Enter the Book_ID to modify the details....");
	scanf("%d",&id);
	while(p){
		if((p->b_id) == id)
		{
			puts("Enter the details for modification(b_nm,b_ar,b_cp)...");
			scanf("%s%s%d",p->b_nm,p->b_ar,&p->b_cp);
		}
		p = p->nxt;
	}
}
void up_b_nm(LD **ptr)
{
	LD *p = *ptr;
	char b_n[20] ;
	puts("Enter the Book_Name to modify the details....");
	scanf("%s",b_n);
	while(p){
		if(strcmp((p->b_nm),(b_n)) == 0)
		{
			puts("Enter the details for modification(b_nm,b_ar,b_cp)...");
			scanf("%s%s%d",p->b_nm,p->b_ar,&p->b_cp);
		}
		p = p->nxt;
	}
}
void search_book(LD **ptr)
{
	int opt;
	search_menu_dp();
	scanf("%d",&opt);
	switch(opt)
	{
		case 1: srch_b_id(ptr);	break;
		case 2:	srch_b_nm(ptr);	break;
		case 3: srch_b_ar(ptr);	break;
		//case 4: 
		default: puts("Invalid Choice");
	}
}
void srch_b_id(LD **ptr)
{
	LD *p = *ptr;
        int id;
	puts("Enter the ID which is to be searched...");	
	scanf("%d",&id);
	while(p)
	{
		if(id == (p->b_id))
			printf("%d %s %s %d\n",p->b_id,p->b_nm,p->b_ar,p->b_cp);
		p = p->nxt;
	}
}
void srch_b_nm(LD **ptr)
{
	LD *p = *ptr;
        char arr[50];
	puts("Enter the book name which is to be searched...");	
	scanf("%s",arr);
	while(p)
	{
		if(strcmp(arr,p->b_nm)==0)
			printf("%d %s %s %d\n",p->b_id,p->b_nm,p->b_ar,p->b_cp);
		p = p->nxt;
	}
}
void srch_b_ar(LD **ptr)
{
	LD *p = *ptr;
        char arr[50];
	puts("Enter the book name which is to be searched...");	
	scanf("%s",arr);
	while(p)
	{
		if(strcmp(arr,p->b_ar)==0)
			printf("%d %s %s %d\n",p->b_id,p->b_nm,p->b_ar,p->b_cp);
		p = p->nxt;
	}
}
void choice_menu_dp(void)
{
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("| ***** BOOK MANAGEMENT MENU ***** |\n");
    printf("|__________________________________|\n");
    printf("| 1. Add New Book                  |\n");
    printf("| 2. Update Book Details           |\n");
    printf("| 3. Remove Book                   |\n");
    printf("| 4. Search Book                   |\n");
    printf("| 5. View All Books                |\n");
    printf("| 6. Issue Book                    |\n");
    printf("| 7. Return Book                   |\n");
    printf("| 8. List Issued Books             |\n");
    printf("| 9. Save                          |\n");
    printf("| 10. Exit                         |\n");
    printf("|    Enter the choice option :     |\n");
    printf("|__________________________________|\n");
}
void update_menu_dp(void)
{
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("| ***** UPDATE BOOK DETAILS  ***** |\n");
    printf("|__________________________________|\n");
    printf("| 1. By Book_ID                    |\n");
    printf("| 2. By Book Name                  |\n");
    printf("| 3. Back To Main Menu             |\n");
    printf("|    Enter the choice option :     |\n");
    printf("|__________________________________|\n");
}
void remove_menu_dp(void)
{
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("| ***** REMOVE BOOK DETAILS  ***** |\n");
    printf("|__________________________________|\n");
    printf("| 1. By Book_ID                    |\n");
    printf("| 2. By Book Name                  |\n");
    printf("| 3. Back To Main Menu             |\n");
    printf("|    Enter the choice option :     |\n");
    printf("|__________________________________|\n");
}
void search_menu_dp(void)
{
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("| ***** SEARCH BOOK DETAILS  ***** |\n");
    printf("|__________________________________|\n");
    printf("| 1. By Book_ID                    |\n");
    printf("| 2. By Book Name                  |\n");
    printf("| 3. By Author Name                |\n");
    printf("| 4. Back To Main Menu             |\n");
    printf("|    Enter the choice option :     |\n");
    printf("|__________________________________|\n");
}

