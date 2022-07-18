#include <stdio.h>
#include <stdlib.h>
#define IntMax 2147483647

struct node
{
    int x;
    struct node *link;
};
typedef struct node ls;

ls *create_ls();
ls *add_end(ls *, int *, int *);
int check_sort(ls *);
ls *reverse(ls *);
ls *findMax(ls *);
int SaveInArr(ls *, int *);
ls *sort(ls *, ls *, int *);

int main()
{
    int n, x;
    printf("How many nodes in the list? ");
    scanf("%d", &n);
    ls *head = create_ls();
    for(int i = 1; i < n; i++){
        head = add_end(head, &n, &i);
    }
    ls *trav = head;
    trav = findMax(trav);
    //head = reverse(head);
    print(head);
    /*x = check_sort(head);

    if(x == 0){
        printf("\nNot sorted.");
    }else if(x == 1){
        printf("\nSorted in ascending order.");
    }else{
        printf("\nSorted in ascending order.");
    }*/
    return 0;
}

void print(ls *head)
{
    ls *trav = head;
    while(trav != NULL){
        printf("%d ", trav -> x);
        trav = trav -> link;
    }
}

ls *create_ls()
{
    ls *head = malloc(sizeof(ls));
    printf("Enter data of node 1: ");
    scanf("%d", &head -> x);
    head -> link = NULL;
    return head;
}

ls *add_end(ls *head, int *n, int *i)
{
    ls *ptr = malloc(sizeof(ls));
    ls *trav = head;
    int x;
    printf("Enter data of node %d: ", *i+1);
    scanf("%d", &x);
    while(trav -> link != NULL){
        trav = trav -> link;
    }
    trav -> link = ptr;
    ptr -> x = x;
    ptr -> link = NULL;
    ptr = NULL;
    return head;
}

/*int check_sort(ls *head)
{
    ls *trav = head;
    while(trav -> link != NULL)
    {
        if(trav -> x > trav -> link -> x){
            return 0;
        }
        trav = trav -> link;
    }
    return 1;
}*/

/*ls *reverse(ls *head)
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

}*/

ls *findMax(ls *save)
{
    ls *kp = NULL, *trav = save;
    if(trav == NULL)    return;
    int INT_MAX, max = -1*IntMax;   //if any item in the list equals max, the function does not work
    while(trav != NULL){
        if(trav -> x > max){
            max = trav -> x;
            kp = trav;
        }
        trav = trav -> link;
    }
    sort(save, kp, &max);
}

ls *sort(ls *save, ls *kp, int *max)
{
    int temp;
    temp = save -> x;
    save -> x = *max;
    kp -> x = temp;
    save = save -> link;
    findMax(save);
}

/*int SaveInArr(ls *head, int *n)
{
    int arr[*n], i = 0;
    ls *trav = head;
    while(trav != NULL){
        arr[i++] = trav -> x;
        trav = trav -> link;
    }

    for(i = 0; i < *n; i++){
        printf("%d ", arr[i]);
    }
    return arr;
}*/

