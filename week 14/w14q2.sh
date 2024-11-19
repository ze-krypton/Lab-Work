#!/bin/bash

# Check if sufficient arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <directory> <filename>"
    echo "Example: $0 /home/user documents.txt"
    exit 1
fi

# Assign arguments to variables
directory="$1"
filename="$2"

# Check if the directory exists
if [ ! -d "$directory" ]; then
    echo "Directory '$directory' does not exist."
    exit 1
fi

# Search for the file in the directory
echo "Searching for '$filename' in '$directory'..."
find "$directory" -type f -name "$filename" 2>/dev/null

# Check if the find command found any matches
if [ $? -eq 0 ]; then
    echo "Search completed."
else
    echo "File '$filename' not found in '$directory'."
fi

