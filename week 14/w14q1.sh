#!/bin/bash

# Check if sufficient arguments are provided
if [ "$#" -lt 3 ]; then
    echo "Usage: $0 <file> <permissions> <owner>:<group>"
    echo "Example: $0 myfile.txt 755 user:group"
    exit 1
fi

# Assign arguments to variables
file="$1"
permissions="$2"
ownership="$3"

# Check if the file exists
if [ -e "$file" ]; then
    # Change file permissions
    chmod "$permissions" "$file"
    echo "Permissions of '$file' changed to $permissions."

    # Change file ownership
    chown "$ownership" "$file"
    echo "Ownership of '$file' changed to $ownership."
else
    echo "File '$file' does not exist."
    exit 1
fi

echo "Operation completed successfully."

