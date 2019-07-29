#Sheershak Agarwal
#HW3
#Problem 3
#22 April 2019

if [ $# -lt 2 ]; then
   echo "less than 2 arguments passed" >&2
   exit 1
fi

if [ ! -e "$2" ]; then
    echo "invalid file $2" >&2
    exit 1
fi

file="$1"
links="$2"
RANK=0

#use IFS="" option to prevent trailing whitespace from being trimmed 
# using -r to prevent backslash escape
while IFS= read -r link; do
    echo "Performing byte-size measurement on $link"
    (( RANK += 1 ))
    SIZE=$(./perform-measurement.sh "$link")
    if [ $SIZE -gt 0 ]; then
	echo "...successful"
	echo "$RANK $link $SIZE" >> "$file"
    else
	echo "...failure"
    fi
done < "$links"

exit 0
