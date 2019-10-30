#!/bin/tcsh -f

# this script is used to create a new package
set herepath = $PWD

# input the name of the package
if( $#argv == 1 ) then
    set jobname = $argv[1]
#    set object = $argv[2]
else
    echo "please append the name of job files , Example: ppjsieecon365"
    exit 0
endif

if(( -e PrintSuccessfulJobs.txt) ) then
   rm PrintSuccessfulJobs.txt
endif

if(( -e PrintSuccessfulScripts.txt) ) then
   rm PrintSuccessfulScripts.txt
endif

if(( -e successfulScripts.txt) ) then
   rm successfulScripts.txt
endif

@ i=0
set j=0
set ai=0
while($i<1999)
     @ ai++
     if((-e ${jobname}_${i}.root)) then
        echo "${jobname}_${i}.root exists" >>PrintSuccessfulJobs.txt
        sed -n ${ai}p list_py.txt >> successfulScripts.txt
        set filename = `sed -n ${ai}p list_py.txt`
        echo "${filename}">>PrintSuccessfulScripts.txt
        @ j++
     endif
@ i++
end

echo "${j} jobs successful"
echo "${i} total jobs"
echo "${ai}"
cd $herepath
