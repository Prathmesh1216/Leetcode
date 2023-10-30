class Solution {
public:
int maybe(const unordered_map<int, int> &have, int x) {
int r = 0;
// How many parts we need if each part is either x or (x + 1).
for (const auto & p : have) {
if (x == 0) {
r += p.second;
} else {
// We want as many (x + 1) as we can.
const int a = p.second / (x + 1), b = p.second % (x + 1);
if (b == 0) {
r += a;
} else if (x - b <= a) {
r += a + 1;
} else {
return -1;
}
}
}
return r;
}
void better(int &x, int y) {
if (y >= 0 && (x < 0 || x > y)) {
x = y;
}
}
    int minGroupsForValidAssignment(vector<int>& a) {
       // sort(nums.begin(),nums.end());
        unordered_map<int, int> have;
for (int x : a) {
++have[x];
}
int m = INT_MAX;
for (const auto& p : have) {
m = min(m, p.second);
}
/*
Let n = a.size(). Note: have.size() <= n / m.
Outer loop for "i": m.
Inner loop for "maybe": have.size()
So the total time complexity is O(n).
*/
int r = a.size();
for (int x = 1; x <= m; ++x) {
// Each part is either x or (x + 1).
better(r, maybe(have, x));
}
return r;
        
    }
};