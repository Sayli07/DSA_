//Create array of 10 students(rollno, name, marks) and sort students by their marks. 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

# define SIZE 10
#define swap (int a, int b){int t = a; a=b;b=t;}


struct student
{
    int rollno;
    char name[30];
    float marks;
};
void Insertion_sort(struct student *arr,int s);


void main (){
struct student std[SIZE];
int arr[SIZE];
//srandom(time(NULL));

for (int i=0;i<10;i++){
    strcpy(std[i].name,"name");
    std[i].rollno=i;
    std[i].marks=random()%100;
}
for(int j=0;j<10;j++)
{
    printf("%.2f %s %-10d\n",std[j].marks,std[j].name,std[j].rollno);
}

Insertion_sort(std,SIZE);

printf("output---------------------------------------------------\n");
    printf("marks,name,     rollno\n");

for(int j=0;j<10;j++)
{
    
    printf("%.2f %s %6d\n",std[j].marks,std[j].name,std[j].rollno);
}

}


void Insertion_sort(struct student *arr,int s)
{
    struct student temp;
    int i,j,iterations,comparison;
    for(i = 1; i < s;i++)
    {
        iterations ++;
        temp.marks = arr[i].marks;
        temp.rollno=arr[i].rollno;
        strcpy(temp.name,arr[i].name);
        for(j = i-1; j >= 0 && temp.marks < arr[j].marks; j--)
        {
            comparison++;
            arr[j+1].marks = arr[j].marks;
            strcpy(arr[j+1].name,arr[j].name);
            arr[j+1].rollno=arr[j].rollno;
        }
        arr[j+1].marks= temp.marks;
        arr[j+1].rollno= temp.rollno;
        strcpy(arr[j+1].name, temp.name);
        
    }
}