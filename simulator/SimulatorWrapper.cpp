#include "include/SimulatorWrapper.h"
#include "include/Simulator.h"
 
#ifdef __cplusplus
extern "C" {
#endif

struct tagSimulator
{
    Simulator simulator;
};

struct tagSimulator *GetInstance(void)
{
    return new struct tagSimulator;
}

void ReleaseInstance(struct tagSimulator **ppInstance)
{
    delete *ppInstance;
    *ppInstance = 0;
}

void SetColor(struct tagSimulator *pSimulator, int color)
{
    pSimulator->simulator.SetColor(color);
}
 
int GetColor(struct tagSimulator *pSimulator)
{
    return pSimulator->simulator.GetColor();
}

void DoSimulation(struct tagSimulator *pSimulator, double *xreal, double *obj){
    pSimulator->simulator.doSimulation(xreal, obj);
}

#ifdef __cplusplus
};
#endif
