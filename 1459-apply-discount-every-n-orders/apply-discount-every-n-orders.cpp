class Cashier {
public:
    unordered_map<int,int> mp; //product id -> product price;
    int dsc = 0;
    int cc = 1;
    int tn = 0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for(int i = 0;i<products.size();i++){
            mp[products[i]] = prices[i];
        }
        dsc = discount;
        tn = n;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill = 0;
        for(int i = 0;i<product.size();i++){
            bill += (mp[product[i]]*amount[i]);
        }
        if(cc%tn==0) bill *= (1.0*(100-dsc)/100);
        cc++;
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */