#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
// Define a structure to represent a 2D point
struct Point {
    int x, y;
};
// Function to find the next-to-top element in the stack
Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
// Function to calculate the square of the Euclidean distance between two points
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
// Function to sort an array of points with respect to the first point
int compare(const void *vp1, const void *vp2) {
    Point *p1  = (Point *)vp1;
    Point *p2  = (Point *)vp2;
    int orient = (p1->y - p2->y) * (p1->x - p2->x) - (p1->y - p2->y) * (p1->x - p2->x);
    if (orient == 0)
        return (distSq(*p1, *p2) >= 0) ? -1 : 1;
    return (orient >= 0) ? -1 : 1;
}
// Function to perform Graham's Scan algorithm
Point *convexHull(Point points[], int n, int &hullSize) {
    // Find the bottom-most point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }
    // Place the bottom-most point at the first position
    swap(points[0], points[min]);
    // Sort the remaining points based on polar angle
    qsort(&points[1], n - 1, sizeof(Point), compare);
    // If two or more points have the same angle with the bottom-most point, keep the farthest one
    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && (points[i].y - points[i + 1].y) * (points[i].x - points[i + 1].x) == 0)
            i++;
        points[m++] = points[i];
    }
    // If there are less than 3 points, the Convex Hull is not possible
    if (m < 3) {
        hullSize = 0;
        return nullptr;
    }
    // Initialize an empty stack
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    // Process the remaining points
    for (int i = 3; i < m; i++) {
        while (S.size() > 1) {
            Point p2 = S.top();
            S.pop();
            Point p1 = S.top();
            S.pop();
            Point p3        = points[i];
            int orientation = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
            if (orientation > 0) {
                S.push(p1);
                S.push(p2);
                break;
            }
        }
        S.push(points[i]);
    }
    // Store the points from the stack to a dynamic array
    hullSize    = S.size();
    Point *hull = (Point *)malloc(hullSize * sizeof(Point));
    int idx     = 0;
    while (!S.empty()) {
        hull[idx++] = S.top();
        S.pop();
    }
    // Reverse the order to get clockwise order
    reverse(hull, hull + hullSize);
    return hull;
}

// Function to display the Convex Hull
void displayConvexHull(Point *hull, int hullSize) {
    cout << "Convex Hull:\n";
    for (int i = 0; i < hullSize; i++) {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }
}

int main() {
    // Example usage
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n          = sizeof(points) / sizeof(points[0]);
    int hullSize;
    Point *hull = convexHull(points, n, hullSize);
    displayConvexHull(hull, hullSize);
    free(hull);
    return 0;
}