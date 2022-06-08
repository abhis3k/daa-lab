#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"\t";
}

int partition(int arr[], int p, int r){
    int key=arr[r];
    int i=p-1, j, temp;

    for(j=p; j<r; j++){
        if(arr[j]<=key){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i],&arr[r]);
    return i;
}

void quickSort(int arr[], int p, int r){
    if(p<r){
        int q;
        q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

int main(){
    int arr[]={2,3,1,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    print(arr,size);
    return 0;
}