#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    int temp;

    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != root){
        temp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = temp;
        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    int temp;
    for (int i=n/2; i>=0; i--){
        heapify(arr, n, i);
    }
    for (int i=n-1; i>=0; i--){
       temp = arr[0];
       arr[0] = arr[i];
       arr[i] = temp;
       heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int n;
   cout << "Number of elements:" << endl;
   cin >> n;

   int heap_arr[n];
   cout << "Enter numbers in array separated by space:" << endl;
   for (int i=0; i<n; i++){
    cin >> heap_arr[i];
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}

