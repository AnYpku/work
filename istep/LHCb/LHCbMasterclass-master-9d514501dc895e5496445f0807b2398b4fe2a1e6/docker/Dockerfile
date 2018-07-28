FROM cern/cc7-base 

#
# Installting the bare minimum to build/ run the masterclass on a CC7 image
#
RUN yum install -y xrootd-client 
RUN yum install -y root root-table root-graf3d-gl root-graf3d-eve root-guibuilder
RUN yum install -y git make cmake
RUN yum install -y devtoolset-7-gcc devtoolset-7-gcc-c++
CMD scl enable devtoolset-7 bash

