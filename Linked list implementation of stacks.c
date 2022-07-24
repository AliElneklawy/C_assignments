#include <stdio.h>
#include <stdlib.h>

/**         Linked list implementation of stacks        **/
/* Linked lists, unlike arrays, enable us to add as much info as we want to the stack   */

int i = 0;

struct node
{
    int x;
    struct node *next;
    struct node *prev;
};
typedef struct node ls;
ls *head = NULL;

int isEmpty(ls *head)
{
    if(head == NULL){
        return 1;
    }
    return 0;
}

int isFull(ls *head)
{
    if(head){
        return 1;
    }
    return 0;
}

void print(ls *head)
{
    while(head != NULL){
        printf("%d ", head -> x);
        head = head -> prev;
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

void push()
{
    system("cls");
    int data;
    printf("Enter the data to be pushed: ");
    scanf("%d", &data);
    if(i == 0){
        head = create_ls(data, head);
        ++i;
    }
    else{
        head = add_end(data, head);
    }
}

void pop()
{
    if(isEmpty(head)){
        printf("Stack is empty");
        return;
    }
    ls *del = head;
    head = head -> prev;
    free(del);  del = NULL;
}

int main()
{
    int ch = 0, check = 0;
    while(1){
        printf("\n1. push\n2. pop\n3. print the stack contents\n4. exit\n   your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            print(head);
            break;
        case 4:
            exit(1);
        default:
            system("cls");
            printf("\nPlease enter a valid value. \n");
        }
    }

}














