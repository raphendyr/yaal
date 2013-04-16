#!/bin/sh -e

cd "${0%/*}"

err=0

echo " ## Run real tests ##"
./tests/run.sh
echo
err=$(($err + $?))

echo " ## Test that all examples buid wihtout errors ##"
./examples/build_test.sh
echo
err=$(($err + $?))

exit $err
