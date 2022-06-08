#include <iostream>

using namespace std;

void merge(int arr[], int p, int q, int r){
    int n1, n2;
    n1=q-p+1;
    n2=r-q;

    int la[n1+1], ra[n2+1];

    for(int i=0,j=0,k=p; k<=r; k++){
        if(k<=q){
            la[i]=arr[k];
            i++;
        }
        else{
            ra[j]=arr[k];
            j++;
        }
    }

    la[n1]=9999; ra[n2]=9999;

    for(int i=0,j=0,k=p; k<=r; k++){
        if(la[i]>=ra[j]){
            arr[k]=ra[j];
            j++;
        }
        else{
            arr[k]=la[i];
            i++;
        }
    }
}

void mergeSort(int arr[], int p, int r){
    if(p<r){
        int q=(p+r)/2;
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

int main(){
    int arr[]={3,2,5,4,1},size;
    size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }

    return 0;
}