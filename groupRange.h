// 每个种群拥有自身的基因区间

class GroupRange{
    private:
    double low;
    double high;
    public:
    GroupRange(double my_low , double my_high) : low(my_low) , high(my_high){};
    double getLow(){return low;};
    double getHigh(){return high;};
};

const GroupRange range1(-3.0, 12.1);
const GroupRange range2(4.1, 5.8);
GroupRange chromosomeRange[chromosomeNumber] = { range1, range2 };