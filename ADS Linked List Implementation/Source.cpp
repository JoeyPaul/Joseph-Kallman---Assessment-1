#include <iostream>
#include <string>
#include "List.h"
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <chrono>

using namespace std;

//random number function, input the range you want (10 = between 1 and 10 inclusive)
int randomRange(int range)
{
	int randomNum = rand() % range + 1;
	return randomNum;
}

void main()
{
	//Seeding random number generator
	srand(static_cast<unsigned int>(time(0)));

	//reading the input text file
	ifstream readFile("input-a1q2.txt");
	int firstLine;
	readFile >> firstLine;
	readFile.close();

	//preparing the output file
	ofstream writeFile("output-a1q2.txt");
	
	//---------------------------------------------------------------------------------------------------------------------//
	//-----------------------------------------Part A: insertAtFront-------------------------------------------------------//
	//---------------------------------------------------------------------------------------------------------------------//
	//making a list object called list1
	List list1;
	//check start time
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	//adding random numbers to the list and checking how long it takes to add them
	for (int i = 0; i < firstLine; i++)
	{
		list1.insertAtFront(randomRange(999));
	}
	//check end time
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	//output time in milliseconds 
	cout << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	writeFile << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

	//---------------------------------------------------------------------------------------------------------------------//
	//-----------------------------------------Part B: insertAtEnd---------------------------------------------------------//
	//---------------------------------------------------------------------------------------------------------------------//

	//making a list object called list2 for next question
	List list2;
	begin = chrono::steady_clock::now();
	for (int i = 0; i < firstLine; i++)
	{
		list2.insertAtEnd(randomRange(999)); // just change this to insertAtEnd
	}
	end = chrono::steady_clock::now();
	cout << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	writeFile << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

	//---------------------------------------------------------------------------------------------------------------------//
	//-----------------------------------------Part C: deleteAtFront-------------------------------------------------------//
	//---------------------------------------------------------------------------------------------------------------------//
	
	//check start time
	begin = chrono::steady_clock::now();
	//adding random numbers to the list and checking how long it takes to add them
	for (int i = 0; i < firstLine; i++)
	{
		list1.deleteAtFront();
	}
	//check end time
	end = chrono::steady_clock::now();
	//output time in milliseconds 
	cout << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	writeFile << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

	//---------------------------------------------------------------------------------------------------------------------//
	//-----------------------------------------Part D: deleteAtEnd---------------------------------------------------------//
	//---------------------------------------------------------------------------------------------------------------------//

	//check start time
	begin = chrono::steady_clock::now();
	//adding random numbers to the list and checking how long it takes to add them
	for (int i = 0; i < firstLine; i++)
	{
		list2.deleteAtEnd();
	}
	//check end time
	end = chrono::steady_clock::now();
	//output time in milliseconds 
	cout << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	writeFile << "Milliseconds = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	writeFile.close();

	system("pause");
}