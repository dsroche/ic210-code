#!/usr/bin/env bash

if [[ $# -ne 2 ]]; then
  echo "usage; $0 your_file test_file"
  exit 1
fi

function showfirst {
  # shows up to the first $1 lines of stdin (like head),
  # and reports how many additional lines there are
  over=false
  for (( i=0; i < $1; i++ )); do
    if read line; then
      echo "$line"
    else
      over=true
      break
    fi
  done
  if ! $over; then
    echo "... and $(wc -l) more lines"
  fi
  return 0
}


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

diff -s -N -U1 --color=always --label "$1" --label "$2" _your_file_ _test_file_ | showfirst 40
rm -f _your_file_ _test_file_

exit 0
