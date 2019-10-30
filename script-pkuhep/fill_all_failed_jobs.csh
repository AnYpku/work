#!/bin/tcsh -f

# this script is used to create a new package
set herepath = $PWD

# input the name of the package
if( $#argv == 3 ) then
    set jobname = $argv[1]
    set number1 = $argv[2]
    set number2 = $argv[3]
else
    echo "please append the name of job files , Example: ppjsieecon 365"
    exit 0
endif

mv list_py.txt list_py_${number1}.py
mv list_py list_py_${number1}

if(( -e list_py) ) then
   rm -r list_py
endif

if(( -e list_py.txt) ) then
   rm list_py.txt
endif

if(( -e submit_failed.jdl) ) then
   rm submit_failed.jdl
endif

if(( -e PrintFailedJobs.txt) ) then
   rm PrintFailedJobs.txt
endif

if(( -e PrintFailedScripts.txt) ) then
   rm PrintFailedScripts.txt
endif

if(( -e PrintSuccessfulJobs.txt) ) then
   rm PrintSuccessfulJobs.txt
endif

if(( -e PrintSuccessfulScripts.txt) ) then
   rm PrintSuccessfulScripts.txt
endif
mkdir list_py
@ i=0
set j=0
set ai=0
while($i<$number2)
     @ ai++
     if(!(-e ${jobname}_${i}.root)) then
        echo "${jobname}_${i}.root does not exist" >>PrintFailedJobs.txt
        sed -n ${ai}p list_py_${number1}.txt >> list_py.txt
        set filename = `sed -n ${ai}p list_py_${number1}.txt`
        echo "${filename}">>PrintFailedScripts.txt
        cp -r ./list_py_${number1}/${filename} ./list_py
        @ j++
	endif
@ i++
end

echo "${j} jobs failed"
echo "${i}"
echo "${ai}"
cp submit.jdl fail_submit.jdl
sed -e /transfer_input_files/s/list_py/list_failed/g ./fail_submit.jdl > temp
mv temp fail_submit.jdl
sed -e /Queue/s/list_py/list_failed/g ./fail_submit.jdl > temp
mv temp fail_submit.jdl
cd $herepath
