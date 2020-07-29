

##################################
# env
##################################
BUILD_DIR="build"
CMAKE="cmake"

if [ ! -d ${BUILD_DIR} ]; then
  mkdir ${BUILD_DIR}
else
  rm -rf ${BUILD_DIR}/*
fi

pushd ${BUILD_DIR}
 ${CMAKE} ..
 make -j32
popd
