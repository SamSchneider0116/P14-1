/*
Sam Schneier


*/



#include <iostream>

using namespace std;



double getAverage(double array[], int size) {
	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum = sum + array[i];
	}

	if (size == 0) {
		return 0;
	}

	return sum / static_cast<double>(size);

}

double* getMaximum(double array[], int size) {

	if (size == 0) {
		return NULL;
	}

	double* max = &array[0];

	for (int i = 0; i < size; i++) {
		if (*max < array[i]) {
			max = &array[i];
		}
	}

	return max;

}

double* getMinimum(double array[], int size) {

	if (size == 0) {
		return NULL;
	}

	double* min = &array[0];

	for (int i = 0; i < size; i++) {
		if (*min > array[i]) {
			min = &array[i];
		}
	}

	return min;

}


int main() {
	int size = 0;

	cout << "Enter the size of the array: ";
	cin >> size;

	double* array = new double[size];

	if (size != 0) {

		cout << "Enter " << size << " floating-point values: ";

	}

	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}

	double* maxPoint = getMaximum(array, size);
	double* minPoint = getMinimum(array, size);

	cout << "Average is " << getAverage(array, size) << endl;

	if (size != 0) {

		cout << "Maximum value is element #" << maxPoint - array << ": " << *maxPoint << endl;
		cout << "Minimum value is element #" << minPoint - array << ": " << *minPoint << endl;

	}

	else {

		cout << "No Maximum value." << endl;
		cout << "No Minimum value." << endl;


	}

	delete[] array;
	return 0;
}