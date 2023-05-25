#!/bin/sh

#Ubuntu Server 20.04 SS install

if [ `id -u` -ne 0 ]; then
	echo "please use sudo"
	exit 1
fi

SS_CONFIG="/etc/shadowsocks.json"
PROX_CONFIG="/etc/proxychains.conf"
SS_TAR="./ss.tar"

apt install -y libsodium23 proxychains4

if [ ! -f $SS_TAR ]; then
	curl -O http://geonode.cn/ss.tar
fi

tar -xzvf $SS_TAR

pip2 install ./shadowsocks

read -p "please enter ip(or url): " SERVER 
read -p "please enter port: " PORT 
read -p "please enter password: " PASSWORD 

if [ -f $SS_CONFIG ]; then
	rm $SS_CONFIG -f
fi

cat >> $SS_CONFIG << EOF
{
  "server": "${SERVER}",
  "server_port": $PORT,
  "local_address": "127.0.0.1",
  "local_port": 1080,
  "password": "${PASSWORD}",
  "timeout": 300,
  "method": "aes-256-cfb",
  "fast_open": false
}
EOF

if [ -f ${PROX_CONFIG} ]; then
	rm $PROX_CONFIG -f
fi

cat >> $PROX_CONFIG << EOF
strict_chain

proxy_dns

tcp_read_time_out 15000

tcp_connect_time_out 8000

[ProxyList]

socks5 127.0.0.1 1080
EOF

sslocal -c $SS_CONFIG -d start

proxychains curl google.com

if [ $? -eq 0 ]; then
  echo "[ssinstall] notice: sslocal cannot quit in docker container."
  echo "[ssinstall] successful!"
else
	echo "[ssinstall] faild!"
fi

