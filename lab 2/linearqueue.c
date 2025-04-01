/*wap to implement menu driven program of liner queue enqueue, dequeue, 
display all element , display front exit */
#include<stdio.h>
#define max 5

int queue[max];
int front = 0;
int rear = -1;
void enqueue (int value){
    if (rear == max-1){
        printf("Queue is full\n");

    }
    else{
        queue[++rear] = value;
        printf("\n%d enqueued to queue\n", value);
    }
}
void dequeue()

{
    if(front > rear){
        printf("Queue is empty\n");

    }else{

        printf("%d dequeued from queue\n",queue[front]);
        front++;

    }
}
void display()
{
    if (front > rear)
    {
        printf("Queue is empty\n");

    }else{
        printf("Queue are :\n");
        for(int i=front; i<=rear; i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }

}
void displayfornt()
{
    if(front > rear){
        printf("Queue is empty\n");

    }else{
        printf("Front element is %d \n", queue[front]);
    }

}

int main()
{
    int choice, value;

    do{
        printf("\nChose the number to perform the task\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display all element\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("Enter the value to enqueued:\t");
            scanf("%d",&value);
            enqueue(value);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            displayfornt();
            break;
            case 5:
            printf("exiting\n");
            break;

            default:
            printf("Invalid choice");


        }


        

    }
    while(choice !=5);
    return 0;
}
