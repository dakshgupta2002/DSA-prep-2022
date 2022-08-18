#include <bits/stdc++.h>
using namespace std;

// Time: O(3*N*logN) --> 529ms
// Space: O(2*N) --> 80.2MB
class Solution1 {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> freq;
        for(auto &i: arr) freq[i]++;

        priority_queue<int> maxFreq;
        for (auto it: freq) maxFreq.push(it.second);

        int reqdNums = 0, deletedInts=0;

        while (deletedInts < arr.size()/2 + arr.size()%2){
            reqdNums++;
            deletedInts+=maxFreq.top();
            maxFreq.pop();
        }

        return reqdNums;
    }
};

// Time: O(N*logN) --> 366ms
// Space: O(N) --> 70MB
class Solution2{
public:
    int minSetSize(vector<int>& arr){
        vector<int> freq(100001); //indexes of every number
        for (auto &i: arr) freq[i]++;
        sort(freq.begin(), freq.end());

        int distinctNums=0, totalNums=0;

        for (int i=freq.size()-1; i>=0; i--){
            if (totalNums>=arr.size()/2 + arr.size()%2) break;

            distinctNums++;
            totalNums+=freq[i];
        }
        return distinctNums;
    }
};

//Time: O(N) --> 237ms
//Space: O(2*N) --> 77.7MB
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //first unordered map then bucket
        unordered_map<int, int> freq;
        for(auto &i: arr) freq[i]++;

        vector<int> occur(arr.size()+1); //the num of times ith freq is
        for (auto it: freq){
            occur[it.second]++;
        }

        int res=0, numbersRemoved=0;
        int target = arr.size()/2 + arr.size()%2;
        for (int i=occur.size()-1; i>=0; i--){
            if (numbersRemoved >=target) break; //already ans achieved

            //now deal with numbers of freq i

            //case 1, use all of them still didnt get to half
            if (numbersRemoved + i*occur[i] < target){
                res += occur[i];
                numbersRemoved += i*occur[i];
            }else{
                //we can use j (<occur[i]) that can give us ans
                int req = (target - numbersRemoved)/i;
                if ((target - numbersRemoved)%i > 0) req++;

                res += req;
                break;
            }
        }
        return res;

    }
};