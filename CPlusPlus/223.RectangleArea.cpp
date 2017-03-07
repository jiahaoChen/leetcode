class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rectA = (C-A)*(D-B);
        int rectB = (G-E)*(H-F);
        int crossRect = coverRect(max(A,E),max(B,F),min(C,G),min(D,H));
        // cout << "rectA: " << rectA << endl;
        // cout << "rectB: " << rectB << endl;
        // cout << "crss Rect: " << crossRect << endl;
        return rectA+rectB-crossRect;
    }
    int coverRect(int left, int bottom, int right, int top)
    {
        if (left >= right) return 0;
        if (bottom >= top) return 0;
        return (right-left)*(top-bottom);
    }
};