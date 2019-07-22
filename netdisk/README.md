# NetDisk

这个小项目模拟了FTP文件服务器，故名为netdisk

## 功能概述

	1. 登录注册功能，并且有密码加密传输和验证，登录后可进行有限的操作，如上传，下载，查看文件目录，删除文件等。
 	2. 数据库存储虚拟目录，存储日志
 	3. 支持多用户，多并发请求
 	4. 上传下载过程与普通操作分离
 	5. 实现断点续传
 	6. 实现多点下载的同时能够断点续传