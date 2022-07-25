#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

int i = 0;

struct node
{
    char x;
    struct node *next;
    struct node *prev;
};
typedef struct node ls;
ls *head = NULL;

int isEmpty()
{
    if(!head){
        return 1;
    }
    return 0;
}

int match(int a, int b)
{
    if(a == '(' && b == ')')
        return 1;
    if(a == '[' && b == ']')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    return 0;
}

void check_bal()
{
    system("cls");
    char exp[MAX];
    char checkb;
    int valid;

    printf("Enter an expression: ");
    fflush(stdin);
    gets(exp);

    for(int j = 0; j<strlen(exp); j++){
        if( (exp[j] == '(') || (exp[j] == '[') || (exp[j] == '{') ){
            push(exp[j]);
        }
        if((exp[j] == ')') || (exp[j] == ']') || (exp[j] == '}')){
            if(isEmpty()){
                printf("Left brackets are more than right brackets. ");
                return;
            }
            checkb = pop();
            if(!match(checkb, exp[j])){
                printf("Mismatch. --> ");
                printf("%c %c", checkb, exp[j]);
                return;
            }
        }
    }
    if(isEmpty(head)){
        printf("Brackets are balanced.");
    }
    else{
        printf("Invalid expression.");
        free(head); head = NULL;
    }
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
    //system("cls");
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
        check_bal();
        printf("\nTry another word? ");
        scanf("%d", &ch);
    }

}
