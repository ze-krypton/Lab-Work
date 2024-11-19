#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <file>"
    echo "Example: $0 myfile.txt"
    exit 1
fi

# Assign the file name to a variable
file="$1"

# Check if the file exists
if [ ! -f "$file" ]; then
    echo "File '$file' does not exist."
    exit 1
fi

# Display the contents of the file with line numbers
echo "Displaying contents of '$file' with line numbers:"
nl "$file"

