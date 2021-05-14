// C++ program for Merge Sort
#include <iostream>
using namespace std;
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(long arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(long arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 
// UTILITY FUNCTIONS
// Function to print an array
void printArray(long A[], int size)
{
    for (size_t i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
// Driver code
int main()
{
     // Creación de un array de los 1 000 000 primeros numeros enteros
    long n = 1000000 ;
    long tam = n;
    long arrayN [tam];

    for (long i = 0; i < tam; i++, n--)
        arrayN[i] = n;
 
    // cout << "Given array is \n";
    // printArray(arrayN, tam);
 
    mergeSort(arrayN, 0, tam - 1);
    cout<<endl;
    cout << "\nSorted array is \n";
    printArray(arrayN, tam);

    cout<<endl;
    
    return 0;
}
