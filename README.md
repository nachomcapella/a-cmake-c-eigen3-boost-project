# A CMake, C++, Eigen3 and Boost project
The purpose of this report is to describe the work performed in the first laboratory of the Software Development Tools and Methods course.

It comprises the use of the CMake tool to create a project and compile its files and libraries; the use of the C++ libraries Boost and Eigen3; and the management of CPUs to speed up computation. We show the necessary steps to assemble and build a C++ project using CMake as well as list several examples of use of the listed libraries. This examples include result checking (Boost.Test) and time performance (Boost.Timer + Eigen3/Boost.Ublas) in simple algebra operations. Time performance is finally studied by changing the compiler's optimization flags and the number of processing units employed to run the tasks.

CMake facilitates the building of programmes that require of mutiple files and libraries, Eigen3 is shown to be a faster alternative to Boost.Ublas and optimization flags are portrayed as an easy way to speed-up computations.
