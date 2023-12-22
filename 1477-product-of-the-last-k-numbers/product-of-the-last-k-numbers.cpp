class ProductOfNumbers {
public:
    vector<int>temp;
    int len;
    ProductOfNumbers() {
        len=0;
    }
    
    void add(int num) {
        temp.push_back(num);
        len++;
        return;
    }
    
    int getProduct(int k) {
        int mul=1;
        for(int idx=0;idx<k;idx++){
            int i=len-1-(idx);
            mul = mul * temp[i];
        }
        return mul;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */