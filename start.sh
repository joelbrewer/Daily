#!/usr/bin/env bash
date=$(date '+%Y-%m-%d')
echo $date

mkdir $date
echo "Copying template..."
cp template.c $date/main.c
echo "Copying Makefile..."
cp Makefile $date
