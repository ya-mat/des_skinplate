// -*- coding: utf-8 -*-

#define EIGEN_DONT_PARALLELIZE // parallel off

#include <iostream>
//#include <ostream>
//#include <fstream>
//#include <vector>
//#include <Eigen/Dense>
//#include <chrono>
#include <cmath>

int main(){
  std::cout.precision(10); // Show 10 digits
  std::cout << std::scientific << std::endl;
  constexpr double pi = std::acos(-1.0);

  double pp;
  double ff;
  double ye = 235.0e6; // yield point of skinplate
  double tt = 0.0032; // tickness of plate
  //  double rad = 2.0; // radius of tunnel
  double theta = pi/12.0; // interval of longitudinal rib
  //  double ts = rad*theta; // span of plate
  double ee = 2.1e11; // young coff.
  //  double ii = tt*tt*tt*ts/12.0; // moment of inertia of area per unit width
  double vv = 0.3; // poisson raitio
  double rad;
  double ts;
  double ii;

//  pp = 4.0*(tt/ts)*(tt/ts)*ye;
//  ff = ye*tt*ts*ts/(4.0*ee*ii)*(1.0 - vv*vv);
// 
//  std::cout << "ts " << ts << std::endl;
//  std::cout << "ii " << ii << std::endl;
//  std::cout << "pp " << pp << std::endl;
//  std::cout << "ff " << ff << std::endl;
//  std::cout << "std::sqrt(ff) " << std::sqrt(ff) << std::endl;
// 
//  std::cout << "kyokugen kaju (N) " << 1.1*pp*std::sqrt(ff) << std::endl;
//  std::cout << "corresponding soil depth to kyokugen kaju (m) " << 1.1*pp*std::sqrt(ff)/18.0/1000.0 << std::endl;

  for(int i = 0; i < 7; i++){
    rad = 1.0 + 0.5*i;
    ts = rad*theta;
    ii = tt*tt*tt*ts/12.0; // moment of inertia of area per unit width

    pp = 4.0*(tt/ts)*(tt/ts)*ye;
    ff = ye*tt*ts*ts/(4.0*ee*ii)*(1.0 - vv*vv);

    std::cout << "now rad " << rad << std::endl;
    std::cout << "kyokugen kaju (N) " << 1.1*pp*std::sqrt(ff) << std::endl;
    std::cout << "corresponding soil depth to kyokugen kaju (m) " << 1.1*pp*std::sqrt(ff)/18.0/1000.0 << std::endl;
    std::cout << " " << std::endl;
  }

  for(int i = 0; i < 7; i++){
    rad = 2.0;
    tt = tt*(1.0 - 0.1*i);
    ts = rad*theta;
    ii = tt*tt*tt*ts/12.0; // moment of inertia of area per unit width

    pp = 4.0*(tt/ts)*(tt/ts)*ye;
    ff = ye*tt*ts*ts/(4.0*ee*ii)*(1.0 - vv*vv);

    std::cout << "now tt " << tt << " x% " <<  (1.0 - 0.1*i) << std::endl;
    std::cout << "kyokugen kaju (N) " << 1.1*pp*std::sqrt(ff) << std::endl;
    std::cout << "corresponding soil depth to kyokugen kaju (m) " << 1.1*pp*std::sqrt(ff)/18.0/1000.0 << std::endl;
    std::cout << " " << std::endl;
  }
}
