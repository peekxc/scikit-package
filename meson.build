project(
  'my_package', 'cpp', 
  license: 'Apache-2.0',
  meson_version: '>= 1.2.0',
  default_options : [
    'buildtype=debugoptimized', 
    'warning_level=2',
    'pkgconfig.relocatable=true', 
    'cpp_std=c++17', 
    'python.bytecompile=2'
  ]
)

## Import python kernel 
py_mod = import('python')
py = py_mod.find_installation(pure: true, required: true, modules: ['numpy']) # python_installation object
message('Python path =' + py.full_path() + ', version: ' + py.version())
message('Numpy version =' + run_command(py, ['-c', 'import numpy; print(numpy.__version__)'], check: true).stdout().strip())

## Check the python version
if py.language_version().version_compare('< 3.8')
  error('Invalid Python version, only >= 3.8 is supported.')
endif

## Print the C++ compiler + tack on default arguments
compiler = meson.get_compiler('cpp')
message('Compiler = '+compiler.get_id()+', version: '+compiler.version())
_cpp_args = compiler.get_supported_arguments(
  '-Wno-unused-but-set-variable',
  '-Wno-unused-function',
  '-Wno-conversion',
  '-Wno-misleading-indentation',
  '-fPIC', 
  '-fvisibility=hidden',
  '-Wno-deprecated-anon-enum-enum-conversion' # to silence Eigen 3.4 warnings
)

## Include directories
incdir_numpy = run_command(py, ['-c', 'import os; os.chdir(".."); import numpy; print(numpy.get_include())'], check : true).stdout().strip()
incdir_pybind11 = run_command(py, ['-c', 'import os; os.chdir(".."); import pybind11; print(pybind11.get_include())'], check : true).stdout().strip()

## Header includes
inc_pkg = include_directories('include')
inc_numpy = include_directories(incdir_numpy)
inc_pybind11 = include_directories(incdir_pybind11)

## Add dependencies, if any
dependency_map = {}

## Compile the package directory
subdir('src' / 'my_package')