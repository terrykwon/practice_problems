#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Basic four-direction DFS problem.
        int m = image.size();
        int n = image[0].size();
        int old_color = image[sr][sc];
        if (color == old_color) {
            return image;
        }

        vector<pair<int, int>> stack;
        stack.push_back({sr, sc});

        while (!stack.empty()) {
            pair<int, int> p = stack.back();
            stack.pop_back();
            int r = p.first;
            int c = p.second;

            if (image[r][c] != old_color) {
                continue;
            }

            image[r][c] = color;
            if (r-1 >= 0 && image[r-1][c] == old_color) {  // up
                stack.push_back({r-1, c});
            }
            if (c-1 >= 0 && image[r][c-1] == old_color) {  // left
                stack.push_back({r, c-1});
            }
            if (r+1 < m && image[r+1][c] == old_color) {  // down
                stack.push_back({r+1, c});
            }
            if (c+1 < n && image[r][c+1] == old_color) {  // right
                stack.push_back({r, c+1});
            }
        }
        return image;
    }
};

int main() {
    
}