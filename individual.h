const int chromosomeNumber = 2; // 染色体个数
// const int group

class Individual{
    private:
    double chromosome[chromosomeNumber]; //染色体数组
    double fitness; // 适应度
    double fitnessProbability ; // 适应度概率
    public:
    Individual(double *); // 构造函数，根据传入数组初始化染色体数组 ， 适应度及概率默认0
    double* getChromosome(); // 获取染色体数组
    double getFitness();
    double getFitnessProbability();
    void setFitness(double);
    void setFitnessProbability(double);
};