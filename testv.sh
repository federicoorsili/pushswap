n="$1"
gcc -Llibft -lft randomize.c -o r
rrr=$(./r $n)
echo $rrr
./push_swap $rrr | ./checker $rrr -v
rm r
unset rrr