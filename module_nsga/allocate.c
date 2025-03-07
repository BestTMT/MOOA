/* Memory allocation and deallocation routines */
/* The Copyright belongs to Luis Felipe Ariza Vesga (lfarizav@unal.edu.co). You
are free to use this algorithm (https://github.com/lfarizav/NSGA-III) for
research purposes. All publications which use this code should acknowledge the
author. Luis Felipe Ariza Vesga. A Fast Nondominated Sorting Genetic Algorithm
Extension to Solve Many-Objective Problems. March, 2019. */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/global.h"
#include "include/rand.h"

/* Function to allocate memory to a population */
void allocate_memory_pop(population *pop, int size) {
  int i;
  pop->ind = (individual *)malloc(size * sizeof(individual));// 分配的是指针变量 must utilize malloc
  for (i = 0; i < size; i++) {
    allocate_memory_ind(&(pop->ind[i]));//分配单一individual变量 //内存是按照顺序一层一层排列。
  }
  return;
}

/* Function to allocate memory to an individual */
void allocate_memory_ind(individual *ind) {
  int j;
  if (nreal != 0) {
    ind->xreal = (double *)malloc(nreal * sizeof(double));
  }
  if (nbin != 0) {
    ind->xbin = (double *)malloc(nbin * sizeof(double));
    ind->gene = (int **)malloc(nbin * sizeof(int *));
    for (j = 0; j < nbin; j++) {
      ind->gene[j] = (int *)malloc(nbits[j] * sizeof(int));
    }
  }
  ind->obj = (double *)malloc(nobj * sizeof(double));
  ind->obj_minus_zmin = (double *)malloc(nobj * sizeof(double));
  ind->obj_normalized = (double *)malloc(nobj * sizeof(double));
  ind->obj_feasible = (double *)malloc(sizeof(double));
  ind->obj_infeasible = (double *)malloc(sizeof(double));
  if (ncon != 0) {
    ind->constr = (double *)malloc(ncon * sizeof(double));
  }
  if (neqcon != 0) {
    ind->equality_constr = (double *)malloc(neqcon * sizeof(double));
  }
  return;
}

/* Function to deallocate memory to a population */
void deallocate_memory_pop(population *pop, int size) {
  int i;
  for (i = 0; i < size; i++) {
    deallocate_memory_ind(&(pop->ind[i]));
  }
  free(pop->ind);
  return;
}

/* Function to deallocate memory to an individual */
void deallocate_memory_ind(individual *ind) {
  int j;
  if (nreal != 0) {
    free(ind->xreal);
  }
  if (nbin != 0) {
    for (j = 0; j < nbin; j++) {
      free(ind->gene[j]);
    }
    free(ind->xbin);
    free(ind->gene);
  }

  if (ncon != 0) {
    free(ind->constr);
  }
  if (neqcon != 0) {
    free(ind->equality_constr);
  }
  return;
}
/* Function to allocate memory to a population of refpoints*/
void allocate_memory_pop_refpoints(population_refpoints *pop_refpoints,
                                   int size) {
  int i;
  pop_refpoints->ind =
      (individual_refpoints *)malloc(size * sizeof(individual_refpoints));
  for (i = 0; i < size; i++) {
    allocate_memory_ind_refpoints(&(pop_refpoints->ind[i]));
  }
  return;
}
/* Function to allocate memory to an individual of refpoints*/
void allocate_memory_ind_refpoints(individual_refpoints *ind) { return; }
/* Function to deallocate memory to a population of refpoints */
void deallocate_memory_pop_refpoints(population *pop_refpoints, int size) {
  int i;
  for (i = 0; i < size; i++) {
    deallocate_memory_ind_refpoints(&(pop_refpoints->ind[i]));
  }
  free(pop_refpoints->ind);
  return;
}
/* Function to deallocate memory to an individual of refpoints */
void deallocate_memory_ind_refpoints(individual_refpoints *ind) {
  int j;

  return;
}
