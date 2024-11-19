#!/bin/bash

# Check if arguments are provided
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 file1 [file2 ...]"
    exit 1
fi

# Iterate over all supplied arguments
for file in "$@"; do
    # Check if the file exists
    if [ -e "$file" ]; then
        # Create a backup of the file
        cp "$file" "${file}.bak"
        echo "Backup of '$file' created as '${file}.bak'."

        # Delete lines containing the word 'unix'
        sed -i '/unix/d' "$file"
        echo "Lines containing the word 'unix' have been deleted from '$file'."
    else
        echo "File '$file' does not exist. Skipping."
    fi
done

echo "Operation completed!"

