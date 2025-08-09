#!/bin/bash
clear

# Output binary name
OUT="cpp7"

# Find all .cpp files in main and modules directory
SRC_FILES=$(find . -name "*.cpp")

# Compile with includes for all subfolders inside ./modules
g++ $SRC_FILES -I./modules -o $OUT


# Check result
if [ $? -eq 0 ]; then 
    echo "✅ Build successful. Run it with: ./$OUT"
else
    echo -e "\033[1;31;41m❌ Build failed\033[0m"
fi

