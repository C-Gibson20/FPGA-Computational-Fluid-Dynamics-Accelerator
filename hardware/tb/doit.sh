#!/bin/bash

# This script runs the testbench
# Usage: ./doit.sh <file1.cpp> <file2.cpp>

# Cleanup
rm -rf test_out
rm -f waveform.vcd

# Constants
SCRIPT_DIR=$(dirname "$(realpath "$0")")
TEST_FOLDER=$(realpath "$SCRIPT_DIR/tests")
RTL_FOLDER=$(realpath "$SCRIPT_DIR/../rtl")
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)

# Variables
passes=0
fails=0

# Handle terminal arguments
if [[ $# -eq 0 ]]; then
    # If no arguments provided, run all tests
    files=(${TEST_FOLDER}/*.cpp)
else
    # If arguments provided, use them as input files
    files=("$@")
fi

cd $SCRIPT_DIR

# Iterate through files
for file in "${files[@]}"; do
    filename=$(basename "$file")
    name=$(basename "$file" _tb.cpp | cut -f1 -d\-)


    #Find Verilog or System Verilog file
    rtl_file="${RTL_FOLDER}/${name}.sv"
    if [[ ! -f "$rtl_file" ]]; then
        rtl_file="${RTL_FOLDER}/${name}.v"
    fi

    if [[ ! -f "$rtl_file" ]]; then
        echo "Error: Could not find RTL file for module '$name'"
        exit 1
    fi


    # Translate Verilog/SystemVerilog -> C++ including testbench
    verilator   -Wall --trace \
                -cc "$rtl_file" \
                --exe ${TEST_FOLDER}/${filename} \
                -y ${RTL_FOLDER} \
                --prefix "Vdut" \
                -o Vdut \
                -CFLAGS "-isystem /opt/homebrew/Cellar/googletest/1.15.2/include" \
                -LDFLAGS "-L/opt/homebrew/Cellar/googletest/1.15.2/lib -lgtest -lgtest_main -lpthread" \
                --Wno-UNUSED \
                --Wno-WIDTH \
                --Wno-SELRANGE


    # Build C++ project with automatically generated Makefile
    make -j -C obj_dir/ -f Vdut.mk

    # Run executable simulation file
    ./obj_dir/Vdut

    # Check if the test succeeded or not
    if [ $? -eq 0 ]; then
        ((passes++))
    else
        ((fails++))
    fi

done

# Save obj_dir in test_out
mv obj_dir test_out/

# Exit as a pass or fail (for CI purposes)
if [ $fails -eq 0 ]; then
    echo "${GREEN}Success! All ${passes} test(s) passed!"
    exit 0
else
    total=$((passes + fails))
    echo "${RED}Failure! Only ${passes} test(s) passed out of ${total}."
    exit 1
    exit 1
fi