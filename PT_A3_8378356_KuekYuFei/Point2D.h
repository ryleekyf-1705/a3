/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 3
*/

#ifndef POINT_2D
#define POINT_2D

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Point2D
{
	friend bool operator ==(const Point2D &lhs, const Point2D &rhs);
	friend ostream & operator <<(ostream &out, const Point2D & pt);
	
	protected:
		int x;
		int y;
		double distFrOrigin;
		virtual void setDistFrOrigin();	
	public:
		Point2D();
		Point2D(int x, int y);
		int getX() const;
		int getY() const;
		double getScalarValue() const;
		void setX(int x);
		void setY(int y);
		static vector<Point2D> processSortingPoint2D(vector<Point2D> point2DVector, string sortingCriteria, string sortingOrder);
		static void displaySortedPoint2D(vector <Point2D> point2DSortedVector);
};
#endif
