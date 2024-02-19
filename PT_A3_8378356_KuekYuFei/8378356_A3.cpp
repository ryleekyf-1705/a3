#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

using namespace std;

// function template

// Display Menu
void printMenu(string, string, string);
// Prompt Choice
int promptChoice();

// choice 1 - Retrieve unique file data
vector <string> uniqueFileData(string);
// choice 1 - Split string using delimiter
vector<string> splitString (string input, string delimiter);
// choice 1 - Point2D
vector<Point2D> processPoint2D(vector<string> fileData);
vector<Point2D> storePoint2D(vector <string> point2dx, vector <string> point2dy);
// choice 1 - Point3D
vector<Point3D> processPoint3D(vector<string> fileData);
vector<Point3D> storePoint3D(vector <string> point3dx, vector <string> point3dy, vector <string> point3dz);
// choice 1 - Line2D
vector<Line2D> processLine2D(vector<string> fileData);
// choice 1 - Line3D
vector<Line3D> processLine3D(vector<string> fileData);

// choice 3 - Display Menu
void printSortCriteriaMenu(string);
// choice 3 - Process Choice
string processSortingChoice(char, string);

// choice 5 - Point2D
void processDisplayPoint2D(vector<Point2D> point2DVector, string sortingCriteria, string sortingOrder);
// choice 5 - Point3D
void processDisplayPoint3D(vector<Point3D> point3DVector, string sortingCriteria, string sortingOrder);
// choice 5 - Line2D
void processDisplayLine2D(vector<Line2D> line2DVector, string sortingCriteria, string sortingOrder);
// choice 5 - Line3D
void processDisplayLine3D(vector<Line3D> line3DVector, string sortingCriteria, string sortingOrder);

