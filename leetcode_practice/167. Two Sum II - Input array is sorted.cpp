/*
Given numbers = [2, 7, 11, 15], target = 9,

Because numbers[0] + numbers[1] = 2 + 7 = 9,
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
vector<int> newVector(int array[], int length){
	vector<int> v;
	for (int i = 0; i < length; ++i){
		v.push_back(array[i]);
	}
	return v;
} 
vector<int> twoSum2(vector<int>& numbers, int target){
	vector<int> v(2);
	int l = 0, r = numbers.size()-1;
	while (l < r){
//		cout<<"l = "<<l<<" | r = "<<r<<endl;
		if ( numbers[l] + numbers[r] > target){
			if (r-l == 1)break;
			int sum1 = numbers[l] + numbers[r-1];
			int sum2 = numbers[l+1] + numbers[r];
			if (sum1 == target){
				--r;
			} else if (sum2 == target){
				++l;
			} else if (sum1 < sum2) {
				if (sum1 == target){
					v[0] = l;
					v[1] = r-1;
					break;
				} else if (sum2 == target) {
					v[0] = l+1;
					v[1] = r;
					break;
				} else
					--r;
			} else if (sum1 > sum2) {
				if (sum1 == target){
					v[0] = l;
					v[1] = r-1;
					break;
				} else if (sum2 == target) {
					v[0] = l+1;
					v[1] = r;
					break;
				} else
					++l;
			} else if (numbers[r] == numbers[r-1]){
				--r;
			} else if (numbers[l] == numbers[l+1]){
				++l;
			}
		} else if (numbers[l] + numbers[r] < target){
			if (r-l == 1)break;
			int sum1 = numbers[l] + numbers[r-1];
			int sum2 = numbers[l+1] + numbers[r];
			if (sum1 == target){
				--r;
			} else if (sum2 == target){
				++l;
			} else if (sum1 > sum2) {
				if (sum1 == target){
					v[0] = l;
					v[1] = r-1;
					break;
				} else if (sum2 == target) {
					v[0] = l+1;
					v[1] = r;
					break;
				} else
					--r;
			} else if (sum1 < sum2) {
				if (sum1 == target){
					v[0] = l;
					v[1] = r-1;
					break;
				} else if (sum2 == target) {
					v[0] = l+1;
					v[1] = r;
					break;
				} else
					++l;
			} else if (numbers[r] == numbers[r-1]){
				--r;
			} else if (numbers[l] == numbers[l+1]){
				++l;
			}
		} else {//equals 
			v[0] = l;
			v[1] = r;
			break;
		}
	}
	++v[0];
	++v[1];
	return v;
} 
vector<int> twoSum(vector<int>& numbers, int target){
	vector<int> v(2); 
	int i = 0, j = numbers.size()-1;
	while (i < j){
		cout<<"i = "<<i<<" | j = "<<j<<endl;
		int sum = numbers[i] + numbers[j];
		if (sum == target){
			v[0] = i;
			v[1] = j;
			break;
		} else if (sum < target) {
			++i;
		} else {
			--j;
		}
	}
	++v[0];
	++v[1];
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
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	target = 6;
	v0 = twoSum(v2, target);
	print(v2);
	print(v0);
	
	vector<int> v3;
	v3.push_back(1);
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(5);
	v3.push_back(10);
	v3.push_back(14);
	v3.push_back(15);
	target = 9;
	v0 = twoSum(v3, target);
	print(v3);
	print(v0);
	
	int array[] = {12,13,23,28,43,44,59,60,61,68,70,86,88,92,
	124,125,136,
	168,
	173,173,180,199,
	212,221,227,230,277,282,
	306,314,316,321,325,328,336,337,363,365,368,
	370,
	370,371,375,384,387,394,
	400,404,414,422,422,427,430,435,457,493,
	506,527,531,538,541,546,568,583,585,587,
	650,652,677,691,
	730,737,740,751,755,764,778,783,785,789,794,
	803,809,815,847,858,863,863,874,887,896,
	916,920,926,927,930,933,957,981,997};
	target = 542;
	int length;
	vector<int> v4 = newVector(array, length = sizeof(array)/sizeof(int));
	cout<<length<<endl;
	v0 = twoSum(v4, target);
	print(v4);
	print(v0);
	
	vector<int> v5;
	v5.push_back(0);
	v5.push_back(0);
	v5.push_back(4);
	v5.push_back(5);
	target = 0;
	v0 = twoSum(v5, target);
	print(v5);
	print(v0);
	
	return 0; 
}
