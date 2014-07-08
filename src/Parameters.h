//
//  Parameters.h
//  cppipm
//
//  Created by Yiming Yan on 06/07/2014.
//  Copyright (c) 2014 Yiming Yan. All rights reserved.
//

#ifndef cppipm_Parameters_h
#define cppipm_Parameters_h

class Parameters
{
public:
    int maxIter;
    double tol;
    int verbose;
    double eta = 0.9995;     // ratio for step sizes
    
    Parameters();
    Parameters(int otherMaxIter, double otherTol, int otherVerbose);
    
    void set_maxIter(int otherMaxIter);
    void set_setTol(double otehrTol);
    void set_verbose(int otherVerbose);
};

#endif