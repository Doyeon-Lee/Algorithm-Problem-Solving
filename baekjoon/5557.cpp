#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, tmp;
    scanf("%d", &n);
    vector<int> nums, v;

    for(int i = 0;i < n;i++){
        scanf("%d", &tmp);
        nums.push_back(tmp);
    }
    v.push_back(nums[0]);

    for(int i = 1;i < n-1;i++){
        int s = v.size();
        auto iter = v.begin();
        for(int j = 0;j < s;j++){
            int buf = *iter;
            if(buf + nums[i] <= 20) v.push_back(buf + nums[i]);
            if(buf - nums[i] >= 0) v.push_back(buf - nums[i]);
            v.erase(iter);
        }
    }

    for(int i = 0;i < v.size();i++)
        cout << v[i] << " ";

    system("pause");
}