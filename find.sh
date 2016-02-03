#! /bin/bash
clear
find="$1"
containing_directory_path="src/"
file_list=$(find . $containing_directory_path -name "*.c" -o -name "*.h")
for file in $file_list
do
 if grep -q $find "$file"; then
   echo "$file"
 fi
done

