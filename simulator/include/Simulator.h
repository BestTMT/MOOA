#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <iostream>
#include <chrono>
#include <ctime>  



class Simulator
{
public:
    Simulator();
    int GetColor(void);
    void SetColor(int color);
    void doSimulation(double *xreal, double *obj);
    
private:
    int m_nColor;
};
#endif