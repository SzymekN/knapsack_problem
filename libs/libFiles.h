#ifndef LIBFILES_H
#define LIBFILES_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

/*
Function creates new file
@param createFile stream used to create a new file
@param passedName passed name of file to be created
*/
void CreateFile(std::ofstream& createFile, std::string passedName="");

/*
Write values from file to array
@param values array 
@param numberOfValues number of values to read and write
@param readFromFile stream with file to read from
*/
void SetValuesToArray(long long* values, int numberOfValues, std::ifstream& readFromFile);

/*
Function opens a file
@param openFile stream used to open a file
*/
void OpenFile(std::ifstream& openFile, std::string passedName = "");

/*
Function checks if given file name has correct extension and if not corrects it
@param fileName[30] variable containing file name
*/
void CheckFileName(char fileName[30]);

/*
Function copies two lines of data from one file to another beggining at the place showed by passed cursor value
@param cursor sets the cursor after number of bytes shown by this value, then copies two lines 
@param readFromFile stream with opened file that values will be copied from
@param writeToFile stream with opened file that values will be written to
*/
void CopyDataSet(int cursor, std::ifstream& readFromFile, std::ofstream& writeToFile);


/*
Functions shows all numbers that divide a number given earlier
@param division contains a number that divides a number given earlier
@param quantityOfANumber contains values how many times does a number from division array at same index divides the original number
@param divisionLength value indicates how many numbers divide an original number
*/
void WriteToFileAllDivisions(int* division, int* quantityOfANumber, int divisionLength, std::ofstream& writeToFile);

int CountLines(std::ifstream& readFromFile);

/*
Write values from array to file
@param arr - write values from this array
@param size - size of an array
@param writeToFile - write to this file
*/
template <class T> void WriteArrayToFile(T* arr, int size, std::ofstream& writeToFile)
{
	for (int i = 0; i < size; i++)
		writeToFile << arr[i] << "\n";
}

#endif
