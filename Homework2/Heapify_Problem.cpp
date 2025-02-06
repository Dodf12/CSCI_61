

#include <iostream>
using namespace std;

// Defining heapify function.
void heapify(int arr[], int n, int i)
 {
    
    // Initializing variables.
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // See if the root is less than the left child
    if (left < n && arr[left] > arr[largest]) largest = left;

    // Check if the largest value so far is less than right child
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) 
    {

        //Swapping the elements
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        // Heapifying recursively
        heapify(arr, n, largest);
    }
}

// Defining buildHeap function.
void buildHeap(int arr[], int len)
 {
    // Traversing from last non-leaf node to root.
    for (int i = (len / 2) - 1; i >= 0; i--)
    {
      heapify(arr, len, i);
    }
}

int main()
{
   // Declaring constant and array.
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18};
    
    // Outputting originals to user.
    cout << "Original heap: ";
    for (int i = 0; i < 9; i++)
    {
      cout << arr[i] << " ";
    } 
    cout << endl;
    
    // Building heap & sorting elements for max heap.
    buildHeap(arr, 9);
    
    // Outputting results to user. Ending program with newline.
    cout << "Heapified: ";
    for (int i = 0; i < 9; i++)
    {
      cout << arr[i] << " ";
    } 
    cout << endl;

    return 0;
}