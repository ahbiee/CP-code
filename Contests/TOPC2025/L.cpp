#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

int sign(double x){
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

struct Point{
    double x, y;
    Point(double _x=0, double _y=0) : x{_x}, y{_y} {}
    Point operator+(const Point &p) const {return Point(x + p.x, y + p.y);}
    Point operator-(const Point &p) const {return Point(x - p.x, y - p.y);}
    Point operator*(double d) const {return Point(x * d, y * d);}
    Point operator/(double d) const {return Point(x / d, y / d);}

    bool operator==(const Point &p) const{
        return sign(x-p.x) == 0 && sign(y - p.y) == 0;
    }

    bool operator<(const Point &p) const{
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
};

using Vector = Point;

double dot(Vector &a, Vector &b){
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

bool onSegment(Point &p, Point &a, Point &b){
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) && p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}

bool Intersect(Point &a, Point &b, Point &c, Point &d){
    double c1 = cross(b-a, c-a);
    double c2 = cross(b-a, d-a);
    double c3 = cross(d-c, a-c);
    double c4 = cross(d-c, b-c);

    if(sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0) return true;

    if (sign(c1) == 0 && onSegment(c, a, b)) return true;
    if (sign(c2) == 0 && onSegment(d, a, b)) return true;
    if (sign(c3) == 0 && onSegment(a, c, d)) return true;
    if (sign(c4) == 0 && onSegment(b, c, d)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int kase;
    cin >> kase;
    while(kase--){
        pair<Point, Point> line, monitor;
        cin >> monitor.first.x >> monitor.first.y >> monitor.second.x >> monitor.second.y;
        cin >> line.first.x >> line.first.y >> line.second.x >> line.second.y;
        Point A{monitor.first.x, monitor.first.y};
        Point B{monitor.first.x, monitor.second.y};
        Point C{monitor.second.x, monitor.first.y};
        Point D{monitor.second.x, monitor.second.y};
        bool intersect = false;
        if(Intersect(line.first, line.second, A, B)) intersect = true;
        if(Intersect(line.first, line.second, B, D)) intersect = true;
        if(Intersect(line.first, line.second, C, D)) intersect = true;
        if(Intersect(line.first, line.second, A, C)) intersect = true;
        if(line.first.x >= monitor.first.x && line.first.y >= monitor.first.y && line.first.x <= monitor.second.x && line.first.y <= monitor.second.y) intersect = true;
        
        if(intersect) cout << "STOP\n";
        else cout << "OK\n";
    }
    return 0;
}

/*
3
0 0 5 5
0 10 10 0
0 0 5 5
6 6 6 7
0 0 5 5
1 1 2 2
*/