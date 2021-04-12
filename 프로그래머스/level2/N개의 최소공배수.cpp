#include <string>
#include <vector>
using namespace std;

int GCD(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int LCM(int a, int b){
    return a*b / GCD(a,b);
}

int solution(vector<int> arr) {
    int lcm = arr[0];
    
    for(int i = 1;i < arr.size();i++)
        lcm = LCM(lcm, arr[i]);
    
    return lcm;
}