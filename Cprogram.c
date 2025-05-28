Cprogram.c#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("Welcome to the Linked List Operations Program!\n");
    printf("Select the type of linked list you want to work with:\n");
    printf("1. Singly Linked List\n");
    printf("2. Doubly Linked List\n");
    printf("3. Circular Singly Linked List\n");
    printf("Select an option\n");

    int opt;
    scanf("%d", &opt);
    switch(opt){
        case 1:
            // Call the function for singly linked list
            printf("You selected Singly Linked List.\n");
           sll();
            break;
        case 2:
            // Call the function for doubly linked list
            printf("You selected Doubly Linked List.\n");
            dll();
            break;
        case 3:
            // Call the function for circular singly linked list
            printf("You selected Circular Singly Linked List.\n");
            scll();
            break;
        default:
            printf("Invalid option. Please select a valid option.\n");
    }
}

//sll.c
struct node
{
    int data;
    struct node *next;
};

struct node *head;

void printll();

void ins_beg()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data of the new node: \n");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;

    printll();
}

void ins_aft()
{
    struct node *ptr, *preptr;
    int pos;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data of the node after which the new node is to be inserted: \n");
    scanf("%d", &pos);
    printf("Enter the data of the new node");
    scanf("%d", &new_node->data);
    preptr = head;
    ptr = preptr->next;
    while (preptr->data != pos)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    new_node->next = ptr;
    preptr->next = new_node;

    printll();
}

void ins_bef()
{
    struct node *ptr, *preptr;
    int pos;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data of the node before which the new node is to be inserted: \n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode \n");
    scanf("%d", &new_node->data);
    preptr = head;
    ptr = preptr->next;
    while (ptr->data != pos)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    new_node->next = preptr->next;
    preptr->next = new_node;
    printll();
}

void ins_end()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    struct node *ptr;
    printf("Enter the data of the new node: \n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    printll(head);
}

void del_beg()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr;
    ptr = head;
    head = ptr->next;
    free(ptr);

    printll(head);
}

void del_mid()
{
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
    struct node *ptr, *preptr;
    int data;
    printf("Enter the data of the node to be deleted \n");
    scanf("%d", &data);
    preptr = head;
    ptr = preptr->next;
    while (preptr->next->data != data)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);

    printll();
    }
}

void del_end()
{
    if(head==NULL){
        printf("The list is empty");
    }
    else{
    struct node *ptr, *preptr;
    preptr = head;
    ptr = preptr->next;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = NULL;
    free(ptr);

    printll();
    }
}

void printll()
{
    struct node *ptr = head;
    if(head == NULL){
        printf("The list is empty");
    }

    else{
        printf("The list is:\n");
    while (ptr != NULL)
    {

        printf("%d\n ", ptr->data);
        ptr = ptr->next;
    } }
}

