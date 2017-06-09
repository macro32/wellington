Reconsidering the use of cmake for the builds. I would like to port
this project to FreeBSD so I can do a build with clang. 

A good cross platformm build system might help. 

Although Makefiles would do the job, it
is a useful exercise to see how cmake works, just as a learning
exercise.

It is true that all build systems are a bit messy.

The following gives a great summary of three contenders. I love
the very balanced rant about autotools.

http://stackoverflow.com/questions/4071880/autotools-vs-cmake-vs-scons

I have personal experience of Ant, Bjam (used by Boost), MSBuild and
traditional Make files. They all have some pros but also cons. I tend
to favour simplicity and for that reason still have a fondness for Make.
A single executable which pretty much does what you want even though it
can be tricky to master. MSBuild and Ant use XML to drive them. Verbose
and with external dependencies.

Great (and very balanced) comments on SCons can be found here.

http://stackoverflow.com/questions/12017580/c-build-systems-what-to-use

