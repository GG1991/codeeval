#!/bin/bash

for i in `seq  1 12`;do
printf "%4i" $i
 for j in `seq  2 12`;do
 printf "%4i" $((i*j))
 done
 printf "\n"
done