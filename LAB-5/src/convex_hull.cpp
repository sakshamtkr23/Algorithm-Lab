#include <iostream>
using namespace std;

struct Point
{
    int x, y;
};

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(Point points[], int n)
{
    if (n < 3)
        return;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;

    do
    {
        cout << "(" << points[p].x << ", " << points[p].y << ")\n";
        q = (p + 1) % n;

        for (int i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != l);
}

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    Point points[100];

    cout << "Enter points (x y):\n";
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    cout << "Convex Hull:\n";
    convexHull(points, n);

    return 0;
}