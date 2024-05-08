#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);

int main(){
    int option;
    struct node *start = NULL; // Moved start declaration here
    do{
        system("cls");
        printf("\n\n****** MAIN MENU ******");
        printf("\n1: Create a list");
        printf("\n2: Display the list");
        printf("\n3: Add a node at the beginning");
        printf("\n4: Add a node at the end");
        printf("\n5: Delete a node from the beginning");
        printf("\n6: Delete a node from the end");
        printf("\n7: Delete a node");
        printf("\n8: Delete the entire list");
        printf("\n9: EXIT");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1:
                start = create_ll(start);
                printf("\nCIRCULAR DOUBLY LINKED LIST CREATED\n");
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 2:
                start = display(start);
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
            	if(start == NULL){
                	printf("Linked list is empty\n");
                	printf("\nPress enter to continue...\n");
                	getchar(); getchar();
                	break;
				}
                start = delete_beg(start);
				printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 6:
            	if(start == NULL){
                	printf("Linked list is empty\n");
                	printf("\nPress enter to continue...\n");
                	getchar(); getchar();
                	break;
				}
                start = delete_end(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 7:
            	if(start == NULL){
                	printf("Linked list is empty\n");
                	printf("\nPress enter to continue...\n");
                	getchar(); getchar();
                	break;
				}
                start = delete_node(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 8:
            	if(start == NULL){
                	printf("Linked list is empty\n");
                	printf("\nPress enter to continue...\n");
                	getchar(); getchar();
                	break;
				}
                start = delete_list(start);
                printf("\nCIRCULAR DOUBLY LINKED LIST DELETED\n");
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 9:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
        }
        
    }while(option != 9);
    return 0;
}

struct node *create_ll(struct node *start){
    struct node *newnode, *ptr;
    int num;
    printf("Enter -1 to end");
    printf("\nEnter the data :");
    scanf("%d", &num);
    while(num!=-1){
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        if(start == NULL){
            newnode->prev = newnode;
            newnode->next = newnode;
            start = newnode;
        }
        else{
            ptr = start;
            while(ptr->next != start){
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
            newnode->next = start;
            start->prev = newnode;
        }
        printf("\nEnter the data :");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    do {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *newnode, *ptr;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    newnode->next = start;
    start->prev = newnode;
    start = newnode;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *ptr, *newnode;
    int num;
    printf("\nEnter the data : ");
    scanf("%d", &num);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    newnode->next = start;
    start->prev = newnode;
    return start;
}

struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = start->next;
    start->next->prev = ptr;
    free(start);
    start = ptr->next;
    return start;
}

struct node *delete_end(struct node *start){
    struct node *ptr, *prev;
    ptr = start;
    while(ptr->next != start){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = start;
    start->prev = prev;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start){
    struct node *ptr, *temp;
    int val;
    printf("\nEnter the value of the node which has to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    if(ptr->data == val){
        start = delete_beg(start);
        return start;
    }
    else{
        while(ptr->data != val){
            ptr = ptr->next;
            if(ptr == start){
                printf("\nNode not found.\n");
                return start;
            }
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        return start;
    }
}

struct node *delete_list(struct node *start){
    struct node *ptr;
    if(start != NULL){
        ptr = start;
        while(ptr->next != start){
            start = delete_end(start);
            ptr = start;
        }
        free(start);
    }
    return NULL;
}

