class ProductOfNumbers {
public:

    // Like prefix sum, We keep a record of prefix products
    // for eg 1,2,3,4 then prod will store 1,2,6,24

    vector<int> prod = {1};
    ProductOfNumbers() {

    }

    void add(int num) {
        // if we encounter a zero, all products before or including it becomes zero
        if (num == 0) prod = {1};
        else {
            int last = prod[prod.size() - 1];
            prod.push_back(last * num); // Storing the prefix product
        }
    }

    int getProduct(int k) {

        int n = prod.size();
        if (k >= n) return 0;

        // if nos 1,2,3,4 and prod 1,2,6,24 and k = 2 then ans = 24/6 ie
        return prod[n - 1] / prod[n - k - 1];

    }
};
