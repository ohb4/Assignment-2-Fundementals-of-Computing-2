#include<iostream>
#include<string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <time.h>
#include "Point.h"

using namespace std;

// Default Constructor, sets X = Y = 0
point::point()
{
	// setting the variables to zero
	x = 0;
	y = 0;
}

// Constructor. Initializes both X and Y.
point::point(float X, float Y)
{
	// initializing X and Y
	x = X;
	y = Y;
}

// Set X value
void point::setX(float X)
{
	// sets the value of x
	x = X;
}

// Set Y value
void point::setY(float Y)
{
	// sets the value of y
	y = Y;
}

// Get X value
float point::getX() const
{
	// returns the value of x
	return x;
}

// Get Y value
float point::getY() const
{
	// returns the value of y
	return y;
}

// Display point as (X , Y)
void point::display() const
{
	// message to reveal the point as (X , Y)
	cout << "The Coordinates of Point ( "  << getX()  <<" , " << getY() << " )\t-\t";
}

//  distance between current point object and another point p
float point::distance(const point& p) const
{
	// variable for the distance
	float D;
	// formula that calculates the distance
	D = sqrt(pow((x - p.x),2)+pow((y - p.y),2));
	// returning the distance
	return D;
}

// center function that returns the center of the cluster
point center(point* C, int n)
{
	// sum for each X and Y coordinates
	float sumx = 0;
	float sumy= 0;

	// variables to find the center
	// or average point of the cluster
	float avg_x;
	float avg_y;

	// computes the sum of x and y coordinates
	for (int i = 0; i < n; i++)
	{
		sumx += C[i].getX();
		sumy += C[i].getY();
	}

	// computes the average of X and Y coordinates
	avg_x = sumx / n;
	avg_y = sumy / n;

	// returns the center of cluster
	return point(avg_x, avg_y);
}

// Function that finds which cluster is nearest to the point
void closer(point* A, point* B, const point& C)
{

	C.display();
	
	// if statement to see which cluster the point is closer to
	if (C.distance(center(A, 200)) < C.distance(center(B, 200)))
	{
		// message displayed that shows that its closer to cluster A
		cout << "The point is closer to Cluster A than Cluster B\n";
	}
	else if(C.distance(center(A, 200)) > C.distance(center(B, 200)))
	{
		// message displayed that shows that its closer to cluster B
		cout << "The point is closer to cluster B than Cluster A\n";
	}
}

int main()
{
	// the function of randomizing numbers
	srand(time(NULL));

	// number of points for the cluster
	int n = 200;
	// size of the array we need to fill with points
	// because we need 20 points
	const int size = 20;

	// Array that takes in the 20 points
	point p[size];
	// Loop that sets the points
	for (int i = 0; i < size; i++)
	{
		p[i].setX((rand() % 95) + 5);
		p[i].setY((rand() % 95) + 5);
	}

	// Array for cluster A
	point* A = new point[n];
	// Loop that sets the points for cluster A
	for (int i = 0; i < n; i++)
	{
		A[i].setX((rand() % 20) + 70.0);
		A[i].setY((rand() % 20) + 70.0);
	}


	// Array for cluster B
	point* B= new point[n];
	// Loop that sets the points for cluster B
	for (int i = 0; i < n; i++)
	{
		B[i].setX((rand() % 20) + 20.0);
		B[i].setY((rand() % 20) + 20.0);
	}

	// loop that sees which of the points 
	// gathered is closer to which cluster
	for (int i = 0; i < size; i++)
	{
		closer(A, B, p[i]);
	}

	return 0;
}