#!/bin/bash
if [ "$CXX" = "g++" ]; then export CXX="g++-4.8" CC="gcc-4.8"; fi
cd /usr/src/gtest
if [ "$CXX" = "g++" ]
then 
	sudo cmake . -DCMAKE_CXX_COMPILER="g++-4.8" -DCMAKE_C_COMPILER="gcc-4.8"
else
	sudo cmake . 
fi
sudo make
sudo mv libg* /usr/lib/