﻿#ifndef _INPUT_H
#define _INPUT_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
//#include <omp.h>
#include "func.h"

#define DEBUG_PRINT_INT(a) (printf("%s: %d\n", #a, a))
#define DEBUG_PRINT_INT(a) (printf("%s: %d\n", #a, a))
#define DEBUG_PRINT_DBL(a) (printf("%s: %20.16lf\n", #a, a))
#define SPRINTF_FILENAME(filename, filenametmpl, state,  a)\
  (sprintf (filename,"%s%s_%s.txt", filenametmpl, state, #a)) 
#define elem2DCMjr(mat, i ,j) ((mat)[(j)][(i)])
#define elem1DCMjr(arr, m, i ,j) ((arr)[(m)*(j)+(i)])

#ifndef BUFF_SIZE
#define BUFF_SIZE 1024
#endif /* BUFF_SIZE */
#ifndef VALID
#define VALID 0
#endif /* VALID */
#ifndef INVALID
#define INVALID 1
#endif /* INVALID */
//#define _DEBUG_

//-- allocate & deallocate matrix
extern void   **allocateMatrix(int size, int m, int n);
extern void   deallocateMatrix(void **aa             );
extern void   *allocateVector (int size, int m       );
extern void   deallocateVector(void *a               );
extern double **readSeparatedValueFiles
   (int *row, int *col, char *fpth, int flg_readasfile); 

//-- initialize arrays or data
extern int  initMatrixToDblZero(int ni, int nj, double **aa);
extern int  initMatrixToRodriguesRotation
   (double* dest, double theta, double *n);
extern int  initVectorToDblZero(int ni, double *a);
extern int  initVectorToDblIdentity
   (int nj, double *a, int n_cols);
extern int  initVectorToIntZero(int ni, int *a);
extern int  copyMatrix
   (int m, int n, double *dest, double *src);
 
extern int convoluteMatMat
   (int m_dest, int n_dest, double *dest,
    int m_src, int n_src, double *src,
    int m_ker, int n_ker, double *ker);
 
//-- operate file actions
extern int  initFileNames(char *newfpth, 
    char *time, const char *fpth, char *fnm, int flg_silent);
extern int  writeOutDblPointer
   (char* filename, int ni, int nj, double** aa);
extern int faddDblPointer
   (FILE *fp, int ni, int nj, double** aa);
extern int writeOutSglPointer
   (char* filename, int ni, double* a);
extern int faddSglPointer(FILE *fp, int ni, double* a);
extern int transSeparatedFile(char* fpth);
// Measure the computation time
extern double GetElapsedTime();
extern double GetCPUTime();
extern int    getCurrentTime(char *str);

#endif /* _INPUT_H */
