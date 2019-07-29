#Sheershak Agarwal
# HW3
# Problem 1
# 22 April 2019

if [ $# -lt 1 ]; then
    echo "No arguments passed"
    exit 1
fi

link="$1"
OUTPUT=$(mktemp 2>/dev/null) # making a temp file and redirectly stderr to /dev/null

wget -t 1 -T 7 -o /dev/null -O "$OUTPUT" "$link" || { echo "0"; rm "$OUTPUT"; exit 2; }

wc -c < "$OUTPUT" || { echo "0"; rm "$OUTPUT"; exit 2;}

rm "$OUTPUT"

exit 0
