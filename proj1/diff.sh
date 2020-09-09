#!/usr/bin/env bash

if [[ $# -ne 2 ]]; then
  echo "usage; $0 your_file test_file"
  exit 1
fi

if [[ ! -r $1 ]]; then
  echo "file not found: '$1'"
  exit 2
fi

if [[ ! -r $2 ]]; then
  echo "file not found: '$2'"
  exit 2
fi

echo $1 | ./readppm > _your_file_
echo $2 | ./readppm > _test_file_

diff -s -N -U0 --color=always _your_file_ _test_file_
rm -f _your_file_ _test_file_

exit 0
