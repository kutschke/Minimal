# Minimal

A minimal set of code, using Mu2e Muse/scons as a build system, to use as test bed for a future build system.

To run this example:
1. In a clean shell, cd to a clean directory.
2. source  /cvmfs/mu2e.opensciencegrid.org/setupmu2e-art.sh
3. git clone https://github.com/kutschke/Minimal
4. muse setup
5. muse build -j 8
6. art -c fcl/write.fcl >& write.log
7. art -c fcl/read.fcl  >& read.log

Notes

1. In this example "setup mu2e" is told my Minimal/.muse to choose envset p040, which chooses art v3_13_01.
It sets the ups products needed for this test, plus a lot more that are not needed.  All that is really needed is the bare art suite.
2. On an empty mu2egpvm*, -j 8 is a good choice for build parallelism;  on an empty mu2ebuild01, -j 24 is a good choice.
3. The libraries produced by the build are in: build/sl7-prof-e20-p040/Minimal/lib/
4. Running write.fcl will create the file testOutput.art in the cwd.  It will also read the product from memory and make soem printout.
5. Running read.fcl will read that file.
6. I have included write.log and read.log as examples of what the output should be.


Content:
1. The DataProducts/ subdirectory holds a single data product class, IntegerProducer.
2. The build of DataProducts creates a .so to hold the data product plus the associated root dictionaries.
3. The Code/subdirectory holds two art modules and one free function:
  - ProduceInteger: this creates one instance of the data product per event and adds it to the evnet.  The payload is an integer equal to 2x the evnet number
  - AnalyzeInteger: this reads the data product from the event and prints out the eventId plus the value of the integer.  In the c'tor it calls the function ping, in order to exercise linking to a .so file.
  - ping: this is the free function. All it does is make some printout.
