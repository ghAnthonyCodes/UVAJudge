#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <set>
#include <algorithm>
#define pfp std::pair<float, pt>
#define vpfp std::vector<pfp>

struct pt { int x,y; };

std::vector<pt> convexHull(pt a, pt b, pt c, pt d);
int calcLength(pt a, pt b) { return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); }
double calcAngle(pt a, pt b) {
   double ang = atan((double)(b.y - a.y)/(double)(b.x - a.x));
   ang *= 180.0/M_PI;
   if (ang < 0) 
      ang = 180.0 + ang;
   return ang;
}
bool isPara(pt a, pt b, pt c, pt d) {
   // (by - ay)/(bx - ax) = (cy - dy)/(cx - dx)
   return (b.y - a.y)*(c.x - d.x) == (c.y - d.y)*(b.x - a.x);
}

std::string calcShape(pt a, pt b, pt c, pt d) {
   // Calc lengths of perim
   int abl = calcLength(a, b);
   int bcl = calcLength(b, c);
   int cdl = calcLength(c, d);
   int adl = calcLength(a, d);

   // Calc cross length
   int acl = calcLength(a, c);
   int bdl = calcLength(b, d);

   // All sides the same, diags same
   if (abl == bcl && bcl == cdl && cdl == adl && acl == bdl)
      return "Square";

   // Check if all sides same
   if (abl == bcl && bcl == cdl && cdl == adl)
      return "Rhombus";

   // Check if opposites are same size with diags same
   if (abl == cdl && adl == bcl && acl == bdl)
      return "Rectangle";

   // Else if opposite sides are same
   if (abl == cdl && adl == bcl && isPara(a, b, c, d) && isPara(a, d, b, c))
      return "Parallelogram";

   // If any two sides are parallel
   if (isPara(a, b, c, d) || isPara(a, d, b, c))
      return "Trapezium";

   return "Ordinary Quadrilateral";
}

int main() {
   int T;
   int ax, ay, bx, by, cx, cy, dx, dy;
   scanf("%d", &T);
   for (int t=1; t<=T; t++) {
      scanf("%d %d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
      std::vector<pt> P = convexHull({ax, ay}, {bx, by}, {cx, cy}, {dx, dy});
      // std::vector<pt> P = {{ax, ay}, {bx, by}, {cx, cy}, {dx, dy}};
      // printf("Selected points: (%d %d), (%d %d), (%d %d), (%d %d)\n", P[0].x, P[0].y, P[1].x, P[1].y, P[2].x, P[2].y, P[3].x, P[3].y);
      printf("Case %d: %s\n", t, calcShape(P[0], P[1], P[2], P[3]).c_str());
   }

   return 0;
}

std::vector<pt> convexHull(pt a, pt b, pt c, pt d) {
   std::vector<pt> points = { a, b, c, d };

   // Select first point (bottom y, leftmost x)
   pt p0 = a;
   for (auto& p : points) {
      if (p.y < p0.y || (p.y == p0.y && p.x < p0.x))
         p0 = p;
   }
   std::vector<pt> newPoints;
   for (int i=0; i<4; i++) {
      if (p0.x == points[i].x && p0.y == points[i].y)
         continue;
      newPoints.push_back(points[i]);
   }
   points = newPoints;
   vpfp v;

   // Calc angles of remaining points
   double ang = calcAngle(points[0], p0);
   // printf("%d %d: %lf\n", points[0].x, points[0].y, ang);
   v.push_back({ ang, points[0] });
   ang = calcAngle(points[1], p0);
   v.push_back({ ang, points[1] });
   // printf("%d %d %lf\n", points[1].x, points[1].y, ang);
   ang = calcAngle(points[2], p0);
   v.push_back({ ang, points[2] });
   // printf("%d %d %lf\n", points[2].x, points[2].y, ang);
   std::sort(v.begin(), v.end(), [](const pfp &l, const pfp &r) {
      return l.first > r.first;
   });

   return { p0, v[0].second, v[1].second, v[2].second };
}

