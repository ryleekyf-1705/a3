/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 3
*/

#ifndef LINE_2D
#define LINE_2D

#include "Point2D.h" // use Point2D class
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Line2D
{
	friend bool operator ==(const Line2D &lhs, const Line2D &rhs);
	friend ostream & operator <<(ostream &out, const Line2D &line);
	
	private:
		Point2D pt1; // Line 2D HAS-A Point2D
		Point2D pt2; // Line 2D HAS-A Point2D
	protected:
		double length;
		virtual void setLength();
	public:
		Line2D();
		Line2D(Point2D pt1, Point2D pt2);
		Point2D getPt1() const;
		Point2D getPt2() const;
		double getScalarValue() const;
		void setPt1(Point2D pt1);
		void setPt2(Point2D pt2);
		static vector<Line2D> processSortingLine2D(vector<Line2D> line2DVector, string sortingCriteria, string sortingOrder);
		static void displaySortedLine2D(vector <Line2D> line2DSortedVector);
};
#endif