int main()
{
	int choice;

	// vector to store Point2D objects
	vector<Point2D> point2DVector;
	// vector to store Point3D objects
	vector<Point3D> point3DVector;
	// vector to store Line2D objects
	vector<Line2D> line2DVector;
	// vector to store Line3D objects
	vector<Line3D> line3DVector;

	// vector to store sorted vector Point2D objects
	vector<Point2D> point2DSortedVector;
	// vector to store sorted vector Point3D objects
	vector<Point3D> point3DSortedVector;
	// vector to store sorted vector Line2D objects
	vector<Line2D> line2DSortedVector;
	// vector to store sorted vector Line3D objects
	vector<Line3D> line3DSortedVector;

	// default values
	string filteringCriteria = "Point2D";
	string sortingCriteria = "x-ordinate";
	string sortingOrder = "ASC";

	// display menu
	printMenu(filteringCriteria, sortingCriteria, sortingOrder);

	// prompt choice
	PROMPTCHOICE:choice = promptChoice();

	if (choice == 1)
	{
		string fileName;
		cout << "Please enter filename: ";
		cin >> fileName;

		cout << endl;

		vector <string> uniqueData;
		uniqueData = uniqueFileData(fileName);
		
		// extract coordinates values, remove brackets
		// store coordinates value by type
		point2DVector = processPoint2D(uniqueData);
		point3DVector = processPoint3D(uniqueData);
		line2DVector = processLine2D(uniqueData);
		line3DVector = processLine3D(uniqueData);

		cout << uniqueData.size() << " records read in successfully!" << endl;
		cout << endl;
		cout << "Going back to main menu ... " << endl;
		cout << endl;
		printMenu(filteringCriteria, sortingCriteria, sortingOrder);
		goto PROMPTCHOICE;
	}
	// Specify filter criteria
	else if (choice == 2)
	{
		cout << "[ Specifying filtering criteria (current : " << filteringCriteria << ") ]" << endl;
		cout << endl;

		char criteria;
		// Submenu		
		cout << setw(6) << "a)" << setw(5) << " " << "Point2D records" << endl;
		cout << setw(6) << "b)" << setw(5) << " " << "Point3D records" << endl;
		cout << setw(6) << "c)" << setw(5) << " " << "Line2D records" << endl;
		cout << setw(6) << "d)" << setw(5) << " " << "Line3D records" << endl;
		cout << endl;
		// Prompt for criteria
		cout << setw(4) << " " << "Please enter your criteria (a - d) : ";
		cin >> criteria;

		// Process criteria
		if (criteria == 'a')
		{
			filteringCriteria = "Point2D";
			sortingCriteria = "x-ordinate";
		}
		else if (criteria == 'b')
		{
			filteringCriteria = "Point3D";
			sortingCriteria = "x-ordinate";
		}
		else if (criteria == 'c')
		{
			filteringCriteria = "Line2D";
			sortingCriteria = "Pt. 1";
		}
		else if (criteria == 'd')
		{
			filteringCriteria = "Line3D";
			sortingCriteria = "Pt. 1";
		}
		
		cout << setw(4) << " " << "Filter criteria successfully set to '" <<  filteringCriteria << "'!" << endl;
		cout << endl;
		cin.clear();
		printMenu(filteringCriteria, sortingCriteria, sortingOrder);
		goto PROMPTCHOICE;
	}
	// Specify Sort Criteria
	else if (choice == 3)
	{
		cout << "[ Specifying sorting criteria (current : " << sortingCriteria << ") ]" << endl;
		cout << endl;
		
		char criteria;
	
		// print submenu
		printSortCriteriaMenu(filteringCriteria);
	
		// prompt user to enter criteria
		if (filteringCriteria == "Point3D")
			cout << setw(4) << " " << "Please enter your criteria (a - d) : ";
		else
			cout << setw(4) << " " << "Please enter your criteria (a - c) : ";
		cin >> criteria;

		// Process criteria selected
		sortingCriteria = processSortingChoice(criteria, filteringCriteria);
		
		cout << setw(4) << " " << "Sorting criteria successfully set to '" <<  sortingCriteria << "'!" << endl;
		cout << endl;
		cin.clear();
		printMenu(filteringCriteria, sortingCriteria, sortingOrder);
		goto PROMPTCHOICE;
	}
	// Specify Sorting Order
	else if (choice == 4)
	{
		cout << "[ Specifying sorting order (current : " << sortingOrder << ") ]" << endl;
		cout << endl;

		char criteria;

		// sub menu
		cout << setw(6) << "a)" << setw(5) << " " << "ASC (Ascending order)" << endl;
		cout << setw(6) << "b)" << setw(5) << " " << "DSC (Descending order)" << endl;

		cout << endl;

		// prompt for criteria
		cout << setw(4) << " " << "Please enter your criteria (a - b) : ";
		cin >> criteria;

		// process criteria
		if (criteria == 'a')
			sortingOrder = "ASC";
		else if (criteria == 'b')
			sortingOrder = "DSC";

		cout << setw(4) << " " << "Sorting order successfully set to '" <<  sortingOrder << "'!" << endl;
		cout << endl;
		cin.clear();
		printMenu(filteringCriteria, sortingCriteria, sortingOrder);
		goto PROMPTCHOICE;

	}
	// View Sorted Data
	else if (choice == 5)
	{
		cout << "[ View data ... ]" << endl;
		
		cout << setw(1) << " " << "filtering criteria : " << filteringCriteria << endl;
		cout << setw(1) << " " << "sorting criteria : " << sortingCriteria << endl;
		cout << setw(1) << " " << "sorting order : " << sortingOrder << endl;
		cout << endl;
		// view filtered & sorted data
		if (filteringCriteria == "Point2D")
		{
			// sort vector, store sorted vector
			point2DSortedVector = Point2D::processSortingPoint2D(point2DVector, sortingCriteria, sortingOrder);
			// display sorted vector
			Point2D::displaySortedPoint2D(point2DSortedVector);
		}
		else if (filteringCriteria == "Point3D")
		{
			// sort vector, store sorted vector
			point3DSortedVector = Point3D::processSortingPoint3D(point3DVector, sortingCriteria, sortingOrder);
			// display sorted vector
			Point3D::displaySortedPoint3D(point3DSortedVector);
		}
		else if (filteringCriteria == "Line2D")
		{
			// sort vector, store sorted vector
			line2DSortedVector = Line2D::processSortingLine2D(line2DVector, sortingCriteria, sortingOrder);
			// display sorted vector
			Line2D::displaySortedLine2D(line2DSortedVector);
		}
		else if (filteringCriteria == "Line3D")
		{
			// sort vector, store sorted vector
			line3DSortedVector = Line3D::processSortingLine3D(line3DVector, sortingCriteria, sortingOrder);
			// display sorted vector
			Line3D::displaySortedLine3D(line3DSortedVector);
		}		
		
		do {
			cout << '\n' << "Press <enter> to go back to main menu ... ";
		} while (cin.get()!='\n');
		cout << endl;

		if (cin.get() == '\n')
		{
			printMenu(filteringCriteria, sortingCriteria, sortingOrder);
			goto PROMPTCHOICE;
		}
	}
	else if (choice == 6)
	{
		string writeFileName;
		cout << "Please enter filename: ";
		cin >> writeFileName;
		cout << endl;

		ofstream writeFile(writeFileName);
		if (writeFile.is_open())
		{
			if (filteringCriteria == "Point2D")
			{
				// Write Header format to file
				writeFile << right << setfill(' ');
				writeFile << setw(5) << "X" << setw(6) << "Y" << setw(4) << " " << setw(14)<< "Dist Fr Origin" << "\n";
				writeFile << "- - - - - - - - - - - - - - - - - - - \n";
				
				// Write sorted vector to file
				for (int i=0; i<point2DSortedVector.size(); i++)
				{
					double scalarValue = point2DSortedVector[i].getScalarValue();
					scalarValue = round(scalarValue * 1000.0) / 1000.0;

					stringstream ss;
					ss << fixed << setprecision(3) << scalarValue;
					string dist = ss.str();

					writeFile << "[" << setw(4) <<  point2DSortedVector[i].getX() << ", " << setw(4) << point2DSortedVector[i].getY() << "]" << setw(dist.size()+3) << dist << endl;
				}

				cout << point2DSortedVector.size() << " records output successfully!" << endl;
			}
			else if (filteringCriteria == "Point3D")
			{
				// Write Header format to file
				writeFile << right << setfill(' ');
				writeFile << setw(5) << "X" << setw(6) << "Y" << setw(6) << "Z";
				writeFile << setw(18) << "Dist Fr Origin" << "\n";
				writeFile << "- - - - - - - - - - - - - - - - - - -" << "\n";

				// Write sorted vector to file
				for (int i=0; i<point3DSortedVector.size(); i++)
				{
					double scalarValue = point3DSortedVector[i].getScalarValue();
					scalarValue = round(scalarValue * 1000.0) / 1000.0;

					stringstream ss;
					ss << fixed << setprecision(3) << scalarValue;
					string dist = ss.str();

					writeFile << "[" << setw(4) << point3DSortedVector[i].getX() << ", " << setw(4) << point3DSortedVector[i].getY() << ", " << setw(4) << point3DSortedVector[i].getZ() 
					<< "]" 	<< setw(3) << " " << dist << endl;
					//writeFile << point3DSortedVector[i] << "\n";
				}

				cout << point3DSortedVector.size() << " records output successfully!" << endl;
			}
			else if (filteringCriteria == "Line2D")	
			{
				// Write Header format to file
				writeFile << right << setfill(' ');
				writeFile << setw(5) << "P1-X" << setw(6) << "P1-Y";
				writeFile << setw(4) << " ";
				writeFile << setw(5) << "P2-X" << setw(6) << "P2-Y";
				writeFile << setw(10) << "Length" << "\n";
				writeFile << "- - - - - - - - - - - - - - - - - - -" << "\n";

				// Write sorted vector to file
				for (int i=0; i<line2DSortedVector.size(); i++)
				{
					double scalarValue = line2DSortedVector[i].getScalarValue();
					scalarValue = round(scalarValue * 1000.0) / 1000.0;

					stringstream ss;
					ss << fixed << setprecision(3) << scalarValue;
					string len = ss.str();

					writeFile << "[" << setw(4) << line2DSortedVector[i].getPt1().getX() << ", " << setw(4) << line2DSortedVector[i].getPt1().getY() 
					<< "]" << setw(3) << " " 
					<< "[" << setw(4) << line2DSortedVector[i].getPt2().getX() << ", "<< setw(4) << line2DSortedVector[i].getPt2().getY() << "]" 
					<< setw(len.size()+3) << len << endl;
				}

				cout << point3DSortedVector.size() << " records output successfully!" << endl;
			}
			else if (filteringCriteria == "Line3D")	
			{
				// Write Header format to file
				writeFile << right << setfill(' ');
				writeFile << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z";
				writeFile << setw(4) << " ";
				writeFile << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z";
				writeFile << setw(10) << "Length" << "\n";
				writeFile << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << "\n";

				// Write sorted vector to file
				for (int i=0; i<line3DSortedVector.size(); i++)
				{
					double scalarValue = line3DSortedVector[i].getScalarValue();
					scalarValue = round(scalarValue * 1000.0) / 1000.0;

					stringstream ss;
					ss << fixed << setprecision(3) << scalarValue;
					string len = ss.str();

					writeFile << "[" << setw(4) << line3DSortedVector[i].getPt1().getX() << ", " << setw(4) << 			line3DSortedVector[i].getPt1().getY() << ", " 
					<< setw(4) << line3DSortedVector[i].getPt1().getZ() << "]" << setw(3) << " " 
					<< "[" << setw(4) << line3DSortedVector[i].getPt2().getX() << ", " << setw(4) << 			line3DSortedVector[i].getPt2().getY() << ", " 
					<< setw(4) << line3DSortedVector[i].getPt2().getZ() 
					<< "]"
					<< setw(len.size()+3) << len << endl;

					//writeFile << line3DSortedVector[i] << endl;
				}

				cout << line3DSortedVector.size() << " records output successfully!" << endl;
			}
			writeFile.close();
		}
		else cout << "Unable to open file";

		cout << endl;
		cout << "Going back to main menu ..." << endl;
		cout << endl;
		printMenu(filteringCriteria, sortingCriteria, sortingOrder);
		goto PROMPTCHOICE;
	}
	else if (choice == 7)
	{
		exit(0);
	}
}

