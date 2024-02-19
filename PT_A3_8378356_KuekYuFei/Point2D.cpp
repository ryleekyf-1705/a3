/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 3
*/

#include "Point2D.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

Point2D::Point2D()
{
}

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
	setDistFrOrigin();
}

int Point2D::getX() const
{
	return x;
}

int Point2D::getY() const
{
	return y;
}

double Point2D::getScalarValue() const
{
	return distFrOrigin;
}

void Point2D::setX(int x)
{
	this->x = x;
}

void Point2D::setY(int y)
{
	this->y = y;
}

void Point2D::setDistFrOrigin()
{
	double xValue = (x - 0) * (x - 0);
	double yValue = (y - 0) * (y - 0);
	//double distance;
	//distance = sqrt(xValue + yValue);
	//cout << "xValue: " << xValue << endl;
	//cout << "yValue: " << yValue << endl;
	//cout << "distance: " << distance << endl;
	this->distFrOrigin = sqrt(xValue + yValue);
}

// overloaded operator ==
bool operator ==(const Point2D &lhs, const Point2D &rhs)
{
	if (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY())
		return true;
	else
		return false;
}

// default overloaded operator <<
ostream & operator <<(ostream &out, const Point2D & pt)
{
	double scalarValue = pt.getScalarValue();
	scalarValue = round(scalarValue * 1000.0) / 1000.0;

	stringstream ss;
	ss << fixed << setprecision(3) << scalarValue;
	string dist = ss.str();

	//out << "[" << setw(4) <<  pt.getX() << ", " << setw(4) << pt.getY() << "]" << setw(dist.size()+3) << dist;
	out << "[" << pt.getX() << ", " << pt.getY() << "], " << "distFrOrigin : " << dist;
	return out;
}


// Choice 5: Process sorting, store sorted vector, return sorted vector
vector<Point2D> Point2D::processSortingPoint2D(vector<Point2D> point2DVector, string sortingCriteria, string sortingOrder)
{
	if (sortingCriteria == "x-ordinate" && sortingOrder == "ASC")
	{
		struct comparePoint2D {
			inline bool
			operator()(Point2D lhs, Point2D rhs) const
			{
				return (lhs.getX() < rhs.getX());
			}
		};
		stable_sort(point2DVector.begin(), point2DVector.end(), comparePoint2D{});
	}
	else if (sortingCriteria == "x-ordinate" && sortingOrder == "DSC")
	{
		struct comparePoint2D {
			inline bool
			operator()(Point2D lhs, Point2D rhs) const
			{
				return (lhs.getX() > rhs.getX());
			}
		};
		stable_sort(point2DVector.begin(), point2DVector.end(), comparePoint2D{});	
	}
	else if (sortingCriteria == "y-ordinate"  && sortingOrder == "ASC")
	{
		struct comparePoint2D {
			inline bool
			operator()(Point2D lhs, Point2D rhs) const
			{
				return (lhs.getY() < rhs.getY());
			}
		};
		stable_sort(point2DVector.begin(), point2DVector.end(), comparePoint2D{});
	}
	else if (sortingCriteria == "y-ordinate"  && sortingOrder == "DSC")
	{
		struct comparePoint2D {
			inline bool
			operator()(Point2D lhs, Point2D rhs) const
			{
				return (lhs.getY() > rhs.getY());
			}
		};
		stable_sort(point2DVector.begin(), point2DVector.end(), comparePoint2D{});
	}
	else if (sortingCriteria == "distFrOrigin" && sortingOrder == "ASC")
	{
		struct comparePoint2D {
			inline bool
			operator()(Point2D lhs, Point2D rhs) const
			{
				return (lhs.getScalarValue() < rhs.getScalarValue());
			}
		};
		stable_sort(point2DVector.begin(), point2DVector.end(), comparePoint2D{});
	}
	else if (sortingCriteria == "distFrOrigin" && sortingOrder == "DSC")
	{
		struct comparePoint2D {
			inline bool
			operator()(Point2D lhs, Point2D rhs) const
			{
				return (lhs.getScalarValue() > rhs.getScalarValue());
			}
		};
		stable_sort(point2DVector.begin(), point2DVector.end(), comparePoint2D{});
	}

	// store sorted vector
	vector <Point2D> point2DSortedVector;
	for (int i=0; i<point2DVector.size(); i++)
	{
		point2DSortedVector.push_back(point2DVector[i]);
	}
	return point2DSortedVector;
}

// Choice 5 -- Display sorted vector
void Point2D::displaySortedPoint2D(vector <Point2D> point2DSortedVector)
{
	// After sort
	// Display Header
	cout << right << setfill(' ');
	cout << setw(5) << "X" << setw(6) << "Y" << setw(4) << " " << setw(14)<< "Dist Fr Origin";
	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - -" << endl;

	// Display sorted vector
	for (int i=0; i<point2DSortedVector.size(); i++)
	{
		double scalarValue = point2DSortedVector[i].getScalarValue();
		scalarValue = round(scalarValue * 1000.0) / 1000.0;

		stringstream ss;
		ss << fixed << setprecision(3) << scalarValue;
		string dist = ss.str();

		cout << "[" << setw(4) <<  point2DSortedVector[i].getX() << ", " << setw(4) << 			point2DSortedVector[i].getY() << "]" << setw(dist.size()+3) << dist << endl;
	}
}
