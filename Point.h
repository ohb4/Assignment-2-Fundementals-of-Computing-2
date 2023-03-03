#include<iostream>
#include<string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <time.h>

using namespace std;

class point
{
	private:
		float x;
		float y;								// Data members x and y
	public:
		point();								// Default Constructor, sets X = Y = 0
		point(float X, float Y); 				// Constructor. Initializes both X and Y.

		void setX(float X); 					// Set X value
		void setY(float Y); 					// Set Y value

		float getX() const; 					// Get X value
		float getY() const; 					// Get Y value

		void display() const; 					// Display point as (X , Y)
		float distance(const point& p) const; 	// distance between current point object and another point p
};

// center function that returns the center of the cluster
point center(point* C, int n);

// Function that finds which cluster is nearest to the point
void closer(point* A, point* B, const point& C);