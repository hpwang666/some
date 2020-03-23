#!/bin/bash

if [ $# = 0 ]
then
echo "please input 3 params..."
return
else
for n in $@
do
    host=172.16.10.$n
    ping -c2 $host 1>/dev/null
    if [ $? = 0 ]; then
        echo "$host is UP"
    else
        echo "$host is DOWN"
    fi
done
fi


