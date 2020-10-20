#define BOOST_TEST_MODULE boost_test_sequence
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

BOOST_AUTO_TEST_CASE( test_collections_vectors )
{

  Vector3d a(1,2,3);
  Vector3d b(0,0,0);
  Vector3d c = a - b;

  std::cout << "Vector a =\n" << a << std::endl;
  std::cout << "Vector b =\n" << b << std::endl;
  std::cout << "Vector c = a - b =\n" << c << std::endl;

  BOOST_TEST(a == c);
}