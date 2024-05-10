#include<stdio.h>
#include<stdlib.h>

#define MAX 100000

int st[MAX], top = -1;

void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(){
	int val, option;
	do{
		system("cls");
		printf("*****MAIN MENU*****");
		printf("\n1. PUSH");
		printf("\n2. POP");
		printf("\n3. PEEK");
		printf("\n4. DISPLAY");
		printf("\n5. EXIT");
		printf("\nEnter your option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				while(1){
					printf("Enter a number to be pushed on stack (-1 to leave this menu): ");
					scanf("%d", &val);
					if(val == -1) break;
					push(st, val);
					printf("Number %d is inserted into the stack\n", val);
				}
				break;
			case 2:
				val = pop(st);
				if(val != -1){
					printf("The value deleted from stack is : %d\n", val);
					printf("PRESS ENTER TO CONTINUE\n");
					getchar(); getchar();
					break;
				}
			case 3:
				val = peek(st);
				if(val != -1){
					printf("The value stored at the top of the stack is : %d\n", val);
					printf("PRESS ENTER TO CONTINUE\n");
					getchar(); getchar();
					break;
				}
			case 4:
				display(st);
				printf("PRESS ENTER TO CONTINUE\n");
				getchar(); getchar();
				break;
		}
	}while(option!=5);
	return 0;
}

void push(int st[], int val){
	if(top == MAX-1){
		printf("\nSTACK OVERFLOW\n");
	}
	else{
		top++;
		st[top] = val;
	}
}

int pop(int st[]){
	int val;
	if(top == -1){
		printf("\nSTACK UNDERFLOW\n");
		return -1;
	}
	else{
		val = st[top];
		top--;
		return val;
	}
}

void display(int st[]){
	int i;
	if(top == -1){
		printf("\nSTACK IS EMPTY\n");
	}
	else{
		for(int i = top; i>=0; i--){
			printf("\n %d", st[i]);
			printf("\n");
		}
	}
}

int peek(int st[]){
	if(top == -1){
		printf("\nSTACK IS EMPTY\n");
		return -1;	
	}
	else return (st[top]);
}

