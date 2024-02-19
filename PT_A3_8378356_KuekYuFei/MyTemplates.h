/*
Done By: Natasha Jeng Yee Heng
Student Number: 6959684
Subject: CSCI251 Assignment 3
*/
#include <math.h>

// Generic Function Template
template <typename T>
double scalar_difference(T val1, T val2)
{
	double difference;
	difference = fabs(val1.getScalarValue() - val2.getScalarValue());
	return difference;
}

template <typename T>
bool equals(T val1, T val2)
{
	if (val1 == val2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

