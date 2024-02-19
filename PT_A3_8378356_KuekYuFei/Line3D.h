/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 3
*/

#ifndef LINE_3D
#define LINE_3D

#include "Line2D.h" // Parent class
#include "Point3D.h" // use Point3D class

using namespace std;

class Line3D : public Line2D
{
	friend bool operator ==(const Line3D &lhs, const Line3D &rhs);
	friend ostream & operator <<(ostream &out, const Line3D &line);
	private:
		Point3D pt1; // Line 3D HAS-A Point3D
		Point3D pt2; // Line 3D HAS-A Point3D
	protected:
		void setLength() override;
	public:
		Line3D();
		Line3D(Point3D pt1, Point3D pt2);
		Point3D getPt1() const;
		Point3D getPt2() const;
		void setPt1(Point3D pt1);
		void setPt2(Point3D pt2);
		static vector<Line3D> processSortingLine3D(vector<Line3D> line3DVector, string sortingCriteria, string sortingOrder);
		static void displaySortedLine3D(vector <Line3D> line3DSortedVector);
};
#endif
