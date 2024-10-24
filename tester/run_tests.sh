#!/bin/sh

# ANSI color codes for colored output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Ensure the libft.a library is present
LIBFT_PATH="../libft.a"
if [ ! -f "$LIBFT_PATH" ]; then
    echo "Error: libft.a not found in Parent Directory"
    exit 1
fi

# Remove results.txt if it exists
if [ -f "results.txt" ]; then
    rm results.txt
    echo "Previous results.txt removed."
fi

# Find all .c files in the functions/ directory
TEST_FILES=$(find functions/ -name "*.c")

# Compile the test files dynamically
cc -Wall -Wextra -Werror -o test main.c $TEST_FILES $LIBFT_PATH

# Check if compilation succeeded
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Initialize counters for success and failure
success_count=0
failure_count=0

# Run the tests and save the results to results.txt
echo "Running tests..."
./test

# Check if results.txt was created
if [ ! -f "results.txt" ]; then
    echo "Error: results.txt was not created!"
    exit 1
fi

# Read the results.txt file line by line
while IFS= read -r line; do
    # Check if the line contains SUCCESS or KO and count accordingly
    if echo "$line" | grep -q "SUCCESS"; then
        echo "${GREEN}${line}${NC}"
        success_count=$((success_count+1))
    elif echo "$line" | grep -q "KO"; then
        echo "${RED}${line}${NC}"
        failure_count=$((failure_count+1))
    fi
done < results.txt

# Total tests run
total_tests=$((success_count + failure_count))

# Print summary with colors in the format "Test Summary: Successes/Total"
echo "\nTest Summary: ${success_count}/${total_tests}"

# Clean up the executable
rm -f test

