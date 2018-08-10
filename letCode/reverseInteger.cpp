#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	//反转整数
	int reverse(int x) {
		int xNew = 0;
		int a = abs(x);
		while (a != 0) {
			int x1 = xNew * 10 + a % 10;
			if (x1 / 10 != xNew)
				return 0;
			xNew = x1;
			a = a / 10;
		}
		return pow(-1,(x<0))*xNew;
		
	}

	//回文数字判断
	bool isPalindrome(int x) {
		if (x<0)
			return false;
		else {
			int temp = 0;
			int a = x;
			while (a != 0) {
				temp = temp * 10 + a % 10;
				a = a / 10;
			}
			if (temp == x)
				return true;
		}
	}

	//回文数字判断方法二
	bool IsPalindrome(int x) {
		// 特殊情况：
		// 如上所述，当 x < 0 时，x 不是回文数。
		// 同样地，如果数字的最后一位是 0，为了使该数字为回文，
		// 则其第一位数字也应该是 0
		// 只有 0 满足这一属性
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}

		int revertedNumber = 0;
		while (x > revertedNumber) {
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		// 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
		// 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
		// 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
		return x == revertedNumber || x == revertedNumber / 10;
	}

	//罗马字转整数
	int romanToInt(string s) {
		map<char, int> m;
		m.insert(pair<char, int>('I', 1)); 
		m.insert(pair<char, int>('V', 5));
		m.insert(pair<char, int>('X', 10));
		m.insert(pair<char, int>('L', 50));
		m.insert(pair<char, int>('C', 100));
		m.insert(pair<char, int>('D', 500)); 
		m.insert(pair<char, int>('M', 1000));
		int sum = m[s[s.size()-1]];
		for (int i = s.size()-2; i >=0; i--) {
			if (m[s[i]] < m[s[i + 1]])
				sum = sum - m[s[i]];
			else
				sum = sum + m[s[i]];
		}
		return sum;
	}
	//最长公共前缀
	string longestCommonPrefix(vector<string>& strs) {
		string s = "";
		if (!strs.empty()) {
			char c;
			for (int j = 0; j < strs[0].size(); j++) {
				c = strs[0][j];
				for (int i = 1; i < strs.size(); i++) {
					if (strs[i][j] != c)
						return s;
				}
				s += c;
			}
			return s;
		}
		else
			return s;
	}

	bool isValid(string s) {
		//if (s.size() % 2 == 1)
		//	return false;
		map<char, int> m;
		m.insert(pair<char, int>('(', 0));
		m.insert(pair<char, int>('[', 1));
		m.insert(pair<char, int>('{', 2));
		m.insert(pair<char, int>(')', 3));
		m.insert(pair<char, int>(']', 4));
		m.insert(pair<char, int>('}', 5));
		vector<char> v;
		for (int i = 0; i < s.size(); i++) {
			if (m[s[i]] < 3)
				v.push_back(s[i]);
			else {
				if (v.empty())
					return false;
				char a = v[v.size()-1];
				if (m[a] == m[s[i]] - 3)
					v.pop_back();
				else
					return false;
			}

		}
		if (v.size()>0)
			return false;
		return true;
		}

	
};



int rectDie(int* a, int* b) {
	int andRect[4] = {0,0,0,0};
	int p1_x = *a;
	int p1_y = *(++a);
	int p2_x = *(++a);
	int p2_y = *(++a);
	int p3_x = *b;
	int p3_y = *(++b);
	int p4_x = *(++b);
	int p4_y = *(++b);
	if (p1_x > p4_x || p1_y < p4_y || p2_x<p3_x || p2_y>p3_y) {
		return 0;
	}
	else {
		return 1;
	}
}
int maxDienum() {
	const int n=2;
	int R[4][n] = { 0, 90,	0, 90,	100, 200,100, 200};
	int m[n][n];
	int sum[n] = { 0 };
	for (int i = 0; i < n; i++) {
		int rect1[] = { R[0][i],R[1][i] ,R[2][i] ,R[3][i] };
		for (int j = i + 1; j < n; j++) {
			int rect2[] = { R[0][j],R[1][j] ,R[2][j] ,R[3][j] };
			sum[i] += rectDie(rect1, rect2);
		}
	}
	return *max_element(begin(sum), end(sum));
}

//int main(){
//	
//	Solution s;
//
//
//	//bool m=s.isValid("((");
//	//cout << sizeof(ss);
//}
