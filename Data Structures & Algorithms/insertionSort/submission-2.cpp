// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> sortState = {};
        for (size_t i = 0; i < pairs.size(); i++) {
            int curLocation = i;
            for (int idx = i - 1; idx >= 0; idx--) {
                if (pairs[curLocation].key < pairs[idx].key) {
                    std::swap(pairs[idx], pairs[curLocation]);
                    curLocation = idx;
                } else {
                    break;
                }
            }
            sortState.push_back(pairs);
        }
        return sortState;
    }
};
