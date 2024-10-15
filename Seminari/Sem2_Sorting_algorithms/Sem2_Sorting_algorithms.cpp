#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool swaped = false;

        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        }

        if (!swaped)
            break;
    }
}

void selectionSort(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
            swap(arr[minIndex], arr[i]);
    }
}

void insertionSort(vector<int>& arr)
{
    for (int i = 1; i < arr.size() - 1; i++)
    {
        int selectedElement = arr[i];
        int prevIndex = i - 1;
        
        while (prevIndex >= 0 && selectedElement < arr[prevIndex])
        {
            arr[prevIndex + 1] = arr[prevIndex];
            prevIndex--;
        }

        arr[prevIndex + 1] = selectedElement;
    }
}

void merge(vector<int>& arr, vector<int>& left, vector<int>& right)
{
    int index = 0; int leftInd = 0; int rightInd = 0;
    int leftSize = left.size();
    int rightSize = right.size();

    while (leftInd < leftSize && rightInd < rightSize)
    {
        if (left[leftInd] < right[rightInd])
            arr[index++] = left[leftInd++];
        else
            arr[index++] = right[rightInd++];
    }

    while (leftInd < leftSize)
        arr[index++] = left[leftInd++];

    while (rightInd < rightSize)
        arr[index++] = right[rightInd++];
}

void mergeSort(vector<int>& arr)
{
    int midd = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + midd);
    vector<int> right(arr.begin() + midd, arr.end());

    mergeSort(left);
    mergeSort(right);
    merge(arr, left, right);
}

// First solution for quickSort when the pivot is the last element
int partitionFirst(vector<int>& arr, int low, int height)
{
    int pivot = arr[height];
    int l = low;

    for (int j = low; j < height; j++)
    {
        // We are searching for a bigger element than the pivot which than will be equal to l
        // and we will swap it with the pivot at the end of the function
        if (arr[j] <= pivot)
        {
            swap(arr[l], arr[j]);
            l++;
        }
    }

    swap(arr[l], arr[height]);
    return l;
}

void quickSortFirst(vector<int>& arr, int low, int height)
{
    if (low < height)
    {
        int pi = partitionFirst(arr, low, height);

        quickSortFirst(arr, low, pi - 1);
        quickSortFirst(arr, pi + 1, height);
    }
}

// Second solution for quickSort when the pivot is the middle element
template <typename T>
int partitionSecond(T* arr, int len)
{
    int pivot = arr[len / 2];
    int low = 0, height = len - 1;

    while (true)
    {
        while (low < pivot)
            low++;

        while (height > pivot)
            height--;

        if (low < height)
        {
            swap(arr[low], arr[height]);
        }
        else
            return height;
    }

}

template <typename T>
void quickSortSecond(T* arr, int len)
{
    if (len <= 1)
        return;

    int pi = partitionSecond(arr, len);

    quickSortSecond(arr, pi);
    quickSortSecond(arr + pi + 1, len - pi - 1);
}

int main()
{
    std::cout << "Hello World!\n";
}

