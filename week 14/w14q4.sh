#!/bin/bash

# Check if at least one argument is provided
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <file_or_directory>..."
    exit 1
fi

# Loop through all arguments
for item in "$@"; do
    if [ -d "$item" ]; then
        # If it's a directory
        echo "$item is a directory."
    elif [ -f "$item" ]; then
        # If it's a file, count the number of lines
        line_count=$(wc -l < "$item")
        echo "$item is a file with $line_count lines."
    else
        # If it's neither a file nor a directory
        echo "$item is neither a file nor a directory."
    fi
done

