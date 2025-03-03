#include <iostream>
#include <map>

//Problem 1
int findJoey(int arr[], int size, int joey)
{
    for(int i = 0; i < size; i++)
    {
        if (arr[i] == i)
        {
            return i;
        }
    }

    return -1;
}

//Functions Associated with Searching QUestion 2
int findIndexOfElement(int arr[], int size, int low, int high, int X)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] ==X)
            return mid;

        if (arr[mid] < X)
            low = mid + 1;

        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

void findNClosestElements(int arr[],int size, int elementIndex, int N)
{
    //First int is the element in the array, second elemtn is the difference
    std::map<int,int> differences;

    int i = elementIndex+1;
    while (i < elementIndex + N  && i < size )
    {
        //std::cout << arr[i] << "," << arr[i] - arr[elementIndex] << std::endl;
        differences[arr[i]] = arr[i] - arr[elementIndex];
        i++;
    }

    int j = elementIndex-1;
    while (j > elementIndex - N && j >= 0 )
    {
        //std::cout << arr[j] << "," << std::abs(arr[j] - arr[elementIndex]) << std::endl;
        differences[arr[j]] =  arr[elementIndex] - arr[j];
        j--;
    }

    for (auto& pair: differences)
    {
        std::cout << "(" << pair.first << "," << pair.second << ")" << std::endl;
    }

    //REversing the differences hashmap, so I can find the elements with the smallest distance away
    std::map<int,int> reversed;
    for (auto& pair: differences)
    {
        reversed[pair.second] = pair.first;
    }

    int counter = 0;
    for (auto& pair: reversed)
    {
        std::cout << pair.second << " ";
        counter++;
        if (counter == N) {break;}
    }


}

int main()
{
    //Testing problem one
    int a[] = {1,5,2,6,7,3};
    std::cout << findJoey(a,6,2) << std::endl;

    //Testing Problem Two
    // int arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};

    // int index = findIndexOfElement(arr,13,0,12,35);
    // std::cout << "Element is at index: " << index << std::endl;
    // findNClosestElements(arr, 13, index, 4);

    int arr2[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};

    int index2 = findIndexOfElement(arr2,13,0,12,16);
    std::cout << "Element is at index: " << index2 << std::endl;
    findNClosestElements(arr2, 13, index2, 3);

    return 0;
}