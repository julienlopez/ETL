#!/bin/bash
if [ "$CXX" = "g++" ]; then export CXX="g++-4.8" CC="gcc-4.8"; fi
cd /usr/src/gtest
sudo cmake .
sudo make
sudo mv libg* /usr/lib/