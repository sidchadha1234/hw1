To run the function simply compile it through typing in the following commands:
cd hw1
g++ -g -Wall ulliststr.cpp ulliststr_test.cpp -o test
./test

To test that there are no memory links, you can run valgrind as well:
valgrind --leak-check=yes ./test

When running ./test the results should be self explanatory. Reference the comments for
further explanation on what functions each output is testing.