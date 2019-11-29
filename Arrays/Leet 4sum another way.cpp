#include<stdio.h>
#include<conio.h>
#include<algorithm>
#include<iostream>
using namespace std;



bool checkDuplicateEntry(int key, int num1, int num2, vector<pair<int,pair<int,int>>> &vec)
{
    if(vec.empty())
    return false; // false means entry is allowed
    
    // write function
    
}

void ssortvector(vector<pair<int,pair<int,int>>> &vec)
{
    
    // sort vector by key
}

bool doesNotExist(vector<int> &v, vector<vector<int>> &result)
{
    // check
}
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    
    vector<vector<int>> result;
    vector<int> v;
    if(nums.size() < 4)
    return result;
    typedef pair<int,pair<int,int>> pi; 
    vector<pi> vec;
    
    
    
    for(int i=0; i < nums.size(); i++)
    for(int j=i+1; j < nums.size(); j++)
    {
        int key = nums[i]+nums[j];
        if (!checkDuplicateEntry(key,nums[i],nums[j],vec)) {
        pi x;
        x.first = key;
        if(nums[i] < nums[j]){
        x.second.first = nums[i];
        x.second.second = nums[j];
        }
        else
        {
            x.second.first = nums[j];
            x.second.second = nums[i];
        }
        
        vec.push_back(x);
     }
    }
    
    // 2 pairs of sum is created 
    
    // sort vector by key in inc order
    ssortvector(vec); 
    
    for(auto i = vec.begin(); i != vec.end() ; i++ )
    {
        auto j = vec.find(Target - *i.first);
        if(j != vec.end())
        {
           vector<int> v;
           if( *i.second.first < *j.second.first)
            {
                v.push_back(*i.second.first);
                
                if(*i.second.second < *j.second.first) {
                v.push_back(*i.second.second);
                v.push_back(*j.second.first);
                v.push_back(*j.second.second);
                }
                else
                {
                  v.push_back(*j.second.first);
                  
                  if(*i.second.second < *j.second.second)
                  {
                      v.push_back(*i.second.second);
                      v.push_back(*j.second.second);
                  }
                  else
                  {
                      v.push_back(*j.second.second);
                      v.push_back(*i.second.second);
                  }
                  
                }
            }
            else
            {
                
                v.push_back(*j.second.first);
                
                if(*i.second.first > *j.second.second) {
                v.push_back(*j.second.second);
                v.push_back(*i.second.first);
                v.push_back(*i.second.second);
                }
                else
                {
                  v.push_back(*i.second.first);
                  
                  if(*i.second.second < *j.second.second)
                  {
                  	
                      v.push_back(*i.second.second);
                      v.push_back(*j.second.second);
                  }
                  else
                  {
                      v.push_back(*j.second.second);
                      v.push_back(*i.second.second);
                  }
        
                }
            } // end
            
            if(doesNotExist(v,result))
            {
                result.push_back(v);
                v.clear();
            }
        }
    }
    
    
    return result;
    }
