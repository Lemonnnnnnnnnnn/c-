#include "individual.h"
#include "iostream"
#include "groupRange.h"
using namespace std;

// 每个种群拥有自身的基因区间

Individual::Individual(double *geneArray)
{
    for (int i = 0; i < chromosomeNumber; i++)
    {
        if (geneArray[i] >= chromosomeRange[i].getLow() && geneArray[i] <= chromosomeRange[i].getHigh())
        {
            chromosome[i] = geneArray[i];
        }
        else
        {
            cout << geneArray[i] << endl;
            cout << chromosomeRange[i].getLow() << endl;
            cout << chromosomeRange[i].getHigh() << endl;
            cerr << "基因不满足区间" << endl;
            exit(1);
        }
    }
    fitness = 0;
    fitnessProbability = 0;
}

double Individual::getFitness()
{
    return fitness;
}

double *Individual::getChromosome()
{
    return chromosome;
}
double Individual::getFitnessProbability()
{
    return fitnessProbability;
}
double Individual::getFitnessSum()
{
    return fitnessSum;
}

void Individual::setFitness(double my_fitness)
{
    fitness = my_fitness;
}

void Individual::setFitnessProbability(double my_fitnessProbability)
{
    fitnessProbability = my_fitnessProbability;
}

void Individual::setFitnessSum(double my_fitnessSum)
{
    fitnessSum = my_fitnessSum;
}
