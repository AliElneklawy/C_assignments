#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {   // the fields of the bt node
    int data;
    struct node *left;
    struct node *right;
} BT;
BT *root = NULL;    //a pointer to the root node. Currently, the tree is empty
BT *trav = NULL;    //for traversing the tree

typedef struct queue    //linked list implementation of queues
{
    BT *address;    //addresses of the nodes
    struct queue *next;
} Q;
Q *head = NULL;
Q *tail = NULL;
Q *follow = NULL;   //a pointer to follow the tail pointer

int arr[20];    //store the elements of the tree in the array to check for BST

Q *create_q(BT *address)
{
    head = malloc(sizeof(Q));
    head -> address = address;
    head -> next = NULL;
    follow = head;
    return head;
}

void enqueue(BT *address)
{
    if(head == NULL){
        head = create_q(address);
    }
    else{
        tail = malloc(sizeof(Q));
        follow -> next = tail;
        follow = tail;
        follow -> address = address;
        follow -> next = NULL;
    }
}

BT *dequeue()
{
    if(!isEmpty()){
        BT *temp = head -> address;
        Q *del = head;
        head = head -> next;
        free(del);
        del = NULL;
        return temp;
    }
}

int isEmpty()
{
    if(head == NULL){
        return 1;
    }
    return 0;
}

void free_nodes()
{
    free(follow);   follow = NULL;
    free(tail);     tail = NULL;
}

BT *insert(BT *root, int data);
BT *create_node(int);
bool search(BT*, int);
int find_max(BT *);
BT *find_min(BT *);
void check_BST(BT *);   //check for binary search tree
void find_height(BT *);
BT *Del_node(BT *root, int);    //delete a node
void traverse_BFT(BT *);
void traverse_inorder(BT *);
void traverse_preorder(BT *);
void traverse_postorder(BT *);

int main()
{
    int n, num;
    printf("\nHow many numbers to insert? ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        printf("Enter a number: ");
        scanf("%d", &num);
        root = insert(root, num);
    }
    system("cls");
    printf("Search a number: ");
    scanf("%d", &n);
    bool ch = search(root, n);
    if(ch)  printf("Found");
    else printf("Not found\n");
    find_max(root); //max value in the tree
    find_min(root);
    find_height(root);  //height of the tree
    traverse_BFT(root); //breadth first traversal
    printf("\nThe contents of the BST using in-order traversal are: ");
    traverse_inorder(root); //inOrder traversal. Produces sorted values
    printf("\nThe contents of the BST using pre-order traversal are: ");
    traverse_preorder(root); //preOrder traversal
    printf("\nThe contents of the BST using post-order traversal are: ");
    traverse_postorder(root);   //postOrder traversal. Root of the tree is found at the end of the sequence
    check_BST(root);
    printf("\nEnter a number to delete: ");
    scanf("%d", &n);
    Del_node(root, n);
    traverse_inorder(root); //the in-order traversal after deleting the node
    //free_nodes();   // to deallocate the memory
}

BT *insert(BT *root, int data) //This function always results in a binary search tree
{
    if (root == NULL){
        root = create_node(data);
    }
    else if (data > root->data){
        root -> right = insert(root -> right, data);
    }
    else {
        root -> left = insert(root->left, data);
    }
    return root;
}

