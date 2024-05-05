#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main(){
    struct node *start = NULL;
    int option;
    system("cls");
    do{
        system("cls");
        printf("\n\n****** MAIN MENU ******");
        printf("\n1: Create a list");
        printf("\n2: Display the list");
        printf("\n3: Add a node at the beginning");
        printf("\n4: Add a node at the end");
        printf("\n5: Delete a node from the beginning");
        printf("\n6: Delete a node from the end");
        printf("\n7: Delete a given node");
        printf("\n8: Delete the entire list");
        printf("\n9: EXIT");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                start = create_cll(start);
                printf("\nCIRCULAR LINKED LIST CREATED! Press enter to continue...\n");
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
                start = delete_beg(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 6:
                start = delete_end(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 7:
                start = delete_after(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
            case 8:
                start = delete_list(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
                break;
        }
    }while(option!= 9);
    getchar();
    return 0;
}

struct node *create_cll(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter data (-1 to end): ");
    scanf("%d", &num);
    while(num != -1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if(start == NULL) {
            new_node->next = new_node;
            start = new_node;
        } else {
            ptr = start;
            while(ptr->next != start) {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("Enter data (-1 to end): ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start){
    if(start == NULL){
    	printf("NULL\n");
    	return start;
	}
	struct node *ptr = start;
    printf("\n");
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while(ptr != start);
    printf("Start\n");
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    return start;
}

struct node *delete_beg(struct node *start){
    struct node *ptr, *temp;
    if(start == NULL){
        printf("List is empty\n");
        return start;
    }
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    temp = start;
    ptr->next = start->next;
    start = start->next;
    free(temp);
    return start;
}

struct node *delete_end(struct node *start){
    struct node *ptr, *preptr;
    if(start == NULL){
        printf("List is empty\n");
        return start;
    }
    ptr = start;
    while(ptr->next != start){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start){
    struct node *ptr, *temp;
    int val;
    printf("Enter value after which to delete: ");
    scanf("%d", &val);
    ptr = start;
    while(ptr->data != val){
        ptr = ptr->next;
    }
    if(ptr->next == start){
        printf("This is the last node, deletion not possible\n");
        return start;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return start;
}

struct node *delete_list(struct node *start){
    struct node *ptr, *temp;
    if(start == NULL){
        printf("List is empty\n");
        return start;
    }
    
    ptr = start;
    while(ptr->next != start){ // Traverse until we reach the last node
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    
    // Free the last node
    free(ptr);
    start = NULL; // Reset the start pointer to NULL
    return start;
}
