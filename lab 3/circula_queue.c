/*wap to implement menu driven program of circular queue enqueue, dequeue, 
display all element , display front exit */
#include<stdio.h>
#include<stdlib.h>
#define size 5

int queue [size], front = -1, rear  = -1;
int is_full()
{
    return (front == 0 && rear == size - 1) || (rear+1)% size == front;
}
int is_empty()
{
return front == -1;

}

void enqueue ()
{
    if(is_full())
    {
        printf("Queue is full\n");
        return ;

    }
    int value;
    printf("Enter the elemnt to be enquqed \n");
    scanf("%d",&value);
    if(front == -1) front = 0;
    rear = (rear+1) % size;
    queue[rear]= value ;
    printf("Enqueued: %d\n",value);

}

void dequeue()
{
    if(is_empty()){
        printf("Queue is empty\n");
        return ;
    }
    printf("Dequeued : %d\n", queue[front]);
    if(front == rear){
        front = rear = -1;
    } else{
        front = (front + 1) % size;
    }


}


void display()
{
     if(is_empty()){
        printf("Queue is empty\n");
        return ;
    }
    printf("Queue elemnt: ");
    int i= front;
    while(1){
        printf("%d ", queue[i]);
        if(i== rear) 
        break;
        i = (i+1)% size;

    }
    printf("\n");
}

void displayfront()
{
     if(is_empty()){
        printf("Queue is empty\n");
        return ;
    } else {
        printf("front element :%d\n",queue[front]);
    }

}
int main()
{
    int choice, value;
    while(1){
        printf("Circular Queue operation : \n");
        printf("1. Enqueue \n2.Dequeue \n3.Display all element \n4.Display front Element \n5.Exit\n");
        printf(" Enter your choice :");
        scanf("%d", &choice);

        switch (choice){
            case 1:
           // printf("Enter the value to enqueud:");
            //scanf("%d",&value);
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            case 3: 
            display();
            break;

            case 4: 
            displayfront();
            break;

            case 5: 
            printf("Exiting\n");
            exit(0);

            default : 
            printf("Invalid choice\n");

        }
    }
    return 0;
}