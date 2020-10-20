#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/timer/timer.hpp>

using namespace boost::numeric::ublas;
using namespace boost::timer;
 
int main()
{
  boost::timer::auto_cpu_timer timer;
  vector<double> a (3);
  a(0) = 1;
  a(1) = 2;
  a(2) = 3;
  vector<double> b (3);
  b(0) = 1;
  b(1) = 0;
  b(2) = 0;
  vector<double> c (3);
  c(0) = 0;
  c(1) = 0;
  c(2) = 0;
  vector<double> d = a - b;
  vector<double> e = a - c;
  std::cout << "Vector a =\n" << a << std::endl;
  std::cout << "Vector b =\n" << b << std::endl;
  std::cout << "Vector c =\n" << c << std::endl;
  std::cout << "d = a - b  =\n" << d << std::endl;
  std::cout << "e = a - c  =\n" << e << std::endl;
  //std::cout << timer.format() << '\n';
}

