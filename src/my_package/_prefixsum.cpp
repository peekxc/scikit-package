#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

auto prefixsum(std::vector< int > v){
  return 0; 
}

PYBIND11_MODULE(_cumsum, m) {
  m.doc() = "cumulative sum module"; 
  m.def("prefixsum", prefixsum);
}