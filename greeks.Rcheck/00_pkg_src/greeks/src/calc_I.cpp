#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector calc_I(NumericMatrix X, int steps, float dt) {
  int i;
  int paths = X.nrow();

  NumericVector I(paths);
  I = X(_, 0)/2 + X(_, steps)/2;
  for(i = 1; i < steps; i++) {
    I = I + X(_, i);
  }
  I = I * dt;
  return I;
}