BT *create_node(int data)
{
    BT *newnode = malloc(sizeof(BT));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

bool search(BT*root, int x)     //search the tree for a number x
{
    if(root == NULL)    return false;
    else if(root->data == x)    return true;
    else if(x >= root->data)    return search(root->right, x);
    else return search(root->left, x);
}

int find_max(BT *root)
{
    int max = 0;
    trav = root;
    if (trav-> right == NULL){  //no right subtree means that the greatest number is the root. This helps not search the entire tree for nothing
        printf("\nThe greatest number in the tree is: %d", root -> data);
        return;
    }
    if (trav == NULL){
        printf("Empty tree");
        return;
    }
    while (trav != NULL){
        if(trav -> data > max){
            max = trav -> data;
            trav = trav -> right;   //the maximum number will always be on the right since this is a binary search tree
        }
    }
    printf("\nThe greatest number in the tree is: %d", max);
}

BT *find_min(BT *root)
{
    int min = 9999999;
    trav = root;
    if (trav-> left == NULL){  //no left subtree means that the smallest number is the root. This helps not search the entire tree for nothing
        printf("\nThe smallest number in the tree is: %d", trav -> data);
        return;
    }
    if (trav == NULL){
        printf("Empty tree");
        return;
    }
    while (trav -> left != NULL){
        if(trav -> data < min){
            min = trav -> data;
            trav = trav -> left;
        }
    }
    printf("\nThe smallest number in the tree is: %d\n\n", min);
    return trav;
}

void find_height(BT *root)
{
    trav = root;
    int left_height = 0;
    int right_height = 0;
    while(trav != NULL){
        trav = trav -> left;
        left_height++;
    }
    trav = root;
    while(trav != NULL){
        trav = trav -> right;
        right_height++;
    }
    if(left_height >= right_height){
        printf("\nHeight = %d", left_height);
    }
    else{
        printf("\nHeight = %d", right_height);
    }
}

void traverse_BFT(BT *root) //breadth first traversal
{
    if(root == NULL)    return;
    printf("\nThe contents of the BST using breadth first traversal are: ");
    BT *current = NULL;
    enqueue(root);
    while(!isEmpty()){
        current = dequeue();
        printf("%d ", current -> data);
        if (current -> left != NULL) enqueue(current -> left);
        if (current -> right != NULL) enqueue(current -> right);
    }
}

void traverse_inorder(BT *root)
{
    if(root == NULL)  return;
    traverse_inorder(root->left);
    printf("%d ", root -> data);
    traverse_inorder(root->right);
}

void traverse_preorder(BT *root)
{
    if(root == NULL)    return;
    printf("%d ", root -> data);
    traverse_preorder(root->left);
    traverse_preorder(root->right);
}

void traverse_postorder(BT *root)
{
    if(root == NULL)    return;
    traverse_postorder(root->left);
    traverse_postorder(root->right);
    printf("%d ", root->data);
}

void traverse_inorder_checkBST(BT *root, int arr[], int i) //in order traversal to check for BST
{
    ++i;
    if(root == NULL)  return;
    traverse_inorder_checkBST(root->left, arr, i);
    arr[i] = root -> data;
    traverse_inorder_checkBST(root->right, arr, i);
}

void check_BST(BT *root)    /** A TREE IS A BINARY SEARCH TREE IF THE IN-ORDER TRAVERSAL RESULTS IN A SORTED SEQUENCE**/
{
    int i=-1;
    traverse_inorder_checkBST(root, arr, i);
    printf("\n");
    for(int i = 0; i!='\0'; i++){
        if(arr[i+1] < arr[i]){
            printf("This is not a BST");
            return;
        }
    }
    printf("This is a BST..");
}

BT *Del_node(BT *root, int data)
{
  if(root == NULL) return;
  else if(data > root -> data)  root -> right = Del_node(root-> right, data);
  else if(data < root -> data)  root -> left = Del_node(root-> left, data);
  else
  { //3 cases will be handled
    /** Case 1: the node has no children **/
    if(root -> right == NULL && root -> left == NULL){
        free(root);
        root = NULL;
    }
    /** Case 2-A: the node has only a right child **/
    else if(root -> left == NULL){
        BT *temp = root;
        root = root -> right;
        free(temp);
        temp = NULL;
    }
    /** Case 2-B: the node has only a left child **/
    else if(root -> right == NULL){
        BT *temp = root;
        root = root -> left;
        free(temp);
        temp = NULL;
    }
    /** Case 3: the node has 2 children **/
    else{
        BT *min = find_min(root->right);
        root -> data = min -> data;
        root -> right = Del_node(root -> right, min -> data);
    }
  }
  return root;
}

