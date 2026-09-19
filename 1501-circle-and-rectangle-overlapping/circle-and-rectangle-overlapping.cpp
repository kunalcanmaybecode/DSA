class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int minx = max(x1, min(xCenter, x2));
        int miny = max(y1, min(yCenter, y2));

        return ((xCenter - minx)*(xCenter - minx) + (yCenter - miny)*(yCenter - miny)) <= (radius*radius);
    }
};