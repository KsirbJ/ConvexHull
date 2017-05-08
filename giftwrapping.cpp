using namespace std;


/**
*	Simulate the giftwrapping (Jarvis March) algorithm
*	
*	@param points - A vector of points
*	@return - The number of points on the hull
*/
int do_giftwrapping(vector<point> &points){

	// If there's less than 4 points, they all form the convex hull
	int size = points.size();
	if(size < 4)
		return size;

	// Find the leftmost point
	int leftmost = 0;
	for(int i = 0; i < size; ++i){
		if(points[i].x < points[leftmost].x || 
			(points[i].x == points[leftmost].x && points[i].y < points[leftmost].y)){
			leftmost = i;
		}
	}

	// Count the number of points on the hull
	int convex_points = 0;

	int p = leftmost, q = 0;
	do {
		// Add the last point we found
		convex_points++;

		// Next point in the list
		q = (p+1)%size;

		for(int i = 0; i < size; ++i){
			if(p == i || q == i)
				continue;
			if(orientation(points[p], points[q], points[i]) > 0 )
				q = i;
		}

		p = q;

	}while(leftmost != p);

	// return the number of convex points
	return convex_points;
}
