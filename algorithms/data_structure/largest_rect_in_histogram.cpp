class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        // Idea: keep a stack with shortest bars. Start by scanning the histogram, whenever see a shorter bar, pop the tall ones and calculate areas.
        
        stack<int> S;
        height.push_back(0);
        int area = 0;
        
        for (int r_idx=0; r_idx<height.size(); r_idx++){
            while (!S.empty() && height[S.top()]>height[r_idx]){
                int cur_height = height[S.top()];
                S.pop();
                int l_idx;
                if (S.empty()) l_idx = -1;
                else l_idx = S.top();
                area = max(area, cur_height*(r_idx-l_idx-1));
            }
            S.push(r_idx);
        }
        return area;
    }
};
