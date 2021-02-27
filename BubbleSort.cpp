#include <iostream>
#include <vector>

template<typename T>
void BubbleSort(std::vector<T>& vec) {
	for(int i = 0; i < vec.size() - 1; ++i) {
		for(int j = 0; j < vec.size() - i - 1; ++j) {
			if(vec[j] > vec[j + 1]) {
				T temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
		}
	}
}

int main() {
	std::vector<int> vec = {1, 7, -9, 4, 5, 12, -4, 3, 8};

	for(int i = 0; i < vec.size(); ++i) {
          std::cout << vec[i] << ' ';
    }
	std::cout << std::endl;

	BubbleSort(vec);
	for(int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
	return 0;
}

