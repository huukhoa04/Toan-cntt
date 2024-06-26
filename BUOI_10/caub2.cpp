// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
//Jarvis
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Point
{
	ll x, y;
    // ostream& operator<<(ostream& os, const Point dt)
    // {
    //     os << "(" <<dt.x << ' - ' << dt.y << ")" << "\n";
    //     return os;
    // }
};

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // collinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

// Prints convex hull of a set of n points.
vector<Point> convexHull(Point points[], int n)
{
	// There must be at least 3 points

	// Initialize Result
	vector<Point> hull;

	// Find the leftmost point
	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;

	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again. This loop runs O(h)
	// times where h is number of points in result or output.
	int p = l, q;
	do
	{
		// Add current point to result
		hull.push_back(points[p]);

		// Search for a point 'q' such that orientation(p, q,
		// x) is counterclockwise for all points 'x'. The idea
		// is to keep track of last visited most counterclock-
		// wise point in q. If any point 'i' is more counterclock-
		// wise than q, then update q.
		q = (p+1)%n;
		for (int i = 0; i < n; i++)
		{
		// If i is more counterclockwise than current q, then
		// update q
		if (orientation(points[p], points[i], points[q]) == 2)
			q = i;
		}

		// Now q is the most counterclockwise with respect to p
		// Set p as q for next iteration, so that q is added to
		// result 'hull'
		p = q;

	} while (p != l); // While we don't come to first point

	// Print Result
	// for (int i = 0; i < hull.size(); i++)
	// 	cout << "(" << hull[i].x << ", "
	// 		<< hull[i].y << ")\n";
    return hull;
}
void printVector(vector<Point> a)
{
    cout << "Convex Hull: " << "\n";
    for (int i = 0; i < a.size(); i++)
	cout << "(" << a[i].x << ", "<< a[i].y << ")\n";
}
double polygonArea(vector<Point> ans, int n)
{
    double S = 0;
    for (int i = 0; i < n - 1; i++)
    {
        S += (ans.at(i).x* ans.at(i+1).y) - (ans.at(i+1).x*ans.at(i).y);
    }
    double A = 0.5*fabs(S);
    // S = (1/2)*fabs(S);
    return A;
}
// Driver program to test above functions
int main()
{
	Point points[] = {{4, 5}, {6, 4}, {7,6}, {8, 7},
					{9, 8}, {5, 10}, {4, 9}, {5, 9}, {8, 5}, {8, 10}};
    int T = sizeof(points) / sizeof(points[0]);
    vector<Point> ans;
	if (T>3){
        ans = convexHull(points, T);
    }
    int n = ans.size();
    // double S = polygonArea(ans);
    printVector(ans);
    double S = polygonArea(ans, n);
    cout <<"polygon area: "<< S << "\n";
	return 0;
}
