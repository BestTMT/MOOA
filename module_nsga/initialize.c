/* Data initializtion routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "include/global.h"
# include "include/rand.h"

/* Function to initialize a population randomly */
void reset_pop_obj (population *pop, int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        reset_ind_obj (&(pop->ind[i]));
    }
    return;
}
/* Function to initialize a population randomly */
void reset_ind_obj (individual *ind)
{
    int i;
    if (nobj==3)
    {
	    for (i=0; i<nobj; i++)
	    {
		ind->obj[i]=0.0;
	    }
    }
    return;
}
/* Function to initialize a population randomly */
void initialize_pop (population *pop)
{
    int i;
    for (i=0; i<popsize; i++)
    {
        initialize_ind (&(pop->ind[i]));
    }
    return;
}

/* Function to initialize an individual randomly */
void initialize_ind (individual *ind)
{
    int j, k;
    if (nreal!=0)
    {
        for (j=0; j<nreal; j++)
        {
            ind->xreal[j] = rndreal (min_realvar[j], max_realvar[j]);
        }
    }
    if (nbin!=0)
    {
        for (j=0; j<nbin; j++)
        {
            for (k=0; k<nbits[j]; k++)
            {
                if (randomperc() <= 0.5)
                {
                    ind->gene[j][k] = 0;
                }
                else
                {
                    ind->gene[j][k] = 1;
                }
            }
        }
    }
    return;
}

