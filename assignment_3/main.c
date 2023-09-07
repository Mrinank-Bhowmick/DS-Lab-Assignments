#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverse(struct Node* head) {
    struct Node* curr = head;
    printf("List: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int isEmpty(struct Node* head) {
    return head == NULL;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1) {
        return insertAtBeginning(head, data);
    }

    struct Node* newNode = createNode(data);
    struct Node* curr = head;
    int currPos = 1;

    while (currPos < pos - 1 && curr != NULL) {
        curr = curr->next;
        currPos++;
    }

    if (curr == NULL) {
        printf("Invalid position\n");
        return head;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return head;
    }
    if (pos == 1) {
        return deleteFromBeginning(head);
    }
    struct Node* curr = head;
    int currPos = 1;
    while (currPos < pos - 1 && curr != NULL) {
        curr = curr->next;
        currPos++;
    }
    if (curr == NULL || curr->next == NULL) {
        printf("Invalid position\n");
        return head;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return head;
}

struct Node* deleteByKey(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* curr = head;
    while (curr->next != NULL && curr->next->data != key) {
        curr = curr->next;
    }
    if (curr->next == NULL) {
        printf("Key not found\n");
        return head;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return head;
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

int searchElement(struct Node* head, int key) {
    struct Node* curr = head;
    int pos = 1;
    while (curr != NULL) {
        if (curr->data == key) {
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    return -1;
}

void deleteList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int c, data, pos, key;
    
    printf("\nMenu:\n");
        printf("1: Traversal\n");
        printf("2: Empty checking\n");
        printf("3: Insert the node at the beginning\n");
        printf("4: Insert the node at the end\n");
        printf("5: Insert the node at a position\n");
        printf("6: Delete the node from the beginning\n");
        printf("7: Delete the node from the end\n");
        printf("8: Delete the node at a position\n");
        printf("9: Delete the node for the key\n");
        printf("10: Total number of nodes\n");
        printf("11: Search the element\n");
        printf("12: Quit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                traverse(head);
                break;
            case 2:
                if (isEmpty(head)) {
                    printf("List is empty.\n");
                } else {
                    printf("List is not empty.\n");
                }
                break;
            case 3:
                printf("Enter the data to be inserted at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 4:
                printf("Enter the data to be inserted at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                head = insertAtPosition(head, data, pos);
                break;
            case 6:
                head = deleteFromBeginning(head);
                break;
            case 7:
                head = deleteFromEnd(head);
                break;
            case 8:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                break;
            case 9:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                head = deleteByKey(head, key);
                break;
            case 10:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;
            case 11:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                pos = searchElement(head, key);
                if (pos != -1) {
                    printf("Element found at position %d\n", pos);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 12:
                deleteList(head);
                printf("The linked list is deleted, and memory is deallocated. Quitting from the main program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }
}
