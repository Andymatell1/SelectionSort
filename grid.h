#include "d_matrix.h"
#include <iostream>
#include <fstream>
#include <math.h>
class grid
{
	public:
	void read();
	private:
	matrix<string> m1; 
};

void grid::read()
{
	vector<char> temp;
	char letter;
	int dimensions;
	int counter = 0;
	ifstream fin;
	string filename = "grid.txt";
	fin.open(filename.c_str());
	if (!fin)
	{
		cout<<"the file can not be opened"<<endl;	
	}
	// find size of the matrix
	while(!fin.eof())
	{
		counter ++;	
		fin>> letter;
		cout<<letter;
		temp.push_back(letter);
	}
	dimensions = pow(counter, 0.5);
	m1.resize(dimensions, dimensions);
	counter = 0;
	cout<<endl;
	for(int i = 0; i < dimensions; i++)
	{
		for(int j = 0; j < dimensions; j++)
		{
			cout<< temp[counter*dimensions +j];
			m1[i][j] = temp[counter*dimensions + j];
		}
		counter ++;
	}
	cout<<"temporary vector"<<endl;
	cout<< temp[4]<<endl;
	cout<<"1 , 3 "<<endl;
	cout<<endl<<m1[1][3]<<endl;
	cout<<"3 , 4"<<endl;
	cout<<m1[3][4]<<endl;
	fin.close();
}

