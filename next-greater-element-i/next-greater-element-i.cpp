class Solution { 
public: 
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
     vector<int>lo; 
          for(auto elem : nums1){
            for (int i = 0; i < nums2.size(); i++){
             if(elem == nums2[i]){ 
                   bool f = false; 
                   int h=i;  
                   for (int k = h ; k <nums2.size(); k++){
                         if(nums2[h]<nums2[k]){
                           f=true; 
                             lo.push_back(nums2[k]); 
                             break; 
                         } 
                  } 
               if(f==false){ 
                   lo.push_back(-1); 
               } 
              } 
            }
          }
        return lo; 

    } 

}; 