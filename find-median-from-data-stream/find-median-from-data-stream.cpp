class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>min;
    priority_queue<int>max;
    int size,max_size;
    MedianFinder() {
        size=0; max_size=0;
    }
    
    void addNum(int num) {
        if(!max.empty() && num<max.top()){
            min.push(max.top()); max.pop(); max.push(num);
        }
        else { min.push(num); }
        size++;
    }
    
    double findMedian() {
        int var=(size+1)/2;
        while(max_size<var){
            max.push(min.top()); min.pop(); max_size++;
        }
        double x = (double)max.top(); double y = (double)min.top();
        return size%2 ? x : (x+y)/2; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */