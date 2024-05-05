#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
    int data;
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
struct node *delete_node(struct node *);
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
        printf("\n9: Delete a given node");
        printf("\n10: Delete a node after a given node");
        printf("\n11: Delete the entire list");
        printf("\n12: Sort the list");
        printf("\n13: EXIT");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                start = create_ll(start);
                printf("\nLINKED LIST CREATED! Press enter to continue...\n");
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
                start = delete_node(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
				break;
            case 10:
                start = delete_after(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
				break;
            case 11:
                start = delete_list(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
				break;
            case 12:
                start = sort_list(start);
                printf("\nPress enter to continue...\n");
                getchar(); getchar();
				break;
        }
    } while(option != 13);
    return 0;
}

struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter data (-1 to end): ");
    scanf("%d", &num);
    while(num != -1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if(start == NULL) {
            start = new_node;
        } else {
            ptr = start;
            while(ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
        printf("Enter data (-1 to end): ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr = start;
    printf("\n");
    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;
    printf("\nEnter data: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter data: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if(start == NULL) {
        start = new_node;
    } else {
        ptr = start;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return start;
}

struct node *insert_before(struct node *start) {
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\nEnter data: ");
    scanf("%d", &num);
    printf("Enter value before which to insert: ");
    scanf("%d", &val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    if(start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    if(start->data == val) {
        new_node->next = start;
        start = new_node;
        return start;
    }
    ptr = start;
    preptr = ptr;
    while(ptr->data != val && ptr != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL) {
        printf("Value not found!\n");
        free(new_node);
        return start;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *insert_after(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;
    printf("\nEnter data: ");
    scanf("%d", &num);
    printf("Enter value after which to insert: ");
    scanf("%d", &val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if(ptr == NULL) {
        printf("Value not found!\n");
        free(new_node);
        return start;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return start;
}

struct node *delete_beg(struct node *start) {
    if(start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    struct node *ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start) {
    if(start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    struct node *ptr = start, *preptr = NULL;
    while(ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if(preptr != NULL) {
        preptr->next = NULL;
    } else {
        start = NULL;
    }
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start) {
    if(start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);
    struct node *ptr = start, *preptr = NULL;
    while(ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL) {
        printf("Value not found!\n");
        return start;
    }
    if(preptr != NULL) {
        preptr->next = ptr->next;
    } else {
        start = ptr->next;
    }
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start) {
    if(start == NULL || start->next == NULL) {
        printf("Not enough nodes!\n");
        return start;
    }
    int val;
    printf("Enter value after which to delete: ");
    scanf("%d", &val);
    struct node *ptr = start, *preptr = NULL;
    while(ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL || ptr->next == NULL) {
        printf("Value not found or not enough nodes!\n");
        return start;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return start;
}

struct node *delete_list(struct node *start) {
    struct node *ptr = start;
    while(ptr != NULL) {
        start = delete_beg(ptr);
        ptr = start;
    }
    return start;
}

struct node *sort_list(struct node *start) {
    struct node *ptr1, *ptr2;
    int temp;
    if(start == NULL) {
        printf("List is empty!\n");
        return start;
    }
    ptr1 = start;
    while(ptr1->next != NULL) {
        ptr2 = ptr1->next;
        while(ptr2 != NULL) {
            if(ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}

