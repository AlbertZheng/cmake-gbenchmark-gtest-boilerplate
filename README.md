# Table of Contents <!-- omit in toc -->

- [C++17 boilerplate project with cmake, google benchmark and google test](#c17-boilerplate-project-with-cmake-google-benchmark-and-google-test)
- [Organization](#organization)
- [Build](#build)
  - [Build Options](#build-options)
  - [Executable commands](#executable-commands)
- [License](#license)
- [Contributing](#contributing)

<br>

# C++17 boilerplate project with cmake, google benchmark and google test

A cross-platform C++17 boilerplate project with ``cmake``, ``Google Benchmark`` and ``Google Test`` frameworks support.

This project boilerplate is using ``git submodule`` to include ``Google Benchmark`` and ``Google Test`` so you
need either to do
    
```bash
$ git clone --recursive git@github.com:AlbertZheng/cmake-gbenchmark-gtest-boilerplate.git
```

or

```bash
$ git clone git@github.com:AlbertZheng/cmake-gbenchmark-gtest-boilerplate.git
$ cd cmake-gbenchmark-gtest-boilerplate
$ git submodule init
$ git submodule update
```


# Organization

* **src** : has the source files and the CMakeLists.txt to compile the api library and executable of your App.
* **include** : has the header files of your App.
* **test** : has the tests and related CMakeLists.txt of your App.
* **benchmark** : has the benchmarks and related CMakeLists.txt of your App.
* **third-party** : all the third party libraries or frameworks and related CMakeLists.txt should be put in this directory. Currently, ``Google Benchmark`` and ``Google Test`` are already there. 
* **doc** : you can put the documents of your App in this directory.
* **examples** : you can put the examples code of App in this directory.
* **tools** : you can put your tools code of App in this directory.


The main CMakeLists.txt file at the root of the project has options and further documentation.


# Build

On Linux/Unix, to build and make the test:

```bash
$ mkdir build && cd $_
$ cmake ..
$ cmake --build .
```

On Windows, you can use cmake to generate Visual Studio build files with the same ``cmake ..`` command.


## Build Options

Options can be turned on and off by providing ``cmake`` with a ``-DOPTIONNAME=ON`` (or ``OFF``) argument. 

For example, to turn off tests and benchmarks, build a shared library, and use sanitize flags in a DEBUG build:
```bash
$ cmake .. -DCMAKE_BUILD_TYPE=DEBUG \
           -DBUILD_TESTS=OFF \
           -DBUILD_BENCHMARKS=OFF \
           -DBUILD_SHARED_LIBS=ON \
           -ENABLE_SANITIZE=ON
```

By default, the project will be built in ``RELEASE`` mode, and the default config of Options are:
> option(BUILD_TESTS       "Build tests" ON)  
> option(BUILD_BENCHMARKS  "Build benchmarks" ON)   
> option(ENABLE_SANITIZE   "Add sanitize flags" OFF)  
> option(BUILD_SHARED_LIBS "Build shared libraries (DLLs)." OFF)  

If you experience the memory or ``UB`` issues in your codes, recommending you to use Google Sanitizers toolbox for checking the issues by ``-DENABLE_SANITIZE=ON`` option.

See the CMakeLists.txt file to see all the options.


By default, the makefiles will build the executable, api library, tests, and benchmarks: 
* An executable program named ``demo`` (of course: you should change the name for your App)
* An api library named ``libdemo-api.a`` or ``libdemo-api.so`` (of course: you should change the name for your App)
* An executable program named ``tests`` for runing unit test cases
* An executable program named ``benchmarks`` for running benchmark test cases


## Executable commands

The commands:    

```
$ ./test/tests
$ ./benchmark/benchmarks
```

will run the tests and benchmarks. And

```bash
$ sudo make install
```

will install (at least on Linux) the library and executable to your computer's path.


# License

Copyright (C) 2018-2019 Lisong Zheng, 郑立松

The binaries and source code of this project can be used according to the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0.html).


# Contributing

Welcome all contributions. You can submit any ideas as ``pull requests``.
