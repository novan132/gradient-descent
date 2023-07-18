# gradient descent algorithm

## guide
to run the code:
```console
make
./main
```

to use different function, edit ObjectFcn in `main.cpp`, example:
```
double ObjectFcn(std::vector<double> *funcLoc) {
    double x = funcLoc->at(0);
    double y = funcLoc->at(1);
    return (x * x) + (x * y) + (y * y)
}
```
