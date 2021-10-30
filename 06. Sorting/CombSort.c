#include <stdio.h>  
#include<math.h>  
  
int updatedGap(int gap)  
{  
    // Shrink gap by Shrink factor  
    gap = floor(gap/1.3);  
  
    if (gap < 1)  
        return 1;  
    return gap;  
}  
  
  
// Function to sort array elements using Comb Sort  
void combSort(int a[], int n)  
{  
    int gap = n; /* Initialize gap size equal to the size of array */  
  
    int swapped = 1;  
  
    while (gap != 1 || swapped == 1)  
    {  
        gap = updatedGap(gap); // find updated gap  
        // Initialize swapped as false so that we can  
        // check if swap happened or not  
        swapped = 0;  
  
        for (int i = 0; i < n-gap; i++) /* Compare all elements with current gap */  
        {  
            if (a[i] > a[i+gap]) //swap a[i] with a[i+gap]  
            {  
                int temp = a[i];    
                a[i] = a[i+gap];    
                a[i+gap] = temp;    
                swapped = 1;  
            }  
        }  
    }  
}  
void printArr(int a[], int n) /* function to print array elements */  
{  
    for (int i=0; i<n; i++)  
        printf("%d ", a[i]);  
}  
  
int main()  
{  
    int a[] = {49, 11, 24, 44, 29, 27, 2};  
    int n = sizeof(a)/sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    combSort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
}  
