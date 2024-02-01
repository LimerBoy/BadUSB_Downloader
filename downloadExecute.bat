@echo off
:: Hide console
mode con: cols=15 lines=1
color 7f
chcp 65001
title 

:: Config
set u='https://cdn.discordapp.com/attachments/1154635152610299964/1155258532598382744/rick.mp4'
set f=%tmp%\rick.mp4

:: Download file
powershell -c "Invoke-WebRequest %u% -OutFile '%f%'"

:: Run
start "" "%f%"

:: Exit
exit