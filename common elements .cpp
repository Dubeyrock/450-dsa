Common elements
EasyAccuracy: 38.69%Submissions: 100k+Points: 2
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function commonElements() which take the 3 arrays A[], B[], C[] and their respective sizes n1, n2 and n3 as inputs and returns an array containing the common element present in all the 3 arrays in sorted order. 
If there are no such elements return an empty array. In this case the output will be printed as -1.

 

Expected Time Complexity: O(n1 + n2 + n3)
Expected Auxiliary Space: O(n1 + n2 + n3)

 

Constraints:
1 <= n1, n2, n3 <= 10^5
The array elements can be both positive or negative integers.
  
  
  /* code */
  class Solution
{
    public:    
       vector <int> commonElements (int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
        {
            int i = 0, j = 0, k = 0;
            vector<int> ans;
            int prev1, prev2, prev3;
         
            prev1 = prev2 = prev3 = INT_MIN;
         
            while (i < n1 && j < n2 && k < n3) {
               
                while (ar1[i] == prev1 && i < n1)
                    i++;
         
                while (ar2[j] == prev2 && j < n2)
                    j++;
         
                while (ar3[k] == prev3 && k < n3)
                    k++;
         
                if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
                    ans.push_back(ar1[i]);
                    prev1 = ar1[i];
                    prev2 = ar2[j];
                    prev3 = ar3[k];
                    i++;
                    j++;
                    k++;
                }
         
                else if (ar1[i] < ar2[j]) {
                    prev1 = ar1[i];
                    i++;
                }
         
                else if (ar2[j] < ar3[k]) {
                    prev2 = ar2[j];
                    j++;
                }
         
                else {
                    prev3 = ar3[k];
                    k++;
                }
            }
            
            return ans;
        }

};
  
