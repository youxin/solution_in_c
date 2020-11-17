#ifndef _MY_LIST_POLYNOMIAL_H_
#define _MY_LIST_POLYNOMIAL_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Term;
typedef struct Term* PtrToTerm;
typedef PtrToTerm Polynomial;
typedef PtrToTerm Position;

void zero_polynomial(Polynomial poly);

void add_polynomial(Polynomial poly1, Polynomial poly2, Polynomial sum);

void mult_polynomial(Polynomial poly1, Polynomial poly2, Polynomial poly_prod);

#ifdef __cplusplus
}
#endif

#endif //_MY_LIST_POLYNOMIAL_H_