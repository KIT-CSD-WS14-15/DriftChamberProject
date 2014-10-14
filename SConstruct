#-*- coding: utf-8 -*-

#to make this SConscript work, I have removed several "src" in includes in the "src" folder.
env = DefaultEnvironment()
env['CXX'] = '/local/scratch/heck/basf2/tools/gcc/bin/g++'

Library('gtest_main', ['gtest/src/gtest_main.cc', 'gtest/src/gtest-all.cc'], CPPPATH=['gtest/include/'] )
Program('myUnittests', [Glob('tests/*.cc'), 'libgtest_main.a'], LIBS=['pthread'], CPPPATH=['gtest/include/', ['.']])

Program ("DriftChamberSimulationReconstruction", [Glob('reconstruction/*.cc'), Glob('geometry/*.cc'), Glob('modules/*.cc'), Glob('core/*.cc') ] , CPPPATH=['.'], CCFLAGS = ['-std=c++11'])
