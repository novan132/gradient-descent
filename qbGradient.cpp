#include "qbGradient.h"
#include <iostream>
#include <fstream>
#include <math.h>

qbGradient::qbGradient() {
    m_nDims = 0;
    m_stepSize = 0.0;
    m_maxIter = 1;
    m_h = 0.001;
    m_gradientThresh = 1e-09;
}

qbGradient::~qbGradient() {
    
}


void qbGradient::SetObjectFcn(std::function<double(std::vector<double>*)> objectFcn) {
    m_objectFcn = objectFcn;
}

void qbGradient::SetStartPoint(const std::vector<double> startPoint) {
    m_startPoint = startPoint;

    // determine number of degree of freedom
    m_nDims = m_startPoint.size(); 
}

void qbGradient::SetStepSize(double stepSize) {
    m_stepSize = stepSize;
}

void qbGradient::SetMaxIterations(int maxIterations) {
    m_maxIter = maxIterations;
}

void qbGradient::SetGradientThresh(double gradientThresh) {
    m_gradientThresh = gradientThresh;
}

bool qbGradient::Optimize(std::vector<double> *funcLoc, double *funcVal) {
    m_currentPoint = m_startPoint;
}

double qbGradient::ComputeGradient(int dim) {
    std::vector<double> newPoint = m_currentPoint;
    newPoint[dim] += m_h;

    double funcVal1 = m_objectFcn(&m_currentPoint);
    double funcVal2 = m_objectFcn(&newPoint);

    return (funcVal2 - funcVal1) / m_h;
}

std::vector<double> qbGradient::ComputeGradientVector() {
    std::vector<double> gradientVector = m_currentPoint;
    for (int i = 0; i < m_nDims; ++i) {
        gradientVector[i] = ComputeGradient(i);
    }
    return gradientVector;
}

double qbGradient::ComputeGradientMagnitude(std::vector<double> gradientVector) {
    double vectorMagnitude = 0.0;
    for (int i = 0; i < m_nDims; ++i) {
        vectorMagnitude += gradientVector[i] * gradientVector[i];
    }
    return sqrt(vectorMagnitude);
}
