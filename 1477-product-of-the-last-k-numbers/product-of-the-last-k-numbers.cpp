class ProductOfNumbers {
public:
    
    vector<long long> pp;
    ProductOfNumbers() {
       pp = {1};
    }
    
    void add(int num) {
        if(num==0){
            pp = {1};
        }
        else pp.push_back(pp.back()*1LL*num);
    }
    
    int getProduct(int k) {
        if(pp.size()<=k) return 0;
        return pp.back()/pp[pp.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */