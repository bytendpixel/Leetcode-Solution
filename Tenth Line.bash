# Read from the file file.txt and output the tenth line to stdout.
counter=0  # Initialize counter

while IFS= read -r line; do
    counter=$((counter + 1))  # Increment counter
    if [ $counter -eq 10 ]; then
        echo "$line"  # Print the 10th line
        break  # Exit the loop once the 10th line is found
    fi
done < file.txt
