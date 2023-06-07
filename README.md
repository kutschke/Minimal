# Minimal

A minimal set of code, using Mu2e Muse/scons as a build syste, to use
as test bed for a future build system.

To run this example:
#In a clean shell, cd to a clean directory.
#source  /cvmfs/mu2e.opensciencegrid.org/setupmu2e-art.sh
#git clone https://github.com/kutschke/Minimal
#muse setup
#muse build -j 8
#art -c fcl/write.fcl >& write.log
#art -c fcl/read.fcl  >& read.log

Notes

# In this example "setup mu2e" is told my Minimal/.muse to choose envset p040, which chooses art v3_13_01.
It also sets up many ups products that are not needed for the example.
# On an empty mu2egpvm*, -j 8 is good;  on an empty mu2ebuild01, -j 24 is good.
# The libraries produced by the build are in: build/sl7-prof-e20-p040/Minimal/lib/
# Running write.fcl will create the file testOutput.art in the cwd
# I have included write.log and read.log as examples of what the output should be.


Content:
# The DataProducts/ subdirectory holds a single data product class, IntegerProducer.
# The build of DataProducts creates a .so to hold the data product plus the associated root dictionaries.
# The Code/subdirectory holds two modules, one to create one instaance per event of the data product, re


is in it's list of things to build.  It will choose the highest numbered envest fro


Manifest

README.md
.muse
fcl/read.fcl
fcl/write.fcl
DataProducts/src/classes_def.xml
DataProducts/src/classes.h
DataProducts/src/SConscript
DataProducts/src/IntegerProduct.cc
DataProducts/src/IntegerProduct.hh
Code/src/SConscript
Code/src/ping.cc
Code/src/ping.hh
Code/src/ProduceInteger_module.cc
Code/src/AnalyzeInteger_module.cc
