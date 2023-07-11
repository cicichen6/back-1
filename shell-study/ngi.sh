#! /bin/bash

#1、如果其UID为0，就显示此为管理员2、否则，就显示其为普通用户；
if [ `id -u` -ne 0 ];then
	echo "please use sudo."
fi



#安装nginx
apt-get -y  purge nginx >> /dev/null 2>&1
apt-get -y  install nginx >> /dev/null 2>&1

if [ $? -ne 0 ]
then
       	echo "failed"
fi

touch /var/www/html/index.html 

cat > /var/www/html/index.html << EOF
hello world
EOF

ufw allow 80/tcp

IPADDR=$(ip addr show | grep inet | grep -v inet6 | grep '/24' | awk '{print $2}' | awk -F '/' '{print $1}')

curl http://$IPADDR:80/index.html
RESULT="curl `http://$IPADDR:80/index.html`"
if [ `echo ${RESULT} | awk -v tem="hello world" '{print($1>tem)? "1":"0"}'` -eq "0" ];then	
echo "nginx installed"
fi

