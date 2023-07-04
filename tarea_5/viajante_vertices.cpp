#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Point {
    double x;
    double y;
};

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int nearestNeighbor(vector<Point>& points, vector<bool>& visited, int current) {
    int n = points.size();
    int nearest = -1;
    double minDist = numeric_limits<double>::max();

    for (int i = 0; i < n; i++) {
        if (!visited[i] && i != current) {
            double dist = distance(points[current], points[i]);
            if (dist < minDist) {
                minDist = dist;
                nearest = i;
            }
        }
    }

    return nearest;
}

vector<int> tspNearestNeighbor(vector<Point>& points) {
    int n = points.size();
    vector<bool> visited(n, false);
    vector<int> tour;
    int current = 0;
    visited[current] = true;
    tour.push_back(current);

    for (int i = 0; i < n - 1; i++) {
        int next = nearestNeighbor(points, visited, current);
        visited[next] = true;
        tour.push_back(next);
        current = next;
    }

    return tour;
}

int main() {
    vector<Point> points = { {0, 0}, {1, 2}, {3, 1}, {4, 3}, {2, 4} };

    vector<int> tour = tspNearestNeighbor(points);

    cout << "Tour: ";
    for (int vertex : tour) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
