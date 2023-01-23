#include<iostream>

//which floor is the drop floor

//egg breaks at floor n, so check n-1 with k-1 eggs
//egg survives at floor n, check n+1 with k eggs

//recursive
int FindDropFloor(int floor, int eggs){
	int ans = INT_MAX;
	if(floor < 1 || floor ==  1){
		return floor;
	}
	if(eggs == 1){
		return floor;
	}
	for (int x = 1; x <= floor; x++){
		int ret = 1 + std::max(FindDropFloor(x-1, eggs-1), FindDropFloor(floor-x, eggs));
		ans = std::min(ans, ret);
	}
	return ans;
}
int main(){
	int n,k;
	std::cin>>n>>k;
	std::cout<<FindDropFloor(n, k)><"\n";
}
