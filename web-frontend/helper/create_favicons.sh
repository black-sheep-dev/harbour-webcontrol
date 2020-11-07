#!/bin/bash

sizes=(16 24 32 48 57 64 72 114 120 144 152)
favicon_sizes=(16 24 32 48 64)

# convert / resize / optimize icons
for size in ${sizes[*]}
do
    inkscape --export-overwrite -C -o ../public/img/favicon-$size.png -w $size -h $size ../../app/icons/harbour-webcontrol.svg
	optipng ../public/img/favicon-$size.png
done

# create favicon
str=""

for size in ${favicon_sizes[*]}
do
	str="${str} favicon-$size.png"
done

convert $str favicon.ico
