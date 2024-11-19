#!/bin/bash

# Display all files in the current directory with read, write, and execute permissions
echo "Files in the current directory with read, write, and execute permissions:"

# Loop through all files in the current directory
for file in *; do
    # Check if the item is a file and if the user has read, write, and execute permissions
    if [ -f "$file" ] && [ -r "$file" ] && [ -w "$file" ] && [ -x "$file" ]; then
        echo "$file"
    fi
done

