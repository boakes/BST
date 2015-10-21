#!/bin/sh
cd "$(dirname "$0")"

now=$(date +"%D %T")

cp ~/Desktop/DataAbstraction/BST\ Map/BSTMap.cpp ~/Desktop/DataAbRepo/BST/
cp ~/Desktop/DataAbstraction/BST\ Map/BSTMap.h ~/Desktop/DataAbRepo/BST/

echo "Finished copy!"

git add .
git commit -m "$now"
git push