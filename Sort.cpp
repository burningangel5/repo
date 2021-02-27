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

int main() {
	std::vector<int> vec = {1, 7, -9, 4, 5, 12, -4, 3, 8, 20, -4, -18};
	std::cout << "Original vector: ";
	PrintVector(vec);

	BubbleSort(vec);
	SelectSort(vec);
	InsertSort(vec);

	return 0;
}

