#include <stdio.h>
#include <string.h>
struct student {
int stu_no;
char name[20];
float marks;
};
struct student stu[5];
 
void create() {
    for (int i = 0; i < 5; i++) {
        printf("Enter student no, name, marks: ");
        scanf("%d %s %f", &stu[i].stu_no, stu[i].name, &stu[i].marks);
    }
}
void display() {
    printf("\nstu No\tName\tmarks\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t%s\t%.2f\n", stu[i].stu_no, stu[i].name, stu[i].marks);
    }
}
void modify() {
    int no;
    printf("Enter student no to modify: ");
    scanf("%d", &no);
 
    for (int i = 0; i < 5; i++) {
        if (stu[i].stu_no == no) {
            printf("Enter new name, marks: ");
            scanf("%s %f", stu[i].name, &stu[i].marks);
            printf("Record updated.\n");
            return;
        }
    }
    printf("student not found.\n");
}
 
void search() {
    int no;
    printf("Enter student no to search: ");
    scanf("%d", &no);
 
    for (int i = 0; i < 5; i++) {
        if (stu[i].stu_no == no) {
            printf("Found: %d\t%s\t%.2f\n", stu[i].stu_no, stu[i].name, stu[i].marks);
            return;
        }
    }
    printf("student not found.\n");
}
 
void sort() {
    struct student temp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (stu[j].stu_no > stu[j + 1].stu_no) {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    printf("Sorted by student no.\n");
}
 
int main() {
    int choice;
 
    do {
        printf("\n1.Create 2.Display 3.Modify 4.Search 5.Sort 6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: modify(); break;
            case 4: search(); break;
            case 5: sort(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
 
    return 0;
}
