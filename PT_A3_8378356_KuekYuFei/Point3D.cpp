/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 3
*/

#include "Point3D.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

Point3D::Point3D() 
{}

Point3D::Point3D(int x, int y, int z) : Point2D(x, y)
{
	this->z = z;
	setDistFrOrigin();
}

int Point3D::getZ() const
{
	return z;
}

void Point3D::setZ(int z)
{
	this->z = z;
}

void Point3D::setDistFrOrigin()
{
	double xValue = (x - 0) * (x - 0);
	double yValue = (y - 0) * (y - 0);
	double zValue = (z - 0) * (z - 0);
	this->distFrOrigin = sqrt(xValue + yValue + zValue);
}

// overloaded operator ==
bool operator ==(const Point3D &lhs, const Point3D &rhs)
{
	if (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY() && lhs.getZ() == rhs.getZ())
		return true;
	else
		return false;
}

// overloaded operator <<
ostream & operator <<(ostream &out, const Point3D & pt)
{
	double scalarValue = pt.getScalarValue();
	scalarValue = round(scalarValue * 1000.0) / 1000.0;

	stringstream ss;
	ss << fixed << setprecision(3) << scalarValue;
	string dist = ss.str();

	out << "[" << pt.getX() << ", " << pt.getY() << ", " << pt.getZ() 
	<< "]" 	<< ", distFrOrigin : " << dist;

	return out;
}

// Choice 5: Process sorting, store sorted vector, return sorted vector
vector<Point3D> Point3D::processSortingPoint3D(vector<Point3D> point3DVector, string sortingCriteria, string sortingOrder)
{
	if (sortingCriteria == "x-ordinate" && sortingOrder == "ASC")
	{
		struct comparePoint3D {
			inline bool
			operator()(Point3D lhs, Point3D rhs) const
			{
				return (lhs.getX() < rhs.getX());
			}
		};
		stable_sort(point3DVector.begin(), point3DVector.end(), comparePoint3D{});
	}
	else if (sortingCriteria == "x-ordinate" && sortingOrder == "DSC")
	{
		struct comparePoint3D {
			inline bool
			operator()(Point3D lhs, Point3D rhs) const
			{
				return (lhs.getX() > rhs.getX());
			}
		};
		stable_sort(point3DVector.begin(), point3DVector.end(), comparePoint3D{});
	}
	else if (sortingCriteria == "y-ordinate" && sortingOrder == "ASC")
	{
		struct comparePoint3D {
			inline bool
			operator()(Point3D lhs, Point3D rhs) const
			{
				return (lhs.getY() < rhs.getY());
			}
		};
		stable_sort(point3DVector.begin(), point3DVector.end(), comparePoint3D{});
	}
	else if (sortingCriteria == "y-ordinate" && sortingOrder == "DSC")
	{
		struct comparePoint3D {
			inline bool
			operator()(Point3D lhs, Point3D rhs) const
			{
				return (lhs.getY() > rhs.getY());
			}
		};
		stable_sort(point3DVector.begin(), point3DVector.end(), comparePoint3D{});
	}
	else if (sortingCriteria == "z-ordinate" && sortingOrder == "ASC")
	{
		struct comparePoint3D {
			inline bool
			operator()(Point3D lhs, Point3D rhs) const
			{
				return (lhs.getZ() < rhs.getZ());
			}
		};
		stable_sort(point3DVector.begin(), point3DVector.end(), comparePoint3D{});
	}
	else if (sortingCriteria == "z-ordinate" && sortingOrder == "DSC")
	{
		struct comparePoint3D {
			inline bool
			operator()(Point3D lhs, Point3D rhs) const
			{
				return (lhs.getZ() > rhs.getZ());
			}
		};
		stable_sort(point3DVector.begin(), point3DVector.end(), comparePoint3D{});
	}
	else if (sortingCriteria == "distFrOrigin" && sortingOrder == "ASC")
	{
		struct comparePoint3D {
			inline bool
			operator()(Point3D lhs, Point3D rhs) const
			{
				return (lhs.getScalarValue() < rhs.getScalarValue());
			}
		};
		stable_sort(point3DVector.begin(), point3DVector.end(), comparePoint3D{});
	}
	else if (sortingCriteria == "distFrOrigin" && sortingOrder == "DSC")
	{
		struct comparePoint3D {
			inline bool
			operator()(Point3D lhs, Point3D rhs) const
			{
				return (lhs.getScalarValue() > rhs.getScalarValue());
			}
		};
		stable_sort(point3DVector.begin(), point3DVector.end(), comparePoint3D{});
	}	
	
	// store sorted vector
	vector <Point3D> point3DSortedVector;

	for (int i=0; i<point3DVector.size(); i++)
	{
		point3DSortedVector.push_back(point3DVector[i]);
	}

	return point3DSortedVector;
}

// Choice 5 -- Display sorted vector
void Point3D::displaySortedPoint3D(vector <Point3D> point3DSortedVector)
{
	// After sort
	// Display Header
	cout << right << setfill(' ');
	cout << setw(5) << "X" << setw(6) << "Y" << setw(6) << "Z";
	cout << setw(18) << "Dist Fr Origin";
	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - -" << endl;

	// Display sorted vector
	for (int i=0; i<point3DSortedVector.size(); i++)
	{
		double scalarValue = point3DSortedVector[i].getScalarValue();
		scalarValue = round(scalarValue * 1000.0) / 1000.0;

		stringstream ss;
		ss << fixed << setprecision(3) << scalarValue;
		string dist = ss.str();

		cout << "[" << setw(4) << point3DSortedVector[i].getX() << ", " << setw(4) << point3DSortedVector[i].getY() << ", " << setw(4) << point3DSortedVector[i].getZ() 
		<< "]" 	<< setw(3) << " " << dist << endl;
	}
}

