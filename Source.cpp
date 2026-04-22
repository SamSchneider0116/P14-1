/*
Sam Schneider
Introducory Programming
April 23, 2026
MP12-1
*/


#include <iostream>

using namespace std;


/*
Gets average of array values
@param double array[] - Array Pointer
@param int size - Size of array
@return - Average value of array values (0 if size == 0)
*/
double getAverage(double array[], int size) {

	if (size == 0) {
		return 0;
	}

	double sum = 0;
	double* pointer = array;

	for (int i = 0; i < size; i++) {
		sum = sum + *pointer;
		pointer++;
	}

	return sum / static_cast<double>(size);

}

/*
Gets maximum value location in array
@param double array[] - Array Pointer
@param int size - Size of array
@return - The location of the maximum value in an array (NULL if size == 0)
*/
double* getMaximum(double array[], int size) {

	if (size == 0) {
		return NULL;
	}

	double* max = &array[0];
	double* pointer = array;

	for (int i = 0; i < size; i++) {
		if (*max < *pointer) {
			max = pointer;
		}
		pointer++;
	}

	return max;

}

/*
Gets minimum value location in array
@param double array[] - Array Pointer
@param int size - Size of array
@return - The location of the minimum value in an array (NULL if size == 0)
*/
double* getMinimum(double array[], int size) {

	if (size == 0) {
		return NULL;
	}

	double* min = &array[0];
	double* pointer = array;

	for (int i = 0; i < size; i++) {
		if (*min > *pointer) {
			min = pointer;
		}
		pointer++;
	}

	return min;

}


int main() {
	int size = 0;								//Size of array

	//Gets array size
	cout << "Enter the size of the array: ";
	cin >> size;

	//Creates new array of size... size
	double* array = new double[size];

	//size == 0 failsafe
	if (size != 0) {

		cout << "Enter " << size << " floating-point values: ";

	}

	//Gets each array value
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}

	//Gets max and minimum locations
	double* maxPoint = getMaximum(array, size);
	double* minPoint = getMinimum(array, size);

	//Displays average of all array values
	cout << "Average is " << getAverage(array, size) << endl;

	//Displays location and value of max and min
	if (size != 0) {

		//Point - array gives the value location in the array, *Point gives the value
		cout << "Maximum value is element #" << maxPoint - array << ": " << *maxPoint << endl;
		cout << "Minimum value is element #" << minPoint - array << ": " << *minPoint << endl;

	}

	//Size == 0 failsafe
	else {

		cout << "No Maximum value." << endl;
		cout << "No Minimum value." << endl;


	}

	//Deletes array and ends program
	delete[] array;
	return 0;
}