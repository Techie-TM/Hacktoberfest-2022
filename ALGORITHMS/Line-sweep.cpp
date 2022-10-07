class MyCalendarThree {
public:
map<int,int> a;// initalizes map
    MyCalendarThree() {
    }
    int book(int start, int end) {
        a[start]+=1;//increments first pair
        a[end]-=1;//decrements second pair
        int k=0,m=0;
        for(auto x:a){
            k+=x.second;
            m=max(k,m);
        }
        return m;
    }
};
