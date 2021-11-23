#!/usr/bin/env bash
today=$(date '+%Y-%m-%d')
yesterday=$(date -v-1d '+%Y-%m-%d')

mkdir $today
echo "Copying yesterday..."
cp -R $yesterday/. $today
