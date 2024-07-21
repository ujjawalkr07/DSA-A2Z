#include<bits/stdc++.h>
using namespace std;
 /*this is applicable for arr in which pos and neg element
  is eqaual in no */
 
 vector<int> rearrangeArray(vector<int>& arr) {
    int n=arr.size();
    /* brute force approach 
    Time Complexity: O(N+N/2)
    Space Complexity:  O(N/2 + N/2)

    vector<int>pos;
    vector<int>neg;
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    for(int i=0;i<n/2;i++)
    {
        arr[2*i+1]=neg[i];
        arr[2*i]=pos[i];

    }
    return arr;
    */
   // optimal approach , t.c=O(n) aand s.c=O(n)
    vector<int > ans(n,0);
    int pos_index=0,neg_index=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            ans[neg_index]=arr[i];
            neg_index+=2;
        }
        else
        {
            ans[pos_index]=arr[i];
            pos_index+=2;
        }
    }
    return ans;
    }

    /*
    this is applicable for any no of pos and neg element in array
    here we are using brute force approach as in above.
    */
    vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}

int main() {
    
  // Array Initialisation.
  int n = 6;
  vector<int> A {1,2,-4,-5,3,4};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}