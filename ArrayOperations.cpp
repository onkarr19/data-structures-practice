#include <iostream>
using namespace std;
#define size(array) (sizeof(array)/sizeof(array[0]))


// Time Complexity -> O(n)
void traverse(int  a[], size_t n) {
	for (int i = 0; i<n; ++i)
	{
		cout << i[a] << " ";
	}
	cout << endl;
}


// Sorted, Time Complexity -> O(n)
void insertAtSorted(int a[], size_t size, size_t *n, int num, int pos) {
	if (pos < 0) cout << "array Underflow\n";
	else if (pos < *n && size > *n) {
		for (int i = ++*n; i >= pos-1; --i)
		{
			a[i] = a[i-1];
		}
		a[pos-1] = num;
	} else cout << "array Overflow\n";
}


// Sorted, Time Complexity -> O(n)
void insertAtSortedStart(int a[], size_t size, size_t *n, int num) {
	if (size > *n) {
		for (int i = ++*n; i >= 0; --i)
		{
			a[i] = a[i-1];
		}
		a[0] = num;
	} else cout << "array Overflow\n";
}


// Sorted, Time Complexity -> O(1)
void insertAtSortedEnd(int a[], size_t size, size_t *n, int num) {
	if (size > *n) {
		a[*n] = num;
		++*n;
	} else cout << "array Overflow\n";
}


// Unsorted, Time Complexity -> O(1)
void insertAtUnsorted(int a[], size_t size, size_t *n, int num, int pos) {
	if (pos < 0) cout << "array Underflow\n";
	else if (pos < *n && size > *n) {
		a[*n] = a[pos-1];
		a[pos-1] = num;
		++*n;
	} else cout << "array Overflow\n";
}


// Unsorted, Time Complexity -> O(1)
void insertAtUnsortedStart(int a[], size_t size, size_t *n, int num) {
	if (size > *n) {
		a[*n] = a[0];
		a[0] = num;
		++*n;
	} else cout << "array Overflow\n";
}


// Sorted, Time Complexity -> O(n)
void deleteAtSorted(int a[], size_t *n, int pos) {
	if (pos > 0 && pos < *n) {
		for (int i = pos; i < *n; ++i)
		{
			a[i-1] = a[i];
		}
		--*n;
	}
}


// Sorted, Time Complexity -> O(n)
void deleteAtSortedStart(int a[], size_t *n) {
	for (int i = 0; i < *n; ++i)
	{
		a[i] = a[i+1];
	}
	--*n;
}


// Sorted, Time Complexity -> O(1)
void deleteAtSortedEnd(int a[], size_t *n) {
	--*n;
}


// Unsorted, Time Complexity -> O(1)
void deleteAtUnsortedStart(int a[], size_t *n) {
	a[0] = a[*n-1];
	--*n;
}


// Unsorted, Time Complexity -> O(1)
void deleteAtUnsorted(int a[], size_t *n, int pos) {
	a[pos-1] = a[*n-1];
	--*n;
}


int main() {
	int arr[20];
	size_t n = 9, size = size(arr);
	for (int i = 0; i < n; ++i) arr[i] = i+2;
	
	traverse(arr, n);
	deleteAtUnsorted(arr, &n, 2);


	traverse(arr, n);
	return 0;
}
