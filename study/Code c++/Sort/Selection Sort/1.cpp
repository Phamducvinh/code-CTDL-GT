#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y){
    int z=x;
    x=y;
    y=z;
}

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j = i+1; j < n; j++){
            if(a[j] < a[i]){
                swap(a[i],a[j]);
            }
        }
    }
}
void selectionSort1(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(a[i],a[min]);
    }
}
void bubbleSort(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j = 0;j<n-1;j++){
            if(a[j] > a[j + 1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

void InsertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int x = a[i], pos = i - 1;
        while(pos >= 0 && x < a[pos]){
            a[pos + 1] = a[pos];
        }
        a[pos + 1] = x;
    }
}
int cnt[10000];
void CoutingSort(int a[], int n){
    int m = INT_MIN;
    for(int i=0;i<n;i++){
        //cin >> a[i];
        cnt[a[i]]++;
        m = max(m, a[i]);
    }
    cout << "Couting Sort: ";
    for(int i=0;i<=m;i++){
        if(cnt[i] != 0){
            for(int j=0;j<cnt[i];j++){
                cout << i << " ";
            }
        }
    }
}

void merge(int a[], int left, int mid, int right){
    int i = left;// bên trái
    int j = mid + 1;//bên phải
    int v = 0;

    int resul[right-left + 1];
    while(i <= mid && j <= right){
        if(a[i] < a[j]){
            resul[v] = a[i];
            i++;
        }else{
            resul[v] = a[j];
            j++;
        }
        v++;
    }

    while(i <= mid){
        resul[v] = a[i];
        i++;
        v++;
    }
    while(j <= right){
        resul[v] = a[j];
        j++;
        v++;
    }
    
}
void mergeSort(int a[], int left,int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

void quickSort(int a[],int d, int c){
    int l = d;
    int r = c;
    int m = a[(d + c)/2];
    do
    {
        while(a[l] < m) l++;
        while(a[r] > m) r--;
        if(l <= r){
            swap(a[l],a[r]);
            l++;
            r--;
        }
    } while (l < r);
    if(l<c) quickSort(a,l,c);
    if(d<r) quickSort(a,d,r);
    
}

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && a[left] > a[largest]){
        largest = left;
    }
    if(right < n && a[right] > a[largest]){
        largest = right;
    }
    if(largest != i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

void heapSort(int a[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(a,n,i);
    }
    for(int i = n - 1; i>= 0; i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main(){
    int a[] = {38,27,43,3,9,82,10};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "------------------------------------------\n";
    selectionSort(a,n);
    cout << "Selection Sort: ";
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n------------------------------------------\n";

    selectionSort1(a,n);
    cout << "Selection Sort1: ";
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }

    cout << "\n------------------------------------------\n";

    bubbleSort(a,n);
    cout << "Bubble Sort: ";
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n------------------------------------------\n";

    InsertionSort(a,n);
    cout << "Insertion Sort: ";
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n------------------------------------------\n";
    
    CoutingSort(a,n);
    
    cout << "\n------------------------------------------\n";
    cout << "Merge Sort: ";
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n------------------------------------------\n";
    cout << "Quick Sort: ";
    quickSort(a,1,n-1);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n------------------------------------------\n";
    cout << "Heap Sort: ";
    heapSort(a,n);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}