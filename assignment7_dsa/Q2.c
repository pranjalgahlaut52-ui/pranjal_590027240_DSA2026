#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

int hashFunction(int key) {
    return (key % 1000) % SIZE;
}

void init() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index = hashFunction(key);

    if(hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        printf("Collision occurred! Using linear probing...\n");
        int i = (index + 1) % SIZE;

        while(i != index) {
            if(hashTable[i] == -1) {
                hashTable[i] = key;
                return;
            }
            i = (i + 1) % SIZE;
        }
        printf("Hash Table is full!\n");
    }
}

void search(int key) {
    int index = hashFunction(key);
    int i = index;

    while(hashTable[i] != -1) {
        if(hashTable[i] == key) {
            printf("Element found at index %d\n", i);
            return;
        }
        i = (i + 1) % SIZE;
        if(i == index) break;
    }
    printf("Element not found\n");
}

void deleteKey(int key) {
    int index = hashFunction(key);
    int i = index;

    while(hashTable[i] != -1) {
        if(hashTable[i] == key) {
            hashTable[i] = -1;
            printf("Element deleted\n");
            return;
        }
        i = (i + 1) % SIZE;
        if(i == index) break;
    }
    printf("Element not found\n");
}

void display() {
    for(int i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;
    init();

    while(1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                search(key);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}
