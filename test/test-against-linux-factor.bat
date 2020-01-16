@echo off

setlocal enabledelayedexpansion

if NOT EXIST tmp\* (
    mkdir tmp
)

REM type tmp\a.txt
REM type tmp\b.txt

REM for %%h in (tmp\a.txt) do (set "a=%%h")
REM for %%h in (tmp\b.txt) do (set "b=%%h")

for /l %%g in (2,1,1000) do (
    factor %%g >tmp\a.txt
    ..\bin\factor.exe %%g >tmp\b.txt

    for /f "skip=1 delims=" %%h in ('fc tmp\a.txt tmp\b.txt') do (
        set "result=%%h"
    )

    if NOT "!result!"=="FC: no differences encountered" (
        echo Fail: %%g
    ) else (
        set cur=%%g
        if "!cur:~-1!"=="0" (
            echo %%g
        )
    )
)

REM ) else (
REM     echo Pass: %%g
REM )

REM del /q tmp\*
rmdir /s /q tmp

endlocal
pause
goto :eof
