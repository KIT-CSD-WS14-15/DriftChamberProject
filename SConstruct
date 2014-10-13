#-*- coding: utf-8 -*-

env = DefaultEnvironment()
env['CXX'] = '/local/scratch/heck/basf2/tools/gcc/bin/g++'

Program ("DriftChamberSimulationReconstruction", [Glob('*.cc'), Glob('./*/*.cc')] , CPPPATH=['.'], CCFLAGS = ['-std=c++11'])
