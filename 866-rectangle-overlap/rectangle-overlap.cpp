class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1 == rec2) return true;
        bool xrange1 = rec1[0] < rec2[0] && rec2[0] < rec1[2] || rec1[0] < rec2[2] && rec2[2] < rec1[2];
        bool xrange2 = rec2[0] < rec1[0] && rec1[0] < rec2[2] || rec2[0] < rec1[2] && rec1[2] < rec2[2];
        bool xrange = xrange1 || xrange2;
        bool yrange1 = rec1[1] < rec2[1] && rec2[1] < rec1[3] || rec1[1] < rec2[3] && rec2[3] < rec1[3];
        bool yrange2 = rec2[1] < rec1[1] && rec1[1] < rec2[3] || rec2[1] < rec1[3] && rec1[3] < rec2[3];
        bool yrange = yrange1 || yrange2;

        if(xrange && yrange) return true;
        return false;

    }
};