Recursive Binary search using C.
Code:-

#include <stdio.h>
int main()
{
int a[100], n, i, j, choice, key;
int low, high, mid, found, temp;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter elements: ");
for(i = 0; i < n; i++)
scanf("%d", &a[i]);
for(;;)
{
printf("\n\n--- MENU ---");
printf("\n1. Display Array");
printf("\n2. Linear Search");
printf("\n3. Binary Search");
printf("\n4. Search an Element");
printf("\n5. Exit");
printf("\nEnter choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
printf("Array: ");
for(i = 0; i < n; i++)
printf("%d ", a[i]);
break;
case 2:
printf("Enter element: ");
scanf("%d", &key);
found = 0;
for(i = 0; i < n; i++)
{
if(a[i] == key)
{
printf("Found at position %d", i + 1);
found = 1;
break;
}
}
if(found == 0)

printf("Not found");
break;
case 3:
/* Sort array */
for(i = 0; i < n - 1; i++)
{
for(j = i + 1; j < n; j++)
{
if(a[i] > a[j])
{
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}
printf("Enter element: ");
scanf("%d", &key);
low = 0;
high = n - 1;
found = 0;
for(; low <= high;)
{
mid = (low + high) / 2;
if(a[mid] == key)
{
printf("Found at position %d", mid + 1);
found = 1;
break;
}
else if(a[mid] < key)
low = mid + 1;
else
high = mid - 1;
}
if(found == 0)
printf("Not found");
break;
case 4:
printf("Enter element: ");

scanf("%d", &key);
found = 0;
for(i = 0; i < n; i++)
{
if(a[i] == key)
{
printf("Found at position %d", i + 1);
found = 1;
break;
}
}
if(found == 0)
printf("Not found");
break;
case 5:
return 0;
default:
printf("Invalid choice");
}
}
}
