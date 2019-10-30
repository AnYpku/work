#!/bin/sh
echo `date`
echo "input the variable"
#read name
#echo "$name It is a test"
echo "$PWD"
set param = `cat submit.jdl|grep \"Executable\":`
echo param
