#include <iostream>
#include <vector>

using namespace std;

class Fancy {
private:
    long long a_ = 1;
    long long b_ = 0;
    const int MOD = 1e9 + 7;
    vector<long long> seq;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {
        seq.clear();
    }
    
    void append(int val) {
        long long v_prime = ((val - b_) % MOD + MOD) % MOD;
        v_prime = (v_prime * modInverse(a_)) % MOD;
        seq.push_back(v_prime);
    }
    
    void addAll(int inc) {
        b_ = (b_ + inc) % MOD;
    }
    
    void multAll(int m) {
        a_ = (a_ * m) % MOD;
        b_ = (b_ * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (a_ * seq[idx] % MOD + b_) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

int main() {
    Fancy* obj = new Fancy();
    obj->append(2);
    obj->addAll(3);
    obj->append(7);
    obj->multAll(2);
    cout << obj->getIndex(0) << endl; // 10
    obj->addAll(3);
    obj->append(10);
    obj->multAll(2);
    cout << obj->getIndex(0) << endl; // 26
    cout << obj->getIndex(1) << endl; // 34
    cout << obj->getIndex(2) << endl; // 20
    
    delete obj;
    return 0;
}
