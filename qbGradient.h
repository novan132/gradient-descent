#ifndef QBGRADIENT_H
#define QBGRADIENT_H

#include <vector>
#include <functional>

class qbGradient {
public:
    qbGradient();
    ~qbGradient();

    // function to add pointer to object function
    void SetObjectFcn(std::function<double(std::vector<double>*)> objectFcn);

    void SetStartPoint(const std::vector<double> startPoint);

    void SetStepSize(double stepSize);

    void SetMaxIterations(int maxIterations);

    // function to set gradient magnitude threshold (stopping condition)
    void SetGradientThresh(double gradientThresh);

    bool Optimize(std::vector<double> *funcLoc, double *funcVal);

private:
    // function to compute gradient in specific dimension
    double ComputeGradient(int dim);

    // function to compute gradient vector
    std::vector<double> ComputeGradientVector();

    // function to compute gradient magnitude
    double ComputeGradientMagnitude(std::vector<double> gradientVector);

private:
    int m_nDims;
    double m_stepSize;
    int m_maxIter;

    // gradient step size
    double m_h;
    
    std::vector<double> m_startPoint;
    std::vector<double> m_currentPoint;

    // function pointer to object function
    std::function<double(std::vector<double>*)> m_objectFcn;
};

#endif
