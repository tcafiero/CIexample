@echo off
"C:\Program Files\MATLAB\R2019a\bin\matlab.exe" -nosplash -softwareopengl -nodesktop -minimize -sd "%cd%\Source\Code" folder -r "generate" -logfile .\logfile.log | more
:loop
tasklist /fi "imagename eq MATLAB.exe" |find ":" > nul
if errorlevel 1 goto loop