// prompt choice
int promptChoice()
{
	int choice;	
	cout << "Please enter your choice: ";
	cin >> choice;
	cout << endl;
	return choice;
}

// display menu
void printMenu(string filteringCriteria, string sortingCriteria, string sortingOrder)
{
	// displays menu	
	cout << "Student ID	: 8378356" << endl;
	cout << "Student Name	: Kuek Yu Fei" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Welcome to A3 program!" << endl;
	cout << endl;
	cout << "1)	Read in data" << endl;
	cout << "2)	Specify filtering criteria (current : " << filteringCriteria << ")" << endl;
	cout << "3)	Specify sorting criteria (current : " << sortingCriteria << ")" << endl;
	cout << "4)	Specify sorting order (current : " << sortingOrder << ")" << endl;
	cout << "5)	View data" << endl;
	cout << "6)	Store data" << endl;
	cout << "7)	Quit" << endl;
	cout << endl;
}

// unique file data
vector <string> uniqueFileData(string fileName)
{
	ifstream readFile (fileName);
	string content;
	
	// store content from file into vector string
	vector<string> fileData;

	if (readFile.is_open())
	{
		while (getline(readFile,content))
		{
			fileData.push_back(content);
		}
	}
	readFile.close();

	// sorts data
	sort(fileData.begin(), fileData.end());
	
	// removes values that are not unique
	fileData.erase(unique(fileData.begin(), fileData.end()), fileData.end());
	
	// fileData only has unique data (no repeated values)
	return fileData;
}

