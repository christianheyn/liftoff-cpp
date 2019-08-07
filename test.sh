if gcc -std=c++17 -lstdc++ ./test/main.cpp -o dist/test ; then
    echo "Compiling succeeded"
    ./dist/test
else
    echo "Compiling failed"
fi
