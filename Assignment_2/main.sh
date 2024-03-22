#!/bin/bash
usage_message()
{
	echo "Usage: $0 <filename1> <filename2>"
}


# Check if exactly two arguments are provided
if [ "$#" -ne 2 ]; then
    usage_message
    exit 1
fi

# Extract filenames from arguments
filename1=$1
filename2=$2

# Check if both files exist
if [ ! -e "$filename1" ]; then
    echo "Error: $filename1 does not exist."
    exit 1
fi

if [ ! -r "$filename1" ]; then
    echo "Error: $filename1 is not readable."
    exit 1
fi

if [ ! -s "$filename1" ]; then
    echo "Error: $filename1 is empty."
    exit 1
fi

# Extract unique cities from the input file
# tail -n +2: Skip the first line
# cut -d ',' -f 3: Extract the third column
# sort -u: Sort and remove duplicates
# sed -e 's/^[ \t]*//': Remove leading whitespaces
unique_cities=$(tail -n +2 "$filename1" | cut -d ',' -f 3 | sort -u| sed -e 's/^[ \t]*//')

# Write unique cities to the output file
# >: Overwrite the file
# >>: Append to the file
echo "------------------" > "$filename2"
echo "Unique cities in the given data file: " >> "$filename2"
echo "$unique_cities" >> "$filename2"

# Extract the three highest earners.
# awk -F ',': Set the field separator to ','
# NR > 1: Skip the first line
# sort -t ',' -k4nr -k1: Sort by the fourth column in descending order and then by the first column
# head -n 3: Extract the top 3 lines
highest_earners=$(awk -F ',' 'NR > 1 {print $0}' "$filename1" | sort -t ',' -k4nr -k1| head -n 3)

# Write this extracted data to output file
echo "------------------" >> "$filename2"
echo "Details of top 3 individuals with the highest salary: " >> "$filename2"
echo "$highest_earners" >> "$filename2"

# Calculate the average salary of each city
# cities[$3] += $4; count[$3]++: Add the salary to the city and increment the count
# END: After processing all lines
# for (city in cities): Iterate over the cities
# avg_salary = cities[city] / count[city]: Calculate the average salary
echo "------------------" >> "$filename2"
echo "Details of average salary of each city: " >> "$filename2"
awk -F ',' 'NR > 1 { cities[$3] += $4; count[$3]++ } 
            END { 
                for (city in cities) 
                {
                    if (count[city] > 0) {
                        avg_salary = cities[city] / count[city];
                        print "City:" city ", Salary: " avg_salary >> "'"$filename2"'";
                    }
                }
            }' "$filename1"

# Extract individuals with a salary above the overall average salary
# overall_avg_salary: Pass the overall
# if ($4 > overall_avg_salary): Check if the salary is above the overall average salary
echo "------------------" >> "$filename2"
echo "Details of individuals with a salary above the overall average salary: " >> "$filename2"

# Calculate the overall average salary
# sum += $4; count++: Add the salary to the sum and increment the count
# print sum/count: Calculate the average salary
overall_avg_salary=$(awk -F ',' 'NR > 1 {sum += $4; count++} END {print sum/count}' "$filename1")   

# Extract individuals with salary above the overall average salary
# if ($4 > overall_avg_salary): Check if the salary is above the overall average salary
awk -F ',' -v overall_avg_salary="$overall_avg_salary" 'NR > 1 { if ($4 > overall_avg_salary ) print $0 }' "$filename1" | sed "s/,/ /g" >> "$filename2"

echo "------------------" >> "$filename2"