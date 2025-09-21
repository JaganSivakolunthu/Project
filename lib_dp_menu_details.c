#include<stdio.h>
void choice_menu_dp(void)
{
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("| ***** BOOK MANAGEMENT MENU ***** |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
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
    printf("|                                  |\n");
    printf("|    Enter the choice option :     |\n");
    printf("|__________________________________|\n");
}
void update_menu_dp(void)
{
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("| ***** UPDATE BOOK DETAILS  ***** |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("| 1. By Book_ID                    |\n");
    printf("| 2. By Book Name                  |\n");
    printf("| 3. Back To Main Menu             |\n");
    printf("|                                  |\n");
    printf("|    Enter the choice option :     |\n");
    printf("|__________________________________|\n");
}
void remove_menu_dp(void)
{
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("| ***** REMOVE BOOK DETAILS  ***** |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("| 1. By Book_ID                    |\n");
    printf("| 2. By Book Name                  |\n");
    printf("| 3. Back To Main Menu             |\n");
    printf("|                                  |\n");
    printf("|    Enter the choice option :     |\n");
    printf("|__________________________________|\n");
}
void search_menu_dp(void)
{
    printf(" __________________________________\n");
    printf("|                                  |\n");
    printf("| ***** SEARCH BOOK DETAILS  ***** |\n");
    printf("|__________________________________|\n");
    printf("|                                  |\n");
    printf("| 1. By Book_ID                    |\n");
    printf("| 2. By Book Name                  |\n");
    printf("| 3. By Author Name                |\n");
    printf("| 4. Back To Main Menu             |\n");
    printf("|                                  |\n");
    printf("|    Enter the choice option :     |\n");
    printf("|__________________________________|\n");
}
int main()
{
	search_menu_dp();
	remove_menu_dp();
	update_menu_dp();
	choice_menu_dp();
}

