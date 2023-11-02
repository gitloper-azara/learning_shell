#!/bin/bash

# read the max PID value from the file
max_pid=$(cat /proc/sys/kernel/pid_max)

echo "Maximum PID value: $max_pid"
