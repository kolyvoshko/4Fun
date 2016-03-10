/**
   @file      nrand.cpp
   @brief     Pseudorandom number generator file.
   @author    Eugene Kolyvoshko (ekolivoshko@gmail.com)
   @date      September 28 2015
   @version   1.0
   @copyright GNU Public License.
*/


#include "nrand.h"
#include <iostream>
#include <stdlib.h>
#include <string>

Nrand::Nrand(){
    m_sMethod = "mwc";
    m_lower = 0.0;
    m_upper = 1.0;
}

Nrand::~Nrand(){
    //dtor
}


double * Nrand::getProbablyDensity(int series){
    int freqCount[10] = {0};

    std::cout << "\n==============================="
        << "\nGeneration of random numbers" << std::endl;
    if (series < 1){
        std::cerr << "\nError: Number of series must be positive."
            << " (Nrand::getProbablyDensity - nrand.cpp)\n"
            << std::endl;

        exit(EXIT_FAILURE);
    }

    std::cout << "Used " << m_sMethod << " method" << std::endl;
    for(int i=0; i<10000;i++){
        double m = 0.0;
        if (m_sMethod == "mwc")
            m = (double) m_mwc()/ULONG_MAX;
        else if(m_sMethod =="x128")
            m = (double) m_x128()/ULONG_MAX;

        for(int i=0; i<10; i++){
            double lower = 0.1*i;
            double upper = 0.1*(i+1);
            if (m > lower && m < upper )
                freqCount[i]++;
        }
    }

    std::cout << "\nProbably Density of Numbers"
         << "\n===============================" << std::endl;
    for(int i=0; i<10; i++)
        std::cout << (double) freqCount[i]/10000 << std::endl;

    double * probably = new double[10];
    for(int i=0; i<10; i++)
        probably[i] = (double) freqCount[i]/series;

    return probably;
}

double Nrand::getNumber(){
    double number = 0.0;
    if (m_sMethod == "mwc")
        number = (double) m_mwc()/ULONG_MAX;
    else if (m_sMethod == "x128")
        number = (double) m_x128()/ULONG_MAX;
    return number;
}

double Nrand::getNumber(std::string method){
        double number = 0.0;
    if (method == "mwc")
        number = (double) m_mwc()/ULONG_MAX;
    else if (method == "x128")
        number = (double) m_x128()/ULONG_MAX;
    return number;
}

double * Nrand::getSeries(int series){
    double * numbSeries = new double[series];
    for(int i=0; i<series; i++)
        numbSeries[i] = getNumber();
    return numbSeries;
}

unsigned long Nrand::m_mwc(){
    static unsigned long x = 123456789L,
    y = 362436069L, z = 77465321L, c = 13579L;
    unsigned __int64 t; // unsigned __int64 for Windows
    t = 916905990LL * x + c;
    x = y; y = z;
    c = (t >> 32);
    return z = (t & 0xffffffff);
}

unsigned long Nrand::m_x128(){
    static unsigned long x = 123456789L,
    y = 362436069L, z = 521288629L, w = 88675123L;
    unsigned long t;
    t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void Nrand::setMethod(std::string method){
    if (method == "mwc") m_sMethod = "mwc";
    else if (method == "x128") m_sMethod = "x128";
    else{
        std::cerr << "\nError: Unknown method. (Nrand::setMethod - nrand.cpp)\n"
             << "Implemented methods: mwc or x128" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Nrand::setRange(double lower, double upper){
    m_lower = lower;
    m_upper = upper;
}
