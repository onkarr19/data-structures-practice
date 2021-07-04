# include <iostream>
using namespace std;

#define get(a) int a; cin >> a;
#define println(a) cout << a << '\n';
#define print(a) cout << a << " ";
#define size(arr) sizeof(arr)/sizeof(arr[0])


int maxElement(int a[], int n) {
    int max = 0;
    for (int i=0; i<n; ++i) {
        if (a[i]>max) max = a[i];
    }
    return max;
}


void countSort(int a[], int n) {
    int max = maxElement(a,n);

    int count[max+1] = {0};
    for (int i=0; i<n; ++i) {
        count[a[i]]++;
    }

    int i=0,j=0;
    while (i<=max) {
        if(count[i]>0){
            a[j] = i;
            count[i]--;
            j++;
        }
        else i++;
    }    

}


int main() {
    int arr[7] = {2,6,3,8,45,37,3};
    int n = size(arr);

    for (int i=0; i<n; ++i) print(arr[i]);

    println(' ');
    countSort(arr, n);
    for (int i=0; i<size(arr); ++i) print(arr[i]);

    return 0;
}