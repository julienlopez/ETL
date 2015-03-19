#!/bin/bash

function launchTest
{
	etlDir=$2
	countTotal=`expr $countTotal + 1`
	cp $1/* $tmpDir

	g++ -std=c++11 $tmpDir/main.cpp -o $tmpDir/a.out -I $etlDir 2>/dev/null > /dev/null
	if [ $? -ne 0 ] 
	then 
		echo -n .
		countSuccesses=`expr $countSuccesses + 1`
	else
		echo -n F
		countErrors=`expr $countErrors + 1`
	fi
}

function runSuite
{
	rootDir=$1
	etlDir=$2
	testName=`basename $rootDir`

	cd $rootDir

	echo "running $testName"

	tmpDir=tmp
	mkdir $tmpDir

	countTotal=0
	countSuccesses=0
	countErrors=0

	for i in $testName*
	do
		launchTest $i $etlDir
	done

	echo 
	echo "$countTotal tests run: $countSuccesses successes, $countErrors errors"

	rm -rf $tmpDir

	cd -

	[ $countTotal -eq $countSuccesses ] && return 0 || return 1
}

rootDir=`pwd`
echo $rootDir
etlDir=$rootDir/..
echo $etlDir

runSuite utils/TestNonCopyable $etlDir
runSuite utils/TestNonInstatiable $etlDir