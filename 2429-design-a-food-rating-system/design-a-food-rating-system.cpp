class FoodRatings {
public:
    unordered_map<string,string>fo_cu;
    unordered_map<string,int>fo_ra;
    unordered_map<string,set<pair<int,string>>>cu_ra_fo;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            string cu=cuisines[i], fo=foods[i]; 
            int ra=ratings[i];
            fo_cu[fo]=cu;
            fo_ra[fo]=ra;
            cu_ra_fo[cu].insert({-ra,fo});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cu = fo_cu[food];
        int old_rat=fo_ra[food];
        auto it = cu_ra_fo[cu].find({-old_rat,food});
        cu_ra_fo[cu].erase(it);

        cu_ra_fo[cu].insert({-newRating,food});
        fo_ra[food]=newRating;

        return;
    }
    
    string highestRated(string cuisine) {
        auto it = *cu_ra_fo[cuisine].begin();
        return it.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */