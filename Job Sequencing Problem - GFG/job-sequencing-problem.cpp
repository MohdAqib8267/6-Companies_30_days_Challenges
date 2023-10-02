//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comparitor(Job a, Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job jobs[], int n) 
    { 
        sort(jobs, jobs + n, comparitor);
        int profit = 0;//This variable will store the total profit gained
        int maxTime = 0;//This will be used to get the maximum limit of array , in which i will store that job
        int jobCount = 0;//This will store the No. of jobs that can be done.

        for (int i = 0; i < n; i++)
        {
            maxTime = max(maxTime,jobs[i].dead);
        }

        vector<int> timeslots(maxTime + 1, false); //This vector will store at what time which job has been done

        for (int i = 0; i < n; i++)
        {
            Job currJob = jobs[i];

            for (int t = currJob.dead; t > 0; t--)
            {
                if (timeslots[t] == false)
                {
                    timeslots[t] = true;
                    profit += currJob.profit;
                    jobCount++;
                    break;
                }
                
            }
        }
        return {jobCount, profit};
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends