#include <stdio.h>
#include <stdlib.h>

int top = -1;

void print(int arr[], short ch)
{
    printf("\nthe reversed array: ");
    for(int i = 0; i<ch;){
        printf("%d ", arr[i++]);
    }
}

void push(int elem, short ch, int stack_arr[])
{
    top += 1;
    stack_arr[top] = elem;
}

void pop(int arr[], int stack_arr[], int i)
{
    arr[i] = stack_arr[top];
    top = top-1;
}

void reverse_int()
{
    system("cls");
    short ch;
    printf("Enter the size of the array: ");
    scanf("%hu", &ch);
    int arr[ch];
    for(int i = 0; i < ch; i++){
        scanf("%d", &arr[i]);
    }

    int stack_arr[ch];
    //memcpy(stack_arr, arr, sizeof(arr));    //stack_arr = arr

    for(int i = 0; i<ch; i++){
        push(arr[i], ch, stack_arr);
    }
    for(int i = 0; i<ch; i++){
        pop(arr, stack_arr, i);
    }
    print(arr, ch);

}



int main()
{
    short ch;
    printf("Array of \n 1- integers\n 2- chars\n  YOUR CHOICE: ");
    scanf("%d", &ch);
    if(ch == 1){
        reverse_int();
    }
}














