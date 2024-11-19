clear

echo "File Creation and Deletion in Linux"
echo "-----------------------------------"

# Create a new file
echo "Enter the name of the file to create:"
read file_name
touch "$file_name"
echo "File '$file_name' created successfully!"

# Check if the file was created
if [ -f "$file_name" ]; then
    echo "File '$file_name' exists."
else
    echo "Failed to create the file."
    exit 1
fi

