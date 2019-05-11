#include <bits/stdc++.h>
using namespace std;
/*
	Given a list of n integers, find the maximum element in a sliding window of size k.
*/

vector<int> max_element(int k, vector<int>& arr){
	deque<int> dq;
	vector<int> ans;
	int n = arr.size();
    for (int i = 0; i < n; i++){
        while(!dq.empty() and arr[dq.back()] <= arr[i]) 
            dq.pop_back();
        dq.push_back(i);

        while(!dq.empty() and dq.front() <= i - k) dq.pop_front();
        if (i >= k -1) ans.push_back(arr[dq.front()]);
    }
   	return ans;
}

int main(){
	vector<int> v = {1,6,4,2,8,9,5,3};
	vector<int> ans = max_element(3, v);
	for (auto& t: ans) cout << t << " ";
	cout << endl;
	return 0;
}