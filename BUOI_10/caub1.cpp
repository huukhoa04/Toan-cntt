// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
//graham scan
#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

struct Point
{
	int x, y;
};

// A global point needed for sorting points with reference
// to the first point Used in compare function of qsort()
Point p0;

// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

// A utility function to swap two points
void swap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
int distSq(Point p1, Point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y);
}

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

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
vector<Point> convexHull(Point points[], int n, vector<Point> inner)
{
    vector<Point> hello;
// Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // Pick the bottom-most or choose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y &&
            points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted output if p2
    // has larger polar angle (in counterclockwise
    // direction) than p1
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);

// If two or more points make same angle with p0,
// Remove all but the one that is farthest from p0
// Remember that, in above sorting, our criteria was
// to keep the farthest point at the end when more than
// one points have same angle.
    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++)
    {
        // Keep removing i while angle of i and i+1 is same
        // with respect to p0
        while (i < n-1 && orientation(p0, points[i],
                                        points[i+1]) == 0)
            i++;


        points[m] = points[i];
        m++; // Update size of modified array
    }

    // If modified array of points has less than 3 points,
    // convex hull is not possible
    if (m < 3) return hello;

// Create an empty stack and push first three points
// to it.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        // Keep removing top while the angle formed by
        // points next-to-top, top, and points[i] makes
        // a non-left turn
        while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
        {
            inner.push_back(S.top());
            S.pop();
        }
        S.push(points[i]);
    }

// Now stack has the output points, print contents of stack
    
    while (!S.empty())
    {
        Point p = S.top();
        hello.push_back(p);
        S.pop();
    }
    return hello;
}

double polygonArea(vector<Point> ans, int n)
{

    double S = 0;
    for (int i = 0; i < n - 1; i++)
    {
        S += (ans.at(i).x* ans.at(i+1).y) - (ans.at(i+1).x*ans.at(i).y);
    }
    double A = 0.5* fabs(S);
    // S = (1/2)*fabs(S);
    return A;
}
void printVector(vector<Point> a)
{
    
    for (int i = 0; i < a.size(); i++)
	cout << "(" << a[i].x << ", "<< a[i].y << ")\n";
}
// Driver program to test above functions
int main()
{
	Point points[] = {{4, 5}, {6, 4}, {7,6}, {8, 7},
					{9, 8}, {5, 10}, {4, 9}, {5, 9}, {8, 5}, {8, 10}};
    int T= sizeof(points) / sizeof(points[0]);
    // cout << "enter number of points: ";
    // cin>>T;
    // if(T<=0)
    // return -1;
    // Point points[T];
    // for(int i=0;i<T;++i){
    //     cout << "Enter x cor of " << i << " point: ";
    //     cin >> x;
    //     points[i].x=x;
    //     cout << "Enter y cor of " << i << " point: ";
    //     cin >> y;
    //     points[i].y=y;
    // }
    vector<Point> inner;
    vector<Point> ans = convexHull(points, T, inner);
    cout<<"\n---------After Using Graham Scan Algorithm---------------\n";
    cout<<"\n***************** CONVEX HULL **********************\n";
    printVector(ans);

    cout << "Inner points: ";
    printVector(inner);
    cout << "Polygon area: " << polygonArea(ans, ans.size());

	return 0;
}
