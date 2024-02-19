/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 3
*/

#include "Line3D.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

Line3D::Line3D() 
{
}

Line3D::Line3D(Point3D pt1, Point3D pt2) 
	: pt1(pt1), pt2(pt2), Line2D(pt1, pt2)
{
	setLength();
}

Point3D Line3D::getPt1() const
{
	return pt1;
}

Point3D Line3D::getPt2() const
{
	return pt2;
}

void Line3D::setPt1(Point3D pt1)
{
	this->pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2)
{
	this->pt2 = pt2;
}

void Line3D::setLength()
{
	double xValue = (pt1.getX() - pt2.getX()) * (pt1.getX() - pt2.getX());
	double yValue = (pt1.getY() - pt2.getY()) * (pt1.getY() - pt2.getY());
	double zValue = (pt1.getZ() - pt2.getZ()) * (pt1.getZ() - pt2.getZ());
	this->length = sqrt(xValue + yValue + zValue);
}

// overloaded operator ==
bool operator ==(const Line3D &lhs, const Line3D &rhs)
{
	if (lhs.getPt1() == rhs.getPt1() && lhs.getPt2() == rhs.getPt2())
		return true;
	else
		return false;
}

// overloaded operator <<
ostream & operator <<(ostream &out, const Line3D & line)
{
	double scalarValue = line.getScalarValue();
	scalarValue = round(scalarValue * 1000.0) / 1000.0;

	stringstream ss;
	ss << fixed << setprecision(3) << scalarValue;
	string len = ss.str();

	out << "( " << line.getPt1() << " to " 
	<< line.getPt2() << " ), "
	<< "length : " << len;
	return out;
}

// Choice 5: Process sorting, store sorted vector, return sorted vector
vector<Line3D> Line3D::processSortingLine3D(vector<Line3D> line3DVector, string sortingCriteria, string sortingOrder)
{
	if (sortingCriteria == "Pt. 1" && sortingOrder == "ASC")
	{
		struct compareLine3D {
			inline bool
			operator()(Line3D lhs, Line3D rhs) const
			{
				// if x is the same value, sort by y ascending
				return 
					(lhs.getPt1().getX() < rhs.getPt1().getX() ||
					lhs.getPt1().getX() == rhs.getPt1().getX() && 
					lhs.getPt1().getY() < rhs.getPt1().getY());
			}
		};
		stable_sort(line3DVector.begin(), line3DVector.end(), compareLine3D{});
	}
	else if (sortingCriteria == "Pt. 1" && sortingOrder == "DSC")
	{
		struct compareLine3D {
			inline bool
			operator()(Line3D lhs, Line3D rhs) const
			{
				// if x is the same value, sort by y descending
				return 
					(lhs.getPt1().getX() > rhs.getPt1().getX() ||
					lhs.getPt1().getX() == rhs.getPt1().getX() && 
					lhs.getPt1().getY() > rhs.getPt1().getY());
			}
		};
		stable_sort(line3DVector.begin(), line3DVector.end(), compareLine3D{});
	}
	else if (sortingCriteria == "Pt. 2" && sortingOrder == "ASC")
	{
		struct compareLine3D {
			inline bool
			operator()(Line3D lhs, Line3D rhs) const
			{
				// if x is the same value, sort by y ascending
				return 
					(lhs.getPt2().getX() < rhs.getPt2().getX() ||
					lhs.getPt2().getX() == rhs.getPt2().getX() && 
					lhs.getPt2().getY() < rhs.getPt2().getY());
			}
		};
		stable_sort(line3DVector.begin(), line3DVector.end(), compareLine3D{});
	}
	else if (sortingCriteria == "Pt. 2" && sortingOrder == "DSC")
	{
		struct compareLine3D {
			inline bool
			operator()(Line3D lhs, Line3D rhs) const
			{
				// if x is the same value, sort by y descending
				return 
					(lhs.getPt2().getX() > rhs.getPt2().getX() ||
					lhs.getPt2().getX() == rhs.getPt2().getX() && 
					lhs.getPt2().getY() > rhs.getPt2().getY());
			}
		};
		stable_sort(line3DVector.begin(), line3DVector.end(), compareLine3D{});
	}
	else if (sortingCriteria == "Length" && sortingOrder == "ASC")
	{
		struct compareLine3D {
			inline bool
			operator()(Line3D lhs, Line3D rhs) const
			{
				return (lhs.getScalarValue() < rhs.getScalarValue());
			}
		};
		stable_sort(line3DVector.begin(), line3DVector.end(), compareLine3D{});
	}
	else if (sortingCriteria == "Length" && sortingOrder == "DSC")
	{
		struct compareLine3D {
			inline bool
			operator()(Line3D lhs, Line3D rhs) const
			{
				return (lhs.getScalarValue() > rhs.getScalarValue());
			}
		};
		stable_sort(line3DVector.begin(), line3DVector.end(), compareLine3D{});
	}

	// store sorted vector
	vector <Line3D> line3DSortedVector;
	for (int i=0; i<line3DVector.size(); i++)
	{
		line3DSortedVector.push_back(line3DVector[i]);
	}
	return line3DSortedVector;
}

// Choice 5 -- Display sorted vector
void Line3D::displaySortedLine3D(vector <Line3D> line3DSortedVector)
{
	// After sort
	// Display Header
	cout << right << setfill(' ');
	cout << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z";
	cout << setw(4) << " ";
	cout << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z";
	cout << setw(10) << "Length";
	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

	// Display sorted vector
	for (int i=0; i<line3DSortedVector.size(); i++)
	{
		double scalarValue = line3DSortedVector[i].getScalarValue();
		scalarValue = round(scalarValue * 1000.0) / 1000.0;

		stringstream ss;
		ss << fixed << setprecision(3) << scalarValue;
		string len = ss.str();

		cout << "[" << setw(4) << line3DSortedVector[i].getPt1().getX() << ", " << setw(4) << 			line3DSortedVector[i].getPt1().getY() << ", " 
		<< setw(4) << line3DSortedVector[i].getPt1().getZ() << "]" << setw(3) << " " 
		<< "[" << setw(4) << line3DSortedVector[i].getPt2().getX() << ", " << setw(4) << 			line3DSortedVector[i].getPt2().getY() << ", " 
		<< setw(4) << line3DSortedVector[i].getPt2().getZ() 
		<< "]"
		<< setw(len.size()+3) << len << endl;
	}
}
