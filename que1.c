//implement linear and binary search using recursion

#include<stdio.h>
#define SIZE 9

int linear_search(int arr[],int key,int);
int rec_binary_search(int arr[],int key, int left,int right);
int comparisons;
int i;
int main()
{
    int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
    int key;

    // step 1 : Accept the key from the user
    printf("Enter the key to Search :");
    scanf("%d",&key); // 77

    int index = linear_search(arr,key,0);

    if(index == -1)
        printf("Key not Found !\n");
    else
        printf("Key is found at index(linear search )%d\n",index);

    printf("Comparisons = %d\n",comparisons);

    int index2 = rec_binary_search(arr,key,0,SIZE-1);

    if(index2== -1)  
        printf("Recursion : Key not Found !\n");
    else
        printf(" Recursion : Key found at index (binary search)= %d\n",index);
    return 0;
}

int linear_search(int arr[],int key,int index1)
{   
    int result;
    // step 2: start the traversal from 0th index
    comparisons ++;
    if (index1>=SIZE)
         return -1;
     //return (key == arr[i])?i:linear_search(arr,key);
    if (arr[index1] ==key)
     {
      return index1;
     }
    else 
    {
        result = linear_search(arr,key,index1+1);
    }
    return result;
}

int rec_binary_search(int arr[],int key, int left,int right)
{
    if ( left > right)
        return -1; 

    int result, mid;

    mid = (left + right) / 2; 
    int x = arr[mid];

    if(key == arr[mid])
        return mid;

    if(key < arr[mid]) 
    {
        result = rec_binary_search(arr,key,left,mid-1);
    }
    else 
    {
        result = rec_binary_search(arr,key,mid+1,right);
    }

    return result;
}