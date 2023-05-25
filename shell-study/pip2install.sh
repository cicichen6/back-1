#!/bin/bash

if [ `id -u` -ne 0 ]; then
	echo "please use sudo"
	exit 1
fi

apt install python2 -y

PIP2_DIR="pip-20.3.4"
SETUPTOOLS_DIR="setuptools-44.1.1"
PIP2_FILE=$PIP2_DIR".tar.gz"
SETUPTOOLS_FILE=$SETUPTOOLS_DIR".zip"

if [ -d $PIP2_DIR ]; then
	rm -rf $PIP2_DIR
fi

if [ -d $SETUPTOOLS_DIR ]; then
	rm -rf $SETUPTOOLS_DIR
fi

if [ ! -f $PIP2_FILE ]; then
	curl -O http://geonode.cn/$PIP2_FILE
fi


if [ ! -f $SETUPTOOLS_FILE ]; then
	curl -O http://geonode.cn/$SETUPTOOLS_FILE
fi

unzip $SETUPTOOLS_FILE
cd $SETUPTOOLS_DIR

python2 setup.py install

cd ..

tar -xzvf $PIP2_FILE

cd $PIP2_DIR

python2 setup.py install

easy_install --version

if [ $? -eq 0 ]; then
	touch ~/.pydistutils.cfg
	cat /dev/null ~/.pydistutils.cfg
cat >> ~/.pydistutils.cfg << EOF
[easy_install]
index-url=https://mirrors.aliyun.com/pypi/simple
EOF
	echo "setuptools install successful"
fi

pip2 --version

if [ $? -eq 0 ]; then
	pip2 config set global.index-url https://mirrors.aliyun.com/pypi/simple/
	echo "pip2 install successful"
fi

cd ..

echo "done!"

