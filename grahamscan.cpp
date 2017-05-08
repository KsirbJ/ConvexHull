#include <stack>
#include <stdlib.h>
#include <algorithm>
using namespace std;


/**
 *	Gets the second to last point from a stack
 *
 *	@param points - stack of points to get the second to last point from
 *	@return - the second to last point in the stack
 */
point secondToLast(stack<point> &points)
{
  point temp = points.top();
  points.pop();
  point secToLast = points.top();
  points.push(temp);
  return secToLast;
}

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


  // Remove collinear points
  int new_size = 1; 
  for (int i=1; i<n; i++){
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
    while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0)
          i++;

    points[new_size] = points[i];
    new_size++;
  }

  // Only look at first m points. Rest are collinear
  n = new_size;

  //Initialize stack for hull points
  stack<point> hull;
  //Push first three points in hull
  hull.push(points[0]);
  hull.push(points[1]);
  hull.push(points[2]);


  //loops through the array to check for each being on the hull
  for (int i = 3; i < n; i++)
  {
    while (orientation(secondToLast(hull), hull.top(), points[i]) > 0)
    {
      if(hull.size() > 1)
        hull.pop();
      else if(i == n)  // All collinear
        break;
      else
        i++;  // Try next point
      
    }
    hull.push(points[i]);
  }

  // if(n < 100000){
  //   for(int k = 0; k < j; ++k){
  //     point p = hull.top();
  //     hull.pop();
  //     cout << "{" <<  p.x << "," << p.y <<  "}," << endl;    
  //   }
  // }
  return hull.size();
}
