# Package template 

This is my own opionated package template for creating modern python packages geared for scientific computing that incorporate C++. 

In particular, this template uses [quarto](https://quarto.org/) for docs, [pybind11](https://pybind11.readthedocs.io/en/stable/index.html) for bindings, and [meson-python](https://meson-python.readthedocs.io/en/latest/#) for building. The package template also incorporates a matrix build via [github actions]() that cross-compiles wheels for each major compiler / architecture using [cibuildwheel]() for maximum compatibility. 

Notable choices made in the template: 

- The template package is a [PEP 518](https://peps.python.org/pep-0518/)-compliant package
- Uses the [src layout](https://packaging.python.org/en/latest/discussions/src-layout-vs-flat-layout/)
- Unit tests in `tests` directory for [pytest](https://docs.pytest.org/en/7.4.x/)
- Optional `include` folder for deploying your own header-only libraries across packages
- Optional `extern` folder for incorporating external header-only libraries (e.g. via git submodules)
- 

The package also contains a simple extension module and some basic meson configuration to jump-start projects that build extension modules. 