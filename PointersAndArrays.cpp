#include <iostream>
using namespace std;
#define size(a) (sizeof(a)/sizeof(a[0]))


void oneDArray() {
	int arr[] = {10,20,30,40,50,60,70,80,90};
	int *p = arr;
	cout << *p+1 << " " << *arr+1 << endl;
	cout << *(p+1) << " " << *(arr+1) << endl;

	cout << endl;
}


void twoDArray() {
	int arr[][3] = {10,20,30,40,50,60,70,80,90};
	int *p = *arr;
	cout << *p+1 << " " << **arr+1 << endl;
	cout << *(p+1) << " " << *(*arr+1) << endl;
	cout << *(p+1)+1 << " " << **(arr+1) << endl;

	cout << endl;
}


void threeDArray() {
	int arr[][3][3] = {
		10,20,30,40,50,60,70,80,90,
		100,110,120,130,140,150,160,170,180,
		190,200,210,220,230,240,250,260,270
	};
	int *p = **arr;
	cout << *p+1 << " " << ***arr+1 << endl;
	cout << *(p+1) << " " << *(*(*arr+1)) << endl;
	cout << *((p+1)+1) << " " << ***(arr+1) << endl;

	cout << endl;
}

int main() {
	oneDArray();
	twoDArray();
	threeDArray();

	return 0;
}
