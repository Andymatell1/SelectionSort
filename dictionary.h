
/*dictionary.h A Matellian
this file contains the dictionary class, which reads
words from the dictionary file and stores them in a vector.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

#ifndef DICTIONARY_H
#define DICTIONARY_H

class dictionary
{
public:
	// constructor import the dictionary file and read it
	dictionary();

	// overloaded operator to print the final word list
	friend ostream &operator<<(ostream &ostr, dictionary &result);

	// funtion that sorts the words using selection sort
	void selectionSort();

	// funtion to handle word lookups using binary search
	//	string binarySearch(string grid& candidate);

	// destructor
	//	~dictionary();

private:
	// vector with all the words from the dictionary file
	vector<string> d;

	// vector with the sorted dictionary
	vector<string> sorted;

	// vector with the results that are grid members that were found in the dictionary
	vector<string> result;
};
#endif // !D_H
// ***********************************************************

//     dictionary class implementation

// ***********************************************************

dictionary::dictionary()
{
	// constructor - open dictionary file and read it then push words into vector d as strings
	ifstream fin; // object
	string fileName = "dictionary.txt";
	fin.open(fileName.c_str());
	if (!fin)
	{
		// error handling
		cout << "The file can't be opened.\n\n";
	}

	string word;

	// get number of words in the file
	// istream_iterator<string> in{ fin }, end;
	cout << "Word Count: 88994" << endl;

	// push words into the vector d and also print to screen for testing
	cout << "The dictionary contains the words: \n";
	while (!fin.eof())
	{
		fin >> word;
		d.push_back(word);
	}

	// print to screen for testing purposes
	int size = 88994;
	/*for (int i = 0; i < size; i++)
		cout << d[i] << endl;
	cout << "\n\n";
	*/
	// close the file
	fin.close();
}

// overloaded operator to print the final word list
ostream &operator<<(ostream &ostr, dictionary &dict)
{
	cout << "sorted" << endl;
	for (int j = 0; j < dict.sorted.size(); j++)
		cout << dict.sorted[j] << endl;

	cout << "results" << endl;
	for (int j = 0; j < dict.result.size(); j++)
		cout << dict.result[j] << endl;
}

void dictionary::selectionSort()
{
	string compare;
	int index;
	for (int l = 0; l < 88994; l++)
	{
		compare = d[l];
		for (int m = 1; m < d.size(); m++)
		{
			if (compare > d[m])
			{
			}
			else
			{
				compare = d[m];
				index = m;
			}
		}
		if (l == 1000)
		{
			cout << l << endl;
		}
		if (l == 10000)
		{
			cout << l << endl;
		}
		if (l == 30000)
		{
			cout << l << endl;
		}
		if (l == 50000)
		{
			cout << l << endl;
		}
		d.erase(d.begin() + index);
		sorted.push_back(compare);
	}
	// print the sorted vector to the screen
	cout << "The sorted dictionary is: \n";
}
