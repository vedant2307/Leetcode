class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>min;
    priority_queue<int>max;
    int size,min_size,max_size;
    MedianFinder() {
        size=0; min_size=0; max_size=0;
    }
    
    void addNum(int num) {
        if(max_size==0 || num<max.top()) { max_size++; max.push(num); }
        else { min_size++; min.push(num); }
        if(max_size>min_size+1){
            min.push(max.top()); max.pop();
            min_size++; max_size--;
        }
        if(min_size>max_size){
            max.push(min.top()); min.pop();
            max_size++; min_size--;
        }
        size++;
    }
    
    double findMedian() {
        double x = (double)max.top();
        if(size==1) return x;
        double y = (double)min.top();
        return size%2 ? x : (x+y)/2; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */