#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main() {
    struct node *start = NULL;
    int option;
    do {
        system("cls");
        printf("\n\n****** MAIN MENU ******");
        printf("\n1: Create a list");
        printf("\n2: Display the list");
        printf("\n3: Add a node at the beginning");
        printf("\n4: Add a node at the end");
        printf("\n5: Add a node before a given node");
        printf("\n6: Add a node after a given node");
        printf("\n7: Delete a node from the beginning");
        printf("\n8: Delete a node from the end");
        printf("\n9: Delete a node after a given node");
        printf("\n10: Delete a node after a given node");
        printf("\n11: Delete the entire list");
        printf("\n12: EXIT");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                start = create_ll(start);
                printf("DOUBLE LINKED LIST CREATED! Press enter to continue...\n");
                getchar(); getchar();
                break;
            case 2:
                display(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 3:
                start = insert_beg(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 4:
                start = insert_end(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 5:
                start = insert_before(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 6:
                start = insert_after(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 7:
                start = delete_beg(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 8:
                start = delete_end(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 9:
                start = delete_after(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 10:
                start = delete_before(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 11:
                start = delete_list(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
        }
    } while(option != 12);
    return 0;
}

struct node *create_ll(struct node *start) {
    struct node *newnode, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data : ");
    scanf("%d", &num);
    while(num != -1) {
        if(start == NULL) {
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = num;
            newnode->prev = NULL;
            newnode->next = NULL;
            start = newnode;
        } else {
            ptr = start;
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = num;
            while(ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
            newnode->next = NULL;
        }
        printf("Enter -1 to end");
        printf("\nEnter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    if(start == NULL) {
        printf("Linked list is empty!\n");
        return start;
    }
    struct node *ptr;
    ptr = start;
    while(ptr != NULL) {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *newnode;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    start->prev = newnode;
    newnode->next = start;
    newnode->prev = NULL;
    start = newnode;
    return start;
}

struct node *insert_end(struct node *start) {
    struct node *ptr, *newnode;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    newnode->next = NULL;
    return start;
}

struct node *insert_before(struct node *start) {
    struct node *ptr, *newnode;
    int num, val;
    printf("\nEnter data: ");
    scanf("%d", &num);
    printf("Enter value before which to insert: ");
    scanf("%d", &val);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while(ptr->data != val) {
        ptr = ptr->next;
    }
    newnode->next = ptr;
    newnode->prev = ptr->prev;
    ptr->prev->next = newnode;
    ptr->prev = newnode;
    return start;
}

struct node *insert_after(struct node *start) {
    struct node *ptr, *newnode;
    int num, val;
    printf("\nEnter data: ");
    scanf("%d", &num);
    printf("Enter value after which to insert: ");
    scanf("%d", &val);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while(ptr->data != val) {
        ptr = ptr->next;
    }
    newnode->prev = ptr;
    newnode->next = ptr->next;
    ptr->next->prev = newnode;
    ptr->next = newnode;
    return start;
}

struct node *delete_beg(struct node *start) {
    if(start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start) {
    if(start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start) {
    struct node *ptr, *temp;
    int val;
    printf("\nEnter value before which to delete: ");
    scanf("%d", &val);
    ptr = start;
    // Find the node with the given value
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    // If the value to delete after is not found or it's the last node
    if (ptr == NULL || ptr->next == NULL) {
        printf("No node to delete after the last node!\n");
        return start;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    // If the node to delete after is not the second last node
    if (temp->next != NULL) {
        temp->next->prev = ptr;
    }
    free(temp);
    return start;
}


struct node *delete_before(struct node *start) {
    struct node *ptr, *temp;
    int val;
    printf("\nEnter value after which to delete: ");
    scanf("%d", &val);
    ptr = start;
    // If the value to delete before is in the first node
    if (ptr->data == val || ptr->next == NULL) {
        printf("No node to delete before the first node!\n");
        return start;
    }
    while (ptr->next != NULL && ptr->next->data != val) {
        ptr = ptr->next;
    }
    // If the value to delete before is not found
    if (ptr->next == NULL) {
        printf("Value %d not found in the list!\n", val);
        return start;
    }
    temp = ptr->prev;
    // If the node to delete before is the start node
    if (temp == start) {
        start = delete_beg(start);
    } else {
        ptr->prev = temp->prev;
        temp->prev->next = ptr;
        free(temp);
    }
    return start;
}


struct node *delete_list(struct node *start) {
    struct node *ptr, *temp;
    if (start == NULL) {
        printf("List is already empty!\n");
        return start;
    }
    ptr = start;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    // Reset the start pointer to NULL
    start = NULL;
    return start;
}


