/*
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm> 
void print(vector<int>& v){
	for (int i = 0; i < v.size(); ++i){
		cout<<v[i]<<' ';
	}
	cout<<endl;
}
vector<int> twoSum(vector<int>& nums, int target){
	vector<int> v(2);
	for (int i = 0; i < nums.size(); ++i){
		for (int j = i+1; j < nums.size(); ++j){
			if (nums[i] + nums[j] == target){
				v[0] = i;
				v[1] = j;
				return v;
			}
		}
	} 
	return v;
} 
int main(){
	vector<int> v;
	v.push_back(2);
	v.push_back(7);
	v.push_back(11);
	v.push_back(15);
	int target = 9;
	vector<int> v0 = twoSum(v, target);
	print(v);
	print(v0);
	
	vector<int> v2;
	v2.push_back(3);
	v2.push_back(2);
	v2.push_back(4);
	target = 6;
	v0 = twoSum(v2, target);
	print(v2);
	print(v0);
	
	return 0; 
}
