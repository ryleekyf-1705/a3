/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 3
*/

#ifndef POINT_3D
#define POINT_3D

#include "Point2D.h"
#include <vector>
#include <string>

using namespace std;

class Point3D : public Point2D
{
	friend bool operator ==(const Point3D &lhs, const Point3D &rhs);
	friend ostream & operator <<(ostream &out, const Point3D & pt);

	protected:
		int z;
		void setDistFrOrigin() override;	
	public:
		Point3D();
		Point3D(int x, int y, int z);
		int getZ() const;
		void setZ(int z);
		static vector<Point3D> processSortingPoint3D(vector<Point3D> point3DVector, string sortingCriteria, string sortingOrder);
		static void displaySortedPoint3D(vector <Point3D> point3DSortedVector);
};
#endif
