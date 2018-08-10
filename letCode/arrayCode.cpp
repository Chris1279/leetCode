#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	//-----26------删除排序数组中的重复项------
	int removeDuplicates(vector<int>& nums) {
		//方法一
		//auto end_unique = unique(nums.begin(), nums.end());
		//nums.erase(end_unique, nums.end());
		//方法二
		if (nums.size() == 0)
			return 0;
		int i = 0;
		for (int j = 1; j < nums.size(); j++) {
			if (nums[i] != nums[j]) {
				i++;
				nums[i] = nums[j];
			}
		}
		return i + 1;
	}

	//-----35------搜索插入位置------
	int searchInsert(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= target)
				return i;
		}
		return nums.size();
	}

	//--------53-----最大子序和--------
	int maxSubArray(vector<int>& nums) {
		vector<int > sums(nums.size(),0);
		int maxSum = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			int sum = nums[i];
			int mSum = sum;
			for (int j = i+1; j < nums.size(); j++) {
				sum += nums[j];
				if (sum > mSum)
					mSum = sum;
			}
			if (mSum > maxSum)
				maxSum = mSum;

		}
		return maxSum;
	}

	//------66----------加一-----------
	vector<int> plusOne(vector<int>& digits) {
		int label = 1;
		vector<int> digitsNew;
		for (int i = digits.size() - 1; i >= 0; i--) {
			if (digits[i] + label < 10) {
				digits[i] = digits[i] + label;
				label = 0;
			}
			else {
				digits[i] = digits[i] + label - 10;
				label = 1;
			}
		}
		if (label)
			digitsNew.push_back(1);
		for (auto c : digits)
			digitsNew.push_back(c);
		return digitsNew;
	}

	//------88-----合并两个有序数组------
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pushNum = 0;
		for (int i = 0; i < nums2.size(); i++) {
			for (int j = pushNum; j < m+i; j++) {
				if (nums1[j] >= nums2[i]) {
					pushNum = j;
					break;
				}
				pushNum = m + i;
			
			}
			for (int k = m + i; k > pushNum; k--) 
				nums1[k] = nums1[k - 1];
			nums1[pushNum] = nums2[i];
		}
	}

	//------118-----杨辉三角--------
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> tangle;
		if (numRows == 0)
			return tangle;
		tangle.push_back(vector<int>(1, 1));
		for (int i = 1; i < numRows; i++) {
			vector<int> tangleRow;
			for (int j = 0; j < i+1; j++) {
				if(j-1<0)
					tangleRow.push_back(0 + tangle[i - 1][j]);
				else if(j>tangle[i - 1].size()-1)
					tangleRow.push_back(tangle[i - 1][j - 1] + 0);
				else
					tangleRow.push_back(tangle[i - 1][j - 1] + tangle[i - 1][j]);
			}
			tangle.push_back(tangleRow);
		}
		return tangle;
	}

	//------119-----杨辉三角II---------
	vector<int> getRow(int rowIndex) {

	}

	//-------414------第三大的数--------
	int thirdMax(vector<int>& nums) {
		vector<int>::iterator first = nums.begin();
		vector<int>::iterator second= nums.end(),third= nums.end();
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == *first)
				continue;
			if (nums[i] > *first) {
				third = second;
				second = first;
				first = nums.begin()+i;
			}
			else {
				if (second == nums.end())
					second = nums.begin() + i;
				if(nums[i]==*second)
					continue;
				if (nums[i] > *second) {
					third = second;
					second = nums.begin() + i;
				}
				else {
					if (third == nums.end()||nums[i] > *third)
						third = nums.begin() + i;
					else
						continue;

				}
			}
		}
		if (third == nums.end())
			return *first;
		return *third;

	}

	//-------661------图片平滑器---------
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>> N;
		for (int i = 0; i < M.size(); i++) { 
			vector<int> n;
			for (int j = 0; j < M[0].size();j++) {
				int a[9][2] = {-1,-1,0,-1,1,-1,-1,0,0,0,1,0,-1,1,0,1,1,1};
				int b[9];
				double sum = 0;
				int num = 0;
				for (int k = 0; k < 9; k++) {
					if (a[k][0] + i < 0 || a[k][1] + j < 0 || a[k][0] + i >= M.size() || a[k][1] + j >= M[0].size())
						b[k] = 0;
					else {
						b[k] = M[a[k][0] + i][a[k][1] + j];
						num++;
					}

					sum += b[k];
				}
			n.push_back( int(sum / num));
			}
			N.push_back(n);
		}
		return N;
	}


	//-------
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {

	}
};

int main() {

	Solution s;

	int a[3][3] = { {1,1,1},{1,0,1},{1,1,1} };

	vector<int> n1(&a[0][0],&a[1][0]);
	vector<int> n2(&a[1][0], &a[2][0]);
	vector<int> n3(&a[2][0], &a[2][2]+1);
	vector<vector<int>> input;
	input.push_back(n1);
	input.push_back(n2);
	input.push_back(n3);

	vector<vector<int>> m = s.imageSmoother(input);

}