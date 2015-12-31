#! /bin/bash
clear
replace="$1"
replace_with="$2"
echo $replace
echo $replace_with
containing_directory_path="src/"
file_list=$(find . $containing_directory_path -name "*.c" -o -name "*.h")
for file in $file_list
do
echo $file
sed -i "s%$replace%$replace_with%g" $file
done

