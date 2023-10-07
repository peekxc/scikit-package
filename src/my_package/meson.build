## Extension modules
extensions = [ '_prefixsum']
foreach ext: extensions
  py.extension_module(
    ext,
    ext + '.cpp',
    include_directories: [inc_pkg, inc_numpy, inc_pybind11],
    install: true, 
    cpp_args: _cpp_args
  )
endforeach

python_sources = [
  '__init__.py'
]

## Print install directory
message('Source install dir = '+py.get_install_dir())
py.install_sources(
  python_sources,
  subdir: 'my_package', 
  pure: false       # Will be installed next to binaries
)