#include <algorithm>
using namespace std;

/**
*	Simulate the graham scan algorithm
*
*	@param points - A vector of points
*	@return - The number of points on the hull
*/
int doGrahamscan(vector<point> points){

  int n = points.size();

  //if graph has less than 4 points there is no hull so return
  if (n < 4) return n;

  //loop to calculate the point with the lowest y-value
  int lowestY = 0;
  for (int i = 1; i < n; i++)
  {
    if ((points[i].y < points[lowestY].y) || 
      (points[lowestY].y == points[i].y && points[i].x < points[lowestY].x))
    {
      lowestY = i;
    }
  }

  //swap the first and the lowest point to ensure low point is at front of array
  point temp = points[0];
  points[0] = points[lowestY];
  points[lowestY] = temp;


  p0 = points[0];

  //sort the points by increasing polar angle
  sort(points.begin() + 1, points.end());


  // Remove points that are collinear with p0
  vector<point> points_;
  points_.push_back(p0);

  // Copy all points that are not collinear to p0 to a new vector
  for (int i=1; i<n; i++){
    while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0)
          i++;

    points_.push_back(points[i]);
  }

  // Only look at first m points. Rest are collinear
  n = points_.size();

  if(n < 4)
    return n;

  //Initialize vector for hull points
  vector<point> hull;
  hull.reserve(points_.size());
  //Push first three points in hull
  hull.push_back(points_[0]);
  hull.push_back(points_[1]);
  hull.push_back(points_[2]);

  int j = 2;


  //loops through the array to check for each being on the hull
  for (int i = 3; i < n; i++)
  {
    while (orientation(hull[j-1], hull[j], points_[i]) > 0)
    {
      if(j > 1){
        hull.pop_back();
        j--;
      }else
        i++;  // Try next point
      
    }
    hull.push_back(points_[i]);
    j++;
  }


  return hull.size();
}
