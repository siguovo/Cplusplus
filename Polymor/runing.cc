#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

//v1 数据   v2 要操作的数据 
vector<int> Solution(vector<vector<int> > &v1, vector<vector<int> > &v2)
{
	vector<int> res;
	for (int i = 0; i < v2.size(); i++) {
		auto Index = v2.at(i).back(); //1  2
		v2.at(i).pop_back();
		vector<int>v;
		for (auto j : v2.at(i)) {
			for (auto k : v1.at(j - 1)) {
				v.push_back(k);
			}
		}
		sort(v.begin(), v.end());

		res.push_back(v.at(Index - 1));
	}
	return res;
}

int main()
{
	//n --> 数组的个数  t --> 没个数组的数值个数
	int n = 0, t = 0, a = 0;
	cin >> n;
	//输入的数组
	vector<vector<int> > v1(n);
	for (int i = 0; i < n; i++) {
		cin >> t;
		while (t--) {
			cin >> a;
			v1.at(i).push_back(a);
		}
	}
	//  q--> 询问次数  num-- > 数组个数  index-- > 询问合并后的下标
	int q = 0, num = 0, index = 0, b = 0;
	cin >> q;
	//操作的数组
	vector<vector<int> > v2(q);
	for (int i = 0; i < q; i++) {
		cin >> num;
		while (num--) {
			cin >> b;
			v2.at(i).push_back(b);
		}
		cin >> index;
		v2.at(i).push_back(index);
	}
	//保存返回的结果
	vector<int> res;
	//算法(放入需要的二维数组，需要合并的数组，访问合并后数组的下标)
	res = Solution(v1, v2);
	//打印结果
	cout << "result---------------" << endl;
	for (auto i : res)
		cout << i << endl;
	return 0;
}