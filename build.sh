gcc -c -fPIC -I /shared/projects/openjdk/jdks/sapmachine11/include/ -I /shared/projects/openjdk/jdks/sapmachine11/include/linux/ -o sample.o sample.c
gcc -shared -fPIC -o sample.so sample.o -lc

gcc -c -fPIC -I /shared/projects/openjdk/jdks/sapmachine11/include/ -I /shared/projects/openjdk/jdks/sapmachine11/include/linux/ -o bwbrdg.o bwbrdg.c
gcc -shared -fPIC -o bwbrdg.so bwbrdg.o -lc

gcc -c -fPIC -O2 -I /shared/projects/openjdk/jdks/sapmachine11/include/ -I /shared/projects/openjdk/jdks/sapmachine11/include/linux/ -o bwbrdg-opt.o bwbrdg.c
gcc -shared -fPIC -o bwbrdg-opt.so bwbrdg-opt.o -lc

# call with: java -agentpath:<lib path>
