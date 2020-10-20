#include <iostream>
#include <Eigen/Dense>
#include <boost/timer/timer.hpp>

using namespace Eigen;
using namespace boost::timer;
 
int main()
{
  boost::timer::auto_cpu_timer timer;
  Vector3d a(1,2,3);
  Vector3d b(1,0,0);
  Vector3d c(0,0,0);
  Vector3d d = a - b;
  Vector3d e = a - c;
  std::cout << "Vector a =\n" << a << std::endl;
  std::cout << "Vector b =\n" << b << std::endl;
  std::cout << "Vector c =\n" << c << std::endl;
  std::cout << "d = a - b  =\n" << d << std::endl;
  std::cout << "e = a - c  =\n" << e << std::endl;
  //std::cout << timer.format() << '\n';
}