// split string by finding delimiter
vector<string> splitString (string input, string delimiter)
{
	size_t pos = 0;
	string token;
	vector<string> result;

	while ((pos = input.find(delimiter)) != string::npos) 
	{
    		token = input.substr(0, pos);
    		result.push_back (token);
		input.erase(0, pos + delimiter.length());
	}

	result.push_back (input);

	return (result);
}


// print submenu of sorting criteria
void printSortCriteriaMenu(string filteringCriteria)
{
	string optionA;
	string optionB;
	string optionC;
	string optionD;

	if (filteringCriteria == "Point2D")
	{
		optionA = "X value";
		optionB = "Y value";
		optionC = "Dist Fr. Origin value";
	
		cout << setw(6) << "a)" << setw(5) << " " << optionA << endl;
		cout << setw(6) << "b)" << setw(5) << " " << optionB << endl;
		cout << setw(6) << "c)" << setw(5) << " " << optionC << endl;
		cout << endl;
	}
	else if (filteringCriteria == "Point3D")
	{
		optionA = "X value";
		optionB = "Y value";
		optionC = "Z value";
		optionD = "Dist. Fr Origin value";

		cout << setw(6) << "a)" << setw(5) << " " << optionA << endl;
		cout << setw(6) << "b)" << setw(5) << " " << optionB << endl;
		cout << setw(6) << "c)" << setw(5) << " " << optionC << endl;
		cout << setw(6) << "d)" << setw(5) << " " << optionD << endl;
		cout << endl;
	}
	else if (filteringCriteria == "Line2D" || filteringCriteria == "Line3D")
	{
		optionA = "Pt. 1's (x,y) values";
		optionB = "Pt. 2's (x,y) values";
		optionC = "Length value";
		cout << setw(6) << "a)" << setw(5) << " " << optionA << endl;
		cout << setw(6) << "b)" << setw(5) << " " << optionB << endl;
		cout << setw(6) << "c)" << setw(5) << " " << optionC << endl;
		cout << endl;
	}
}

