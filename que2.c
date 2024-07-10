//2. Modify selection sort, bubble sort and insertion sort functions to return number of passes and number of comparisons and print both in main function.

// Selection sort

#include<stdio.h>
#define SIZE 6
#define Swap(a,b) { int t = a; a = b; b = t;}

void Selection_sort(int arr[SIZE],int*,int*,int*);
void display(int arr[SIZE]);
void bubble_sort(int arr[SIZE],int*,int*,int*);
void Insertion_sort(int arr[SIZE],int*,int*,int*);



int main()
{
   int arr[SIZE] = {30,20,60,50,10,40};
  //int arr[SIZE] = {11,22,33,44,55,66};
  int iterations=0, comparisons=0 , pass=0;
    printf("\n Before selection Sort :\n");
    display(arr);
    Selection_sort(arr,&iterations,&comparisons,&pass);
    printf("\n After selection Sort :\n");
    display(arr);
    printf("\n selection sort: Iterations = %d  comparisons = %d  passes = %d\n",iterations,comparisons,pass);

    
    int arr1[SIZE] = {31,21,61,41,11,41};
    int iterations1=0, comparisons1=0 , pass1=0;
    printf("\n Before bubble Sort :\n");
    display(arr1);
    bubble_sort(arr1,&iterations1,&comparisons1,&pass1);
    printf("\n After bubble Sort :\n");
    display(arr1);
    printf("\n bubble sort: Iterations = %d  comparisons = %d  passes = %d\n",iterations1,comparisons1,pass1);
    
    int iterations2=0, comparisons2=0, pass2=0;
    int arr2[SIZE] = {32,22,62,52,22,42};
    printf("\n Before insertion Sort :\n");
    display(arr2);
    Insertion_sort(arr2,&iterations2,&comparisons2,&pass2);
    printf("\n After insertion Sort :\n");
    display(arr2);
    printf("\n insertion sort: Iterations = %d  comparisons = %d  passes = %d\n",iterations2,comparisons2,pass2);


    return 0;
}

void Selection_sort(int arr[SIZE],int *iterations,int *comparisons,int *pass)
{
    int sel_pos,pos;
    // Iterations
    for(sel_pos = 0; sel_pos < SIZE-1;sel_pos++)
    {
        // comparisons
        *iterations=*iterations+1;
        for(pos = sel_pos+1; pos < SIZE; pos++)
        {
            *comparisons=*comparisons+1;
            if(arr[sel_pos] > arr[pos])
            {
                // swap
                Swap(arr[sel_pos],arr[pos]);
            }
            else 
             *pass=*pass+1;
        }

    }
    
}


// normal bubble sort
void bubble_sort(int arr[SIZE],int *iterations1,int *comparisons1, int *pass1)
{
    // Iterations
    for(int it = 0; it < SIZE-1; it++)
    {
        // comparisons
        *iterations1=*iterations1+1;
        for(int pos = 0; pos < SIZE-1-it; pos++)
        {
            *comparisons1=*comparisons1+1;
            if(arr[pos] > arr[pos+1])
            {
                // swap
                Swap(arr[pos],arr[pos+1]);
            }
            else 
               *pass1= *pass1+1;
        }
    }
}

void Insertion_sort(int arr[SIZE],int *iterations2,int *comparisons2,int *pass2)
{
    int temp,i,j;
    for(i = 1; i < SIZE;i++)
    {
        *iterations2=*iterations2+1;
        temp = arr[i];
        for(j = i-1; j >= 0 && temp < arr[j]; j--)
        {
            *comparisons2=*comparisons2+1;
            arr[j+1] = arr[j];
        }
        if(j<=0 || temp > arr[j])
            pass2=pass2+1;
        arr[j+1] = temp;
    }
}

void display(int arr[SIZE])
{
    for(int i =0;i<SIZE ; i++)
    {
        printf("%4d",arr[i]);
    }
}