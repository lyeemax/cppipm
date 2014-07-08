//
//  Iterate.h
//  cppipm
//
//  Created by Yiming Yan on 07/07/2014.
//  Copyright (c) 2014 Yiming Yan. All rights reserved.
//

#ifndef cppipm_Iterate_h
#define cppipm_Iterate_h
#include <armadillo>

#include "Problem.h"
#include "Parameters.h"
#include "Status.h"

using namespace arma;

class Iterate
{
public:
    // constructor
    Iterate();
    Iterate(const Problem &prob);
    
    // functions
    void initialPoint(const Problem &prob);
    void calResiduals(const Problem &prob);
    bool checkTermination(const Parameters &pars, Status &stat);
    void solveNewton(const Problem &prob);
    void getStepSize(const Parameters &pars);
    void updateIter();
    void iterIncrement();
    
    vec getIterx() const;
    vec getItery() const;
    vec getIters() const;
    int getIterNum() const;
    double getMu() const;
    double getRes() const;
    
    
    
private:
    // internal properties
    int iter;
    double sigma;       // centring paramter
    double bc;          // regulator
    vec Rp;             // primal residual
    vec Rd;             // dual residual
    vec Rm;             // complementary residual
    double residual;    // residual
    double mu;          // duality gap
    
    vec    x;           // |
    vec    y;           // | iterates
    vec    s;           // |
    
    vec    dx;          // |
    vec    ds;          // | newton directions
    vec    dy;          // |
    
    double alphax;      // Step size for primal vars
    double alphas;      // Step size for dual vars
    
};



#endif