#!/bin/bash

get_downspeed() {
    echo $(ifconfig enp0s3 | grep bytes | grep RX | cut -d ':' -f 2 | cut -d ' ' -f 1);
}
get_upspeed() {
    echo $(ifconfig enp0s3 | grep bytes | grep TX | cut -d ':' -f 2 | cut -d ' ' -f 1);
}

for((;;));
do
	r1=$(get_downspeed);

	sleep 1s;

	r2=$(get_downspeed);

	d=$(($r2-$r1));
    
	echo "download speed : "$(($d / 1024))" kB/s";

	t1=$(get_upspeed);

    	sleep 1s;

        t2=$(get_upspeed);

    	d=$(($t2-$t1));

	echo "upload speed : "$(($d / 1024))" kB/s";

done
