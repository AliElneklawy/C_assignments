#include <stdio.h>
#include <stdlib.h>
#define IntMax 2147483647
#define maxBin 30

/* decimal to binary conversion and vice versa using linked lists */



struct node
{
    int x;
    struct node *link;
};
typedef struct node ls;

ls *create_ls(int *);
ls *add_end(ls *, int *);
ls *reverse(ls *);
void dec2bin(int);
void bin2dec(ls *);
void saveBinInLs(int);

int main()
{
    int n, ch;
    printf("Choose an option:\n 1- Decimal to binary\n 2- Binary to decimal\n  YOUR CHOICE: ");
    scanf("%d", &ch);
    if(ch == 1){    //decimal to binary
        system("cls");
        printf("Enter a decimal number: ");
        scanf("%d", &n);
        if (n==0){      //if the user enters 0, the output is just 0
            printf("\nThe binary equivalent is: 0\n");
            exit(1);
        }
        dec2bin(n);
        printf("\n");
    }
    else{   //binary to decimal
        system("cls");
        printf("Enter a binary number: ");
        scanf("%d", &n);
        saveBinInLs(n);     //save the binary bits each in a node
    }

    return 0;
}

void dec2bin(int n)
{
    int i = 0, rem;
    ls *trav = NULL, *head = NULL;
    while(n != 0){
        rem = n%2;
        if(i == 0){
           head = create_ls(&rem);  //create the first node in the list
           trav = head;
           i = 1;
        }
        else{
            head = add_end(head, &rem);
        }
        n = n/2;
    }
    head = reverse(head);     //reverse the bits in the linked list
    print(head);
}

void bin2dec(ls *head)
{
    int base = 1, dec = 0;
    ls *trav = head;
    while(trav != NULL){
        dec += (trav -> x)*base;
        base = base * 2;
        trav = trav -> link;
    }
    printf("\nThe decimal equivalent is: %d", dec);
}

void saveBinInLs(int n)
{
    int i = 0, rem=0;
    ls *head = NULL;
    while(n != 0){
        rem = n%10;
        n = n/10;
        if((rem != 1) && (rem != 0)){
            printf("This is not a binary number.\n");
            main();
        }
        if(i == 0){
            head = create_ls(&rem);
            i = 1;
        }
        else{
            head = add_end(head, &rem);
        }
    }
    bin2dec(head);
}

void print(ls *head)
{
    ls *trav = head;
    printf("\nThe binary equivalent is: ");
    while(trav != NULL){
        printf("%d", trav -> x);
        trav = trav -> link;
    }
}

ls *create_ls(int *rem)
{
    ls *head = malloc(sizeof(ls));
    head -> x = *rem;
    head -> link = NULL;
    return head;
}

ls *add_end(ls *head, int *n)
{
    ls *ptr = malloc(sizeof(ls));
    ls *trav = head;
    while(trav -> link != NULL){
        trav = trav -> link;
    }
    trav -> link = ptr;
    ptr -> x = *n;
    ptr -> link = NULL;
    ptr = NULL;
    return head;
}

ls *reverse(ls *head)
{
    ls *prev = head, *next = head -> link;

    short i = 1;
    while(1){
        if(next == NULL){
            prev = NULL;
            break;
        }
        if(i == 1){
            prev -> link = NULL;
            i = 0;
        }
        head = next;
        next = next -> link;
        head -> link = prev;
        prev = head;
    }
    return head;

}

