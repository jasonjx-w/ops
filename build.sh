# !/bib/bash
set -e
##################################
# env
##################################
BUILD_DIR="build"
CMAKE="cmake"
GCC=`which gcc`
GXX=`which g++`

if [ ! -d ${BUILD_DIR} ]; then
  mkdir ${BUILD_DIR}
else
  rm -rf ${BUILD_DIR}/*
fi

pushd ${BUILD_DIR}
 ${CMAKE} \
 -DCMAKE_C_COMPILE=${GCC} \
 -DCMAKE_CXX_COMPILER=${GXX} \
 ..

 make -j32
popd
