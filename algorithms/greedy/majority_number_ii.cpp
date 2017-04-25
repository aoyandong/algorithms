class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n1, n2;
        int counter1=0, counter2=0;
        
        for (int i=0; i<nums.size(); i++){
            if (counter1!=0 && n1==nums[i]){
                counter1++;
                continue;
            }
            if (counter2!=0 && n2==nums[i]){
                counter2++;
                continue;
            }
            if (counter1==0){
                n1 = nums[i];
                counter1++;
            }
            else if (counter2==0){
                n2 = nums[i];
                counter2++;
            }
            else{
                counter1--;
                counter2--;
            }
        }
        counter1 = 0;
        for (int i=0; i<nums.size();i++){
            if (nums[i]==n1) counter1++;
            if (nums[i]==n2) counter1--;
        }
        if (counter1>0) return n1;
        else return n2;
    }
};

