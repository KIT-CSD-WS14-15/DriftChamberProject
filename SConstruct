#-*- coding: utf-8 -*-

"""
To make this SConscript work, I have removed all 'src' in includes in the 'src' folder.
As well I rename or link the gtest-Blah folder to just gtest.
"""

env = DefaultEnvironment()
#you need to reset the g++ in case you have as system compiler a version < 4.7
#env['CXX'] = '/local/scratch/heck/basf2/tools/gcc/bin/g++'

Library('gtest_main', ['gtest/src/gtest_main.cc', 'gtest/src/gtest-all.cc'], CPPPATH=['gtest/include/'] )

Program ("DriftChamberSimulationReconstruction", [Glob('reconstruction/*.cc'), Glob('geometry/*.cc'), Glob('modules/*.cc'), Glob('core/*.cc') ] , CPPPATH=['.'], CCFLAGS = ['-std=c++11', '-ggdb'])

Program('myUnittests', [Glob('tests/*.cc'), Glob('reconstruction/*.o'), Glob('geometry/*.o'), Glob('modules/*.o'), 'libgtest_main.a'], \
LIBS=['pthread'], CPPPATH=['gtest/include/', '.'], CCFLAGS = ['-std=c++11'])
