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
void BubbleSort(std::vector<T> vec) {
	for(int i = 0; i < vec.size() - 1; ++i) {
		for(int j = 0; j < vec.size() - i - 1; ++j) {
			if(vec[j] > vec[j + 1]) {
				T temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
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

		T temp = vec[k];
		vec[k] = vec[i];
		vec[i] = temp;
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

int main() {
	std::vector<int> vec = {1, 7, -9, 4, 5, 12, -4, 3, 8, 20, -4, -18};
	std::cout << "Original vector: ";
	PrintVector(vec);

	BubbleSort(vec);
	SelectSort(vec);
	InsertSort(vec);

	std::vector<int> vec1(vec);
	std::vector<int> temp(vec.size());
	MergeSort(vec1, temp, 0, vec1.size() - 1);
	std::cout << "Merge Sort ";
	PrintVector(vec1);

	return 0;
}