// process sort choice based on filtering criteria and criteria selected
string processSortingChoice(char criteria, string filteringCriteria)
{
	string sortingCriteria;

	if (filteringCriteria == "Point2D")
	{
		if (criteria == 'a')
			sortingCriteria = "x-ordinate";
		else if (criteria == 'b')
			sortingCriteria = "y-ordinate";
		else if (criteria == 'c')
			sortingCriteria = "distFrOrigin";
	}
	else if (filteringCriteria == "Point3D")
	{
		if (criteria == 'a')
			sortingCriteria = "x-ordinate";
		else if (criteria == 'b')
			sortingCriteria = "y-ordinate";
		else if (criteria == 'c')
			sortingCriteria = "z-ordinate";
		else if (criteria == 'd')
			sortingCriteria = "distFrOrigin";
	}
	else if (filteringCriteria == "Line2D" || filteringCriteria == "Line3D")
	{
		if (criteria == 'a')
			sortingCriteria = "Pt. 1";
		else if (criteria == 'b')
			sortingCriteria = "Pt. 2";
		else if (criteria == 'c')
			sortingCriteria = "Length";
	}
	return sortingCriteria;
}

// extract x and y values of Point2D
// remove ',' 
// remove '[' and ']' 
vector<Point2D> processPoint2D(vector<string> fileData)
{
	vector <string> tokenStringVector;

	vector <string> point2dx; // Point 2D is made up of a set of x & y
	vector <string> point2dy;

	// Store Point2D objects
	vector <Point2D> point2DVector;

	for (int i=0; i<fileData.size(); i++)
	{
		tokenStringVector = splitString (fileData[i], ", ");
		if (tokenStringVector[0] == "Point2D")
		{
			point2dx.push_back(tokenStringVector[1]);
			point2dy.push_back(tokenStringVector[2]);
		} 
	}

	// After removal of brackets
	point2DVector = storePoint2D(point2dx, point2dy);
	return point2DVector;
}

// Removal of brackets and storing as Point2D object
// remove '[' and ']'
vector<Point2D> storePoint2D(vector <string> point2dx, vector <string> point2dy)
{
	// vector to store Point2D objects
	vector<Point2D> point2DVector;

	// remove brackets to work with x,y values
	for (int i=0; i<point2dx.size(); i++)
	{
		size_t posOpenBracket = point2dx[i].find("[");
		size_t posCloseBracket = point2dy[i].find("]");
		string xVal = point2dx[i].substr(posOpenBracket +1);
		string yVal = point2dy[i].substr(0, posCloseBracket);
		int x = stoi(xVal);
		int y = stoi(yVal);
		point2DVector.push_back(Point2D(x,y));
	}

	return point2DVector;
}

// extract x, y and z values of Point3D
// remove ',' 
// remove '[' and ']' 
vector<Point3D> processPoint3D(vector<string> fileData)
{
	vector <string> tokenStringVector;

	vector <string> point3dx; // Point 3D is made up of a set of x & y & z
	vector <string> point3dy;
	vector <string> point3dz;

	// vector to store Point3D objects
	vector<Point3D> point3DVector;

	for (int i=0; i<fileData.size(); i++)
	{
		tokenStringVector = splitString (fileData[i], ", ");
		
		if (tokenStringVector[0] == "Point3D")
		{
			point3dx.push_back(tokenStringVector[1]);
			point3dy.push_back(tokenStringVector[2]);
			point3dz.push_back(tokenStringVector[3]);
		}

	}
	// After removal of brackets
	point3DVector = storePoint3D(point3dx, point3dy, point3dz);
	return point3DVector;
}

