gcc -c -fPIC -I /shared/projects/openjdk/jdks/sapmachine11/include/ -I /shared/projects/openjdk/jdks/sapmachine11/include/linux/ -o sample.o sample.c
gcc -shared -fPIC -o sample.so sample.o -lc
# call with: java -agentpath:<lib path>
gcc -c -fPIC -I /shared/projects/openjdk/jdks/sapmachine11/include/ -I /shared/projects/openjdk/jdks/sapmachine11/include/linux/ -o bwbrdg.o bwbrdg.c
gcc -shared -fPIC -o bwbrdg.so bwbrdg.o -lc
# call with: java -agentpath:<lib path>
