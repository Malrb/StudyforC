del "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup\Winsh.lnk"
del %appdata%\Col.log
TASKKILL /F /IM Winsh.exe /T
del %appdata%\Winsh.exe