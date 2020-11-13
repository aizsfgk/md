
SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-./bin-build}
cmake -S $SOURCE_DIR -B $BUILD_DIR
cd $BUILD_DIR && make

