# 设置当前代理
git config --global http.proxy 127.0.0.1:7891

# 取消当前代理
git config --global --unset http.proxy

# 查看端口状态
netstat -aon|findstr "9527"

#浏览器设置调试模式打开
"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe" --remote-debugging-port=9527 --"%1"
C:\Program Files\Google\Chrome\Application\chrome.exe --remote-debugging-port=9527 --"%1"


pip freeze > requirements.txt