class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
      int r = matrix.size(), c = matrix[0].size();
         vector<int> vect;
    int row_start = 0, row_end = r - 1, column_start = 0,
    	column_end = c - 1, i;
        
    while(row_start <= row_end && column_start <= column_end){

        for(i = column_start; i <= column_end; i++) 
            vect.push_back(matrix[row_start][i]);
        row_start++;
        if(row_start > row_end || column_start > column_end)
        	break;

        for(i = row_start; i <= row_end; i++) 
            vect.push_back(matrix[i][column_end]);        
        column_end--;
        if(row_start > row_end || column_start > column_end)
        	break;

        for(i = column_end; i >= column_start; i--) 
            vect.push_back(matrix[row_end][i]);
        row_end--;
        if(row_start > row_end || column_start > column_end)
        	break;

        for(i = row_end; i >= row_start; i--) 
            vect.push_back(matrix[i][column_start]);
        column_start++;

    }
    return vect;
    }
};