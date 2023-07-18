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
