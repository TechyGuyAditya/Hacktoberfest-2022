//Searching algorithm to search an ele in logarithmic time. 
//TC:O(logN)

bool binSearch(vector<int> &v,int t){
  //search space.
  int lo=0,hi=v.size()-1;
  bool ans=0;
  //main loop
  while(hi>=lo){
    //halving the search space.
    int mid=lo+(hi-lo)/2;
    
    //if ele found return true.
    if(v[mid]==t){
      return true;
    }
    //if ele on left search on left.
    else if(v[mid]>t){
      hi=mid-1;
    }
    else{
      lo=mid+1;
    }
  }
  return ans;
}
