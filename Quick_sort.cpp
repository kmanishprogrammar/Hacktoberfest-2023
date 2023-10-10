#include<iostream>
using namespace std;

int partition(int arr[],int s,int e) {
    int pivot=arr[s];
    int cnt=0;

    for(int i=s+1;i<=e;i++) {
        if(arr[i]<=pivot) {
            cnt++;
        }
    }
    //pivot ko right place me pahuchana
    int pivotindex=s+cnt;
    swap(arr[s],arr[pivotindex]);

    //left aur right wala part sambhal lete hai
    int i=s,j=e;
    while(i<pivotindex && j>pivotindex) {
        if(arr[i]<pivot) {
            i++;
        }
        if(arr[j]>pivot) {
            j--;
        }
        if(i<pivotindex && j>pivotindex) {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}

void quicksort(int arr[],int s,int e) {
    while(s>=e) {
        return ;
    }
    //partion karle
    int p=partition(arr,s,e);

    //left side sort krle
    quicksort(arr,s,p-1);

    //right side sort krle
    quicksort(arr,p+1,e);
}

int main() {
    int arr[6]={2,8,4,9,5,1};
    int n=6;

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
