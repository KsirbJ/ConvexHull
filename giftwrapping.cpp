#include <string>
#include <iostream>
#include <vector>

using namespace std;

// A points, has x and y. 
// Only using int, though should work with float/double
struct point {
	int x;
	int y;
};


/**
 *	Find out whether the lines fromed by 3 points make a right or left turn
 *
 *	@param p1, p2, p3 - The 3 points to check
 *	@return - The difference in their slopes
 */
int slope_difference(point p1, point p2, point p3){
	return (p2.y - p1.y)*(p3.x - p2.x) - (p2.x - p1.x)*(p3.y - p1.y);

}


/**
*	Simulate the giftwrapping (Jarvis March) algorithm
*	
*	@param points - A vector of points
*	@return - A vector of the points that form the convex hull
*/
vector<point> do_giftwrapping(vector<point> points){

	// If there's less than 4 points, they all form the convex hull
	if(points.size() < 4)
		return points;

	// Find the leftmost point
	int leftmost = 0;
	for(int i = 0; i < points.size(); ++i){
		if(points[i].x < points[leftmost].x){
			leftmost = i;
		}else if(points[i].x == points[leftmost].x){
			// In case of tie, select the one with lowest y
			leftmost = points[i].y < points[leftmost].y ? i : leftmost;
		}
	}

	// vector to store the results
	vector<point> hull;

	int p = leftmost, q = 0;
	int size = points.size();

	do {
		// Add the last point we found
		hull.push_back(points[p]);

		// Next point in the list
		q = (p+1)%size;

		for(int i = 0; i < size; ++i){
			if(slope_difference(points[p], points[i], points[q]) > 0 )
				q = i;
		}

		p = q;

	}while(leftmost != p);

	return hull;
}



int main(int argc, char const *argv[])
{
	vector<point> p = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}, {2,4}, {4,6}, {6, 8}};

    vector<point> res(do_giftwrapping(p));

    for(int i = 0; i < res.size(); ++i){
    	cout << "(" << res[i].x << "," << res[i].y << ")" << endl;
    }
	return 0;

}