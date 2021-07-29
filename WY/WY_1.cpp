#include<iostream>
#include<vector>


using namespace std;

int maxSum(vector<int>&nums)
{
    int len=nums.size();
    int pre=nums[0];
    int maxValue=nums[0];
    for(int i=1;i<len;i++)
    {
        if(pre<0)
        {
            pre=nums[i];
        }
        else
        {
            pre+=nums[i];

        }
        maxValue=max(maxValue,pre);
    }
    return maxValue;

}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    cout<<maxSum(nums)<<endl;

    return 0;
}