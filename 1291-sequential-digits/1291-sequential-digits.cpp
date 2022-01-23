class Solution { // Time and Space: O(1)
public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int> seqDigitsInRange;
        
        // Create all numbers with sequential digits and compare if they fit the given range
        for (int i = 1; i < 9; i++) { // Runs 8 times
            int number = i;
            for (int j = i + 1; j < 10; j++) { // Runs maximum 8 times
                number = number * 10 + j;
                if (number >= low && number <= high)
                    seqDigitsInRange.push_back(number);
            }
        }
        sort(seqDigitsInRange.begin(), seqDigitsInRange.end()); // Result is required to be sorted
        return seqDigitsInRange;
	}
};