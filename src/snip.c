/* Copyright 2011-2013 Sebastian Gibb
 * <mail@sebastiangibb.de>
 *
 * This file is part of MALDIquant for R and related languages.
 *
 * MALDIquant is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MALDIquant is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MALDIquant. If not, see <http://www.gnu.org/licenses/>
 */

/* SNIP algorithm based on:
 * C.G. Ryan, E. Clayton, W.L. Griffin, S.H. Sie, and D.R. Cousens.
 * "Snip, a statistics-sensitive background treatment for the quantitative
 *  analysis of pixe spectra in geoscience applications."
 * Nuclear Instruments and Methods in Physics Research Section B:
 * Beam Interactions with Materials and Atoms, 34(3):396-402, 1988.
 * ISSN 0168-583X. doi:10.1016/0168-583X(88)90063-8.
 * URL http://www.sciencedirect.com/science/article/B6TJN-46YSYTJ-30/2/e0d015ceb8ea8a7bc0702a857a19750b
 */

#include "MALDIquant.h"

#include <R.h>
#include <Rinternals.h>

/* y = array of double values
 * iterations = max iteration steps
 */
SEXP C_snip(SEXP y, SEXP iterations) {
  SEXP tmp, output;
  /* TODO: replace by R_xlen_t in R 3.0.0 */
  int n, i, j, k;
  double a, b;

  PROTECT(tmp=coerceVector(duplicate(y), REALSXP));
  n=LENGTH(tmp);

  PROTECT(output=allocVector(REALSXP, n));

  double* xo=REAL(output);
  double* xy=REAL(tmp);

  k=asInteger(iterations);

  for (i=1; i<=k; ++i) {
    for (j=i; j<n-i; ++j) {
      a=xy[j];
      b=(xy[j-i]+xy[j+i])/2;
      if (b < a) {
        a=b;
      }
      xo[j]=a;
    }

    for(j=i; j<n-i; ++j) {
      xy[j]=xo[j];
    }
  }

  memcpy(xo, xy, n*sizeof(double));

  UNPROTECT(2);

  return(output);
}

