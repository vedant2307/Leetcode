#define ll long long
class Solution {
public:
    long long flowerGame(int n, int m) {
        ll n_even=n/2, n_odd=(n-n_even);
        ll m_even=m/2, m_odd=(m-m_even);
        return n_even*m_odd + n_odd*m_even; 
    }
};