#Sheershak Agarwal                                                                                             
# HW3
# Problem 2                                                                                                           
# 22 April 2019

if [ $# -lt 2 ]; then
   echo "less than 2 arguments passed" >&2
   exit 1
fi

if [ ! -e "$2" ]; then
    echo "invalid html file $2" >&2
    exit 1
fi

file="$1"
link="$2"

grep -Eo '<strong><a [^>]+>' "$2" |  grep -Eo '(http)://[^/"]+' > "$file"

#grep -Eo '<strong><a [^>]+>' popular.html | sed -r -e 's/.*href="([^"#]+)".*/\1/'

exit 0
