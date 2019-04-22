# Get SW and HW specs from your computer with Linux

## Steps:
* Compile: `gcc specs-linux.c -o specs-linux`
* Execute: `./specs-linux `

## Sample output
<pre>
Get SW and HW specs from your computer with linux

Option 1: Extracting data from '/proc' and '/etc' directories
model name      : Intel(R) Core(TM) i7-6500U CPU @ 2.50GHz
MemTotal:       12163216 kB
PRETTY_NAME="Ubuntu 18.10"

Option 2: Extracting data from 'lshw' command
WARNING: you should run this program as super-user.
WARNING: output may be incomplete or inaccurate, you should run this program as super-user.
/0/1                   processor      Intel(R) Core(TM) i7-6500U CPU @ 2.50GHz
/0/0                   memory         11GiB System memory
</pre>
