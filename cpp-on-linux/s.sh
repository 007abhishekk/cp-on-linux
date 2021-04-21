g++ -std=c++17 -DLOCAL_DEFINE -o gen gen.cpp
g++ -std=c++17 -DLOCAL_DEFINE -o a C.cpp
g++ -std=c++17 -DLOCAL_DEFINE -o b B.cpp
for((i = 1; ; ++i)); do
    ./gen $i > in
    # ./a < in > in1
    ./b < in
    # diff -w <(./a < in > out) <(./b < in > out1) || break
    # diff -w out1 out || break
    echo $i "OK"
done

# echo "Failed Test on: "
# cat in
# echo "Expected Output: "
# cat out1
# echo "Your Output: "
# cat out