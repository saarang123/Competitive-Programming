echo "Making files for contest $1"
START=$2
STOP=$3
for letter in $(eval echo {$START..$STOP}); do
    echo "$1$letter"
    cp template.cpp "$1$letter.cpp"
    subl "$1$letter.cpp"
done
