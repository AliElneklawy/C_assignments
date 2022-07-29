#include <stdio.h>
#include <stdlib.h>
#define MAX 10

                                    /**     REVERSING A NUMBER USING QUEUES     **/

int head = 0;
int tail = 0;
int queue_arr[MAX];

void reverse()
{
    system("cls");
    int data;
    printf("Enter a number: ");
    scanf("%d", &data);
    while(data > 0){
        enqueue(data % 10);
        data = data / 10;
    }
    printf("\nDigits in reverse order: ");
    while(head != tail){
        printf("%d", dequeue());
    }
    printf("\n\n");
}

void enqueue(int data)
{
    if(tail == MAX)     tail = 0;
    else    ++tail;
    if(tail == head){
        printf("\nQueue is full!!");
        return;
    }
    queue_arr[tail] = data;

}

int dequeue()
{
    if(head == tail){
        return;
    }
    if(head == MAX) head = 0;
    else
        ++head;
    return queue_arr[head];
}

int main()
{
    int ch;
    while(1){
        printf("\n1- reverse queue\n2- exit\n  YOUR CHOICE: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            reverse();
            break;
        case 2:
            exit(1);
        }
    }

}
