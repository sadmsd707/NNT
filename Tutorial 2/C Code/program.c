#include <stdio.h>

void insert(int m, int arr[]) {
    printf("enter array elements: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &arr[i]);
}

void display(int m, int arr[]) {
    printf("Array elements: ");
    for (int i = 0; i < m; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void lsearch(int m, int arr[], int key) {
    for (int i = 0; i < m; i++) {
        if (arr[i] == key) {
            printf("found the key element at index %d\n", i);
            return;
        }
    }
    printf("Key element not found.\n");
}

/* Recursive binary search - array must be sorted in ascending order */
void bisearch(int m, int arr[], int low, int high, int key) {
    if (low > high) {
        printf("Key element not found.\n");
        return;                      /* stop here, don't compute mid */
    }
    int mid = low + (high - low) / 2;
    if (key == arr[mid])
        printf("found the key element at index %d\n", mid);
    else if (key < arr[mid])
        bisearch(m, arr, low, mid - 1, key);
    else
        bisearch(m, arr, mid + 1, high, key);
}

void displaymenu(void) {
    printf("\nMENU");
    printf("\n1.display");
    printf("\n2.linear search");
    printf("\n3.binary search (array must be sorted)");
    printf("\n4.exit");
}

int main(void) {
    int m, arr[100], choice, key;

    printf("enter size of array: ");
    scanf("%d", &m);
    if (m < 1 || m > 100) {
        printf("Size must be between 1 and 100.\n");
        return 1;
    }
    insert(m, arr);

    do {
        displaymenu();
        printf("\n\nenter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display(m, arr);
                break;
            case 2:
                printf("enter key element: ");
                scanf("%d", &key);
                lsearch(m, arr, key);
                break;
            case 3:
                printf("enter key element: ");
                scanf("%d", &key);
                bisearch(m, arr, 0, m - 1, key);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    } while (choice != 4);

    return 0;
}
