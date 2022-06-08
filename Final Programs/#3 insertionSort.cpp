#include <iostream>

using namespace std;

void insertionSort(int arr[], int n){
    int i, j, key;

    for(i=1; i<n; i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            arr[j]=key;
            j--;
        }
    }

    for(i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
}

int main(){
    int arr[]={3,2,5,4,1},size;
    size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,size);
    return 0;
}

//To sort an array of size N in ascending order: 

//Iterate from arr[1] to arr[N] over the array. 
//Compare the current element (key) to its predecessor. 
//If the key element is smaller than its predecessor, compare it to the elements before.
//Move the greater elements one position up to make space for the swapped element.
