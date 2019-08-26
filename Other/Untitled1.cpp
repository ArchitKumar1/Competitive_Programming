#include<iostream>
#include<algorithm>
using namespace std;
#define N 75000
void printArray(int arr[], int size) 
{ 
    for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<endl;
	} 
} 
void bubblesort(int a[])
{
	for(int i=0;i<N-1;i++)
	{
		for(int j=0;j<N-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	printArray(a,N);
	
}

  
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  

int main()
{
	int a[N];
	for(int i=0;i<N;i++)
	{
		a[i]=rand()%100000;
	}
	bubblesort(a);
	//quickSort(a,0,N-1);
	printArray(a,N);
	
}
