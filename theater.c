#include<stdio.h>
#include<stdlib.h>
#define ROWS 10
#define SEATS 7

typedef struct Seat
{
    int seatNo;
    struct Seat* prev;
    struct Seat* next;
} Seat;

Seat* head[ROWS];

Seat* createSeat(int seatNo)
{
    Seat* newSeat = (Seat*)malloc(sizeof(Seat));
    newSeat->seatNo = seatNo;
    newSeat->prev = newSeat->next = NULL;
    return newSeat;
}

void initilizeTheatre()
{
    for(int i = 0; i < ROWS; i++)
    {
        head[i] = NULL;
        for(int j = 1; j <= SEATS; j++)
        {
            Seat* newSeat = createSeat(j);
            if(head[i] == NULL)
            {
                head[i] = newSeat;
            }
            else
            {
                Seat* temp = head[i];
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newSeat;
                newSeat->prev = temp;
            }
        }
    }
}

void displaySeats()
{
    printf("\nAvailable Seats\n");
    for(int i = 0; i < ROWS; i++)
    {
        printf("Row %d:", i + 1);
        Seat* temp = head[i];
        if (!temp)
        {
            printf(" No seats available");
        }
        while(temp != NULL)
        {
            printf(" %d", temp->seatNo);
            temp = temp->next;
        }
        printf("\n");
    }
}

void bookSeat(int row, int seatNo)
{
    if(row < 1 || row > ROWS)
    {
        printf("Invalid Row!\n");
        return;
    }
    if(seatNo < 1 || seatNo > SEATS)
    {
        printf("Invalid Seat Number!\n");
        return;
    }
    Seat* temp = head[row - 1];
    while(temp != NULL && temp->seatNo != seatNo)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Seat %d in Row %d is already booked or invalid\n", seatNo, row);
        return;
    }

    if(temp->prev)
    {
        temp->prev->next = temp->next;
    }
    if(temp->next)
    {
        temp->next->prev = temp->prev;
    }
    if(temp == head[row - 1])
    {
        head[row - 1] = temp->next;
    }
    free(temp);
    printf("Seat %d in Row %d booked successfully!!\n", seatNo, row);
}

void cancelSeat(int row, int seatNo)
{
    if(row < 1 || row > ROWS)
    {
        printf("Invalid Row!!\n");
        return;
    }
    if(seatNo < 1 || seatNo > SEATS)
    {
        printf("Invalid Seat Number!!\n");
        return;
    }

    Seat* tempCheck = head[row - 1];
    while(tempCheck)
    {
        if(tempCheck->seatNo == seatNo)
        {
            printf("Seat %d in Row %d is already available.\n", seatNo, row);
            return;
        }
        tempCheck = tempCheck->next;
    }

    Seat* newSeat = createSeat(seatNo);
    Seat* temp = head[row - 1];

    if(!temp || seatNo < temp->seatNo)
    {
        newSeat->next = head[row - 1];
        if(head[row - 1])
        {
            head[row - 1]->prev = newSeat;
        }
        head[row - 1] = newSeat;
        printf("Booking cancelled: Seat %d in Row %d is now available!!\n", seatNo, row);
        return;
    }

    while(temp->next && temp->next->seatNo < seatNo)
    {
        temp = temp->next;
    }

    newSeat->next = temp->next;
    if(temp->next)
    {
        temp->next->prev = newSeat;
    }
    temp->next = newSeat;
    newSeat->prev = temp;
    printf("Booking cancelled: Seat %d in Row %d is now available!!\n", seatNo, row);
}

int main()
{
    initilizeTheatre();

    int choice, row, seatNo;
    while(1)
    {
        printf("\n----- CINEMAX TICKET BOOKING SYSTEM -----\n");
        printf("1. Display available seats\n");
        printf("2. Book a seat\n");
        printf("3. Cancel a booking\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displaySeats();
                break;

            case 2:
                printf("Enter Row (1-10) and Seat (1-7): ");
                scanf("%d %d", &row, &seatNo);
                bookSeat(row, seatNo);
                break;

            case 3:
                printf("Enter Row (1-10) and Seat (1-7): ");
                scanf("%d %d", &row, &seatNo);
                cancelSeat(row, seatNo);
                break;

            case 4:
                printf("Exiting... Thank you!\n");
                exit(0);

            default:
                printf("!! Invalid Choice !!\n");
        }
    }

    return 0;
}
 
