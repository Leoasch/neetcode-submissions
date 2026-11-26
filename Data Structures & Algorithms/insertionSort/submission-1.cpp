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
        for (int i = 0; i < pairs.size(); i++) {
            Pair cPair = pairs.at(i);
            int curLocation = i;
            for (int idx = i; idx >= 0; idx--) {
                Pair oPair = pairs[idx];

                if (cPair.key < oPair.key) {
                    pairs[idx] = cPair;
                    pairs[curLocation] = oPair;
                    curLocation = idx;
                    continue;
                }
            }
            sortState.push_back(pairs);
        }
        return sortState;
    }
};
