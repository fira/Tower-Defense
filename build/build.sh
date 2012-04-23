#!/bin/bash
cmake .. -G "Unix Makefiles"
cmake .. -G "Unix Makefiles"
doxygen Doxyfile
#i don't know why we have to execute it two time, but it works
