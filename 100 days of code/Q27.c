#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection node
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    // Align both lists
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--) p1 = p1->next;
    } else {
        while (diff--) p2 = p2->next;
    }

    // Traverse together
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2)
            return p1;  // intersection found
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL; // no intersection
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *head2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head1 = insertEnd(head1, val);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        head2 = insertEnd(head2, val);
    }

    // 🔴 IMPORTANT: Create intersection manually (for testing)
    // Example: connect last node of list2 to 3rd node of list1 (value 30)
    struct Node* temp1 = head1;
    for (int i = 0; i < 2; i++)   // move to node with value 30
        temp1 = temp1->next;

    struct Node* temp2 = head2;
    while (temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = temp1; // create intersection

    // Find intersection
    struct Node* result = getIntersection(head1, head2);

    if (result != NULL)
        printf("%d", result->data);
    else
        printf("No Intersection");

    return 0;
}