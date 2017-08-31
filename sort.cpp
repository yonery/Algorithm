#include <iostream>
using namespace std;

#define MAX 1000

int N;
int arr[MAX];

//버블정렬
void bubble(int N) {
	for (int i = 0; i < N-1; i++) {
		for (int j = N - 1; j > i; j--) {
			if (arr[j-1] > arr[j]) {
				//swap이용
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}

}
//삽입정렬
void insert(int N) {
	int* b = new int[N];
	b[0] = arr[0];
	for (int i = 1; i < N; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (b[j] > arr[i]) {
				b[j + 1] = b[j];
				b[j] = arr[i];
			}
			else {
				b[j+1] = arr[i];
				break;
			}
		}
	}

	for (int i = 0; i < N; i++)
		arr[i] = b[i];
	free(b);

}
//선택정렬
void select(int N) {
	for (int i = 0; i < N; i++) {
		int min_idx = i;
		int min = arr[i];
		for (int j = i; j < N; j++) {
			if (min > arr[j]) {
				min = arr[j];
				min_idx = j;
			}
		}
		//swap
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}

}
//합병정렬
void merge_sort(int s, int m, int e, int arr[]) {
	int* a = new int[N];
	int index=s, l=s, r=m+1;

	while (l <= m&& r<= e) {
		if (arr[l] < arr[r])
			a[index++] = arr[l++];
		else
			a[index++] = arr[r++];
	}
	if (l > m)
		for (int i = r; i <= e; i++)
			a[index++] = arr[i];
	if (r > e)
		for (int i = l; i <= m; i++)
			a[index++] = arr[i];
	
	for (int i = s; i <= e; i++) {
		arr[i] = a[i];
	}
	free(a);
}
void dnc(int s, int e, int arr[]) {
	if (s == e)
		return;

	int m = (s + e) / 2;

	dnc(s, m, arr);
	dnc(m + 1, e, arr);

	merge_sort(s, m, e, arr);
}

void merge(int N) {
	dnc(0, N-1, arr);
}
//퀵정렬
int partition(int s, int e, int arr[]) {
	int p, l, r;

}

void quick_sort(int s, int e, int arr[]) {
	if (s >= e)
		return;
	int m = partition(s, e, arr);
	quick_sort(s, m - 1, arr);
	quick_sort(m + 1, e, arr);
}
void quick(int N) {
	quick_sort(0, N - 1, arr);
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//정렬
	quick(N);

	//출력
	for (int i = 0; i < N; i++)
		cout << arr[i] << "\n";


	return 0;
}