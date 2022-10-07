# open-read-write-linux-c

Design a program using ordinary pipes in which the parent process sends
a message from a file named file.txt to a child process, and the child
process removes the occurrences of all the special characters including
&amp;,@,#,%,*,? &amp;,$,”, and ~ and replace them with space (’ ’). And send
the modified version back to the parent process and the parent process
writes the modified data to the file updated.txt. This will require using
two pipes, one for sending the original message from the first to the
second process, and the other for sending the modified message from
the second back to the first process.
Note: Use only read, write and open system calls. Use of Cin, cout, prinf, ofstream, ifstream
etc. will result in zero marks.