int sll()
{
    int opt;
    while (1)
    {
        printf("---------Operations on Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            ins_beg();
            break;
        case 2:
            ins_end();
            break;
        case 3:
            ins_aft();
            break;
        case 4:
            ins_bef();
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_mid();
            break;
        case 7:
            del_end();
            break;
        case 8:
            printll(head);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}

//dll.c
// Doubly Linked List Node Structure
struct node1 {
    int data;
    struct node1 *next;
    struct node1 *prev;
};
struct node1 *start;

// Function prototypes
void printll1();
void ins_beg1();
void ins_end1();
void ins_aft1();
void ins_bef1();
void del_beg1();
void del_end1();
void del_mid1();

// Fixed function to insert at beginning
void ins_beg1(){
    int data;
    struct node1 *new_node=(struct node1*)malloc(sizeof(struct node1));
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data of the new node\n");
    scanf("%d",&new_node->data);
    new_node->prev = NULL;
    
    if(start == NULL) {
        new_node->next = NULL;
        start = new_node;
    } else {
        new_node->next = start;
        start->prev = new_node; // Fixed: Set previous pointer of old start
        start = new_node;
    }

    printll1();
}

// Fixed function to insert at end
void ins_end1(){
    struct node1 *new_node=(struct node1*)malloc(sizeof(struct node1));
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    printf("Enter the data of the new node\n");
    scanf("%d",&new_node->data);
    
    new_node->next = NULL;
    
    if(start == NULL) {
        new_node->prev = NULL;
        start = new_node;
    } else {
        struct node1 *ptr = start;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        new_node->prev = ptr;
        ptr->next = new_node;
    }

    printll1();
}

// Fixed function to insert after a node
void ins_aft1(){
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node1* new_node=(struct node1*)malloc(sizeof(struct node1));
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    struct node1 *ptr;
    int pos;
    ptr = start;
    printf("Enter the data of the node after which new node has to be inserted\n");
    scanf("%d",&pos);
    printf("Enter the data of the new node\n");
    scanf("%d",&new_node->data);
    
    while(ptr != NULL && ptr->data != pos){
        ptr = ptr->next;
    }
    
    if(ptr == NULL) {
        printf("Node with data %d not found\n", pos);
        free(new_node); // Free memory if node not found
        return;
    }
    
    if(ptr->next == NULL) {
        // Inserting at the end
        new_node->next = NULL;
        new_node->prev = ptr;
        ptr->next = new_node;
    } else {
        // Inserting in the middle
        new_node->next = ptr->next;
        new_node->prev = ptr;
        ptr->next->prev = new_node;
        ptr->next = new_node;
    }

    printll1();
}

// Fixed function to insert before a node
void ins_bef1(){
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node1* new_node=(struct node1*)malloc(sizeof(struct node1));
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    struct node1 *ptr;
    int pos;
    printf("Enter the data of the node before which the new node is inserted\n");
    scanf("%d",&pos);
    printf("Enter the data of the new node\n");
    scanf("%d",&new_node->data);
    
    ptr = start;
    
    // If inserting before first node
    if(ptr->data == pos) {
        new_node->next = start;
        new_node->prev = NULL;
        start->prev = new_node;
        start = new_node;
        printll1();
        return;
    }
    
    while(ptr != NULL && ptr->data != pos){
        ptr = ptr->next;
    }
    
    if(ptr == NULL) {
        printf("Node with data %d not found\n", pos);
        free(new_node); // Free memory if node not found
        return;
    }
    
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    printll1();
}

// Fixed function to delete from beginning
void del_beg1(){
    if(start == NULL){
        printf("The list is empty\n");
        return;
    }
    
    struct node1 *ptr;
    ptr = start;
    
    if(start->next == NULL) {
        // Only one node in the list
        start = NULL;
    } else {
        start = ptr->next;
        start->prev = NULL;
    }
    
    free(ptr);
    printll1();
}

// Fixed function to delete from end
void del_end1(){
    if(start == NULL){
        printf("The list is empty\n");
        return;
    }
    
    struct node1 *ptr = start;
    
    // If only one node
    if(ptr->next == NULL) {
        start = NULL;
        free(ptr);
        printll1();
        return;
    }
    
    // Traverse to the last node
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    
    ptr->prev->next = NULL;
    free(ptr);
    printll1();
}

// Fixed function to delete a specific node
void del_mid1(){
    if(start == NULL){
        printf("The list is empty\n");
        return;
    }
    
    struct node1 *ptr = start;
    int data;
    printf("Enter the data of the node to be deleted\n");
    scanf("%d",&data);
    
    // If deleting the first node
    if(ptr->data == data) {
        del_beg1();
        return;
    }
    
    while(ptr != NULL && ptr->data != data){
        ptr = ptr->next;
    }
    
    if(ptr == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }
    
    // If deleting the last node
    if(ptr->next == NULL) {
        ptr->prev->next = NULL;
    } else {
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
    }
    
    free(ptr);
    printll1();
}

// Fixed function to print the list
void printll1(){
    struct node1 *ptr;
    ptr = start;
    
    if(start == NULL){
        printf("The list is empty\n");
        return;
    }
    
    printf("The list is: ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function for doubly linked list operations
int dll()
{
    int opt = 0;
    while (opt != 9)
    {
        printf("---------Operations on Doubly Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            ins_beg1();
            break;
        case 2:
            ins_end1();
            break;
        case 3:
            ins_aft1();
            break;
        case 4:
            ins_bef1();
            break;
        case 5:
            del_beg1();
            break;
        case 6:
            del_mid1();
            break;
        case 7:
            del_end1();
            break;
        case 8:
            printll1();
            break;
        case 9:
            return 0;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}

//scll
struct node2
{
    int data;
    struct node2 *next;
};

struct node2 *start2 = NULL;
void printll2();

void ins_beg2()
{
    struct node2 *new_node = malloc(sizeof(struct node2));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data of newnode\n");
    scanf("%d", &new_node->data);
    if (start2 == NULL)
    {
        start2 = new_node;
        new_node->next = start2;
    }
    else
    {
        struct node2 *temp = start2;
        while (temp->next != start2)
        {
            temp = temp->next;
        }
        new_node->next = start2;
        start2 = new_node;
        temp->next = start2;
    }
    printll2();
}

void ins_bef2()
{
    struct node2 *new_node = malloc(sizeof(struct node2));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    struct node2 *ptr, *preptr;
    int pos;
    printf("Enter the data of node2 after which you need to insert the new node2;\n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode\n");
    scanf("%d", &new_node->data);
    ptr = start2;
    if (start2->data == pos)
    {
        ins_beg2();
        return;
    }
    while (ptr->next != start2 && ptr->data != pos)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr->data == pos)
    {
        new_node->next = ptr;
        preptr->next = new_node;
    }
    printll2();
}

void ins_aft2()
{
    struct node2 *new_node = malloc(sizeof(struct node2));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    struct node2 *ptr;
    int pos;
    printf("Enter the data of the node2 after which you need to insert the new node2\n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode\n");
    scanf("%d", &new_node->data);
    ptr = start2;
    if(start2 == NULL){
        printf("List is empty, cannot insert after a node.\n");
        free(new_node);
        return;
    }
    do {
        if(ptr->data == pos){
            new_node->next = ptr->next;
            ptr->next = new_node;
            printll2();
            return;
        }
        ptr = ptr->next;
    } while (ptr != start2);

    printf("Node not found\n");
    free(new_node);
}

void ins_end2()
{
    struct node2 *new_node = malloc(sizeof(struct node2));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    struct node2 *ptr;
    printf("Enter the data of newnode\n");
    scanf("%d", &new_node->data);
    ptr = start2;
    if (start2 != NULL) {
        while (ptr->next != start2)
        {
            ptr = ptr->next;
        }
        new_node->next = start2;
        ptr->next = new_node;
    } else {
        start2 = new_node;
        new_node->next = start2;
    }
    printll2();
}

void del_beg2()
{
    struct node2 *ptr;
    if (start2 == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start2;
    while (ptr->next != start2)
    {
        ptr = ptr->next;
    }
    struct node2 *temp = start2;
    start2 = start2->next;
    ptr->next = start2;
    free(temp);
    printll2();
}

void del_mid2()
{
    struct node2 *ptr, *preptr;
    int data;
    printf("Enter the data of the node2 to be deleted\n");
    scanf("%d", &data);
    ptr = start2;
    if (ptr->data == data)
    {
        del_beg2();
        return;
    }
    while (ptr->next != start2 && ptr->next->data != data)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr->next->data == data)
    {
        struct node2 *temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    printll2();
}

void del_end2()
{
    struct node2 *ptr, *preptr;
    if (start2 == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start2;
    while (ptr->next != start2)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start2;
    free(ptr);
    printll2();
}

void printll2()
{
    if (start2 == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct node2 *ptr = start2;
    printf("The list is \n");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start2);
    printf("\n");
}

int scll()
{
    int opt;
    while (opt != 9)
    {
        printf("---------Operations on Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node2\n");
        printf("4. Insertion before the specified node2\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node2\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            ins_beg2();
            break;
        case 2:
            ins_end2();
            break;
        case 3:
            ins_aft2();
            break;
        case 4:
            ins_bef2();
            break;
        case 5:
            del_beg2();
            break;
        case 6:
            del_mid2();
            break;
        case 7:
            del_end2();
            break;
        case 8:
            printll2();
            break;
        case 9:
            return 0;
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}
