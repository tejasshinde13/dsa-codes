#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
 
typedef struct Node { 
    int PRN; 
    char name[50]; 
    struct Node* next; 
} Node; 
 
Node* createNode(int PRN, char* name) { 
    Node* newnode = (Node*)malloc(sizeof(Node)); 
    strcpy(newnode->name, name); 
    newnode->PRN = PRN; 
    newnode->next = NULL; 
    return newnode; 
} 
 
Node* addPresident(Node* head, int PRN, char* name) { 
    Node* newnode = createNode(PRN, name); 
    newnode->next = head; 
    return newnode; 
} 
 
Node* addSecretary(Node* head, int PRN, char* name) { 
    Node* newnode = createNode(PRN, name); 
    if (head == NULL) 
        return newnode; 
    Node* temp = head; 
    while (temp->next != NULL) 
        temp = temp->next; 
    temp->next = newnode; 
    return head; 
} 
 
Node* addMember(Node* head, int PRN, char* name) { 
    Node* newnode = createNode(PRN, name); 
    if (head == NULL || head->next == NULL) { 
        printf("Error: Need at least President and Secretary.\n"); 
        return head; 
    } 
    Node* temp = head; 
    while (temp->next->next != NULL) 
        temp = temp->next; 
    newnode->next = temp->next; 
    temp->next = newnode; 
    return head; 
} 
 
Node* deletePresident(Node* head) { 
    if (head == NULL) 
        return NULL; 
    Node* temp = head; 
    head = head->next; 
    free(temp); 
    return head; 
} 
 
Node* deleteSecretary(Node* head) { 
    if (head == NULL || head->next == NULL) 
        return NULL; 
    Node* temp = head; 
    while (temp->next->next != NULL) 
        temp = temp->next; 
    free(temp->next); 
    temp->next = NULL; 
    return head; 
} 
 
Node* deleteMember(Node* head, int PRN) { 
    if (head == NULL || head->next == NULL || head->next->next == NULL) { 
        printf("Error: Not enough members.\n"); 
        return head; 
    } 
    Node* prev = head; 
    Node* curr = head->next; 
    while (curr->next != NULL && curr->PRN != PRN) { 
        prev = curr; 
        curr = curr->next; 
    } 
    if (curr == head || curr->next == NULL) { 
        printf("Error: Member not found or trying to delete President/Secretary.\n"); 
        return head; 
    } 
    prev->next = curr->next; 
    free(curr); 
    return head; 
} 
 
int countMembers(Node* head) { 
    int count = 0; 
    Node* temp = head; 
    while (temp != NULL) { 
        count++; 
        temp = temp->next; 
    } 
    return count; 
} 
 
void displayMembers(Node* head) { 
    if (head == NULL) { 
        printf("The list is empty.\n"); 
        return; 
    } 
    Node* temp = head; 
    printf("Club Members:\n"); 
    while (temp != NULL) { 
        printf("PRN: %d, Name: %s\n", temp->PRN, temp->name); 
        temp = temp->next; 
    } 
} 
 
Node* concatenateLists(Node* head1, Node* head2) { 
    if (head1 == NULL) return head2; 
    Node* temp = head1; 
    while (temp->next != NULL) 
        temp = temp->next; 
    temp->next = head2; 
    return head1; 
} 
 
int main() { 
    Node* head = NULL; 
    Node* head2 = NULL; 
    int choice, PRN; 
    char name[50]; 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Add President\n"); 
        printf("2. Add Secretary\n"); 
        printf("3. Add Member\n"); 
        printf("4. Delete President\n"); 
        printf("5. Delete Secretary\n"); 
        printf("6. Delete Member by PRN\n"); 
        printf("7. Display Members\n"); 
        printf("8. Count Members\n"); 
        printf("9. Concatenate Two Lists\n"); 
        printf("10. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter President PRN and Name: "); 
                scanf("%d %s", &PRN, name); 
                head = addPresident(head, PRN, name); 
                break; 
            case 2: 
                printf("Enter Secretary PRN and Name: "); 
                scanf("%d %s", &PRN, name); 
                head = addSecretary(head, PRN, name); 
                break; 
            case 3: 
                printf("Enter Member PRN and Name: "); 
                scanf("%d %s", &PRN, name); 
                head = addMember(head, PRN, name); 
                break; 
            case 4: 
                head = deletePresident(head); 
                break; 
            case 5: 
                head = deleteSecretary(head); 
                break; 
            case 6: 
                printf("Enter Member PRN to Delete: "); 
                scanf("%d", &PRN); 
                head = deleteMember(head, PRN); 
                break; 
            case 7: 
                displayMembers(head); 
                break; 
            case 8: 
                printf("Total Members: %d\n", countMembers(head)); 
                break; 
            case 9: 
                printf("Enter details for second list:\n"); 
                while (1) { 
                    printf("1. Add President to list 2\n"); 
                    printf("2. Add Secretary to list 2\n"); 
                    printf("3. Add Member to list 2\n"); 
                    printf("4. Done adding to list 2\n"); 
                    int ch2; 
                    scanf("%d", &ch2); 
                    if (ch2 == 4) break; 
                    printf("Enter PRN and Name: "); 
                    scanf("%d %s", &PRN, name); 
                    if (ch2 == 1) head2 = addPresident(head2, PRN, name); 
                    else if (ch2 == 2) head2 = addSecretary(head2, PRN, name); 
                    else if (ch2 == 3) head2 = addMember(head2, PRN, name); 
                } 
                head = concatenateLists(head, head2); 
                break; 
            case 10: 
                exit(0); 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
    return 0; 
}
