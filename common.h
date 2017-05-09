#include <string>
#include <iostream>
#include <vector>


// A point, has x and y. 
// Only using int, though should work with float/double
struct point {
	int x;
	int y;
};

point p0;


/**
 *  Find out whether the lines fromed by 3 points make a right or left turn
 *
 *  @param p1, p2, p3 - The 3 points to check
 *  @return - The magnitude of the cross product of vectors formed by p1p2 and p1p3
 */
int orientation(point p1, const point &p2, const point &p3){
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}


// Overloaded == operator for the point struct
bool operator==(const point &p1, const point &p2){
    return p1.x == p2.x && p1.y == p2.y;
}

// Compute square distance between 2 points
int distance(const point &lhs, const point &rhs){
    return (lhs.x - rhs.x)*(lhs.x - rhs.x) + (lhs.y - rhs.y)*(lhs.y - rhs.y);
}


/**
 *	Oveloaded < operator for point struct
 *	@param lhs - The left hand side point
 *	@param rhs - The right hand side point
 */
bool operator<(const point &lhs, const point &rhs) {

    int res = orientation(p0, lhs, rhs);
	
    if(res == 0)
        return distance(p0, rhs) >= distance(p0, lhs) ? true : false ; 

    return res > 0 ? false : true;
}





