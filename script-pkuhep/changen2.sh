#!/bin/tcsh -f

# this script is used to create a new package
set herepath = $PWD

# input the name of the package
if( $#argv == 2 ) then
    set job = $argv[1]

    set object = $argv[2]
else
    echo "please append the name of origin and object files and the number of jobs, Example:  sim   GammaKPi"
    exit 0
endif

set ai=1
while ($ai<41)
   set bi=1
   while($bi<51)
#if(!( -d ${object}) ) then
#     echo "this file does not exist, please check the name"
#     exit 0
#else 
    
# copy all files needed

    

# relace names in these files 
       if(-f temp) then    
       rm temp
       endif
      cp ${job}-${object}_1_cfg.py test_${ai}_{$bi}.py
      sed -e /firstRun/s/1/${ai}/g ./test_${ai}_{$bi}.py > temp
      mv temp test_${ai}_{$bi}.py
      sed -e /firstLuminosityBlock/s/1/${bi}/g ./test_${ai}_{$bi}.py > temp
      mv temp test_${ai}_{$bi}.py
      mv test_${ai}_{$bi}.py $PWD/list_py
      
      @ bi++
    end
    @ ai++
end
# endif
cd $herepath
