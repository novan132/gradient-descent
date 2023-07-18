#include "qbGradient.h"
#include <iostream>
#include <functional>

// define object function
double ObjectFcn(std::vector<double> *funcLoc) {
    // y = x ^ 2
    double x = funcLoc->at(0);
    // double y = funcLoc->at(1);
    // return (x * x * x) + (2 * (x * x)) - (2 * x);
    return (x * x);
    // return (x * x * x * x) + (2 * (x * x * x)) - (6 * (x * x)) + (4 * x) + 2
    // return (x * x) + (x * y) + (y * y)
}

int main(int argc, char* argv[]) {
    // create function pointer for object function
    std::function<double(std::vector<double> *)> p_ObjectFcn {ObjectFcn};

    qbGradient solver;

    solver.SetObjectFcn(p_ObjectFcn);

    // set start point
    std::vector<double> startPoint = {-1.0};
    solver.SetStartPoint(startPoint);
    
    solver.SetMaxIterations(50);
    solver.SetStepSize(0.2);

    std::vector<double> funcLoc;
    double funcVal;
    solver.Optimize(&funcLoc, &funcVal);

    std::cout << "Function location: " << funcLoc[0] << std::endl;
    std::cout << "Function value: " << funcVal << std::endl;

    return 0;
}
