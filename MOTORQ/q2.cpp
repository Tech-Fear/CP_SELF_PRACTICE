#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to find maximum value for average age X
int maxValueWithAvgAge(const vector<int>& ages, const vector<int>& values, int X) {
    unordered_map<int, int> valueMap; // Maps (sum of ages) to (max total value)
    
    // Initialize with zero sum and zero value
    valueMap[0] = 0;

    int n = ages.size();
    
    // Iterate through ages and values
    for (int i = 0; i < n; ++i) {
        // Store the current state to avoid overwriting
        unordered_map<int, int> currentMap = valueMap;
        
        for (const auto& [sum_ages, total_value] : currentMap) {
            int new_sum = sum_ages + ages[i];
            int new_value = total_value + values[i];

            // Update the maximum value for this new sum of ages
            valueMap[new_sum] = max(valueMap[new_sum], new_value);
        }
    }

    int max_value = 0;

    // Now find the maximum value for sums that can yield the required average
    for (const auto& [sum_ages, total_value] : valueMap) {
        // Check if sum can yield the average X
        if (sum_ages % X == 0) {
            max_value = max(max_value, total_value);
        }
    }

    return max_value;
}

int main() {
    // Example with 100000 elements
    vector<int> ages(100000);
    vector<int> values(100000);
    
    // Fill the arrays with sample data
    for (int i = 0; i < 100000; ++i) {
        ages[i] = rand() % 100 + 1; // Random ages between 1 and 100
        values[i] = rand() % 1000 + 1; // Random values between 1 and 1000
    }

    int X = 35; // Desired average age

    int result = maxValueWithAvgAge(ages, values, X);
    cout << "Maximum value for average age " << X << " is: " << result << endl;

    return 0;
}
