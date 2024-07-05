class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minH.size() < maxH.size()) {
            if(maxH.size() && num < maxH.front()) {
                maxH.push_back(num);
                push_heap(maxH.begin(), maxH.end());
                pop_heap(maxH.begin(), maxH.end());
                num = maxH.back();
                maxH.pop_back();
            }

            minH.push_back(num);
            push_heap(minH.begin(), minH.end(), greater<int>());
        }
        else {
            if(minH.size() && num > minH.front()) {
                minH.push_back(num);
                push_heap(minH.begin(), minH.end(), greater<int>());
                pop_heap(minH.begin(), minH.end(), greater<int>());
                num = minH.back();
                minH.pop_back();
            }
            
            maxH.push_back(num);
            push_heap(maxH.begin(), maxH.end());
        }
    }
    
    double findMedian() {
        if(maxH.size() == minH.size()) 
            return (maxH.front() + minH.front()) / 2.;
        else
            return maxH.front();
    }

private:
    vector<int> minH, maxH;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */