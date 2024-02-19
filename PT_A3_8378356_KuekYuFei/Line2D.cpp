/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 3
*/

#include "Line2D.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

Line2D::Line2D()
{
}

Line2D::Line2D(Point2D pt1, Point2D pt2)
	: pt1(pt1), pt2(pt2)
{
	setLength();
}

Point2D Line2D::getPt1() const
{
	return pt1;
}

Point2D Line2D::getPt2() const
{
	return pt2;
}

double Line2D::getScalarValue() const
{
	return length;
}

void Line2D::setPt1(Point2D pt1)
{
	this->pt1 = pt1;
}

void Line2D::setPt2(Point2D pt2)
{
	this->pt2 = pt2;
}

void Line2D::setLength()
{
	double xValue = (pt1.getX() - pt2.getX()) * (pt1.getX() - pt2.getX());
	double yValue = (pt1.getY() - pt2.getY()) * (pt1.getY() - pt2.getY());
	this->length = sqrt(xValue + yValue);
}

// overloaded operator ==
bool operator ==(const Line2D &lhs, const Line2D &rhs)
{
	if (lhs.getPt1() == rhs.getPt1() && lhs.getPt2() == rhs.getPt2())
		return true;
	else
		return false;
}

// overloaded operator <<
ostream & operator <<(ostream &out, const Line2D & line)
{
	double scalarValue = line.getScalarValue();
	scalarValue = round(scalarValue * 1000.0) / 1000.0;

	stringstream ss;
	ss << fixed << setprecision(3) << scalarValue;
	string len = ss.str();

	out << "( " << line.getPt1() << " to " << line.getPt2() << " ), " << "length : " << len;
	return out;
}

// Choice 5: Process sorting, store sorted vector, return sorted vector
vector<Line2D> Line2D::processSortingLine2D(vector<Line2D> line2DVector, string sortingCriteria, string sortingOrder)
{
	if (sortingCriteria == "Pt. 1" && sortingOrder == "ASC")
	{
		struct compareLine2D {
			inline bool
			operator()(Line2D lhs, Line2D rhs) const
			{
				// if x is the same value, sort by y ascending
				return 
					(lhs.getPt1().getX() < rhs.getPt1().getX() ||
					lhs.getPt1().getX() == rhs.getPt1().getX() && 
					lhs.getPt1().getY() < rhs.getPt1().getY());
			}
		};
		stable_sort(line2DVector.begin(), line2DVector.end(), compareLine2D{});
	}
	else if (sortingCriteria == "Pt. 1" && sortingOrder == "DSC")
	{
		struct compareLine2D {
			inline bool
			operator()(Line2D lhs, Line2D rhs) const
			{
				// if x is the same value, sort by y descending
				return 
					(lhs.getPt1().getX() > rhs.getPt1().getX() ||
					lhs.getPt1().getX() == rhs.getPt1().getX() && 
					lhs.getPt1().getY() > rhs.getPt1().getY());
			}
		};
		stable_sort(line2DVector.begin(), line2DVector.end(), compareLine2D{});
	}
	else if (sortingCriteria == "Pt. 2" && sortingOrder == "ASC")
	{
		struct compareLine2D {
			inline bool
			operator()(Line2D lhs, Line2D rhs) const
			{
				// if x is the same value, sort by y ascending
				return 
					(lhs.getPt2().getX() < rhs.getPt2().getX() ||
					lhs.getPt2().getX() == rhs.getPt2().getX() && 
					lhs.getPt2().getY() < rhs.getPt2().getY());
			}
		};
		stable_sort(line2DVector.begin(), line2DVector.end(), compareLine2D{});
	}
	else if (sortingCriteria == "Pt. 2" && sortingOrder == "DSC")
	{
		struct compareLine2D {
			inline bool
			operator()(Line2D lhs, Line2D rhs) const
			{
				// if x is the same value, sort by y descending
				return 
					(lhs.getPt2().getX() > rhs.getPt2().getX() ||
					lhs.getPt2().getX() == rhs.getPt2().getX() && 
					lhs.getPt2().getY() > rhs.getPt2().getY());
			}
		};
		stable_sort(line2DVector.begin(), line2DVector.end(), compareLine2D{});
	}	
	else if (sortingCriteria == "Length" && sortingOrder == "ASC")
	{
		struct compareLine2D {
			inline bool
			operator()(Line2D lhs, Line2D rhs) const
			{
				return (lhs.getScalarValue() < rhs.getScalarValue());
			}
		};
		stable_sort(line2DVector.begin(), line2DVector.end(), compareLine2D{});
	}
	else if (sortingCriteria == "Length" && sortingOrder == "DSC")
	{
		struct compareLine2D {
			inline bool
			operator()(Line2D lhs, Line2D rhs) const
			{
				return (lhs.getScalarValue() > rhs.getScalarValue());
			}
		};
		stable_sort(line2DVector.begin(), line2DVector.end(), compareLine2D{});
	}

	// store sorted vector
	vector <Line2D> line2DSortedVector;
	for (int i=0; i<line2DVector.size(); i++)
	{
		line2DSortedVector.push_back(line2DVector[i]);
	}
	return line2DSortedVector;
}

// Choice 5 -- Display sorted vector
void Line2D::displaySortedLine2D(vector <Line2D> line2DSortedVector)
{
	// After sort
	// Display Header
	cout << right << setfill(' ');
	cout << setw(5) << "P1-X" << setw(6) << "P1-Y";
	cout << setw(4) << " ";
	cout << setw(5) << "P2-X" << setw(6) << "P2-Y";
	cout << setw(10) << "Length";
	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - -" << endl;
	
	// Display sorted vector
	for (int i=0; i<line2DSortedVector.size(); i++)
	{
		double scalarValue = line2DSortedVector[i].getScalarValue();
		scalarValue = round(scalarValue * 1000.0) / 1000.0;

		stringstream ss;
		ss << fixed << setprecision(3) << scalarValue;
		string len = ss.str();

		cout << "[" << setw(4) << line2DSortedVector[i].getPt1().getX() << ", " << setw(4) << line2DSortedVector[i].getPt1().getY() 
		<< "]" << setw(3) << " " 
		<< "[" << setw(4) << line2DSortedVector[i].getPt2().getX() << ", "<< setw(4) << line2DSortedVector[i].getPt2().getY() << "]" 
		<< setw(len.size()+3) << len << endl;
	}
}
