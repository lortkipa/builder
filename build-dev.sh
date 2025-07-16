
cd build
make config=dev all
bear -- make config=dev all > /dev/null 2>&1
cd ..
