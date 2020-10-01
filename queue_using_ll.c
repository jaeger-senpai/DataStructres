#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* insert(Node*);
Node* del(Node*);
void display(Node*);

int main(){
    int ch;
    Node *Front = NULL,*Rear = NULL;
    do{
        printf("\n1 Insert\n2 Delete\n3 Display\n4 Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                Rear = insert(Rear);
                if(Front == NULL)
                    Front = Rear;
                break;
            case 2:
                Front = del(Front);
                if(Front == NULL)
                    Rear = NULL;
                break;
            case 3:
                display(Front);
                break;
        }   // End of switch statement
    }while(ch<=3);
    return 0;
}

Node* insert(Node* rear){
    int n;
    Node *p = NULL;
    p = (Node*)malloc(sizeof(Node));
    if(p != NULL){
        printf("\nEnter value to insert: ");
        scanf("%d",&n);
        p->data = n;
        if(rear == NULL)
            rear = p;
        else{
            rear->next = p;
            rear = p;
        }
        rear->next = NULL;
    }
    return rear;
}

Node* del(Node* front){
    Node *p = NULL;
    if(front == NULL)
        printf("\nNothing to delete\n");
    else{
        printf("\nData of the deleted node: %d",front->data);
        p = front;
        front = front->next;
        free(p);
    }
    return front;
}

void display(Node* front){
    if(front == NULL)
        printf("Nothing to Display\n");
    else{
        while(front != NULL){
            printf("\n%d",front->data);
            front = front->next;
        }
    }
}