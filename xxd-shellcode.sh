#!/bin/bash
if [ $# -ne 1 ]
then
    printf "\n\tUsage: $0 filename.bin\n\n"
    exit
fi

filename=`echo $1 | sed s/"\.bin$"//`
rm -f $filename.shellcode

for i in `xxd -i $filename.bin | grep , | sed s/" "/" "/ | sed s/","/""/g | sed s/"0x"/"\\\\x"/g`
do
    echo -n "\\$i" >> $filename.shellcode
    echo -n "\\$i"
done
echo
