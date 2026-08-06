class Solution {
private:
    int getDigitProduct(int num) {
        int product = 1;
        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }
        return product;
    }

public:
    int smallestNumber(int n, int t) {
        int current = n;
        while (true) {
            if (getDigitProduct(current) % t == 0) {
                return current;
            }
            current++;
        }
    }
};
