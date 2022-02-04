const int chromosomeNumber = 2; // 染色体个数
// const int group

class Individual{ 
    private:
    double chromosome[chromosomeNumber]; //染色体数组
    double fitness; // 适应度
    double fitnessProbability ; // 适应度概率
    double fitnessSum ; // 适应度概率和，用于轮盘赌 ，所有概率累加和为1 ，这里值为0-1
    public:
    Individual(double *); // 构造函数，根据传入数组初始化染色体数组 ， 适应度及概率默认0
    double* getChromosome(); // 获取染色体数组
    double getFitness();
    double getFitnessProbability();
    double getFitnessSum();
    void setFitness(double);
    void setFitnessProbability(double);
    void setFitnessSum(double);
};