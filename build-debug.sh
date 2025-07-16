
cd build
make config=debug all
bear -- make config=debug all > /dev/null 2>&1
cd ..
