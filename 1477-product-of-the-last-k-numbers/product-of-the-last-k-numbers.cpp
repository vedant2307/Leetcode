class ProductOfNumbers {
public:
    vector<int>temp;
    int len;
    ProductOfNumbers() {
        temp.push_back(1);
        len=1;
    }
    
    void add(int num) {
        if(num){
            temp.push_back(temp.back()*num);
            len++;
        }
        else {
            temp = {1}; len=1;
        }
    }
    
    int getProduct(int k) {
        int idx = len-1-k;
        return k<len ? temp.back()/temp[idx] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */