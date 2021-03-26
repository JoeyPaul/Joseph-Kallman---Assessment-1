#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <stdlib.h>

using namespace std;

//random number function, input the range you want the number to be (2 would be 0,1)
int randomNumber(int range)
{
	int randomNumber = rand() % range +1;
	return randomNumber -1;
}

//makes a sample output file for testing purposes
void makeTestOutput()
{
	//writing to a file
	ofstream  writeFile;
	writeFile.open("sampleTest.txt");
	int randomLine1 = randomNumber(2);   // 0 or 1 on line 1
	writeFile << randomLine1 << endl;
	int randomLine2 = randomNumber(1);   // 0 or 1 on line 2
	writeFile << randomLine2 << endl;
	int testingThirdLine = randomNumber(10000); // line 3 determines how many line 4 will have (max 19 for this test)  
	writeFile << testingThirdLine << endl;
	for (int i = 0; i < testingThirdLine; i++)
	{
		int randomLine4 = randomNumber(99999);  // numbers for line 4 (between 0 and 98)
		writeFile << randomLine4 << " ";
	}
	writeFile.close();
}

//could turn this into a displayVector function
void displayArray(int arr[], int arraySize)
{
	for (int i = 0; i <= arraySize - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//partition function for the quicksort algorithm
//the partition function does the majority of the work
//input vector, left and right vector values, and direction for sorting
int partition(vector<int> &nums, int left, int right, char direction) 
{
	//Make a pivot variable, setting it as the mid point, between the start and the end of the vector
	int pivotIndex = left + (right - left) / 2;
	int pivotValue = nums[pivotIndex];
	int i = left, j = right;
	int temp;
	//checking which way to sort the data, accending or decending
	if (direction == '>') //accending
	{
		while (i <= j) //while the left side is lower than the right
		{
			while (nums[i] < pivotValue) //increase left while left index is LOWER than pivot
			{
				i++;
			}
			while (nums[j] > pivotValue) // decrease right while right index is HIGHER than pivot
			{
				j--;
			}
			if (i <= j) //check if left index is lower than or equal to right index and swap
				        //then move up and continue loops until left index intersects with right index
			{
				temp = nums[i];
				nums[i] = nums[j]; // Could replace this with the swap() function
				nums[j] = temp;
				i++;
				j--;
			}
		}
	}
	else //decending
	{
		while (i <= j) //same as above but...
		{
			while (nums[i] > pivotValue) //increase left while left index is *HIGHER* than pivot (instead of lower)
			{
				i++;
			}
			while (nums[j] < pivotValue) //and decrease right while right index is *LOWER* than pivot
			{
				j--;
			}
			if (i <= j) 
			{
				temp = nums[i];
				nums[i] = nums[j]; // Could replace this with the swap() function
				nums[j] = temp;
				i++;
				j--;
			}
		}
	}
	return i; // return lower index value, it will be used in the next loop as the Pivot Index
}

// quicksort is a recursive divide and conquor algorithm
//input vector, left and right vector values, and direction you want the data sorted ('>' or '<')
void quickSort(vector<int> &nums, int left, int right, char direction) 
{
	//if left is higher or equal to right, the numbers are sorted and 
	//the recursion is stopped
	if (left < right) 
	{
		//partition function is called and pivot index is returned
		//so a new one can be used in the next recursion of quicksort
		int pivotIndex = partition(nums, left, right, direction);
		//calls quicksort and works from left to pivot index
		quickSort(nums, left, pivotIndex - 1, direction);
		//calls again and works from pivot index to right
		quickSort(nums, pivotIndex, right, direction);
	}
}

/// <summary>
/// InsertionSort
/// </summary>
/// <param name="arr"></param>
/// <param name="arraySize"></param>
vector<int> insertionSort(vector<int> vec, int vectorSize, char direction)
{
	for (int i = 1; i <= vectorSize - 1; i++) // starting at index 1 in array because it needs to check to the left of it
	{
		//makes a copy of the value at index i in the array
		int key = vec[i];
		int j = i - 1; //gets the element before i 

		if (direction == '>') // picks a while loop based on the sorting direction
		{//while j is index 0 or higher andwhile value in arr[j] bigger than key value
			while (j >= 0 && vec[j] > key) // *>* key for sorting forwards           
			{
				// move value in index j up 1                                                          
				vec[j + 1] = vec[j];
				//keep moving j to the left
				j = j - 1;
			}
		}
		else 
		while (j >= 0 && vec[j] < key) // *<* key for sorting backwards            
		{
			//as above                                                         
			vec[j + 1] = vec[j];
			j = j - 1;
		}
		//we've moved everything up, so put key value back in to where it should fit
		vec[j + 1] = key;
	}
	return vec;
}

int main()
{
	// seeding random number generator for sample output files (testing purposes)
	srand(static_cast<unsigned int>(time(0)));

	//makes a sample output file for testing purposes
	//makeTestOutput();

	//----------------------------------------------------------------------------------------------------------------//
	//------------------------------------------------------PART 1----------------------------------------------------//
	//----------------------------------------------READING INPUT DATA------------------------------------------------//
	//----------------------------------------------------------------------------------------------------------------//


	//reading from a file
    ifstream readFile;
    readFile.open("input-a1q1.txt");
	//check what is on the first line (0 or 1)
	char direction = ' ';
	int firstLine;
	readFile >> firstLine;
	if (firstLine == 0)         //direction is equal to
		direction = '>';        //accending if 0
	else if (firstLine == 1) 
		direction = '<';        //decending if 1
	else                        //print error if it isn't (0 or 1)
	{
		cout << "ERROR! Invalid Input on Line 1. Input must be (0 or 1)"; // first lines input must be invalid
		return 0;
	}
	//cout << firstLine << endl;                                              

	//check what is on the second line (0 or 1)
	int secondLine;
	readFile >> secondLine;
	//cout << secondLine << endl;

	//Check what is on the third line
	int amountOfNumbers;    //this is the amount of times the next loop will run
	readFile >> amountOfNumbers;
	if (amountOfNumbers == 0)
	{
		cout << "ERROR! Nothing to sort." << endl;   //check for errors in input
		return 0;
	}
	else if (amountOfNumbers < 0)
	{
		cout << "ERROR! Invalid Input on line 3. Input must be greater than (0)" << endl;
		return 0;
	}
	
	//Loop through all the numbers on the 4th line
	//Storing them in a temporary int and then pushing them into a vector each loop
	vector<int> nums;
	do
	{
		int temp;
		readFile >> temp;
		nums.push_back(temp);
	} while (readFile.peek() != EOF); // keep storing numbers until the end of the text file

	//This gets rid of a bug I was getting where it duplicated the last element of the vector if 
	//there was a ' ' at the end of the input file
	if (nums.size() != amountOfNumbers)
	{
		nums.pop_back();
	}

	//checks for errors: line 3 doesn't match the amount on line 4
	if (nums.size() != amountOfNumbers)
	{
		cout << "ERROR! Line 4 must have the amount of numbers specified on line 3." << endl;
		return 0;
	}
	readFile.close();

	//Output the numbers on Line 4 to console
	/*cout << amountOfNumbers << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;*/

	//----------------------------------------------------------------------------------------------------------------//
	//------------------------------------------------------PART 1----------------------------------------------------//
	//----------------------------------------------OUTPUT SECTION & SORTING------------------------------------------//
	//----------------------------------------------------------------------------------------------------------------//

	//check what was on the second line (0, or 1) 
	// if 0 choose and print algorithm that is good for mostly sorted data (insertionsort)
	// if 1 choose and print algorithm that is good for really unsorted data (quicksort)
	// OUTPUT time sorting algorithm took to finish and sorted data set 
	vector<int> sorted;
	ofstream writeFile;
	writeFile.open("output-a1q1.txt");
	if (secondLine == 0)
	{
		//check start time
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		//sort data
		sorted = insertionSort(nums, amountOfNumbers, direction);
		//check end time
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		//output time in milliseconds 
		cout << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
		writeFile << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
		//output sorted vector
		for (int i = 0; i < sorted.size(); i++)
		{
			cout << sorted[i] << " ";
			writeFile << nums[i] << " ";
		}
		cout << endl;
	}
	else if (secondLine == 1)
	{
		//check start time
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		//sort data, actual nums vector is passed in with & so I don't need to return anything
		quickSort(nums, 0, nums.size()-1, direction);
		//check end time
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		//output time in milliseconds
		cout << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
		writeFile << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
		//output sorted vector
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
			writeFile << nums[i] << " ";
		}
		cout << endl;
		writeFile.close();
	}
	else // check for invalid input on line 2
	{
		cout << "ERROR! Invalid Input on Line 2. Input must be (0 or 1)"; 
		return 0;
	}

	std::system("pause");
	return 0;
}

//// REFERENCE

// Quicksort function - derived from in class and https://www.thepolyglotdeveloper.com/2019/04/sort-vector-integers-quicksort-algorithm-cpp/
// I was having trouble turning the class example into a function that inputs a vector so I used their quicksort logic, but I went through it
// and made changes so I could change the direction the data is sorted from outside the function. 