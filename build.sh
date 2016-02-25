rm -rf build
mkdir -p build
pushd build

gcc -g ../src/alp.cpp -o alp
gcc -g ../src/logol.cpp -o logol
