#ifndef GLOBALS_H
#define GLOBALS_H

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cmath>

class SimulError : public std::runtime_error {

public:
    SimulError(const char *c, int v=0) : std::runtime_error(c), code(v) {}
    SimulError(const std::string &s, int v=0) : std::runtime_error(s), code(v) {}
    int value() const {return code;}

protected:
    const int code;
};

#define _SIMULERR_(_N, _id) class _N : public SimulError { \
    public: _N(const char *c) : SimulError(c,_id) {} \
            _N(const std::string &s) : SimulError(s,_id) {} };


/// *Specific error codes*
_SIMULERR_(TCLAP_ERROR, 10)
_SIMULERR_(OUTPUT_ERROR, 20)
_SIMULERR_(CFILE_ERROR, 30)

#undef _SIMULERR_

/// * hard-coded constants *
/// * default parameter values *
#define _SIZE_ 100
#define _TIME_ 10
#define _DEGREE_ 4
#define _STRENG_ .25
#define _THALAM_ 5
#define _PROP_INHIB_ 0.2
#define _FIRING_TH_ 30
#define _REST_VAL_ -65.0
#define _AVAR_ .8
#define _BVAR_ .25
#define _CVAR_ 0.2307692
#define _DVAR_ .75

/// * text messages *
#define _PRGRM_TEXT_ "Simulation of the Izhikevich neuron model"
#define _TIME_TEXT_ "Number of time-steps"
#define _SIZE_TEXT_ "Number of neurons"
#define _DEGREE_TEXT_ "Average connectivity between neurons"
#define _INHIB_TEXT_ "Proportion of inhibitory (FS) neurons, the complement will be RS neurons"
#define _STRENG_TEXT_ "Average link strength for excitatory neurons (inhibitory is the double)"
#define _THALAM_TEXT_ "Std deviation of thalamic input noise"
#define _TYPES_TEXT_ "Proportions of each type of neurons as a list like 'IB:0.4,CH:0.35'. If total is less than 1, it will be completed with RS neurons"
#define _OUTPUT_TEXT_ "Output file name (default is output to screen)"
#define _CFILE_TEXT_ "Configuration file name"

#endif //GLOBALS_H
