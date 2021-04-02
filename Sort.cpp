#include <iostream>
#include <vector>

template<typename T>
void PrintVector(std::vector<T>& vec) {
	for(int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}

template<typename T>
void Swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
void BubbleSort(std::vector<T> vec) {
	for(int i = 0; i < vec.size() - 1; ++i) {
		for(int j = 0; j < vec.size() - i - 1; ++j) {
			if(vec[j] > vec[j + 1]) {
				Swap(vec[j], vec[j + 1]);
			}
		}
	}

	std::cout << "Bubble Sort: ";
	PrintVector(vec);
}

template<typename T>
void SelectSort(std::vector<T> vec) {
	for(int i = 0; i < vec.size() - 1; ++i) {
		int k = i;
		for(int j = k + 1; j < vec.size(); ++j) {
			if(vec[k] > vec[j]) {
				k = j;
			}
		}

		Swap(vec[i], vec[k]);
	}

	std::cout << "Select Sort: ";
	PrintVector(vec);
}

template<typename T>
void InsertSort(std::vector<T> vec) {
	for(int i = 1; i < vec.size(); ++i) {
		int j = i;
		T temp = vec[j];
		while(j > 0 && vec[j - 1] > temp) {
			vec[j] = vec[j - 1];
			--j;
		}
		vec[j] = temp;
	}

	std::cout << "Insert Sort: ";
	PrintVector(vec);
}

template<typename T>
void MergeSort(std::vector<T>& vec, std::vector<T>& temp, int left, int right) {
	if(left >= right) return;
	int mid = (left + right) / 2;
	MergeSort(vec, temp, left, mid);
	MergeSort(vec, temp, mid + 1, right);

	int k = left;
	int i = left;
	int j = mid + 1;
	while(i <= mid && j <= right) {
		if(vec[i] < vec[j]) {
			temp[k++] = vec[i++];
		}
		else {
			temp[k++] = vec[j++];
		}
	}
	while(i <= mid) {
		temp[k++] = vec[i++];
	}
	while(j <= right) {
		temp[k++] = vec[j++];
	}
	k = left;
	while(k <= right) {
		vec[k] = temp[k];
		++k;
	}
}

template<typename T>
void QuickSort(std::vector<T>& vec, int lo, int hi) {
	if(lo >= hi) return;
	
	int i = lo;
	int j = hi;
	T pivot = vec[lo];

	while(i != j) {
		while(i < j && vec[j] >= pivot) --j;
		while(i < j && vec[i] <= pivot) ++i;

		if(i < j) {
			Swap(vec[i], vec[j]);
		}
	}
	Swap(vec[j], vec[lo]);

	QuickSort(vec, lo, j - 1);
	QuickSort(vec, j + 1, hi);
}

int main() {
	std::vector<int> vec = {1, 7, -9, 4, 5, 12, -4, 3, 7, 8, 20, -4, -18, -9};
	std::cout << "Original vector: ";
	PrintVector(vec);

	// N^2 complexity
	BubbleSort(vec);
	SelectSort(vec);
	InsertSort(vec);

	// N*log(N) complexity
	std::vector<int> vec1(vec);
	std::vector<int> temp(vec.size());
	MergeSort(vec1, temp, 0, vec1.size() - 1);
	std::cout << "Merge Sort ";
	PrintVector(vec1);

	std::vector<int> vec2(vec);
	QuickSort(vec2, 0, vec2.size() - 1);
	std::cout << "Quick Sort ";
	PrintVector(vec2);

	return 0;
}

