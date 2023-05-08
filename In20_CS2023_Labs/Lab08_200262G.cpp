#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify

    int max = root; // Initialize max as root Since we are using 0 based indexing
    int l = 2 * root + 1; // left = 2*i + 1
    int r = 2 * root + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[max])
        max = l;
 
    // If right child is larger than max so far
    if (r < n && arr[r] > arr[max])
        max = r;
 
    // If max is not root
    if (max != root) {
        swap(arr[root], arr[max]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, max);
    }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{

    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
  
   // extracting elements from heap one by one
   
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
    // vary input as required
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}