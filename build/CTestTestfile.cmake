# CMake generated Testfile for 
# Source directory: /home/csmajs/asrin045/final-project-tuffyteam
# Build directory: /home/csmajs/asrin045/final-project-tuffyteam/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AllTests "/home/csmajs/asrin045/final-project-tuffyteam/build/runtests")
set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "/home/csmajs/asrin045/final-project-tuffyteam/CMakeLists.txt;35;add_test;/home/csmajs/asrin045/final-project-tuffyteam/CMakeLists.txt;0;")
subdirs("googletest")
