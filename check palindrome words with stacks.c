#include <stdio.h>
#include <stdlib.h>

/**         check palindrome words with stacks        **/

int i = 0;

struct node
{
    char x;
    struct node *next;
    struct node *prev;
};
typedef struct node ls;
ls *head = NULL;

void check_pal()
{
    system("cls");
    char pal[100], check[100] = {0};
    printf("Enter a string: ");
    scanf("%s", pal);
    for(int j = 0; j<strlen(pal); j++){
        push(pal[j]);
    }
    for(int j = 0; j < strlen(pal); j++){
        check[j] = pop();
    }
    if(!strcmp(pal, check)){
        printf("This word is a palindrome.");
    }
    else printf("Not palindrome.");
}

ls *add_end(int data, ls* head)
{
    ls *ptr = malloc(sizeof(ls));
    ptr -> x = data;
    ptr -> next = NULL;
    ptr -> prev = head;
    head = ptr;
    return head;
}

ls *create_ls(int data, ls *head)
{
    head = malloc(sizeof(ls));
    head -> x = data;
    head -> prev = NULL;
    head -> next = NULL;
    return head;
}

void push(char ch)
{
    system("cls");
    int data;
    if(i == 0){
        head = create_ls(ch, head);
        ++i;
    }
    else{
        head = add_end(ch, head);
    }
}

int pop()
{
    char p = head -> x;
    ls *del = head;
    head = head -> prev;
    free(del);  del = NULL;
    return p;
}

int main()
{
    int ch = 1;
    while(ch == 1)
    {
        check_pal();
        printf("\nTry another word? ");
        scanf("%d", &ch);
    }

}
