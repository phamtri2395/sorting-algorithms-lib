#pragma once

template<class T>
bool check(T arr[], long start, long end) {
	for (long i = start; i <= end; i++)
	if (arr[i] < arr[i - 1]) return false;

	return true;
}
template<class T>
void _swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

/* O(n^2) sorting algorithms in efficency order */
template<class T>
void InsertionSort(T[], long, long); // ( > Selection Sort ) if speed of Copy > Comparision (element not large)
template<class T>
void SelectionSort(T[], long, long); // Do alot of comparisions
template<class T>
void BubbleSort(T[], long, long); // slowest - too much swap

/* O(n log n) sorting algorithms */
template<class T>
void HeapSort(T[], long, long);
template<class T>
void MergeSort(T[], long, long); // Require temporary memory
template<class T>
void QuickSort(T[], long, long); // Depend on pivot





/* Implementations */
template<class T>
void InsertionSort(T arr[], long start, long end) {
	for (long i = start + 1; i <= end; i++) {
		T temp = arr[i]; // save element at current position

		long j = i - 1;
		for (; j >= 0 && arr[j] > temp; j--)
			arr[j + 1] = arr[j];

		arr[j + 1] = temp;
	}
}

template<class T>
void SelectionSort(T arr[], long start, long end) {
	for (long i = start; i < end; i++) {
		long index = i;

		// Find min element in the rest of list
		for (long j = i + 1; j <= end; j++)
		if (arr[index] > arr[j]) index = j;

		_swap<T>(arr[i], arr[index]);
	}
}

template<class T>
void BubbleSort(T arr[], long start, long end) {
	for (long i = start; i < end; i++) {
		bool flag = true; // exit early if there is no swap is made from previous loop

		for (long j = end; j > i; j--) {
			if (arr[j] < arr[j - 1]) _swap(arr[j], arr[j - 1]);
			flag = false;
		}

		if (flag) return;
	}
}



template<class T>
void HeapSort(T arr[], long start, long end) {
	
}

template<class T>
void merge(T arr[], long start, long end) {
	T* temp = new T[end - start + 1];

	long middle = (start + end) / 2;

	long i = start;
	long j = middle + 1;
	long pos = 0;

	// Merge into temp array
	while ((i <= middle) && (j <= end)) {
		if (arr[i] < arr[j])
			temp[pos++] = arr[i++];
		else temp[pos++] = arr[j++];
	}
	while (i <= middle) temp[pos++] = arr[i++];
	while (j <= end) temp[pos++] = arr[j++];

	// Replace data in main array by temp array
	while (pos > 0) arr[--j] = temp[--pos];
	delete temp;
}

template<class T>
void MergeSort(T arr[], long start, long end) {
	if (start < end) {
		long middle = (start + end) / 2;
		MergeSort(arr, start, middle);
		MergeSort(arr, middle + 1, end);
		merge(arr, start, end);
	}
}

template<class T>
void QuickSort(T arr[], long start, long end) {
	long lower = start + 1;
	long upper = end;

	// Chose middle
	long middle = (start + end) / 2;
	if ((arr[middle] > arr[start]) && (arr[middle] > arr[end]))
		(arr[start] > arr[end]) ? (middle = start) : (middle = end);
	if ((arr[middle] < arr[start]) && (arr[middle] < arr[end]))
		(arr[start] > arr[end]) ? (middle = end) : (middle = start);

	swap(arr[start], arr[(start + end) / 2]); // save pivot
	T pivot = arr[start];

	// partition
	while (lower <= upper) {
		while ((lower < end) && (arr[lower] < pivot))
			lower++;

		while ((upper > start) && (arr[upper] > pivot))
			upper--;

		if (lower < upper)
			swap(arr[lower++], arr[upper--]);
		else lower++;
	}

	// recursion
	swap(arr[start], arr[upper]);
	if (upper - 1 > start) QuickSort(arr, start, upper - 1);
	if (upper + 1 < end) QuickSort(arr, upper + 1, end);
}
