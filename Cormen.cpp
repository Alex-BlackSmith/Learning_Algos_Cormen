#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void InsertionSort() {
	int key, i;

	vector<int> Sequence = { 0,2,4,9,1,8,7,3,5,6 };
	for (int j = 1; j < Sequence.size(); ++j) {
		key = Sequence[j];
		i = j;
		while ((i > 0) && (Sequence[i - 1] > key)) {
			Sequence[i] = Sequence[i - 1];
			i--;
		}
		Sequence[i] = key;
	}
	for (int j = 0; j < Sequence.size(); j++) {
		cout << Sequence[j] << ' ';
	}
	return;
}

void InsertionSortBack() {
	int key, i;

	vector<int> Sequence = { 0,2,4,9,1,8,7,3,5,6 };
	for (int j = 1; j < Sequence.size(); ++j) {
		key = Sequence[j];
		i = j;
		while ((i > 0) && (Sequence[i - 1] < key)) {
			Sequence[i] = Sequence[i - 1];
			i--;
		}
		Sequence[i] = key;
	}
	for (int j = 0; j < Sequence.size(); j++) {
		cout << Sequence[j] << ' ';
	}
	return;
}

void BitsNumbersSum() {
	vector<int> bit_num_1 = { 1,0,1,1,1 };
	vector<int> bit_num_2 = { 1,1,0,1,1 };
	vector<int> res = { 0,0,0,0,0,0 };
	int a = 0;
	for (int i = bit_num_1.size()-1; i >= 0; i--) {
		res[i] = (int)((res[i + 1] + bit_num_1[i] + bit_num_2[i]) / 2);
		res[i+1] = (int)((res[i+1] + bit_num_1[i] + bit_num_2[i]) % 2);
	}
	for (int j = 0; j < res.size(); j++) {
		cout << res[j] << ' ';
	}
	return;
}

void Merge(vector<int>& Array,int p,int q,int r) {
	int n_1 = q - p + 1;
	int n_2 = r - q;
	vector<int> L;
	vector<int> R;
	for (int i = 0; i < n_1; i++) {
		L.push_back(Array[p + i]);
	}
	for (int j = 0; j < n_2; j++) {
		R.push_back(Array[q + j + 1]);
	}
	L.push_back(1000);
	R.push_back(1000);
	int i = 0;
	int j = 0;
	for (int k = p; k <= r;k++) {
		if (L[i] <= R[j]) {
			Array[k] = L[i];
			i++;
		}
		else {
			Array[k] = R[j];
			j++;
		}
	}
}

void Merge_Sort(vector<int>& Array, int p, int r) {
	if (p < r) {
		int q = (int)(std::ceil((p + r) / 2));
		Merge_Sort(Array, p, q);
		Merge_Sort(Array, q + 1, r);
		Merge(Array, p, q, r);
	}
}

int main() {
	vector<int> A = { 0,2,1,7,3,4,6,5,9,8 };
	Merge_Sort(A, 0, 9);

	return 0;
}