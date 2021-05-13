g++ -Dsaarang -std=c++17 -D_GLIBCXX_DEBUG -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -ftrapv -Wshadow -Wparentheses -Wshift-overflow=2 $1.cpp -o $1
./$1 < /home/saarang/Documents/cp/input.txt
