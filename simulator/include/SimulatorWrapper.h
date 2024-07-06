#ifndef _SIMULATOR_WRAPPER_H__
#define _SIMULATOR_WRAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

struct tagSimulator; // Warning: 不能使用 extern 修饰

extern struct tagSimulator *GetInstance(void);
extern void ReleaseInstance(struct tagSimulator **ppInstance);
extern void SetColor(struct tagSimulator *pSimulator, int color);
extern int GetColor(struct tagSimulator *pSimulator);
extern void DoSimulation(struct tagSimulator *pSimulator, double *xreal, double *obj);
#ifdef __cplusplus
};
#endif

#endif