// Removal of brackets and storing as Point3D object
// remove '[' and ']'
vector<Point3D> storePoint3D(vector <string> point3dx, vector <string> point3dy, vector <string> point3dz)
{
	// vector to store Point3D objects
	vector<Point3D> point3DVector;
	// remove brackets to work with x,y,z values
	for (int i=0; i<point3dx.size(); i++)
	{
		size_t posOpenBracket = point3dx[i].find("[");
		size_t posCloseBracket = point3dz[i].find("]");
		string xVal = point3dx[i].substr(posOpenBracket +1);
		string yVal = point3dy[i].substr(0);
		string zVal = point3dz[i].substr(0, posCloseBracket);
		int x = stoi(xVal);
		int y = stoi(yVal);
		int z = stoi(zVal);
		point3DVector.push_back(Point3D(x,y,z));
	}
	return point3DVector;
}

// extract x, y values of Line2D
// remove ',' 
// remove '[' and ']' 
vector<Line2D> processLine2D(vector<string> fileData)
{
	vector <string> tokenStringVector;

	vector <string> line2dx1; // Line 2D is made up 2 Point2D
	vector <string> line2dy1;

	vector <string> line2dx2;
	vector <string> line2dy2;

	// vector to store Line2D objects
	vector<Line2D> line2DVector;

	vector<Point2D> line2DPt1Vector; // stores Line2D Point 1
	vector<Point2D> line2DPt2Vector; // stores Line2D Point 2

	// Before removal of brackets
	for (int i=0; i<fileData.size(); i++)
	{
		tokenStringVector = splitString (fileData[i], ", ");
		if (tokenStringVector[0] == "Line2D")
		{
			line2dx1.push_back(tokenStringVector[1]);
			line2dy1.push_back(tokenStringVector[2]);
			line2dx2.push_back(tokenStringVector[3]);
			line2dy2.push_back(tokenStringVector[4]);
		}
	}
	
	// Removal of brackets
	line2DPt1Vector = storePoint2D(line2dx1, line2dy1);
	line2DPt2Vector = storePoint2D(line2dx2, line2dy2);

	// store into Line2D
	for (int i=0; i<line2DPt1Vector.size(); i++)
	{
		line2DVector.push_back(Line2D(line2DPt1Vector[i], line2DPt2Vector[i]));
	}

	return line2DVector;
}

// extract x, y, z values of Line3D
// remove ',' 
// remove '[' and ']' 
vector<Line3D> processLine3D(vector<string> fileData)
{
	vector <string> tokenStringVector;

	vector <string> line3dx1; // Line 3D is made up 2 Point3D
	vector <string> line3dy1;
	vector <string> line3dz1;

	vector <string> line3dx2;
	vector <string> line3dy2;
	vector <string> line3dz2;

	// vector to store Line3D objects
	vector<Line3D> line3DVector;

	vector<Point3D> line3DPt1Vector; // stores Line3D Point 1
	vector<Point3D> line3DPt2Vector; // stores Line3D Point 2

	// Before removal of brackets
	for (int i=0; i<fileData.size(); i++)
	{
		tokenStringVector = splitString (fileData[i], ", ");
		if (tokenStringVector[0] == "Line3D")
		{
			line3dx1.push_back(tokenStringVector[1]);
			line3dy1.push_back(tokenStringVector[2]);
			line3dz1.push_back(tokenStringVector[3]);
			line3dx2.push_back(tokenStringVector[4]);
			line3dy2.push_back(tokenStringVector[5]);
			line3dz2.push_back(tokenStringVector[6]);
		}
	}
	
	// Removal of brackets
	line3DPt1Vector = storePoint3D(line3dx1, line3dy1, line3dz1);
	line3DPt2Vector = storePoint3D(line3dx2, line3dy2, line3dz2);
	
	// store into Line3D
	for (int i=0; i<line3DPt1Vector.size(); i++)
	{
		line3DVector.push_back(Line3D(line3DPt1Vector[i], line3DPt2Vector[i]));
	}

	return line3DVector;
}
